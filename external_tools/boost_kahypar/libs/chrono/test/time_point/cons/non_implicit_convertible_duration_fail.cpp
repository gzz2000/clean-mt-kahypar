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

// Duration2 shall be implicitly convertible to duration.

#include <boost_kahypar/chrono/chrono.hpp>

void test()
{
    typedef boost_kahypar::chrono::system_clock Clock;
    typedef boost_kahypar::chrono::milliseconds Duration1;
    typedef boost_kahypar::chrono::microseconds Duration2;
    {
    boost_kahypar::chrono::time_point<Clock, Duration2> t2(Duration2(3));
    boost_kahypar::chrono::time_point<Clock, Duration1> t1 = t2;
    }
}
