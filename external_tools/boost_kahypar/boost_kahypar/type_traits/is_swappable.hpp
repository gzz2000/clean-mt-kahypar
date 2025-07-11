#ifndef BOOST_TYPE_TRAITS_IS_SWAPPABLE_HPP_INCLUDED
#define BOOST_TYPE_TRAITS_IS_SWAPPABLE_HPP_INCLUDED

//  Copyright 2023 Andrey Semashev
//
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/config.hpp>
#include <boost_kahypar/config/workaround.hpp>

#if !defined(BOOST_NO_SFINAE_EXPR) && !defined(BOOST_NO_CXX11_DECLTYPE) && !defined(BOOST_NO_CXX11_FUNCTION_TEMPLATE_DEFAULT_ARGS) && \
    !(defined(BOOST_DINKUMWARE_STDLIB) && (BOOST_CXX_VERSION < 201703L))

#include <boost_kahypar/type_traits/detail/is_swappable_cxx_11.hpp>

namespace boost_kahypar
{

template<class T, class U> struct is_swappable_with : boost_kahypar_type_traits_swappable_detail::is_swappable_with_helper<T, U>::type
{
};

template<class T> struct is_swappable : boost_kahypar_type_traits_swappable_detail::is_swappable_helper<T>::type
{
};

} // namespace boost_kahypar

#elif defined(BOOST_DINKUMWARE_STDLIB) && (BOOST_CXX_VERSION < 201703L) && \
    !defined(BOOST_NO_SFINAE_EXPR) && !defined(BOOST_NO_CXX11_DECLTYPE) && !defined(BOOST_NO_CXX11_FUNCTION_TEMPLATE_DEFAULT_ARGS) && !defined(BOOST_NO_CXX11_RVALUE_REFERENCES) && \
    !defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES) && !BOOST_WORKAROUND(BOOST_MSVC, < 1800) // these are required for is_constructible and is_assignable

// MSVC standard library has SFINAE-unfriendly std::swap in C++ modes prior to C++17,
// so we have to reproduce the restrictions on std::swap that are in effect in C++17 mode.

#include <cstddef>
#include <boost_kahypar/type_traits/negation.hpp>
#include <boost_kahypar/type_traits/conjunction.hpp>
#include <boost_kahypar/type_traits/integral_constant.hpp>
#include <boost_kahypar/type_traits/is_constructible.hpp>
#include <boost_kahypar/type_traits/is_assignable.hpp>
#include <boost_kahypar/type_traits/is_const.hpp>
#include <boost_kahypar/type_traits/detail/is_swappable_cxx_11.hpp>

namespace boost_kahypar
{

template<class T> struct is_swappable
    : boost_kahypar::conjunction<
        boost_kahypar::negation< boost_kahypar::is_const<T> >,
        boost_kahypar::is_constructible<T, T&&>,
        boost_kahypar::is_assignable<T&, T&&>
    >::type {};

template<> struct is_swappable<void> : false_type {};
template<> struct is_swappable<const void> : false_type {};
template<> struct is_swappable<volatile void> : false_type {};
template<> struct is_swappable<const volatile void> : false_type {};
template<class T> struct is_swappable<T[]> : false_type {};
template<class T> struct is_swappable<T(&)[]> : false_type {};
template<class T, std::size_t N> struct is_swappable<T[N]> : is_swappable<T> {};
template<class T, std::size_t N> struct is_swappable<T(&)[N]> : is_swappable<T> {};

template<class T, class U> struct is_swappable_with : boost_kahypar_type_traits_swappable_detail::is_swappable_with_helper<T, U>::type
{
};

template<class T> struct is_swappable_with<T, T> : is_swappable<T> {};

} // namespace boost_kahypar

#else

#include <boost_kahypar/type_traits/is_scalar.hpp>
#include <boost_kahypar/type_traits/integral_constant.hpp>

namespace boost_kahypar
{

template<class T> struct is_swappable : boost_kahypar::is_scalar<T> {};
template<class T> struct is_swappable<const T> : false_type {};

template<class T, class U> struct is_swappable_with : false_type {};
template<class T> struct is_swappable_with<T, T> : is_swappable<T> {};

} // namespace boost_kahypar

#endif

#endif // #ifndef BOOST_TYPE_TRAITS_IS_SWAPPABLE_HPP_INCLUDED
