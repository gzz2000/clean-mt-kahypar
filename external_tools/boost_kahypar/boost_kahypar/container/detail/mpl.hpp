//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2005-2013.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/container for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef BOOST_CONTAINER_CONTAINER_DETAIL_MPL_HPP
#define BOOST_CONTAINER_CONTAINER_DETAIL_MPL_HPP

#ifndef BOOST_CONFIG_HPP
#  include <boost_kahypar/config.hpp>
#endif

#if defined(BOOST_HAS_PRAGMA_ONCE)
#  pragma once
#endif

#include <boost_kahypar/container/detail/config_begin.hpp>
#include <boost_kahypar/container/detail/workaround.hpp>
#include <boost_kahypar/move/detail/type_traits.hpp>
#include <boost_kahypar/intrusive/detail/mpl.hpp>

#include <cstddef>

namespace boost_kahypar {
namespace container {
namespace dtl {

using boost_kahypar::move_detail::integral_constant;
using boost_kahypar::move_detail::true_type;
using boost_kahypar::move_detail::false_type;
using boost_kahypar::move_detail::enable_if_c;
using boost_kahypar::move_detail::enable_if;
using boost_kahypar::move_detail::enable_if_convertible;
using boost_kahypar::move_detail::disable_if_c;
using boost_kahypar::move_detail::disable_if;
using boost_kahypar::move_detail::disable_if_convertible;
using boost_kahypar::move_detail::is_convertible;
using boost_kahypar::move_detail::if_c;
using boost_kahypar::move_detail::if_;
using boost_kahypar::move_detail::identity;
using boost_kahypar::move_detail::bool_;
using boost_kahypar::move_detail::true_;
using boost_kahypar::move_detail::false_;
using boost_kahypar::move_detail::yes_type;
using boost_kahypar::move_detail::no_type;
using boost_kahypar::move_detail::bool_;
using boost_kahypar::move_detail::true_;
using boost_kahypar::move_detail::false_;
using boost_kahypar::move_detail::unvoid_ref;
using boost_kahypar::move_detail::and_;
using boost_kahypar::move_detail::or_;
using boost_kahypar::move_detail::not_;
using boost_kahypar::move_detail::enable_if_and;
using boost_kahypar::move_detail::disable_if_and;
using boost_kahypar::move_detail::enable_if_or;
using boost_kahypar::move_detail::disable_if_or;
using boost_kahypar::move_detail::remove_const;

template <class FirstType>
struct select1st
{
   typedef FirstType type;

   template<class T>
   BOOST_CONTAINER_FORCEINLINE const type& operator()(const T& x) const
   {  return x.first;   }

   template<class T>
   BOOST_CONTAINER_FORCEINLINE type& operator()(T& x)
   {  return const_cast<type&>(x.first);   }
};


template<typename T>
struct void_t { typedef void type; };

template <class T, class=void>
struct is_transparent_base
{
   BOOST_STATIC_CONSTEXPR bool value = false;
};

template <class T>
struct is_transparent_base<T, typename void_t<typename T::is_transparent>::type>
{
   BOOST_STATIC_CONSTEXPR bool value = true;
};

template <class T>
struct is_transparent
   : is_transparent_base<T>
{};

template <typename C, class /*Dummy*/, typename R>
struct enable_if_transparent
   : boost_kahypar::move_detail::enable_if_c<dtl::is_transparent<C>::value, R>
{};

#ifndef BOOST_CONTAINER_NO_CXX17_CTAD

// void_t (void_t for C++11)
template<typename...> using variadic_void_t = void;

// Trait to detect Allocator-like types.
template<typename Allocator, typename = void>
struct is_allocator
{
   BOOST_STATIC_CONSTEXPR bool value = false;
};

template <typename T>
T&& ctad_declval();

template<typename Allocator>
struct is_allocator < Allocator,
   variadic_void_t< typename Allocator::value_type
                  , decltype(ctad_declval<Allocator&>().allocate(size_t{})) >>
{
   BOOST_STATIC_CONSTEXPR bool value = true;
};

template<class T>
using require_allocator_t = typename enable_if_c<is_allocator<T>::value, T>::type;

template<class T>
using require_nonallocator_t = typename enable_if_c<!is_allocator<T>::value, T>::type;

#endif

}  //namespace dtl {
}  //namespace container {
}  //namespace boost_kahypar {

#include <boost_kahypar/container/detail/config_end.hpp>

#endif   //#ifndef BOOST_CONTAINER_CONTAINER_DETAIL_MPL_HPP

