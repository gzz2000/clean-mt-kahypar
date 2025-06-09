
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef BOOST_TT_HAS_NOTHROW_CONSTRUCTOR_HPP_INCLUDED
#define BOOST_TT_HAS_NOTHROW_CONSTRUCTOR_HPP_INCLUDED

#include <cstddef> // size_t
#include <boost_kahypar/type_traits/intrinsics.hpp>
#include <boost_kahypar/type_traits/integral_constant.hpp>

#ifdef BOOST_HAS_NOTHROW_CONSTRUCTOR

#if defined(BOOST_MSVC) || defined(BOOST_INTEL)
#include <boost_kahypar/type_traits/has_trivial_constructor.hpp>
#endif
#if defined(__GNUC__ ) || defined(__SUNPRO_CC) || defined(__clang__)
#include <boost_kahypar/type_traits/is_default_constructible.hpp>
#endif

namespace boost_kahypar {

template <class T> struct has_nothrow_constructor : public integral_constant<bool, BOOST_HAS_NOTHROW_CONSTRUCTOR(T)>{};

#elif !defined(BOOST_NO_CXX11_NOEXCEPT)

#include <boost_kahypar/type_traits/is_default_constructible.hpp>
#include <boost_kahypar/type_traits/remove_all_extents.hpp>

#ifdef BOOST_MSVC
#pragma warning(push)
#pragma warning(disable:4197) // top-level volatile in cast is ignored
#endif

namespace boost_kahypar { namespace detail{

   template <class T, bool b> struct has_nothrow_constructor_imp : public boost_kahypar::integral_constant<bool, false>{};
   template <class T> struct has_nothrow_constructor_imp<T, true> : public boost_kahypar::integral_constant<bool, noexcept(T())>{};
   template <class T, std::size_t N> struct has_nothrow_constructor_imp<T[N], true> : public has_nothrow_constructor_imp<T, true> {};
}

template <class T> struct has_nothrow_constructor : public detail::has_nothrow_constructor_imp<T, is_default_constructible<T>::value>{};

#ifdef BOOST_MSVC
#pragma warning(pop)
#endif

#else

#include <boost_kahypar/type_traits/has_trivial_constructor.hpp>

namespace boost_kahypar {

template <class T> struct has_nothrow_constructor : public ::boost_kahypar::has_trivial_constructor<T> {};

#endif

template<> struct has_nothrow_constructor<void> : public false_type {};
#ifndef BOOST_NO_CV_VOID_SPECIALIZATIONS
template<> struct has_nothrow_constructor<void const> : public false_type{};
template<> struct has_nothrow_constructor<void const volatile> : public false_type{};
template<> struct has_nothrow_constructor<void volatile> : public false_type{};
#endif

template <class T> struct has_nothrow_default_constructor : public has_nothrow_constructor<T>{};

} // namespace boost_kahypar

#endif // BOOST_TT_HAS_NOTHROW_CONSTRUCTOR_HPP_INCLUDED
