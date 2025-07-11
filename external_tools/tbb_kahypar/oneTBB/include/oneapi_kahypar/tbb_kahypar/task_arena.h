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

#ifndef __TBB_task_arena_H
#define __TBB_task_arena_H

#include "detail/_config.h"

#include "detail/_aligned_space.h"
#include "detail/_attach.h"
#include "detail/_exception.h"
#include "detail/_namespace_injection.h"
#include "detail/_small_object_pool.h"
#include "detail/_task.h"

#include "detail/_task_handle.h"

#if __TBB_ARENA_BINDING
#include "info.h"
#endif /*__TBB_ARENA_BINDING*/

namespace tbb_kahypar {
namespace detail {

namespace d1 {

template<typename F, typename R>
class task_arena_function : public delegate_base {
    F &my_func;
    aligned_space<R> my_return_storage;
    bool my_constructed{false};
    // The function should be called only once.
    bool operator()() const override {
        new (my_return_storage.begin()) R(my_func());
        return true;
    }
public:
    task_arena_function(F& f) : my_func(f) {}
    // The function can be called only after operator() and only once.
    R consume_result() {
        my_constructed = true;
        return std::move(*(my_return_storage.begin()));
    }
    ~task_arena_function() override {
        if (my_constructed) {
            my_return_storage.begin()->~R();
        }
    }
};

template<typename F>
class task_arena_function<F,void> : public delegate_base {
    F &my_func;
    bool operator()() const override {
        my_func();
        return true;
    }
public:
    task_arena_function(F& f) : my_func(f) {}
    void consume_result() const {}

    friend class task_arena_base;
};

class task_arena_base;
class task_scheduler_observer;
} // namespace d1

namespace r1 {
class arena;
struct task_arena_impl;

TBB_EXPORT void __TBB_EXPORTED_FUNC observe(d1::task_scheduler_observer&, bool);
TBB_EXPORT void __TBB_EXPORTED_FUNC initialize(d1::task_arena_base&);
TBB_EXPORT void __TBB_EXPORTED_FUNC terminate(d1::task_arena_base&);
TBB_EXPORT bool __TBB_EXPORTED_FUNC attach(d1::task_arena_base&);
TBB_EXPORT void __TBB_EXPORTED_FUNC execute(d1::task_arena_base&, d1::delegate_base&);
TBB_EXPORT void __TBB_EXPORTED_FUNC wait(d1::task_arena_base&);
TBB_EXPORT int  __TBB_EXPORTED_FUNC max_concurrency(const d1::task_arena_base*);
TBB_EXPORT void __TBB_EXPORTED_FUNC isolate_within_arena(d1::delegate_base& d, std::intptr_t);

TBB_EXPORT void __TBB_EXPORTED_FUNC enqueue(d1::task&, d1::task_arena_base*);
TBB_EXPORT void __TBB_EXPORTED_FUNC enqueue(d1::task&, d1::task_group_context&, d1::task_arena_base*);
TBB_EXPORT void __TBB_EXPORTED_FUNC submit(d1::task&, d1::task_group_context&, arena*, std::uintptr_t);

#if __TBB_PREVIEW_PARALLEL_PHASE
TBB_EXPORT void __TBB_EXPORTED_FUNC enter_parallel_phase(d1::task_arena_base*, std::uintptr_t);
TBB_EXPORT void __TBB_EXPORTED_FUNC exit_parallel_phase(d1::task_arena_base*, std::uintptr_t);
#endif
} // namespace r1

namespace d2 {
inline void enqueue_impl(task_handle&& th, d1::task_arena_base* ta) {
    __TBB_ASSERT(th != nullptr, "Attempt to schedule empty task_handle");

    auto& ctx = task_handle_accessor::ctx_of(th);

    // Do not access th after release
    r1::enqueue(*task_handle_accessor::release(th), ctx, ta);
}
} //namespace d2

namespace d1 {

static constexpr unsigned num_priority_levels = 3;
static constexpr int priority_stride = INT_MAX / (num_priority_levels + 1);

class task_arena_base {
    friend struct r1::task_arena_impl;
    friend void r1::observe(d1::task_scheduler_observer&, bool);
public:
    enum class priority : int {
        low    = 1 * priority_stride,
        normal = 2 * priority_stride,
        high   = 3 * priority_stride
    };

#if __TBB_PREVIEW_PARALLEL_PHASE
    enum class leave_policy : int {
        automatic = 0,
        fast      = 1
    };
#endif

#if __TBB_ARENA_BINDING
    using constraints = tbb_kahypar::detail::d1::constraints;
#endif /*__TBB_ARENA_BINDING*/
protected:
    //! Special settings
    intptr_t my_version_and_traits;

    std::atomic<do_once_state> my_initialization_state;

    //! nullptr if not currently initialized.
    std::atomic<r1::arena*> my_arena;
    static_assert(sizeof(std::atomic<r1::arena*>) == sizeof(r1::arena*),
        "To preserve backward compatibility we need the equal size of an atomic pointer and a pointer");

    //! Concurrency level for deferred initialization
    int my_max_concurrency;

    //! Reserved slots for external threads
    unsigned my_num_reserved_slots;

    //! Arena priority
    priority my_priority;

    //! The NUMA node index to which the arena will be attached
    numa_node_id my_numa_id;

    //! The core type index to which arena will be attached
    core_type_id my_core_type;

    //! Number of threads per core
    int my_max_threads_per_core;

    // Backward compatibility checks.
    core_type_id core_type() const {
        return (my_version_and_traits & core_type_support_flag) == core_type_support_flag ? my_core_type : automatic;
    }
    int max_threads_per_core() const {
        return (my_version_and_traits & core_type_support_flag) == core_type_support_flag ? my_max_threads_per_core : automatic;
    }

#if __TBB_PREVIEW_PARALLEL_PHASE
    leave_policy get_leave_policy() const {
        return (my_version_and_traits & fast_leave_policy_flag) ? leave_policy::fast : leave_policy::automatic;
    }

    int leave_policy_trait(leave_policy lp) const {
        return lp == leave_policy::fast ? fast_leave_policy_flag : 0;
    }

    void set_leave_policy(leave_policy lp) {
        my_version_and_traits |= leave_policy_trait(lp);
    }
#endif

    enum {
        default_flags               = 0,
        core_type_support_flag      = 1,
        fast_leave_policy_flag      = 1 << 1
    };

    task_arena_base(int max_concurrency, unsigned reserved_for_masters, priority a_priority
#if __TBB_PREVIEW_PARALLEL_PHASE
                    , leave_policy lp
#endif
    )
        : my_version_and_traits(default_flags | core_type_support_flag
#if __TBB_PREVIEW_PARALLEL_PHASE
                | leave_policy_trait(lp)
#endif
        )
        , my_initialization_state(do_once_state::uninitialized)
        , my_arena(nullptr)
        , my_max_concurrency(max_concurrency)
        , my_num_reserved_slots(reserved_for_masters)
        , my_priority(a_priority)
        , my_numa_id(automatic)
        , my_core_type(automatic)
        , my_max_threads_per_core(automatic)
        {}

#if __TBB_ARENA_BINDING
    task_arena_base(const constraints& constraints_, unsigned reserved_for_masters, priority a_priority
#if __TBB_PREVIEW_PARALLEL_PHASE
                    , leave_policy lp
#endif
    )
        : my_version_and_traits(default_flags | core_type_support_flag 
#if __TBB_PREVIEW_PARALLEL_PHASE
                | leave_policy_trait(lp)
#endif
                )
        , my_initialization_state(do_once_state::uninitialized)
        , my_arena(nullptr)
        , my_max_concurrency(constraints_.max_concurrency)
        , my_num_reserved_slots(reserved_for_masters)
        , my_priority(a_priority)
        , my_numa_id(constraints_.numa_id)
        , my_core_type(constraints_.core_type)
        , my_max_threads_per_core(constraints_.max_threads_per_core)
        {}
#endif /*__TBB_ARENA_BINDING*/
public:
    //! Typedef for number of threads that is automatic.
    static const int automatic = -1;
    static const int not_initialized = -2;
};

template<typename R, typename F>
R isolate_impl(F& f) {
    task_arena_function<F, R> func(f);
    r1::isolate_within_arena(func, /*isolation*/ 0);
    return func.consume_result();
}

template <typename F>
class enqueue_task : public task {
    small_object_allocator m_allocator;
    const F m_func;

    void finalize(const execution_data& ed) {
        m_allocator.delete_object(this, ed);
    }
    task* execute(execution_data& ed) override {
        m_func();
        finalize(ed);
        return nullptr;
    }
    task* cancel(execution_data&) override {
        __TBB_ASSERT_RELEASE(false, "Unhandled exception from enqueue task is caught");
        return nullptr;
    }
public:
    enqueue_task(const F& f, small_object_allocator& alloc) : m_allocator(alloc), m_func(f) {}
    enqueue_task(F&& f, small_object_allocator& alloc) : m_allocator(alloc), m_func(std::move(f)) {}
};

template<typename F>
void enqueue_impl(F&& f, task_arena_base* ta) {
    small_object_allocator alloc{};
    r1::enqueue(*alloc.new_object<enqueue_task<typename std::decay<F>::type>>(std::forward<F>(f), alloc), ta);
}
/** 1-to-1 proxy representation class of scheduler's arena
 * Constructors set up settings only, real construction is deferred till the first method invocation
 * Destructor only removes one of the references to the inner arena representation.
 * Final destruction happens when all the references (and the work) are gone.
 */
class task_arena : public task_arena_base {

    void mark_initialized() {
        __TBB_ASSERT( my_arena.load(std::memory_order_relaxed), "task_arena initialization is incomplete" );
        my_initialization_state.store(do_once_state::initialized, std::memory_order_release);
    }

    template<typename R, typename F>
    R execute_impl(F& f) {
        initialize();
        task_arena_function<F, R> func(f);
        r1::execute(*this, func);
        return func.consume_result();
    }
public:
    //! Creates task_arena with certain concurrency limits
    /** Sets up settings only, real construction is deferred till the first method invocation
     *  @arg max_concurrency specifies total number of slots in arena where threads work
     *  @arg reserved_for_masters specifies number of slots to be used by external threads only.
     *       Value of 1 is default and reflects behavior of implicit arenas.
     **/
    task_arena(int max_concurrency_ = automatic, unsigned reserved_for_masters = 1,
               priority a_priority = priority::normal
#if __TBB_PREVIEW_PARALLEL_PHASE
               , leave_policy lp = leave_policy::automatic
#endif
    )
        : task_arena_base(max_concurrency_, reserved_for_masters, a_priority
#if __TBB_PREVIEW_PARALLEL_PHASE
                         , lp
#endif
          )
    {}

#if __TBB_ARENA_BINDING
    //! Creates task arena pinned to certain NUMA node
    task_arena(const constraints& constraints_, unsigned reserved_for_masters = 1,
               priority a_priority = priority::normal
#if __TBB_PREVIEW_PARALLEL_PHASE
               , leave_policy lp = leave_policy::automatic
#endif
    )
        : task_arena_base(constraints_, reserved_for_masters, a_priority
#if __TBB_PREVIEW_PARALLEL_PHASE
                         , lp
#endif
          )
    {}

    //! Copies settings from another task_arena
    task_arena(const task_arena &a) // copy settings but not the reference or instance
        : task_arena_base(
            constraints{}
                .set_numa_id(a.my_numa_id)
                .set_max_concurrency(a.my_max_concurrency)
                .set_core_type(a.my_core_type)
                .set_max_threads_per_core(a.my_max_threads_per_core)
            , a.my_num_reserved_slots, a.my_priority
#if __TBB_PREVIEW_PARALLEL_PHASE
            , a.get_leave_policy()
#endif
        )
    
    {}
#else
    //! Copies settings from another task_arena
    task_arena(const task_arena& a) // copy settings but not the reference or instance
        : task_arena_base(a.my_max_concurrency,
                          a.my_num_reserved_slots,
                          a.my_priority,
#if __TBB_PREVIEW_PARALLEL_PHASE
                          a.get_leave_policy()
#endif
          )
    {}
#endif /*__TBB_ARENA_BINDING*/

    //! Tag class used to indicate the "attaching" constructor
    struct attach {};

    //! Creates an instance of task_arena attached to the current arena of the thread
    explicit task_arena( attach )
        : task_arena_base(automatic, 1, priority::normal
#if __TBB_PREVIEW_PARALLEL_PHASE
        , leave_policy::automatic
#endif
        ) // use default settings if attach fails
    {
        if (r1::attach(*this)) {
            mark_initialized();
        }
    }

    //! Creates an instance of task_arena attached to the current arena of the thread
    explicit task_arena(d1::attach)
        : task_arena(attach{})
    {}

    //! Forces allocation of the resources for the task_arena as specified in constructor arguments
    void initialize() {
        atomic_do_once([this]{ r1::initialize(*this); }, my_initialization_state);
    }

    //! Overrides concurrency level and forces initialization of internal representation
    void initialize(int max_concurrency_, unsigned reserved_for_masters = 1,
                    priority a_priority = priority::normal
#if __TBB_PREVIEW_PARALLEL_PHASE
                    , leave_policy lp = leave_policy::automatic
#endif
    )
    {
        __TBB_ASSERT(!my_arena.load(std::memory_order_relaxed), "Impossible to modify settings of an already initialized task_arena");
        if( !is_active() ) {
            my_max_concurrency = max_concurrency_;
            my_num_reserved_slots = reserved_for_masters;
            my_priority = a_priority;
#if __TBB_PREVIEW_PARALLEL_PHASE
            set_leave_policy(lp);
#endif
            r1::initialize(*this);
            mark_initialized();
        }
    }

#if __TBB_ARENA_BINDING
    void initialize(constraints constraints_, unsigned reserved_for_masters = 1,
                    priority a_priority = priority::normal
#if __TBB_PREVIEW_PARALLEL_PHASE
                    , leave_policy lp = leave_policy::automatic
#endif
    )
    {
        __TBB_ASSERT(!my_arena.load(std::memory_order_relaxed), "Impossible to modify settings of an already initialized task_arena");
        if( !is_active() ) {
            my_numa_id = constraints_.numa_id;
            my_max_concurrency = constraints_.max_concurrency;
            my_core_type = constraints_.core_type;
            my_max_threads_per_core = constraints_.max_threads_per_core;
            my_num_reserved_slots = reserved_for_masters;
            my_priority = a_priority;
#if __TBB_PREVIEW_PARALLEL_PHASE
            set_leave_policy(lp);
#endif
            r1::initialize(*this);
            mark_initialized();
        }
    }
#endif /*__TBB_ARENA_BINDING*/

    //! Attaches this instance to the current arena of the thread
    void initialize(attach) {
        // TODO: decide if this call must be thread-safe
        __TBB_ASSERT(!my_arena.load(std::memory_order_relaxed), "Impossible to modify settings of an already initialized task_arena");
        if( !is_active() ) {
            if ( !r1::attach(*this) ) {
                r1::initialize(*this);
            }
            mark_initialized();
        }
    }

    //! Attaches this instance to the current arena of the thread
    void initialize(d1::attach) {
        initialize(attach{});
    }

    //! Removes the reference to the internal arena representation.
    //! Not thread safe wrt concurrent invocations of other methods.
    void terminate() {
        if( is_active() ) {
            r1::terminate(*this);
            my_initialization_state.store(do_once_state::uninitialized, std::memory_order_relaxed);
        }
    }

    //! Removes the reference to the internal arena representation, and destroys the external object.
    //! Not thread safe wrt concurrent invocations of other methods.
    ~task_arena() {
        terminate();
    }

    //! Returns true if the arena is active (initialized); false otherwise.
    //! The name was chosen to match a task_scheduler_init method with the same semantics.
    bool is_active() const {
        return my_initialization_state.load(std::memory_order_acquire) == do_once_state::initialized;
    }

    //! Enqueues a task into the arena to process a functor, and immediately returns.
    //! Does not require the calling thread to join the arena

    template<typename F>
    void enqueue(F&& f) {
        initialize();
        enqueue_impl(std::forward<F>(f), this);
    }

    //! Enqueues a task into the arena to process a functor wrapped in task_handle, and immediately returns.
    //! Does not require the calling thread to join the arena
    void enqueue(d2::task_handle&& th) {
        initialize();
        d2::enqueue_impl(std::move(th), this);
    }

    //! Joins the arena and executes a mutable functor, then returns
    //! If not possible to join, wraps the functor into a task, enqueues it and waits for task completion
    //! Can decrement the arena demand for workers, causing a worker to leave and free a slot to the calling thread
    //! Since C++11, the method returns the value returned by functor (prior to C++11 it returns void).
    template<typename F>
    auto execute(F&& f) -> decltype(f()) {
        return execute_impl<decltype(f())>(f);
    }

#if __TBB_PREVIEW_PARALLEL_PHASE
    void start_parallel_phase() {
        initialize();
        r1::enter_parallel_phase(this, /*reserved*/0);
    }
    void end_parallel_phase(bool with_fast_leave = false) {
        __TBB_ASSERT(my_initialization_state.load(std::memory_order_relaxed) == do_once_state::initialized, nullptr);
        // It is guaranteed by the standard that conversion of boolean to integral type will result in either 0 or 1
        r1::exit_parallel_phase(this, static_cast<std::uintptr_t>(with_fast_leave));
    }

    class scoped_parallel_phase : no_copy {
        task_arena& arena;
        bool one_time_fast_leave;
    public:
        scoped_parallel_phase(task_arena& ta, bool with_fast_leave = false)
            : arena(ta), one_time_fast_leave(with_fast_leave)
        {
            arena.start_parallel_phase();
        }
        ~scoped_parallel_phase() {
            arena.end_parallel_phase(one_time_fast_leave);
        }
    };
#endif

#if __TBB_EXTRA_DEBUG
    //! Returns my_num_reserved_slots
    int debug_reserved_slots() const {
        // Handle special cases inside the library
        return my_num_reserved_slots;
    }

    //! Returns my_max_concurrency
    int debug_max_concurrency() const {
        // Handle special cases inside the library
        return my_max_concurrency;
    }

    //! Wait for all work in the arena to be completed
    //! Even submitted by other application threads
    //! Joins arena if/when possible (in the same way as execute())
    void debug_wait_until_empty() {
        initialize();
        r1::wait(*this);
    }
#endif //__TBB_EXTRA_DEBUG

    //! Returns the maximal number of threads that can work inside the arena
    int max_concurrency() const {
        // Handle special cases inside the library
        return (my_max_concurrency > 1) ? my_max_concurrency : r1::max_concurrency(this);
    }

    friend void submit(task& t, task_arena& ta, task_group_context& ctx, bool as_critical) {
        __TBB_ASSERT(ta.is_active(), nullptr);
        call_itt_task_notify(releasing, &t);
        r1::submit(t, ctx, ta.my_arena.load(std::memory_order_relaxed), as_critical ? 1 : 0);
    }
};

//! Executes a mutable functor in isolation within the current task arena.
//! Since C++11, the method returns the value returned by functor (prior to C++11 it returns void).
template<typename F>
inline auto isolate(F&& f) -> decltype(f()) {
    return isolate_impl<decltype(f())>(f);
}

//! Returns the index, aka slot number, of the calling thread in its current arena
inline int current_thread_index() {
    slot_id idx = r1::execution_slot(nullptr);
    return idx == slot_id(-1) ? task_arena_base::not_initialized : int(idx);
}

#if __TBB_PREVIEW_TASK_GROUP_EXTENSIONS
inline bool is_inside_task() {
    return nullptr != current_context();
}
#endif //__TBB_PREVIEW_TASK_GROUP_EXTENSIONS

//! Returns the maximal number of threads that can work inside the arena
inline int max_concurrency() {
    return r1::max_concurrency(nullptr);
}

inline void enqueue(d2::task_handle&& th) {
    d2::enqueue_impl(std::move(th), nullptr);
}

template<typename F>
inline void enqueue(F&& f) {
    enqueue_impl(std::forward<F>(f), nullptr);
}

#if __TBB_PREVIEW_PARALLEL_PHASE
inline void start_parallel_phase() {
    r1::enter_parallel_phase(nullptr, /*reserved*/0);
}

inline void end_parallel_phase(bool with_fast_leave) {
    // It is guaranteed by the standard that conversion of boolean to integral type will result in either 0 or 1
    r1::exit_parallel_phase(nullptr, static_cast<std::uintptr_t>(with_fast_leave));
}
#endif

using r1::submit;

} // namespace d1
} // namespace detail

inline namespace v1 {
using detail::d1::task_arena;
using detail::d1::attach;

#if __TBB_PREVIEW_TASK_GROUP_EXTENSIONS
using detail::d1::is_inside_task;
#endif

namespace this_task_arena {
using detail::d1::current_thread_index;
using detail::d1::max_concurrency;
using detail::d1::isolate;

using detail::d1::enqueue;

#if __TBB_PREVIEW_PARALLEL_PHASE
using detail::d1::start_parallel_phase;
using detail::d1::end_parallel_phase;
#endif
} // namespace this_task_arena

} // inline namespace v1

} // namespace tbb
#endif /* __TBB_task_arena_H */
