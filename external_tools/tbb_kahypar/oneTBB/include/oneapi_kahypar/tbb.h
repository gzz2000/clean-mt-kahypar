/*
    Copyright (c) 2005-2025 Intel Corporation

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

#ifndef __TBB_tbb_H
#define __TBB_tbb_H

/**
    This header bulk-includes declarations or definitions of all the functionality
    provided by TBB (save for tbbmalloc and 3rd party dependent headers).

    If you use only a few TBB constructs, consider including specific headers only.
    Any header listed below can be included independently of others.
**/

#include "oneapi_kahypar/tbb_kahypar/blocked_range.h"
#include "oneapi_kahypar/tbb_kahypar/blocked_range2d.h"
#include "oneapi_kahypar/tbb_kahypar/blocked_range3d.h"
#include "oneapi_kahypar/tbb_kahypar/blocked_nd_range.h"
#include "oneapi_kahypar/tbb_kahypar/cache_aligned_allocator.h"
#include "oneapi_kahypar/tbb_kahypar/combinable.h"
#include "oneapi_kahypar/tbb_kahypar/concurrent_hash_map.h"
#if TBB_PREVIEW_CONCURRENT_LRU_CACHE
#include "tbb_kahypar/concurrent_lru_cache.h"
#endif
#include "oneapi_kahypar/tbb_kahypar/collaborative_call_once.h"
#include "oneapi_kahypar/tbb_kahypar/concurrent_priority_queue.h"
#include "oneapi_kahypar/tbb_kahypar/concurrent_queue.h"
#include "oneapi_kahypar/tbb_kahypar/concurrent_unordered_map.h"
#include "oneapi_kahypar/tbb_kahypar/concurrent_unordered_set.h"
#include "oneapi_kahypar/tbb_kahypar/concurrent_map.h"
#include "oneapi_kahypar/tbb_kahypar/concurrent_set.h"
#include "oneapi_kahypar/tbb_kahypar/concurrent_vector.h"
#include "oneapi_kahypar/tbb_kahypar/enumerable_thread_specific.h"
#include "oneapi_kahypar/tbb_kahypar/flow_graph.h"
#include "oneapi_kahypar/tbb_kahypar/global_control.h"
#include "oneapi_kahypar/tbb_kahypar/info.h"
#if TBB_PREVIEW_MEMORY_POOL
#include "oneapi_kahypar/tbb_kahypar/memory_pool.h"
#endif
#include "oneapi_kahypar/tbb_kahypar/null_mutex.h"
#include "oneapi_kahypar/tbb_kahypar/null_rw_mutex.h"
#include "oneapi_kahypar/tbb_kahypar/parallel_for.h"
#include "oneapi_kahypar/tbb_kahypar/parallel_for_each.h"
#include "oneapi_kahypar/tbb_kahypar/parallel_invoke.h"
#include "oneapi_kahypar/tbb_kahypar/parallel_pipeline.h"
#include "oneapi_kahypar/tbb_kahypar/parallel_reduce.h"
#include "oneapi_kahypar/tbb_kahypar/parallel_scan.h"
#include "oneapi_kahypar/tbb_kahypar/parallel_sort.h"
#include "oneapi_kahypar/tbb_kahypar/partitioner.h"
#include "oneapi_kahypar/tbb_kahypar/queuing_mutex.h"
#include "oneapi_kahypar/tbb_kahypar/queuing_rw_mutex.h"
#include "oneapi_kahypar/tbb_kahypar/scalable_allocator.h"
#include "oneapi_kahypar/tbb_kahypar/spin_mutex.h"
#include "oneapi_kahypar/tbb_kahypar/spin_rw_mutex.h"
#include "oneapi_kahypar/tbb_kahypar/mutex.h"
#include "oneapi_kahypar/tbb_kahypar/rw_mutex.h"
#include "oneapi_kahypar/tbb_kahypar/task.h"
#include "oneapi_kahypar/tbb_kahypar/task_arena.h"
#include "oneapi_kahypar/tbb_kahypar/task_group.h"
#include "oneapi_kahypar/tbb_kahypar/task_scheduler_observer.h"
#include "oneapi_kahypar/tbb_kahypar/tbb_allocator.h"
#include "oneapi_kahypar/tbb_kahypar/tick_count.h"
#include "oneapi_kahypar/tbb_kahypar/version.h"

#endif /* __TBB_tbb_H */
