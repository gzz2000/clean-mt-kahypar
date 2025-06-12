/*
    Copyright (c) 2024 Intel Corporation

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#ifndef __TBB_test_tbb_buffering_try_put_and_wait_H
#define __TBB_test_tbb_buffering_try_put_and_wait_H

#include <oneapi_kahypar/tbb_kahypar/task_arena.h>
#include <oneapi_kahypar/tbb_kahypar/flow_graph.h>

#include <vector>

#if __TBB_PREVIEW_FLOW_GRAPH_TRY_PUT_AND_WAIT

namespace test_try_put_and_wait {

template <typename BufferingNode, typename... Args>
std::size_t test_buffer_push(const std::vector<int>& start_work_items,
                             int wait_message,
                             const std::vector<int>& new_work_items,
                             std::vector<int>& processed_items,
                             Args... args)
{
    std::size_t after_try_put_and_wait_start_index = 0;
    tbb_kahypar::task_arena arena(1);

    arena.execute([&] {
        tbb_kahypar::flow::graph g;

        using function_node_type = tbb_kahypar::flow::function_node<int, int>;

        BufferingNode buffer1(g, args...);

        function_node_type function(g, tbb_kahypar::flow::serial,
            [&](int input) noexcept {
                if (input == wait_message) {
                    for (auto item : new_work_items) {
                        buffer1.try_put(item);
                    }
                }
                return input;
            });

        BufferingNode buffer2(g, args...);

        function_node_type writer(g, tbb_kahypar::flow::unlimited,
            [&](int input) noexcept {
                processed_items.emplace_back(input);
                return 0;
            });

        tbb_kahypar::flow::make_edge(buffer1, function);
        tbb_kahypar::flow::make_edge(function, buffer2);
        tbb_kahypar::flow::make_edge(buffer2, writer);

        for (auto item : start_work_items) {
            buffer1.try_put(item);
        }

        buffer1.try_put_and_wait(wait_message);

        after_try_put_and_wait_start_index = processed_items.size();

        g.wait_for_all();
    });

    return after_try_put_and_wait_start_index;
}

template <typename BufferingNode, typename... Args>
std::size_t test_buffer_pull(const std::vector<int>& start_work_items,
                             int wait_message,
                             int occupier,
                             const std::vector<int>& new_work_items,
                             std::vector<int>& processed_items,
                             Args... args)
{
    tbb_kahypar::task_arena arena(1);
    std::size_t after_try_put_and_wait_start_index = 0;

    arena.execute([&] {
        tbb_kahypar::flow::graph g;

        using function_node_type = tbb_kahypar::flow::function_node<int, int, tbb_kahypar::flow::rejecting>;

        BufferingNode buffer(g, args...);

        function_node_type function(g, tbb_kahypar::flow::serial,
            [&](int input) noexcept {
                if (input == wait_message) {
                    for (auto item : new_work_items) {
                        buffer.try_put(item);
                    }
                }

                processed_items.emplace_back(input);
                return 0;
            });

        // Occupy the concurrency of function_node
        // This call spawns the task to process the occupier
        function.try_put(occupier);

        // Make edge between buffer and function after occupying the concurrency
        // To ensure that forward task of the buffer would be spawned after the occupier task
        // And the function_node would reject the items from the buffer
        // and process them later by calling try_get on the buffer
        tbb_kahypar::flow::make_edge(buffer, function);

        for (auto item : start_work_items) {
            buffer.try_put(item);
        }

        buffer.try_put_and_wait(wait_message);

        after_try_put_and_wait_start_index = processed_items.size();

        g.wait_for_all();
    });

    return after_try_put_and_wait_start_index;
}

template <typename BufferingNode, typename... Args>
std::size_t test_buffer_reserve(std::size_t limiter_threshold,
                                const std::vector<int>& start_work_items,
                                int wait_message,
                                const std::vector<int>& new_work_items,
                                std::vector<int>& processed_items,
                                Args... args)
{
    tbb_kahypar::task_arena arena(1);
    std::size_t after_try_put_and_wait_start_index = 0;

    arena.execute([&] {
        tbb_kahypar::flow::graph g;

        BufferingNode buffer(g, args...);

        tbb_kahypar::flow::limiter_node<int, int> limiter(g, limiter_threshold);
        tbb_kahypar::flow::function_node<int, int, tbb_kahypar::flow::rejecting> function(g, tbb_kahypar::flow::serial,
            [&](int input) {
                if (input == wait_message) {
                    for (auto item : new_work_items) {
                        buffer.try_put(item);
                    }
                }
                // Explicitly put to the decrementer instead of making edge
                // to guarantee that the next task would be spawned and not returned
                // to the current thread as the next task
                // Otherwise, all elements would be processed during the try_put_and_wait
                limiter.decrementer().try_put(1);
                processed_items.emplace_back(input);
                return 0;
            });

        tbb_kahypar::flow::make_edge(buffer, limiter);
        tbb_kahypar::flow::make_edge(limiter, function);

        for (auto item : start_work_items) {
            buffer.try_put(item);
        }

        buffer.try_put_and_wait(wait_message);

        after_try_put_and_wait_start_index = processed_items.size();

        g.wait_for_all();
    });

    return after_try_put_and_wait_start_index;
}

} // test_try_put_and_wait

#endif // __TBB_PREVIEW_FLOW_GRAPH_TRY_PUT_AND_WAIT
#endif // __TBB_test_tbb_buffering_try_put_and_wait_H
