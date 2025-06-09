/*
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * https://www.boost.org/LICENSE_1_0.txt)
 *
 * Copyright (c) 2023 Andrey Semashev
 */
/*!
 * \file scope/detail/type_traits/negation.hpp
 *
 * This header contains definition of \c negation type trait.
 */

#ifndef BOOST_SCOPE_DETAIL_TYPE_TRAITS_NEGATION_HPP_INCLUDED_
#define BOOST_SCOPE_DETAIL_TYPE_TRAITS_NEGATION_HPP_INCLUDED_

#include <type_traits>
#include <boost_kahypar/scope/detail/config.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#if (defined(__cpp_lib_logical_traits) && (__cpp_lib_logical_traits >= 201510l)) || \
    (defined(BOOST_MSSTL_VERSION) && (BOOST_MSSTL_VERSION >= 140) && (_MSC_FULL_VER >= 190023918) && (BOOST_CXX_VERSION >= 201703l))

namespace boost_kahypar {
namespace scope {
namespace detail {

using std::negation;

} // namespace detail
} // namespace scope
} // namespace boost_kahypar

#else

#include <boost_kahypar/type_traits/negation.hpp>

namespace boost_kahypar {
namespace scope {
namespace detail {

using boost_kahypar::negation;

} // namespace detail
} // namespace scope
} // namespace boost_kahypar

#endif

#endif // BOOST_SCOPE_DETAIL_TYPE_TRAITS_NEGATION_HPP_INCLUDED_
