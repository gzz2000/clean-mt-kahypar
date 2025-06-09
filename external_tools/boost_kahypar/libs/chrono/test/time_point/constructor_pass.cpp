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
#include <boost_kahypar/detail/lightweight_test.hpp>
#include "../rep.h"
#ifdef BOOST_NO_CXX11_CONSTEXPR
#define BOOST_CONSTEXPR_ASSERT(C) BOOST_TEST(C)
#else
#include <boost_kahypar/static_assert.hpp>
#define BOOST_CONSTEXPR_ASSERT(C) BOOST_STATIC_ASSERT(C)
#endif

int main()
{
  {
    typedef boost_kahypar::chrono::system_clock Clock;
    typedef boost_kahypar::chrono::microseconds Duration1;
    typedef boost_kahypar::chrono::milliseconds Duration2;
    boost_kahypar::chrono::time_point<Clock, Duration2> t2(Duration2(3));
    boost_kahypar::chrono::time_point<Clock, Duration1> t1 = t2;
    BOOST_TEST(t1.time_since_epoch() == Duration1(3000));
  }
  {
    typedef boost_kahypar::chrono::system_clock Clock;
    typedef boost_kahypar::chrono::microseconds Duration1;
    typedef boost_kahypar::chrono::milliseconds Duration2;
    BOOST_CONSTEXPR boost_kahypar::chrono::time_point<Clock, Duration2> t2(Duration2(3));
    BOOST_CONSTEXPR boost_kahypar::chrono::time_point<Clock, Duration1> t1 = t2;
    BOOST_CONSTEXPR_ASSERT(t1.time_since_epoch() == Duration1(3000));
  }
  {
    typedef boost_kahypar::chrono::system_clock Clock;
    typedef boost_kahypar::chrono::duration<Rep, boost_kahypar::milli> Duration;
    boost_kahypar::chrono::time_point<Clock, Duration> t;
    BOOST_TEST(t.time_since_epoch() == Duration::zero());
  }
  {
    typedef boost_kahypar::chrono::system_clock Clock;
    typedef boost_kahypar::chrono::duration<Rep, boost_kahypar::milli> Duration;
    BOOST_CONSTEXPR boost_kahypar::chrono::time_point<Clock, Duration> t;
    BOOST_CONSTEXPR_ASSERT(t.time_since_epoch() == Duration::zero());
  }
  {
    typedef boost_kahypar::chrono::system_clock Clock;
    typedef boost_kahypar::chrono::milliseconds Duration;
    boost_kahypar::chrono::time_point<Clock, Duration> t(Duration(3));
    BOOST_TEST(t.time_since_epoch() == Duration(3));
  }
  {
    typedef boost_kahypar::chrono::system_clock Clock;
    typedef boost_kahypar::chrono::milliseconds Duration;
    BOOST_CONSTEXPR boost_kahypar::chrono::time_point<Clock, Duration> t(Duration(3));
    BOOST_CONSTEXPR_ASSERT(t.time_since_epoch() == Duration(3));
  }
  {
    typedef boost_kahypar::chrono::system_clock Clock;
    typedef boost_kahypar::chrono::milliseconds Duration;
    boost_kahypar::chrono::time_point<Clock, Duration> t(boost_kahypar::chrono::seconds(3));
    BOOST_TEST(t.time_since_epoch() == Duration(3000));
  }
  {
    typedef boost_kahypar::chrono::system_clock Clock;
    typedef boost_kahypar::chrono::milliseconds Duration;
    BOOST_CONSTEXPR boost_kahypar::chrono::time_point<Clock, Duration> t(boost_kahypar::chrono::seconds(3));
    BOOST_CONSTEXPR_ASSERT(t.time_since_epoch() == Duration(3000));
  }

  return boost_kahypar::report_errors();
}
