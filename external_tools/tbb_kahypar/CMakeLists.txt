# this embedded intel TBB is patched from official https://github.com/uxlfoundation/oneTBB using a series of `sed`s..
#
# namespace tbb->tbb_kahypar
# include/{tbb->tbb_kahypar}
# include/{oneapi->oneapi_kahypar}
#
# this cmake is a simple polyfill by zizheng.

add_library(
  TBBKaHyPar
  STATIC
  oneTBB/src/tbb/address_waiter.cpp
  oneTBB/src/tbb/allocator.cpp
  oneTBB/src/tbb/arena.cpp
  oneTBB/src/tbb/arena_slot.cpp
  oneTBB/src/tbb/concurrent_bounded_queue.cpp
  oneTBB/src/tbb/dynamic_link.cpp
  oneTBB/src/tbb/exception.cpp
  oneTBB/src/tbb/governor.cpp
  oneTBB/src/tbb/global_control.cpp
  oneTBB/src/tbb/itt_notify.cpp
  oneTBB/src/tbb/main.cpp
  oneTBB/src/tbb/market.cpp
  oneTBB/src/tbb/tcm_adaptor.cpp
  oneTBB/src/tbb/misc.cpp
  oneTBB/src/tbb/misc_ex.cpp
  oneTBB/src/tbb/observer_proxy.cpp
  oneTBB/src/tbb/parallel_pipeline.cpp
  oneTBB/src/tbb/private_server.cpp
  oneTBB/src/tbb/profiling.cpp
  oneTBB/src/tbb/rml_tbb.cpp
  oneTBB/src/tbb/rtm_mutex.cpp
  oneTBB/src/tbb/rtm_rw_mutex.cpp
  oneTBB/src/tbb/semaphore.cpp
  oneTBB/src/tbb/small_object_pool.cpp
  oneTBB/src/tbb/task.cpp
  oneTBB/src/tbb/task_dispatcher.cpp
  oneTBB/src/tbb/task_group_context.cpp
  oneTBB/src/tbb/thread_dispatcher.cpp
  oneTBB/src/tbb/thread_request_serializer.cpp
  oneTBB/src/tbb/threading_control.cpp
  oneTBB/src/tbb/version.cpp
  oneTBB/src/tbb/queuing_rw_mutex.cpp
  )

target_include_directories(
  TBBKaHyPar PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/oneTBB/include
  )

target_compile_definitions(
  TBBKaHyPar PRIVATE
  __TBB_BUILD
  __TBB_DYNAMIC_LOAD_ENABLED=0
  __TBB_SOURCE_DIRECTLY_INCLUDED=1
  )

set_target_properties(TBBKaHyPar PROPERTIES POSITION_INDEPENDENT_CODE ON)

add_library(
  TBBMallocKaHyPar
  STATIC
  oneTBB/src/tbbmalloc/backend.cpp
  oneTBB/src/tbbmalloc/backref.cpp
  oneTBB/src/tbbmalloc/frontend.cpp
  oneTBB/src/tbbmalloc/large_objects.cpp
  oneTBB/src/tbbmalloc/tbbmalloc.cpp
  oneTBB/src/tbb/itt_notify.cpp
  )

target_include_directories(
  TBBMallocKaHyPar PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/oneTBB/include
  )

target_compile_definitions(
  TBBMallocKaHyPar PRIVATE
  __TBBMALLOC_BUILD
  __TBB_DYNAMIC_LOAD_ENABLED=0
  __TBB_SOURCE_DIRECTLY_INCLUDED=1
  )

set_target_properties(TBBMallocKaHyPar PROPERTIES POSITION_INDEPENDENT_CODE ON)
