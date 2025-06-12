/*
    Copyright (c) 2005-2022 Intel Corporation

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

#include "common/test.h"
#include "common/utils.h"

#include "oneapi_kahypar/tbb_kahypar/task_arena.h"
#include "oneapi_kahypar/tbb_kahypar/task_scheduler_observer.h"
#include "oneapi_kahypar/tbb_kahypar/enumerable_thread_specific.h"
#include "oneapi_kahypar/tbb_kahypar/parallel_for.h"

//! \file conformance_task_arena.cpp
//! \brief Test for [scheduler.task_arena scheduler.task_scheduler_observer] specification

// This test requires TBB in an uninitialized state
//! Test for uninitilized arena
//! \brief \ref requirement \ref interface
TEST_CASE("Test current_thread_index") {
    REQUIRE_MESSAGE((tbb_kahypar::this_task_arena::current_thread_index() == tbb_kahypar::task_arena::not_initialized), "TBB was initialized state");
}

//! Test task arena interfaces
//! \brief \ref requirement \ref interface
TEST_CASE("Arena interfaces") {
    //! Initialization interfaces
    oneapi::tbb_kahypar::task_arena a(1,1); a.initialize();
    std::atomic<bool> done{ false };
    //! Enqueue interface
    a.enqueue([&done] {
        CHECK(oneapi::tbb_kahypar::this_task_arena::max_concurrency() == 2);
        done = true;
    });
    //! Execute interface
    a.execute([&] {
        //! oneapi::tbb_kahypar::this_task_arena interfaces
        CHECK(oneapi::tbb_kahypar::this_task_arena::current_thread_index() >= 0);
        //! Attach interface
        oneapi::tbb_kahypar::task_arena attached_arena{oneapi::tbb_kahypar::task_arena::attach()};
        CHECK(attached_arena.is_active());
        oneapi::tbb_kahypar::task_arena attached_arena2{oneapi::tbb_kahypar::attach()};
        CHECK(attached_arena2.is_active());
    });
    while (!done) {
        utils::yield();
    }
    //! Terminate interface
    a.terminate();
}

//! Test tasks isolation for inner oneapi::tbb_kahypar::parallel_for loop
//! \brief \ref requirement \ref interface
TEST_CASE("Task isolation") {
    const int N1 = 1000, N2 = 1000;
    oneapi::tbb_kahypar::enumerable_thread_specific<int> ets;
    oneapi::tbb_kahypar::parallel_for(0, N1, [&](int i) {
        // Set a thread specific value
        ets.local() = i;
        // Run the second parallel loop in an isolated region to prevent the current thread
        // from taking tasks related to the outer parallel loop.
        oneapi::tbb_kahypar::this_task_arena::isolate([&]{
            oneapi::tbb_kahypar::parallel_for(0, N2, utils::DummyBody(10));
        });
        REQUIRE(ets.local() == i);
    });
}

class conformance_observer: public oneapi::tbb_kahypar::task_scheduler_observer {
public:
    std::atomic<bool> is_entry_called{false};
    std::atomic<bool> is_exit_called{false};

    conformance_observer( oneapi::tbb_kahypar::task_arena &a ) : oneapi::tbb_kahypar::task_scheduler_observer(a) {
        observe(true); // activate the observer
    }

    ~conformance_observer() {
        observe(false);
    }

    void on_scheduler_entry(bool) override {
        is_entry_called.store(true, std::memory_order_relaxed);
    }

    void on_scheduler_exit(bool) override {
        is_exit_called.store(true, std::memory_order_relaxed);
    }

    bool is_callbacks_called() {
        return is_entry_called.load(std::memory_order_relaxed)
            && is_exit_called.load(std::memory_order_relaxed);
    }
};

//! Test task arena observer interfaces
//! \brief \ref requirement \ref interface
TEST_CASE("Task arena observer") {
    oneapi::tbb_kahypar::task_arena a; a.initialize();
    conformance_observer observer(a);
    a.execute([&] {
        oneapi::tbb_kahypar::parallel_for(0, 100, utils::DummyBody(10), oneapi::tbb_kahypar::simple_partitioner());
    });
    REQUIRE(observer.is_callbacks_called());
}

//! Test task arena copy constructor
//! \brief \ref interface \ref requirement
TEST_CASE("Task arena copy constructor") {
    oneapi::tbb_kahypar::task_arena arena(1);
    oneapi::tbb_kahypar::task_arena copy = arena;

    REQUIRE(arena.max_concurrency() == copy.max_concurrency());
    REQUIRE(arena.is_active() == copy.is_active());
}


//! Basic test for arena::enqueue with task handle
//! \brief \ref interface \ref requirement
TEST_CASE("enqueue task_handle") {
    oneapi::tbb_kahypar::task_arena arena;
    oneapi::tbb_kahypar::task_group tg;

    //This flag is intentionally made non-atomic for Thread Sanitizer
    //to raise a flag if implementation of task_group is incorrect
    bool run{false};

    auto task_handle = tg.defer([&]{ run = true; });

    arena.enqueue(std::move(task_handle));
    tg.wait();

    CHECK(run == true);
}

//! Basic test for this_task_arena::enqueue with task handle
//! \brief \ref interface \ref requirement
TEST_CASE("this_task_arena::enqueue task_handle") {
    oneapi::tbb_kahypar::task_arena arena;
    oneapi::tbb_kahypar::task_group tg;

    //This flag is intentionally made non-atomic for Thread Sanitizer
    //to raise a flag if implementation of task_group is incorrect
    bool run{false};

    arena.execute([&]{
        auto task_handle = tg.defer([&]{ run = true; });

        oneapi::tbb_kahypar::this_task_arena::enqueue(std::move(task_handle));
    });

    tg.wait();

    CHECK(run == true);
}

//TODO: Add
//! Basic test for this_task_arena::enqueue with functor

//! Test case for the common use-case of prolonging task_group lifetime
//! \brief \ref interface \ref requirement
TEST_CASE("this_task_arena::enqueue prolonging task_group") {
    oneapi::tbb_kahypar::task_arena arena;
    oneapi::tbb_kahypar::task_group tg;

    //This flag is intentionally made non-atomic for Thread Sanitizer
    //to raise a flag if implementation of task_group is incorrect
    bool run{false};

    //block the task_group to wait on it
    auto task_handle = tg.defer([]{});

    arena.execute([&]{
        oneapi::tbb_kahypar::this_task_arena::enqueue([&]{
            run = true;
            //release the task_group
            task_handle = oneapi::tbb_kahypar::task_handle{};
        });
    });

    tg.wait();

    CHECK(run == true);
}

#if TBB_USE_EXCEPTIONS
//! Basic test for exceptions in task_arena::enqueue with task_handle
//! \brief \ref interface \ref requirement
TEST_CASE("task_arena::enqueue(task_handle) exception propagation"){
    oneapi::tbb_kahypar::task_group tg;
    oneapi::tbb_kahypar::task_arena arena;

    oneapi::tbb_kahypar::task_handle h = tg.defer([&]{
        volatile bool suppress_unreachable_code_warning = true;
        if (suppress_unreachable_code_warning) {
            throw std::runtime_error{ "" };
        }
    });

    arena.enqueue(std::move(h));

    CHECK_THROWS_AS(tg.wait(), std::runtime_error);
}

//! Basic test for exceptions in this_task_arena::enqueue with task_handle
//! \brief \ref interface \ref requirement
TEST_CASE("this_task_arena::enqueue(task_handle) exception propagation"){
    oneapi::tbb_kahypar::task_group tg;

    oneapi::tbb_kahypar::task_handle h = tg.defer([&]{
        volatile bool suppress_unreachable_code_warning = true;
        if (suppress_unreachable_code_warning) {
            throw std::runtime_error{ "" };
        }
    });

    oneapi::tbb_kahypar::this_task_arena::enqueue(std::move(h));

    CHECK_THROWS_AS(tg.wait(), std::runtime_error);
}

#endif // TBB_USE_EXCEPTIONS
