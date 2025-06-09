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

#include <boost_kahypar/chrono/chrono.hpp>
#include <boost_kahypar/type_traits.hpp>

#if !defined(BOOST_NO_CXX11_STATIC_ASSERT) 
#define NOTHING ""
#endif

template <class D1, class D2, class De>
void
test()
{
    typedef boost_kahypar::chrono::system_clock C;
    typedef boost_kahypar::chrono::time_point<C, D1> T1;
    typedef boost_kahypar::chrono::time_point<C, D2> T2;
    typedef boost_kahypar::chrono::time_point<C, De> Te;
    typedef typename boost_kahypar::common_type<T1, T2>::type Tc;
    BOOST_CHRONO_STATIC_ASSERT((boost_kahypar::is_same<Tc, Te>::value), NOTHING, (T1, T2, Tc, Te));
}

void testall()
{
    test<boost_kahypar::chrono::duration<int, boost_kahypar::ratio<1, 100> >,
         boost_kahypar::chrono::duration<long, boost_kahypar::ratio<1, 1000> >,
         boost_kahypar::chrono::duration<long, boost_kahypar::ratio<1, 1000> > >();
    test<boost_kahypar::chrono::duration<long, boost_kahypar::ratio<1, 100> >,
         boost_kahypar::chrono::duration<int, boost_kahypar::ratio<1, 1000> >,
         boost_kahypar::chrono::duration<long, boost_kahypar::ratio<1, 1000> > >();
    test<boost_kahypar::chrono::duration<char, boost_kahypar::ratio<1, 30> >,
         boost_kahypar::chrono::duration<short, boost_kahypar::ratio<1, 1000> >,
         boost_kahypar::chrono::duration<int, boost_kahypar::ratio<1, 3000> > >();
    test<boost_kahypar::chrono::duration<double, boost_kahypar::ratio<21, 1> >,
         boost_kahypar::chrono::duration<short, boost_kahypar::ratio<15, 1> >,
         boost_kahypar::chrono::duration<double, boost_kahypar::ratio<3, 1> > >();
}
