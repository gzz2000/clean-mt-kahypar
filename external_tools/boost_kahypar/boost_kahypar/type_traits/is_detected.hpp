/*
Copyright 2017-2018 Glen Joseph Fernandes
(glenjofe@gmail.com)

Distributed under the Boost Software License,
Version 1.0. (See accompanying file LICENSE_1_0.txt
or copy at http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef BOOST_TT_IS_DETECTED_HPP_INCLUDED
#define BOOST_TT_IS_DETECTED_HPP_INCLUDED

#include <boost_kahypar/type_traits/detail/detector.hpp>
#include <boost_kahypar/type_traits/nonesuch.hpp>

namespace boost_kahypar {

template<template<class...> class Op, class... Args>
using is_detected = typename
    detail::detector<nonesuch, void, Op, Args...>::value_t;

#if !defined(BOOST_NO_CXX14_VARIABLE_TEMPLATES)
template<template<class...> class Op, class... Args>
constexpr bool is_detected_v = is_detected<Op, Args...>::value;
#endif

} /* boost */

#endif
