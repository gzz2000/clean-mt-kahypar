/*
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * https://www.boost.org/LICENSE_1_0.txt)
 *
 * Copyright (c) 2023 Andrey Semashev
 */
/*!
 * \file scope/detail/type_traits/is_final.hpp
 *
 * This header contains definition of \c is_final type trait.
 */

#ifndef BOOST_SCOPE_DETAIL_TYPE_TRAITS_IS_FINAL_HPP_INCLUDED_
#define BOOST_SCOPE_DETAIL_TYPE_TRAITS_IS_FINAL_HPP_INCLUDED_

#include <type_traits>
#include <boost_kahypar/scope/detail/config.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#if (defined(__cpp_lib_is_final) && (__cpp_lib_is_final >= 201402l)) || \
    (defined(BOOST_MSSTL_VERSION) && (BOOST_MSSTL_VERSION >= 140) && (BOOST_CXX_VERSION >= 201402l))

namespace boost_kahypar {
namespace scope {
namespace detail {

using std::is_final;

} // namespace detail
} // namespace scope
} // namespace boost_kahypar

#else

#include <boost_kahypar/type_traits/is_final.hpp>

namespace boost_kahypar {
namespace scope {
namespace detail {

using boost_kahypar::is_final;

} // namespace detail
} // namespace scope
} // namespace boost_kahypar

#endif

#endif // BOOST_SCOPE_DETAIL_TYPE_TRAITS_IS_FINAL_HPP_INCLUDED_
