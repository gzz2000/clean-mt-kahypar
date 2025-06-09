// Test for boost/core/bit.hpp (bit_cast)
//
// Copyright 2020 Peter Dimov
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/core/bit.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>
#include <boost_kahypar/cstdint.hpp>
#include <cstring>

int main()
{
    {
        float x = 0.89f;
        boost_kahypar::uint32_t y = boost_kahypar::core::bit_cast<boost_kahypar::uint32_t>( x );

        BOOST_TEST( std::memcmp( &x, &y, sizeof(x) ) == 0 );
    }

    {
        double x = 0.89;
        boost_kahypar::uint64_t y = boost_kahypar::core::bit_cast<boost_kahypar::uint64_t>( x );

        BOOST_TEST( std::memcmp( &x, &y, sizeof(x) ) == 0 );
    }

    return boost_kahypar::report_errors();
}
