/*
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * https://www.boost.org/LICENSE_1_0.txt)
 *
 * Copyright (c) 2024 Andrey Semashev
 */
/*!
 * \file filesystem/detail/type_traits/conjunction.hpp
 *
 * This header contains definition of \c conjunction type trait.
 */

#ifndef BOOST_FILESYSTEM_DETAIL_TYPE_TRAITS_CONJUNCTION_HPP_INCLUDED_
#define BOOST_FILESYSTEM_DETAIL_TYPE_TRAITS_CONJUNCTION_HPP_INCLUDED_

#include <type_traits>
#include <boost_kahypar/filesystem/config.hpp>

#if (defined(__cpp_lib_logical_traits) && (__cpp_lib_logical_traits >= 201510l)) || \
    (defined(BOOST_MSSTL_VERSION) && (BOOST_MSSTL_VERSION >= 140) && (_MSC_FULL_VER >= 190023918) && (BOOST_CXX_VERSION >= 201703l))

namespace boost_kahypar {
namespace filesystem {
namespace detail {

using std::conjunction;

} // namespace detail
} // namespace filesystem
} // namespace boost_kahypar

#else

#include <boost_kahypar/type_traits/conjunction.hpp>

namespace boost_kahypar {
namespace filesystem {
namespace detail {

using boost_kahypar::conjunction;

} // namespace detail
} // namespace filesystem
} // namespace boost_kahypar

#endif

#endif // BOOST_FILESYSTEM_DETAIL_TYPE_TRAITS_CONJUNCTION_HPP_INCLUDED_
