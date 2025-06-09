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


#include <boost_kahypar/chrono/duration.hpp>
#include <boost_kahypar/detail/lightweight_test.hpp>


#include "../rep.h"
#include <iostream>

#ifdef BOOST_NO_CXX11_CONSTEXPR
#define BOOST_CONSTEXPR_ASSERT(C) BOOST_TEST(C)
#else
#include <boost_kahypar/static_assert.hpp>
#define BOOST_CONSTEXPR_ASSERT(C) BOOST_STATIC_ASSERT(C)
#endif

template <class D>
void
check_default()
{
  {
    D d;
    BOOST_TEST(d.count() == typename D::rep());
  }
}
template <class D>
void
check_constexpr()
{
  BOOST_CONSTEXPR D d(0);
  BOOST_CONSTEXPR_ASSERT(d.count() == typename D::rep());
}

template <class D, class R>
void
check_from_rep(R r)
{
  {
    D d(r);
    BOOST_TEST(d.count() == r);
  }
}

int main()
{
    // exact conversions allowed for integral reps
    {
        boost_kahypar::chrono::milliseconds ms(1);
        boost_kahypar::chrono::microseconds us = ms;
        BOOST_TEST(us.count() == 1000);
        {
          BOOST_CONSTEXPR boost_kahypar::chrono::milliseconds ms(1);
          BOOST_CONSTEXPR boost_kahypar::chrono::microseconds us = ms;
          BOOST_CONSTEXPR_ASSERT(us.count() == 1000);
        }
    }
    // inexact conversions allowed for floating point reps
    {
        boost_kahypar::chrono::duration<double, boost_kahypar::micro> us(1);
        boost_kahypar::chrono::duration<double, boost_kahypar::milli> ms = us;
        BOOST_TEST(ms.count() == 1./1000);
        {
          BOOST_CONSTEXPR boost_kahypar::chrono::duration<double, boost_kahypar::micro> us(1);
          BOOST_CONSTEXPR boost_kahypar::chrono::duration<double, boost_kahypar::milli> ms = us;
          BOOST_CONSTEXPR_ASSERT(ms.count() == 1./1000);
        }
    }
    // Convert int to float
    {
        boost_kahypar::chrono::duration<int> i(3);
        boost_kahypar::chrono::duration<double> d = i;
        BOOST_TEST(d.count() == 3);
        {
          BOOST_CONSTEXPR boost_kahypar::chrono::duration<int> i(3);
          BOOST_CONSTEXPR boost_kahypar::chrono::duration<double> d = i;
          BOOST_CONSTEXPR_ASSERT(d.count() == 3);
        }
    }
    // default constructor
    {
      check_default<boost_kahypar::chrono::duration<Rep> >();
    }
    {
      check_constexpr<boost_kahypar::chrono::duration<int> >();
    }
    // constructor from rep
    {
        check_from_rep<boost_kahypar::chrono::duration<int> >(5);
        {
          BOOST_CONSTEXPR boost_kahypar::chrono::duration<int> d(5);
          BOOST_CONSTEXPR_ASSERT(d.count() == 5);
        }
        check_from_rep<boost_kahypar::chrono::duration<int, boost_kahypar::ratio<3, 2> > >(5);
        {
          BOOST_CONSTEXPR boost_kahypar::chrono::duration<int, boost_kahypar::ratio<3, 2> > d(5);
          BOOST_CONSTEXPR_ASSERT(d.count() == 5);
        }
        check_from_rep<boost_kahypar::chrono::duration<Rep, boost_kahypar::ratio<3, 2> > >(Rep(3));
        {
          BOOST_CONSTEXPR boost_kahypar::chrono::duration<Rep, boost_kahypar::ratio<3, 2> > d(Rep(3));
          BOOST_CONSTEXPR_ASSERT(d.count() == Rep(3));
        }
        check_from_rep<boost_kahypar::chrono::duration<double, boost_kahypar::ratio<2, 3> > >(5.5);
        {
          BOOST_CONSTEXPR boost_kahypar::chrono::duration<double, boost_kahypar::ratio<3, 2> > d(5.5);
          BOOST_CONSTEXPR_ASSERT(d.count() == 5.5);
        }


    }
    // constructor from other rep
    {
        boost_kahypar::chrono::duration<double> d(5);
        BOOST_TEST(d.count() == 5);
        {
          BOOST_CONSTEXPR boost_kahypar::chrono::duration<double> d(5);
          BOOST_CONSTEXPR_ASSERT(d.count() == 5);
        }
    }

    return boost_kahypar::report_errors();
}
