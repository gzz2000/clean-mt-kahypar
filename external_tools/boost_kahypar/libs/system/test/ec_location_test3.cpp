// Copyright 2021, 2022 Peter Dimov.
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/system.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>
#include <cerrno>

int main()
{
    int const val = ENOENT;
    boost_kahypar::system::error_category const & cat = boost_kahypar::system::generic_category();

    {
        boost_kahypar::system::error_code ec;

        BOOST_TEST( !ec.has_location() );
        BOOST_TEST_EQ( ec.location(), boost_kahypar::source_location() );

        BOOST_STATIC_CONSTEXPR boost_kahypar::source_location loc = BOOST_CURRENT_LOCATION;

        boost_kahypar::system::error_code ec2( ec, &loc );

        BOOST_TEST_EQ( ec2, ec );

        BOOST_TEST( !ec2.has_location() );
        BOOST_TEST_EQ( ec2.location(), boost_kahypar::source_location() );

        boost_kahypar::system::error_code ec3( ec2, 0 );

        BOOST_TEST_EQ( ec3, ec2 );

        BOOST_TEST( !ec3.has_location() );
        BOOST_TEST_EQ( ec3.location(), boost_kahypar::source_location() );
    }

    {
        boost_kahypar::system::error_code ec( val, cat );

        BOOST_TEST( !ec.has_location() );
        BOOST_TEST_EQ( ec.location(), boost_kahypar::source_location() );

        BOOST_STATIC_CONSTEXPR boost_kahypar::source_location loc = BOOST_CURRENT_LOCATION;

        boost_kahypar::system::error_code ec2( ec, &loc );

        BOOST_TEST_EQ( ec2, ec );

        BOOST_TEST( ec2.has_location() );
        BOOST_TEST_EQ( ec2.location(), loc );

        boost_kahypar::system::error_code ec3( ec2, 0 );

        BOOST_TEST_EQ( ec3, ec2 );

        BOOST_TEST( !ec3.has_location() );
        BOOST_TEST_EQ( ec3.location(), boost_kahypar::source_location() );
    }

    {
        std::error_code e2( val, std::generic_category() );

        boost_kahypar::system::error_code ec( e2 );

        BOOST_TEST( !ec.has_location() );
        BOOST_TEST_EQ( ec.location(), boost_kahypar::source_location() );

        BOOST_STATIC_CONSTEXPR boost_kahypar::source_location loc = BOOST_CURRENT_LOCATION;

        boost_kahypar::system::error_code ec2( ec, &loc );

        BOOST_TEST_EQ( ec2, ec );

        BOOST_TEST( !ec2.has_location() );
        BOOST_TEST_EQ( ec2.location(), boost_kahypar::source_location() );

        boost_kahypar::system::error_code ec3( ec2, 0 );

        BOOST_TEST_EQ( ec3, ec2 );

        BOOST_TEST( !ec3.has_location() );
        BOOST_TEST_EQ( ec3.location(), boost_kahypar::source_location() );
    }

    return boost_kahypar::report_errors();
}
