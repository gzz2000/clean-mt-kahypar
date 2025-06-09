#ifndef BOOST_BIND_PLACEHOLDERS_HPP_INCLUDED
#define BOOST_BIND_PLACEHOLDERS_HPP_INCLUDED

// MS compatible compilers support #pragma once

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

//
//  bind/placeholders.hpp - _N definitions
//
//  Copyright 2002, 2015, 2024 Peter Dimov
//
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//
//  See http://www.boost.org/libs/bind for documentation.
//

#include <boost_kahypar/bind/arg.hpp>
#include <boost_kahypar/config.hpp>

namespace boost_kahypar
{

namespace placeholders
{

#if !defined(BOOST_NO_CXX17_INLINE_VARIABLES)

BOOST_INLINE_CONSTEXPR boost_kahypar::arg<1> _1;
BOOST_INLINE_CONSTEXPR boost_kahypar::arg<2> _2;
BOOST_INLINE_CONSTEXPR boost_kahypar::arg<3> _3;
BOOST_INLINE_CONSTEXPR boost_kahypar::arg<4> _4;
BOOST_INLINE_CONSTEXPR boost_kahypar::arg<5> _5;
BOOST_INLINE_CONSTEXPR boost_kahypar::arg<6> _6;
BOOST_INLINE_CONSTEXPR boost_kahypar::arg<7> _7;
BOOST_INLINE_CONSTEXPR boost_kahypar::arg<8> _8;
BOOST_INLINE_CONSTEXPR boost_kahypar::arg<9> _9;

#else

BOOST_STATIC_CONSTEXPR boost_kahypar::arg<1> _1;
BOOST_STATIC_CONSTEXPR boost_kahypar::arg<2> _2;
BOOST_STATIC_CONSTEXPR boost_kahypar::arg<3> _3;
BOOST_STATIC_CONSTEXPR boost_kahypar::arg<4> _4;
BOOST_STATIC_CONSTEXPR boost_kahypar::arg<5> _5;
BOOST_STATIC_CONSTEXPR boost_kahypar::arg<6> _6;
BOOST_STATIC_CONSTEXPR boost_kahypar::arg<7> _7;
BOOST_STATIC_CONSTEXPR boost_kahypar::arg<8> _8;
BOOST_STATIC_CONSTEXPR boost_kahypar::arg<9> _9;

#endif

} // namespace placeholders

} // namespace boost_kahypar

#endif // #ifndef BOOST_BIND_PLACEHOLDERS_HPP_INCLUDED
