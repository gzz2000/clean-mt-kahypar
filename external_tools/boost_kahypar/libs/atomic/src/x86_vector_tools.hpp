/*
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * Copyright (c) 2020 Andrey Semashev
 */
/*!
 * \file   x86_vector_tools.hpp
 *
 * This file contains common tools for x86 vectorization
 */

#ifndef BOOST_ATOMIC_X86_VECTOR_TOOLS_HPP_INCLUDED_
#define BOOST_ATOMIC_X86_VECTOR_TOOLS_HPP_INCLUDED_

#include <boost_kahypar/predef/architecture/x86.h>
#include <boost_kahypar/atomic/detail/int_sizes.hpp>

#if BOOST_ARCH_X86 && defined(BOOST_ATOMIC_DETAIL_SIZEOF_POINTER) && (BOOST_ATOMIC_DETAIL_SIZEOF_POINTER == 8)

#include <emmintrin.h>
#include <boost_kahypar/cstdint.hpp>
#include <boost_kahypar/atomic/detail/intptr.hpp>
#include <boost_kahypar/atomic/detail/config.hpp>

#include <boost_kahypar/atomic/detail/header.hpp>

namespace boost_kahypar {
namespace atomics {
namespace detail {

BOOST_FORCEINLINE __m128i mm_set1_epiptr(uintptr_t ptr)
{
#if !defined(_MSC_VER) || _MSC_FULL_VER >= 190024210
    return _mm_set1_epi64x(ptr);
#else
    // MSVC up until 14.0 update 3 doesn't provide _mm_set1_epi64x
    uint32_t lo = static_cast< uint32_t >(ptr), hi = static_cast< uint32_t >(ptr >> 32);
    return _mm_set_epi32(hi, lo, hi, lo);
#endif
}

} // namespace detail
} // namespace atomics
} // namespace boost_kahypar

#include <boost_kahypar/atomic/detail/footer.hpp>

#endif // BOOST_ARCH_X86 && defined(BOOST_ATOMIC_DETAIL_SIZEOF_POINTER) && (BOOST_ATOMIC_DETAIL_SIZEOF_POINTER == 8)

#endif // BOOST_ATOMIC_X86_VECTOR_TOOLS_HPP_INCLUDED_
