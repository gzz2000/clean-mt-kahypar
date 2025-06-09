// Copyright 2021 Peter Dimov.
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt

#if defined(__GNUC__) && __GNUC__ >= 7
# pragma GCC diagnostic ignored "-Wformat-truncation"
#endif

#if defined(__clang__) && defined(__has_warning)
# if __has_warning( "-Wformat-truncation" )
#  pragma clang diagnostic ignored "-Wformat-truncation"
# endif
#endif

#include <boost_kahypar/system/detail/snprintf.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>

int main()
{
    {
        char buffer[ 64 ];
        boost_kahypar::system::detail::snprintf( buffer, sizeof(buffer), "...%s...%d...", "xy", 151 );

        BOOST_TEST_CSTR_EQ( buffer, "...xy...151..." );
    }

    {
        char buffer[ 64 ];
        boost_kahypar::system::detail::snprintf( buffer, sizeof(buffer), "...%s...%d...", "xy", 151 );

        BOOST_TEST_CSTR_EQ( buffer, "...xy...151..." );
    }

    {
        char buffer[ 15 ];
        boost_kahypar::system::detail::snprintf( buffer, sizeof(buffer), "...%s...%d...", "xy", 151 );

        BOOST_TEST_CSTR_EQ( buffer, "...xy...151..." );
    }

    {
        char buffer[ 14 ];
        boost_kahypar::system::detail::snprintf( buffer, sizeof(buffer), "...%s...%d...", "xy", 151 );

        BOOST_TEST_CSTR_EQ( buffer, "...xy...151.." );
    }

    {
        char buffer[ 5 ];
        boost_kahypar::system::detail::snprintf( buffer, sizeof(buffer), "...%s...%d...", "xy", 151 );

        BOOST_TEST_CSTR_EQ( buffer, "...x" );
    }

    {
        char buffer[ 1 ];
        boost_kahypar::system::detail::snprintf( buffer, sizeof(buffer), "...%s...%d...", "xy", 151 );

        BOOST_TEST_CSTR_EQ( buffer, "" );
    }

    {
        char buffer[ 1 ] = { 'Q' };
        boost_kahypar::system::detail::snprintf( buffer, 0, "...%s...%d...", "xy", 151 );

        BOOST_TEST_EQ( buffer[0], 'Q' );
    }

    return boost_kahypar::report_errors();
}
