/*
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * Copyright (c) 2020 Andrey Semashev
 */
/*!
 * \file   atomic/detail/fence_ops_windows.hpp
 *
 * This header contains implementation of the \c fence_operations struct.
 */

#ifndef BOOST_ATOMIC_DETAIL_FENCE_OPS_WINDOWS_HPP_INCLUDED_
#define BOOST_ATOMIC_DETAIL_FENCE_OPS_WINDOWS_HPP_INCLUDED_

#include <boost_kahypar/cstdint.hpp>
#include <boost_kahypar/memory_order.hpp>
#include <boost_kahypar/atomic/detail/config.hpp>
#include <boost_kahypar/atomic/detail/interlocked.hpp>
#include <boost_kahypar/atomic/detail/ops_msvc_common.hpp>
#include <boost_kahypar/atomic/detail/header.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

namespace boost_kahypar {
namespace atomics {
namespace detail {

//! Fence operations based on Windows-specific system calls or intrinsics
struct fence_operations_windows
{
    static BOOST_FORCEINLINE void thread_fence(memory_order order) BOOST_NOEXCEPT
    {
        if (order != memory_order_relaxed)
        {
            BOOST_ATOMIC_DETAIL_COMPILER_BARRIER();
            if (order == memory_order_seq_cst)
                hardware_full_fence();
            BOOST_ATOMIC_DETAIL_COMPILER_BARRIER();
        }
    }

    static BOOST_FORCEINLINE void signal_fence(memory_order order) BOOST_NOEXCEPT
    {
        if (order != memory_order_relaxed)
            BOOST_ATOMIC_DETAIL_COMPILER_BARRIER();
    }

    static BOOST_FORCEINLINE void hardware_full_fence() BOOST_NOEXCEPT
    {
        boost_kahypar::uint32_t tmp;
        BOOST_ATOMIC_INTERLOCKED_INCREMENT(&tmp);
    }
};

typedef fence_operations_windows fence_operations;

} // namespace detail
} // namespace atomics
} // namespace boost_kahypar

#include <boost_kahypar/atomic/detail/footer.hpp>

#endif // BOOST_ATOMIC_DETAIL_FENCE_OPS_WINDOWS_HPP_INCLUDED_
