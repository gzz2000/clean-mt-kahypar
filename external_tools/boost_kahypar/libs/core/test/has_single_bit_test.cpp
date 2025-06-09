// Test for boost/core/bit.hpp (has_single_bit)
//
// Copyright 2020 Peter Dimov
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/core/bit.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>
#include <boost_kahypar/core/detail/splitmix64.hpp>
#include <boost_kahypar/cstdint.hpp>
#include <limits>

template<class T> void test_single_bit( T x )
{
    BOOST_TEST_EQ( boost_kahypar::core::has_single_bit( x ), boost_kahypar::core::popcount( x ) == 1 );
}

int main()
{
    {
        boost_kahypar::uint8_t x = 0;

        BOOST_TEST_EQ( boost_kahypar::core::has_single_bit( x ), false );

        x = 1;

        BOOST_TEST_EQ( boost_kahypar::core::has_single_bit( x ), true );

        x = 2;

        for( int i = 1; i < 8; ++i, x = static_cast<boost_kahypar::uint8_t>( x << 1 ) )
        {
            BOOST_TEST_EQ( boost_kahypar::core::has_single_bit( x ), true );
            BOOST_TEST_EQ( boost_kahypar::core::has_single_bit( static_cast<boost_kahypar::uint8_t>( x | ( x >> 1 ) ) ), false );
            BOOST_TEST_EQ( boost_kahypar::core::has_single_bit( static_cast<boost_kahypar::uint8_t>( x | ( x >> 1 ) | ( x >> 2 ) ) ), false );
        }
    }

    {
        boost_kahypar::uint16_t x = 0;

        BOOST_TEST_EQ( boost_kahypar::core::has_single_bit( x ), false );

        x = 1;

        BOOST_TEST_EQ( boost_kahypar::core::has_single_bit( x ), true );

        x = 2;

        for( int i = 1; i < 16; ++i, x = static_cast<boost_kahypar::uint16_t>( x << 1 ) )
        {
            BOOST_TEST_EQ( boost_kahypar::core::has_single_bit( x ), true );
            BOOST_TEST_EQ( boost_kahypar::core::has_single_bit( static_cast<boost_kahypar::uint16_t>( x | ( x >> 1 ) ) ), false );
            BOOST_TEST_EQ( boost_kahypar::core::has_single_bit( static_cast<boost_kahypar::uint16_t>( x | ( x >> 1 ) | ( x >> 2 ) ) ), false );
        }
    }

    {
        boost_kahypar::uint32_t x = 0;

        BOOST_TEST_EQ( boost_kahypar::core::has_single_bit( x ), false );

        x = 1;

        BOOST_TEST_EQ( boost_kahypar::core::has_single_bit( x ), true );

        x = 2;

        for( int i = 1; i < 32; ++i, x <<= 1 )
        {
            BOOST_TEST_EQ( boost_kahypar::core::has_single_bit( x ), true );
            BOOST_TEST_EQ( boost_kahypar::core::has_single_bit( static_cast<boost_kahypar::uint32_t>( x | ( x >> 1 ) ) ), false );
            BOOST_TEST_EQ( boost_kahypar::core::has_single_bit( static_cast<boost_kahypar::uint32_t>( x | ( x >> 1 ) | ( x >> 2 ) ) ), false );
        }
    }

    {
        boost_kahypar::uint64_t x = 0;

        BOOST_TEST_EQ( boost_kahypar::core::has_single_bit( x ), false );

        x = 1;

        BOOST_TEST_EQ( boost_kahypar::core::has_single_bit( x ), true );

        x = 2;

        for( int i = 1; i < 64; ++i, x <<= 1 )
        {
            BOOST_TEST_EQ( boost_kahypar::core::has_single_bit( x ), true );
            BOOST_TEST_EQ( boost_kahypar::core::has_single_bit( static_cast<boost_kahypar::uint64_t>( x | ( x >> 1 ) ) ), false );
            BOOST_TEST_EQ( boost_kahypar::core::has_single_bit( static_cast<boost_kahypar::uint64_t>( x | ( x >> 1 ) | ( x >> 2 ) ) ), false );
        }
    }

    boost_kahypar::detail::splitmix64 rng;

    for( int i = 0; i < 1000; ++i )
    {
        boost_kahypar::uint64_t x = rng();

        test_single_bit( static_cast<unsigned char>( x ) );
        test_single_bit( static_cast<unsigned short>( x ) );
        test_single_bit( static_cast<unsigned int>( x ) );
        test_single_bit( static_cast<unsigned long>( x ) );
        test_single_bit( static_cast<boost_kahypar::ulong_long_type>( x ) );
    }

    return boost_kahypar::report_errors();
}
