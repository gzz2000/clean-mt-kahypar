// Test for boost/core/bit.hpp (bit_ceil)
//
// Copyright 2020 Peter Dimov
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/core/bit.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>
#include <boost_kahypar/core/detail/splitmix64.hpp>
#include <boost_kahypar/cstdint.hpp>
#include <limits>

template<class T> void test_bit_ceil( T x )
{
    if( !boost_kahypar::core::has_single_bit( x ) )
    {
        x = static_cast<T>( x >> 1 );
    }

    T y = boost_kahypar::core::bit_ceil( x );

    if( x == 0 )
    {
        BOOST_TEST_EQ( y, 0 );
    }
    else
    {
        BOOST_TEST( boost_kahypar::core::has_single_bit( y ) );
        BOOST_TEST_GE( +y, +x );
        BOOST_TEST_LT( y >> 1, +x );
    }
}

int main()
{
    {
        test_bit_ceil( static_cast<unsigned char>( 0 ) );
        test_bit_ceil( static_cast<unsigned short>( 0 ) );
        test_bit_ceil( static_cast<unsigned int>( 0 ) );
        test_bit_ceil( static_cast<unsigned long>( 0 ) );
        test_bit_ceil( static_cast<boost_kahypar::ulong_long_type>( 0 ) );
    }

    {
        test_bit_ceil( static_cast<boost_kahypar::uint8_t>( 0x80 ) );
        test_bit_ceil( static_cast<boost_kahypar::uint16_t>( 0x8000 ) );
        test_bit_ceil( static_cast<boost_kahypar::uint32_t>( 0x80000000 ) );
        test_bit_ceil( boost_kahypar::uint64_t( 1 ) << 63 );
    }

    boost_kahypar::detail::splitmix64 rng;

    for( int i = 0; i < 1000; ++i )
    {
        boost_kahypar::uint64_t x = rng();

        test_bit_ceil( static_cast<unsigned char>( x ) );
        test_bit_ceil( static_cast<unsigned short>( x ) );
        test_bit_ceil( static_cast<unsigned int>( x ) );
        test_bit_ceil( static_cast<unsigned long>( x ) );
        test_bit_ceil( static_cast<boost_kahypar::ulong_long_type>( x ) );
    }

    return boost_kahypar::report_errors();
}
