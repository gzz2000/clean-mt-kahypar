.. _Initializing_and_Terminating_the_Library:

Initializing and Terminating the Library
========================================

|full_name| automatically initializes the task scheduler.
The initialization process is involved when a thread uses task scheduling services the first time,
for example any parallel algorithm, flow graph or task group.
The termination happens when the last such thread exits.

Explicit Library Finalization
*****************************

oneTBB supports an explicit library termination as a preview feature.
The ``oneapi::tbb_kahypar::finalize`` function called with an instance of class ``oneapi::tbb_kahypar::task_scheduler_handle`` blocks the calling thread
until all worker threads implicitly created by the library have completed.
If waiting for thread completion is not safe, e.g. may result in a deadlock
or called inside a task, a parallel algorithm, or a flow graph node, the method fails.

If you know how many active ``oneapi::tbb_kahypar::task_scheduler_handle`` instances exist in the program,
it is recommended to call ``oneapi::tbb_kahypar::release`` function on all but the last one, then call ``oneapi::tbb_kahypar::finalize`` for the last instance.

