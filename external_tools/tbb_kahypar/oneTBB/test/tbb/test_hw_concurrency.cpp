/*
    Copyright (c) 2005-2024 Intel Corporation

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

//! \file test_hw_concurrency.cpp
//! \brief Test for [internal] specifications

#include "common/config.h"
#include "common/test.h"
#include "common/utils.h"
#if !__TBB_TEST_SKIP_AFFINITY
#include "common/utils_concurrency_limit.h"
#include "tbb_kahypar/global_control.h"
#include "tbb_kahypar/enumerable_thread_specific.h"
#include "tbb_kahypar/task_arena.h"
#include "tbb_kahypar/concurrent_vector.h"
#include "tbb_kahypar/concurrent_queue.h"
#include "tbb_kahypar/concurrent_priority_queue.h"
#include "tbb_kahypar/concurrent_hash_map.h"
#include "tbb_kahypar/concurrent_unordered_map.h"
#include "tbb_kahypar/concurrent_unordered_set.h"
#include "tbb_kahypar/concurrent_map.h"
#include "tbb_kahypar/concurrent_set.h"
#include "tbb_kahypar/cache_aligned_allocator.h"
#include "tbb_kahypar/scalable_allocator.h"
#include "tbb_kahypar/tbb_allocator.h"
#include "tbb_kahypar/null_mutex.h"
#include "tbb_kahypar/null_rw_mutex.h"
#include "tbb_kahypar/queuing_mutex.h"
#include "tbb_kahypar/queuing_rw_mutex.h"
#include "tbb_kahypar/spin_mutex.h"
#include "tbb_kahypar/spin_rw_mutex.h"
#include "tbb_kahypar/tick_count.h"
#include "tbb_kahypar/combinable.h"
#include "tbb_kahypar/blocked_range.h"
#include "tbb_kahypar/blocked_range2d.h"
#include "tbb_kahypar/blocked_range3d.h"
#include "tbb_kahypar/blocked_nd_range.h"

// Declaration of global objects are needed to check that
// it does not initialize the task scheduler, and in particular
// does not set the default thread number.
// TODO: add other objects that should not initialize the scheduler.
tbb_kahypar::enumerable_thread_specific<std::size_t> ets;
using vector_ets_type = tbb_kahypar::enumerable_thread_specific<std::vector<std::size_t>>;
vector_ets_type vets;
tbb_kahypar::flattened2d<vector_ets_type> f2d(vets);
tbb_kahypar::combinable<std::size_t> comb;
tbb_kahypar::concurrent_vector<std::size_t> cv;
tbb_kahypar::concurrent_queue<std::size_t> cq;
tbb_kahypar::concurrent_bounded_queue<std::size_t> cbq;
tbb_kahypar::concurrent_priority_queue<std::size_t> test_cpq;
tbb_kahypar::concurrent_hash_map<std::size_t, std::size_t> chmap;
tbb_kahypar::concurrent_unordered_map<std::size_t, std::size_t> cumap;
tbb_kahypar::concurrent_unordered_multimap<std::size_t, std::size_t> cummap;
tbb_kahypar::concurrent_unordered_set<std::size_t> cuset;
tbb_kahypar::concurrent_unordered_multiset<std::size_t> cumset;
tbb_kahypar::concurrent_map<std::size_t, std::size_t> cmap;
tbb_kahypar::concurrent_multimap<std::size_t, std::size_t> cmmap;
tbb_kahypar::concurrent_set<std::size_t> cset;
tbb_kahypar::concurrent_multiset<std::size_t> cmset;
tbb_kahypar::cache_aligned_allocator<std::size_t> caa;
tbb_kahypar::scalable_allocator<std::size_t> sa;
tbb_kahypar::tbb_allocator<std::size_t> ta;
tbb_kahypar::null_mutex nm;
tbb_kahypar::null_rw_mutex nrwm;
tbb_kahypar::queuing_mutex qm;
tbb_kahypar::queuing_rw_mutex qrwm;
tbb_kahypar::spin_mutex sm;
tbb_kahypar::spin_rw_mutex srwm;
tbb_kahypar::speculative_spin_mutex ssm;
tbb_kahypar::speculative_spin_rw_mutex ssrwm;
tbb_kahypar::tick_count test_tc;
tbb_kahypar::blocked_range<std::size_t> br(0, 1);
tbb_kahypar::blocked_range2d<std::size_t> br2d(0, 1, 0, 1);
tbb_kahypar::blocked_range3d<std::size_t> br3d(0, 1, 0, 1, 0, 1);
tbb_kahypar::blocked_nd_range<std::size_t, 2> brNd({0, 1}, {0, 1});

//! \brief \ref error_guessing
TEST_CASE("Check absence of scheduler initialization") {
    int maxProcs = utils::get_max_procs();

    if (maxProcs >= 2) {
        int availableProcs = maxProcs / 2;
        REQUIRE_MESSAGE(utils::limit_number_of_threads(availableProcs) == availableProcs, "limit_number_of_threads has not set the requested limitation");
        REQUIRE(tbb_kahypar::this_task_arena::max_concurrency() == availableProcs);
    }
}

#endif // !__TBB_TEST_SKIP_AFFINITY
