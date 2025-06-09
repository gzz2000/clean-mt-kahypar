// Copyright 2020, 2021 Peter Dimov.
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/system/error_code.hpp>
#include <boost_kahypar/system/generic_category.hpp>
#include <boost_kahypar/system/system_category.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>

namespace sys = boost_kahypar::system;

int main()
{
    {
        sys::error_code ec;

        BOOST_TEST_EQ( ec.value(), 0 );
        BOOST_TEST( ec.category() == sys::system_category() );

        BOOST_TEST_EQ( ec.what(), ec.message() + " [system:0]" );
    }

    {
        sys::error_code ec( 5, sys::generic_category() );

        BOOST_TEST_EQ( ec.value(), 5 );
        BOOST_TEST( ec.category() == sys::generic_category() );

        BOOST_TEST_EQ( ec.what(), ec.message() + " [generic:5]" );
    }

    {
        sys::error_code ec( 5, sys::system_category() );

        BOOST_TEST_EQ( ec.value(), 5 );
        BOOST_TEST( ec.category() == sys::system_category() );

        BOOST_TEST_EQ( ec.what(), ec.message() + " [system:5]" );
    }

    {
        BOOST_STATIC_CONSTEXPR boost_kahypar::source_location loc = BOOST_CURRENT_LOCATION;

        sys::error_code ec( 5, sys::generic_category(), &loc );

        BOOST_TEST_EQ( ec.value(), 5 );
        BOOST_TEST( ec.category() == sys::generic_category() );
        BOOST_TEST_EQ( &ec.location(), &loc );

        BOOST_TEST_EQ( ec.what(), ec.message() + " [generic:5 at " + loc.to_string() + "]" );
    }

    {
        BOOST_STATIC_CONSTEXPR boost_kahypar::source_location loc = BOOST_CURRENT_LOCATION;

        sys::error_code ec( 5, sys::system_category(), &loc );

        BOOST_TEST_EQ( ec.value(), 5 );
        BOOST_TEST( ec.category() == sys::system_category() );
        BOOST_TEST_EQ( &ec.location(), &loc );

        BOOST_TEST_EQ( ec.what(), ec.message() + " [system:5 at " + loc.to_string() + "]" );
    }

    {
        std::error_code ec;
        sys::error_code ec2( ec );

        BOOST_TEST_EQ( ec2.what(), ec2.message() + " [std:system:0]" );
    }

    {
        std::error_code ec( 5, std::generic_category() );
        sys::error_code ec2( ec );

        BOOST_TEST_EQ( ec2.what(), ec2.message() + " [std:generic:5]" );
    }

    {
        std::error_code ec( 5, std::system_category() );
        sys::error_code ec2( ec );

        BOOST_TEST_EQ( ec2.what(), ec2.message() + " [std:system:5]" );
    }

    return boost_kahypar::report_errors();
}
