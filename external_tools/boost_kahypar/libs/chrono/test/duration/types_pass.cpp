//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//  Adaptation to Boost of the libcxx
//  Copyright 2010 Vicente J. Botet Escriba
//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

// duration
// Test nested types

// typedef Rep rep;
// typedef Period period;

#include <boost_kahypar/chrono/duration.hpp>
#include <boost_kahypar/type_traits.hpp>
#if !defined(BOOST_NO_CXX11_STATIC_ASSERT)
#define NOTHING ""
#endif

typedef boost_kahypar::chrono::duration<long, boost_kahypar::ratio<3, 2> > D;
BOOST_CHRONO_STATIC_ASSERT((boost_kahypar::is_same<D::rep, long>::value), NOTHING, ());
BOOST_CHRONO_STATIC_ASSERT((boost_kahypar::is_same<D::period, boost_kahypar::ratio<3, 2> >::value), NOTHING, ());
