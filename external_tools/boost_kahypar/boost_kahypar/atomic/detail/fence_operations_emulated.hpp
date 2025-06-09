/*
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * Copyright (c) 2020 Andrey Semashev
 */
/*!
 * \file   atomic/detail/fence_operations_emulated.hpp
 *
 * This header contains implementation of the \c fence_operations struct.
 */

#ifndef BOOST_ATOMIC_DETAIL_FENCE_OPERATIONS_EMULATED_HPP_INCLUDED_
#define BOOST_ATOMIC_DETAIL_FENCE_OPERATIONS_EMULATED_HPP_INCLUDED_

#include <boost_kahypar/memory_order.hpp>
#include <boost_kahypar/atomic/detail/config.hpp>
#include <boost_kahypar/atomic/detail/lock_pool.hpp>
#include <boost_kahypar/atomic/detail/header.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

namespace boost_kahypar {
namespace atomics {
namespace detail {

//! Fence operations based on lock pool
struct fence_operations_emulated
{
    static BOOST_FORCEINLINE void thread_fence(memory_order) BOOST_NOEXCEPT
    {
        atomics::detail::lock_pool::thread_fence();
    }

    static BOOST_FORCEINLINE void signal_fence(memory_order) BOOST_NOEXCEPT
    {
        atomics::detail::lock_pool::signal_fence();
    }
};

} // namespace detail
} // namespace atomics
} // namespace boost_kahypar

#include <boost_kahypar/atomic/detail/footer.hpp>

#endif // BOOST_ATOMIC_DETAIL_FENCE_OPERATIONS_EMULATED_HPP_INCLUDED_
