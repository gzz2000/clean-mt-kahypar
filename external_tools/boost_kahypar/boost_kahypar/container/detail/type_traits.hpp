//////////////////////////////////////////////////////////////////////////////
// (C) Copyright John Maddock 2000.
// (C) Copyright Ion Gaztanaga 2005-2015.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/container for documentation.
//
// The alignment and Type traits implementation comes from
// John Maddock's TypeTraits library.
//
// Some other tricks come from Howard Hinnant's papers and StackOverflow replies
//////////////////////////////////////////////////////////////////////////////
#ifndef BOOST_CONTAINER_CONTAINER_DETAIL_TYPE_TRAITS_HPP
#define BOOST_CONTAINER_CONTAINER_DETAIL_TYPE_TRAITS_HPP

#ifndef BOOST_CONFIG_HPP
#  include <boost_kahypar/config.hpp>
#endif

#if defined(BOOST_HAS_PRAGMA_ONCE)
#  pragma once
#endif

#include <boost_kahypar/move/detail/type_traits.hpp>

namespace boost_kahypar {
namespace container {
namespace dtl {

using ::boost_kahypar::move_detail::enable_if;
using ::boost_kahypar::move_detail::enable_if_and;
using ::boost_kahypar::move_detail::is_same;
using ::boost_kahypar::move_detail::is_different;
using ::boost_kahypar::move_detail::is_pointer;
using ::boost_kahypar::move_detail::add_reference;
using ::boost_kahypar::move_detail::add_const;
using ::boost_kahypar::move_detail::add_const_reference;
using ::boost_kahypar::move_detail::remove_const;
using ::boost_kahypar::move_detail::remove_reference;
using ::boost_kahypar::move_detail::remove_cvref;
using ::boost_kahypar::move_detail::make_unsigned;
using ::boost_kahypar::move_detail::is_floating_point;
using ::boost_kahypar::move_detail::is_integral;
using ::boost_kahypar::move_detail::is_enum;
using ::boost_kahypar::move_detail::is_pod;
using ::boost_kahypar::move_detail::is_empty;
using ::boost_kahypar::move_detail::is_trivially_destructible;
using ::boost_kahypar::move_detail::is_trivially_default_constructible;
using ::boost_kahypar::move_detail::is_trivially_copy_constructible;
using ::boost_kahypar::move_detail::is_trivially_move_constructible;
using ::boost_kahypar::move_detail::is_trivially_copy_assignable;
using ::boost_kahypar::move_detail::is_trivially_move_assignable;
using ::boost_kahypar::move_detail::is_nothrow_default_constructible;
using ::boost_kahypar::move_detail::is_nothrow_copy_constructible;
using ::boost_kahypar::move_detail::is_nothrow_move_constructible;
using ::boost_kahypar::move_detail::is_nothrow_copy_assignable;
using ::boost_kahypar::move_detail::is_nothrow_move_assignable;
using ::boost_kahypar::move_detail::is_nothrow_swappable;
using ::boost_kahypar::move_detail::alignment_of;
using ::boost_kahypar::move_detail::aligned_storage;
using ::boost_kahypar::move_detail::nat;
using ::boost_kahypar::move_detail::nat2;
using ::boost_kahypar::move_detail::nat3;
using ::boost_kahypar::move_detail::natN;
using ::boost_kahypar::move_detail::max_align_t;
using ::boost_kahypar::move_detail::is_convertible;

}  //namespace dtl {
}  //namespace container {
}  //namespace boost_kahypar {

#endif   //#ifndef BOOST_CONTAINER_CONTAINER_DETAIL_TYPE_TRAITS_HPP
