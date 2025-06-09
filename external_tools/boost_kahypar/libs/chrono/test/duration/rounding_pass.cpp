// Copyright 2013 Krzysztof Czainski
// Copyright 2013 Vicente J. Botet Escriba
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

/*
 * @file chrono_rounding.cpp
 *
 * @since 2013-11-22
 * @author  Krzysztof Czainski <1czajnik@gmail.com>
 */

#include <boost_kahypar/cstdint.hpp>
#include <boost_kahypar/chrono/ceil.hpp>
#include <boost_kahypar/chrono/floor.hpp>
#include <boost_kahypar/chrono/round.hpp>

#include <boost_kahypar/chrono/chrono_io.hpp>
#include <boost_kahypar/detail/lightweight_test.hpp>

using namespace boost_kahypar::chrono;

void test_floor()
{
    BOOST_TEST_EQ( seconds(-2), floor<seconds>( milliseconds(-2000) ) );
    BOOST_TEST_EQ( seconds(-2), floor<seconds>( milliseconds(-1999) ) );
    BOOST_TEST_EQ( seconds(-2), floor<seconds>( milliseconds(-1001) ) );
    BOOST_TEST_EQ( seconds(-1), floor<seconds>( milliseconds(-1000) ) );
    BOOST_TEST_EQ( seconds(-1), floor<seconds>( milliseconds(-999) ) );
    BOOST_TEST_EQ( seconds(-1), floor<seconds>( milliseconds(-1) ) );
    BOOST_TEST_EQ( seconds(0), floor<seconds>( milliseconds(0) ) );
    BOOST_TEST_EQ( seconds(0), floor<seconds>( milliseconds(1) ) );
    BOOST_TEST_EQ( seconds(0), floor<seconds>( milliseconds(999) ) );
    BOOST_TEST_EQ( seconds(1), floor<seconds>( milliseconds(1000) ) );
    BOOST_TEST_EQ( seconds(1), floor<seconds>( milliseconds(1001) ) );
    BOOST_TEST_EQ( seconds(1), floor<seconds>( milliseconds(1999) ) );
    BOOST_TEST_EQ( seconds(2), floor<seconds>( milliseconds(2000) ) );

    {
      // check that int32 isn't overflowed in intermediate calculations:
        typedef duration<boost_kahypar::int32_t> sec32;
        typedef duration< boost_kahypar::int32_t, boost_kahypar::ratio<999,1000> > sec32_m1ms;
        BOOST_TEST_EQ( sec32(-999000000), floor<sec32>( sec32_m1ms(-1000000000) ) );
        BOOST_TEST_EQ( sec32( 999000000), floor<sec32>( sec32_m1ms( 1000000000) ) );
    }
}

void test_ceil()
{
    BOOST_TEST_EQ( seconds(-2), ceil<seconds>( milliseconds(-2000) ) );
    BOOST_TEST_EQ( seconds(-1), ceil<seconds>( milliseconds(-1999) ) );
    BOOST_TEST_EQ( seconds(-1), ceil<seconds>( milliseconds(-1001) ) );
    BOOST_TEST_EQ( seconds(-1), ceil<seconds>( milliseconds(-1000) ) );
    BOOST_TEST_EQ( seconds(0), ceil<seconds>( milliseconds(-999) ) );
    BOOST_TEST_EQ( seconds(0), ceil<seconds>( milliseconds(-1) ) );
    BOOST_TEST_EQ( seconds(0), ceil<seconds>( milliseconds(0) ) );
    BOOST_TEST_EQ( seconds(1), ceil<seconds>( milliseconds(1) ) );
    BOOST_TEST_EQ( seconds(1), ceil<seconds>( milliseconds(999) ) );
    BOOST_TEST_EQ( seconds(1), ceil<seconds>( milliseconds(1000) ) );
    BOOST_TEST_EQ( seconds(2), ceil<seconds>( milliseconds(1001) ) );
    BOOST_TEST_EQ( seconds(2), ceil<seconds>( milliseconds(1999) ) );
    BOOST_TEST_EQ( seconds(2), ceil<seconds>( milliseconds(2000) ) );
    {
      // check that int32 isn't overflowed in intermediate calculations:
        typedef duration<boost_kahypar::int32_t> sec32;
        typedef duration< boost_kahypar::int32_t, boost_kahypar::ratio<999,1000> > sec32_m1ms;
        BOOST_TEST_EQ( sec32(-999000000), ceil<sec32>( sec32_m1ms(-1000000000) ) );
        BOOST_TEST_EQ( sec32( 999000000), ceil<sec32>( sec32_m1ms( 1000000000) ) );
    }
}

void test_round()
{
    // to even on tie
    BOOST_TEST_EQ( seconds(-2), round<seconds>( milliseconds(-2000) ) );
    BOOST_TEST_EQ( seconds(-2), round<seconds>( milliseconds(-1500) ) );
    BOOST_TEST_EQ( seconds(-1), round<seconds>( milliseconds(-1499) ) );
    BOOST_TEST_EQ( seconds(-1), round<seconds>( milliseconds(-1000) ) );
    BOOST_TEST_EQ( seconds(0), round<seconds>( milliseconds(-500) ) );
    BOOST_TEST_EQ( seconds(0), round<seconds>( milliseconds(-499) ) );
    BOOST_TEST_EQ( seconds(0), round<seconds>( milliseconds(0) ) );
    BOOST_TEST_EQ( seconds(0), round<seconds>( milliseconds(499) ) );
    BOOST_TEST_EQ( seconds(0), round<seconds>( milliseconds(500) ) );
    BOOST_TEST_EQ( seconds(1), round<seconds>( milliseconds(1000) ) );
    BOOST_TEST_EQ( seconds(1), round<seconds>( milliseconds(1499) ) );
    BOOST_TEST_EQ( seconds(2), round<seconds>( milliseconds(1500) ) );
    BOOST_TEST_EQ( seconds(2), round<seconds>( milliseconds(2000) ) );
    {
      // check that int32 isn't overflowed in intermediate calculations:
        typedef duration<boost_kahypar::int32_t> sec32;
        typedef duration< boost_kahypar::int32_t, boost_kahypar::ratio<999,1000> > sec32_m1ms;
        BOOST_TEST_EQ( sec32(-999000000), round<sec32>( sec32_m1ms(-1000000000) ) );
        BOOST_TEST_EQ( sec32( 999000000), round<sec32>( sec32_m1ms( 1000000000) ) );
    }
}

int main()
{
  test_floor();
  test_ceil();
  test_round();
  return boost_kahypar::report_errors();

}
