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
        boost_kahypar::system::error_code e1;
        boost_kahypar::system::error_code e2( 0, boost_kahypar::system::system_category() );

        BOOST_TEST_EQ( e1, e2 );

        std::error_code e3( e1 );
        std::error_code e4( e2 );

        BOOST_TEST_EQ( e3, e4 );
    }

    {
        boost_kahypar::system::error_code e1;

        std::error_code e2( e1 );
        std::error_code e3( e1.value(), e1.category() );

        BOOST_TEST_EQ( e2, e3 );
    }

    {
        boost_kahypar::system::error_condition e1;
        boost_kahypar::system::error_condition e2( 0, boost_kahypar::system::generic_category() );

        BOOST_TEST_EQ( e1, e2 );

        std::error_condition e3( e1 );
        std::error_condition e4( e2 );

        BOOST_TEST( e3 == e4 );
    }

    {
        boost_kahypar::system::error_condition e1;

        std::error_condition e2( e1 );
        std::error_condition e3( e1.value(), e1.category() );

        BOOST_TEST( e2 == e3 );
    }

    return boost_kahypar::report_errors();
}
