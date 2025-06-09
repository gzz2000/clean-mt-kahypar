// Test for boost/core/detail/minstd_rand.hpp
//
// Copyright 2022, 2024 Peter Dimov
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/core/detail/minstd_rand.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>
#include <boost_kahypar/cstdint.hpp>

int main()
{
    {
        boost_kahypar::detail::minstd_rand rng;

        boost_kahypar::uint_least32_t r1 = rng(), x1 = 48271;
        BOOST_TEST_EQ( r1, x1 );

        for( int i = 0; i < 1000; ++i ) rng();

        boost_kahypar::uint_least32_t r2 = rng(), x2 = 2076422031;
        BOOST_TEST_EQ( r2, x2 );
    }

    {
        boost_kahypar::detail::minstd_rand rng( 12345 );

        boost_kahypar::uint_least32_t r1 = rng(), x1 = 595905495;
        BOOST_TEST_EQ( r1, x1 );

        for( int i = 0; i < 1000; ++i ) rng();

        boost_kahypar::uint_least32_t r2 = rng(), x2 = 1065162103;
        BOOST_TEST_EQ( r2, x2 );
    }

    return boost_kahypar::report_errors();
}
