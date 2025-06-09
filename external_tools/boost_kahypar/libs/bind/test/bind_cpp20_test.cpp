// Copyright 2020 Peter Dimov
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt)

#include <boost_kahypar/bind/bind.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>
#include <boost_kahypar/config.hpp>
#include <boost_kahypar/config/workaround.hpp>
#include <functional>

//

int main()
{
    BOOST_TEST_EQ( boost_kahypar::bind( std::plus<int>(), 1, 2 )(), 3 );
    BOOST_TEST_EQ( boost_kahypar::bind( std::minus<int>(), 1, 2 )(), -1 );
    BOOST_TEST_EQ( boost_kahypar::bind( std::multiplies<int>(), 1, 2 )(), 2 );
    BOOST_TEST_EQ( boost_kahypar::bind( std::divides<int>(), 1, 2 )(), 0 );
    BOOST_TEST_EQ( boost_kahypar::bind( std::modulus<int>(), 1, 2 )(), 1 );
    BOOST_TEST_EQ( boost_kahypar::bind( std::negate<int>(), 1 )(), -1 );

    BOOST_TEST_EQ( boost_kahypar::bind( std::equal_to<int>(), 1, 2 )(), false );
    BOOST_TEST_EQ( boost_kahypar::bind( std::not_equal_to<int>(), 1, 2 )(), true );
    BOOST_TEST_EQ( boost_kahypar::bind( std::greater<int>(), 1, 2 )(), false );
    BOOST_TEST_EQ( boost_kahypar::bind( std::less<int>(), 1, 2 )(), true );
    BOOST_TEST_EQ( boost_kahypar::bind( std::greater_equal<int>(), 1, 2 )(), false );
    BOOST_TEST_EQ( boost_kahypar::bind( std::less_equal<int>(), 1, 2 )(), true );

    BOOST_TEST_EQ( boost_kahypar::bind( std::logical_and<int>(), 1, 2 )(), true );
    BOOST_TEST_EQ( boost_kahypar::bind( std::logical_or<int>(), 1, 2 )(), true );
    BOOST_TEST_EQ( boost_kahypar::bind( std::logical_not<int>(), 1 )(), false );

#if !BOOST_WORKAROUND(BOOST_MSVC, < 1600)

    BOOST_TEST_EQ( boost_kahypar::bind( std::bit_and<int>(), 1, 2 )(), 0 );
    BOOST_TEST_EQ( boost_kahypar::bind( std::bit_or<int>(), 1, 2 )(), 3 );
    BOOST_TEST_EQ( boost_kahypar::bind( std::bit_xor<int>(), 1, 2 )(), 3 );

#endif

    return boost_kahypar::report_errors();
}
