// Copyright 2021 Peter Dimov.
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/system/error_code.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>
#include <cerrno>
#include <system_error>

int main()
{
    {
        std::error_code e1;
        boost_kahypar::system::error_code e2 = e1;

        BOOST_TEST( !e2.failed() );
        BOOST_TEST_EQ( e1.message(), e2.message() );

        std::error_code e3 = e2;
        BOOST_TEST_EQ( e1, e3 );
    }

    {
        std::error_code e1( 5, std::system_category() );
        boost_kahypar::system::error_code e2 = e1;

        BOOST_TEST( e2.failed() );
        BOOST_TEST_EQ( e1.message(), e2.message() );

        std::error_code e3 = e2;
        BOOST_TEST_EQ( e1, e3 );
    }

    {
        std::error_code e1( 0, std::generic_category() );
        boost_kahypar::system::error_code e2 = e1;

        BOOST_TEST( !e2.failed() );
        BOOST_TEST_EQ( e1.message(), e2.message() );

        std::error_code e3 = e2;
        BOOST_TEST_EQ( e1, e3 );
    }

    {
        std::error_code e1( ENOENT, std::generic_category() );
        boost_kahypar::system::error_code e2 = e1;

        BOOST_TEST( e2.failed() );
        BOOST_TEST_EQ( e1.message(), e2.message() );

        std::error_code e3 = e2;
        BOOST_TEST_EQ( e1, e3 );
    }

    {
        std::error_code e1 = make_error_code( std::errc::no_such_file_or_directory );
        boost_kahypar::system::error_code e2 = e1;

        BOOST_TEST( e2.failed() );
        BOOST_TEST_EQ( e1.message(), e2.message() );

        std::error_code e3 = e2;
        BOOST_TEST_EQ( e1, e3 );
    }

    return boost_kahypar::report_errors();
}
