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

#define BOOST_CHRONO_EXTENSIONS
#include <boost_kahypar/chrono/chrono.hpp>
#include <boost_kahypar/detail/lightweight_test.hpp>
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
    typedef boost_kahypar::chrono::milliseconds Duration;
    boost_kahypar::chrono::time_point<Clock, Duration> t(Duration(3));
    t += 2;
    BOOST_TEST(t.time_since_epoch() == Duration(5));
  }
  {
    typedef boost_kahypar::chrono::system_clock Clock;
    typedef boost_kahypar::chrono::milliseconds Duration;
    boost_kahypar::chrono::time_point<Clock, Duration> t(Duration(3));
    t++;
    BOOST_TEST(t.time_since_epoch() == Duration(4));
  }
  {
    typedef boost_kahypar::chrono::system_clock Clock;
    typedef boost_kahypar::chrono::milliseconds Duration;
    boost_kahypar::chrono::time_point<Clock, Duration> t(Duration(3));
    ++t;
    BOOST_TEST(t.time_since_epoch() == Duration(4));
  }
  {
    typedef boost_kahypar::chrono::system_clock Clock;
    typedef boost_kahypar::chrono::milliseconds Duration;
    boost_kahypar::chrono::time_point<Clock, Duration> t(Duration(3));
    t -= 2;
    BOOST_TEST(t.time_since_epoch() == Duration(1));
  }
  {
    typedef boost_kahypar::chrono::system_clock Clock;
    typedef boost_kahypar::chrono::milliseconds Duration;
    boost_kahypar::chrono::time_point<Clock, Duration> t(Duration(3));
    t--;
    BOOST_TEST(t.time_since_epoch() == Duration(2));
  }
  {
    typedef boost_kahypar::chrono::system_clock Clock;
    typedef boost_kahypar::chrono::milliseconds Duration;
    boost_kahypar::chrono::time_point<Clock, Duration> t(Duration(3));
    --t;
    BOOST_TEST(t.time_since_epoch() == Duration(2));
  }

  return boost_kahypar::report_errors();
}
