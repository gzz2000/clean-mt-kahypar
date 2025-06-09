// Copyright 2021 Peter Dimov
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#define _SCL_SECURE_NO_WARNINGS

#include <boost_kahypar/core/detail/string_view.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>
#include <stdexcept>
#include <cstddef>

int main()
{
    {
        boost_kahypar::core::string_view sv;

        BOOST_TEST_EQ( sv.copy( 0, 0 ), 0 );
        BOOST_TEST_EQ( sv.copy( 0, 0, 0 ), 0 );
        BOOST_TEST_THROWS( sv.copy( 0, 0, 1 ), std::out_of_range );
        BOOST_TEST_THROWS( sv.copy( 0, 0, boost_kahypar::core::string_view::npos ), std::out_of_range );
    }

    {
        boost_kahypar::core::string_view sv( "12345" );
        char buffer[ 8 ] = {};

        BOOST_TEST_EQ( sv.copy( buffer, 0 ), 0 );
        BOOST_TEST_EQ( buffer[0], 0 );

        BOOST_TEST_EQ( sv.copy( buffer, 0, 0 ), 0 );
        BOOST_TEST_EQ( buffer[0], 0 );

        BOOST_TEST_EQ( sv.copy( buffer, 0, 1 ), 0 );
        BOOST_TEST_EQ( buffer[0], 0 );

        BOOST_TEST_THROWS( sv.copy( buffer, 0, boost_kahypar::core::string_view::npos ), std::out_of_range );
        BOOST_TEST_EQ( buffer[0], 0 );

        BOOST_TEST_EQ( sv.copy( buffer, 1 ), 1 );
        BOOST_TEST_EQ( buffer[0], '1' );
        BOOST_TEST_EQ( buffer[1], 0 );

        BOOST_TEST_EQ( sv.copy( buffer, 1, 1 ), 1 );
        BOOST_TEST_EQ( buffer[0], '2' );
        BOOST_TEST_EQ( buffer[1], 0 );

        BOOST_TEST_EQ( sv.copy( buffer, 8 ), 5 );
        BOOST_TEST_CSTR_EQ( buffer, "12345" );
    }

    return boost_kahypar::report_errors();
}
