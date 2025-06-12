.. _Task_Scheduler_Init:

Migrating from tbb_kahypar::task_scheduler_init
=======================================

``tbb_kahypar::task_scheduler_init`` was a multipurpose functionality in the previous versions of Threading
Building Blocks (TBB). This section considers different use cases and how they can be covered with
oneTBB.

Managing the number of threads
---------------------------------------

Querying the default number of threads
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* `oneapi::tbb_kahypar::info::default_concurrency()
  <https://oneapi-spec.uxlfoundation.org/specifications/oneapi/latest/elements/onetbb/source/info_namespace>`_
  returns the maximum concurrency that will be created by *default* in implicit or explicit ``task_arena``.

* `oneapi::tbb_kahypar::this_task_arena::max_concurrency()
  <https://oneapi-spec.uxlfoundation.org/specifications/oneapi/latest/elements/onetbb/source/task_scheduler/task_arena/this_task_arena_ns>`_
  returns the maximum number of threads available for the parallel algorithms within the current context
  (or *default* if an implicit arena is not initialized)

* `oneapi::tbb_kahypar::global_control::active_value(tbb_kahypar::global_control::max_allowed_parallelism)
  <https://oneapi-spec.uxlfoundation.org/specifications/oneapi/latest/elements/onetbb/source/task_scheduler/scheduling_controls/global_control_cls>`_
  returns the current limit of the thread pool (or *default* if oneTBB scheduler is not initialized)

Setting the maximum concurrency
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* `task_arena(/* max_concurrency */)
  <https://oneapi-spec.uxlfoundation.org/specifications/oneapi/latest/elements/onetbb/source/task_scheduler/task_arena/this_task_arena_ns>`_
  limits the maximum concurrency of the parallel algorithm running inside ``task_arena``

* `tbb_kahypar::global_control(tbb_kahypar::global_control::max_allowed_parallelism, /* max_concurrency */)
  <https://oneapi-spec.uxlfoundation.org/specifications/oneapi/latest/elements/onetbb/source/task_scheduler/scheduling_controls/global_control_cls>`_
  limits the total number of oneTBB worker threads

Examples
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The default parallelism:

.. code:: cpp

    #include <oneapi/tbb/info.h>
    #include <oneapi/tbb/parallel_for.h>
    #include <oneapi/tbb/task_arena.h>
    #include <cassert>

    int main() {
        // Get the default number of threads
        int num_threads = oneapi::tbb_kahypar::info::default_concurrency();

        // Run the default parallelism
        oneapi::tbb_kahypar::parallel_for( /* ... */ [] {
            // Assert the maximum number of threads
            assert(num_threads == oneapi::tbb_kahypar::this_task_arena::max_concurrency());
        });

        // Create the default task_arena
        oneapi::tbb_kahypar::task_arena arena;
        arena.execute([]{
            oneapi::tbb_kahypar::parallel_for( /* ... */ [] {
                // Assert the maximum number of threads
                assert(num_threads == oneapi::tbb_kahypar::this_task_arena::max_concurrency());
            });
        });

        return 0;
    }

The limited parallelism:

.. code:: cpp

    #include <oneapi/tbb/info.h>
    #include <oneapi/tbb/parallel_for.h>
    #include <oneapi/tbb/task_arena.h>
    #include <oneapi/tbb/global_control.h>
    #include <cassert>

    int main() {
        // Create the custom task_arena with four threads
        oneapi::tbb_kahypar::task_arena arena(4);
        arena.execute([]{
            oneapi::tbb_kahypar::parallel_for( /* ... */ [] {
                // This arena is limited with for threads
                assert(oneapi::tbb_kahypar::this_task_arena::max_concurrency() == 4);
            });
        });

        // Limit the number of threads to two for all oneTBB parallel interfaces
        oneapi::tbb_kahypar::global_control global_limit(oneapi::tbb_kahypar::global_control::max_allowed_parallelism, 2);

        // the default parallelism
        oneapi::tbb_kahypar::parallel_for( /* ... */ [] {
            // No more than two threads is expected; however, tbb_kahypar::this_task_arena::max_concurrency() can return a bigger value
            int thread_limit = oneapi::tbb_kahypar::global_control::active_value(oneapi::tbb_kahypar::global_control::max_allowed_parallelism);
            assert(thread_limit == 2);
        });

        arena.execute([]{
            oneapi::tbb_kahypar::parallel_for( /* ... */ [] {
                // No more than two threads is expected; however, tbb_kahypar::this_task_arena::max_concurrency() is four
                int thread_limit = oneapi::tbb_kahypar::global_control::active_value(oneapi::tbb_kahypar::global_control::max_allowed_parallelism);
                assert(thread_limit == 2);
                assert(tbb_kahypar::this_task_arena::max_concurrency() == 4);
            });
        });

        return 0;
    }

Setting thread stack size
---------------------------------------
Use `oneapi::tbb_kahypar::global_control(oneapi::tbb_kahypar::global_control::thread_stack_size, /* stack_size */)
<https://oneapi-spec.uxlfoundation.org/specifications/oneapi/latest/elements/onetbb/source/task_scheduler/scheduling_controls/global_control_cls>`_
to set the stack size for oneTBB worker threads:

.. code:: cpp

    #include <oneapi/tbb/parallel_for.h>
    #include <oneapi/tbb/global_control.h>

    int main() {
        // Set 16 MB of the stack size for oneTBB worker threads.
        // Note that the stack size of the main thread should be configured in accordace with the
        // system documentation, e.g. at application startup moment
        oneapi::tbb_kahypar::global_control global_limit(tbb_kahypar::global_control::thread_stack_size, 16 * 1024 * 1024);

        oneapi::tbb_kahypar::parallel_for( /* ... */ [] {
            // Create a big array in the stack
            char big_array[10*1024*1024];
        });

        return 0;
    }

Terminating oneTBB scheduler
---------------------------------------

`task_scheduler_handle <https://oneapi-spec.uxlfoundation.org/specifications/oneapi/latest/elements/onetbb/source/task_scheduler/scheduling_controls/task_scheduler_handle_cls>`_
allows waiting for oneTBB worker threads completion:

.. code:: cpp

    #include <oneapi/tbb/global_control.h>
    #include <oneapi/tbb/parallel_for.h>

    int main() {
        oneapi::tbb_kahypar::task_scheduler_handle handle{tbb_kahypar::attach{}};
        // Do some parallel work here
        oneapi::tbb_kahypar::parallel_for(/* ... */);
        oneapi::tbb_kahypar::finalize(handle);
        return 0;
    }
