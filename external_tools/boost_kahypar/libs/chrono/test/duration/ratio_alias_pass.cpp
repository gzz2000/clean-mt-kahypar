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
// Period shall be a specialization of ratio, diagnostic required.

#include <boost_kahypar/chrono/duration.hpp>

void test()
{
    typedef boost_kahypar::chrono::duration<int,
        boost_kahypar::ratio_add<
            boost_kahypar::ratio<1,2>,
            boost_kahypar::ratio<1,3>
        >
    > D;
    D d;
    (void)d;
}
