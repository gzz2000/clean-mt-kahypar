// Copyright 2021 Peter Dimov
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/core/detail/string_view.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>
#include <stdexcept>
#include <cstddef>

int main()
{
    {
        boost_kahypar::core::string_view sv( "" );

        BOOST_TEST( sv.starts_with( boost_kahypar::core::string_view() ) );
        BOOST_TEST( sv.starts_with( boost_kahypar::core::string_view( "" ) ) );
        BOOST_TEST( sv.starts_with( "" ) );

        BOOST_TEST( !sv.starts_with( boost_kahypar::core::string_view( "1" ) ) );
        BOOST_TEST( !sv.starts_with( '1' ) );
        BOOST_TEST( !sv.starts_with( "1" ) );
    }

    {
        boost_kahypar::core::string_view sv( "123" );

        BOOST_TEST( sv.starts_with( boost_kahypar::core::string_view() ) );
        BOOST_TEST( sv.starts_with( boost_kahypar::core::string_view( "" ) ) );
        BOOST_TEST( sv.starts_with( "" ) );

        BOOST_TEST( sv.starts_with( boost_kahypar::core::string_view( "1" ) ) );
        BOOST_TEST( sv.starts_with( '1' ) );
        BOOST_TEST( sv.starts_with( "1" ) );

        BOOST_TEST( sv.starts_with( boost_kahypar::core::string_view( "12" ) ) );
        BOOST_TEST( sv.starts_with( "12" ) );

        BOOST_TEST( sv.starts_with( boost_kahypar::core::string_view( "123" ) ) );
        BOOST_TEST( sv.starts_with( "123" ) );

        BOOST_TEST( !sv.starts_with( boost_kahypar::core::string_view( "1234" ) ) );
        BOOST_TEST( !sv.starts_with( "1234" ) );

        BOOST_TEST( !sv.starts_with( boost_kahypar::core::string_view( "2" ) ) );
        BOOST_TEST( !sv.starts_with( '2' ) );
        BOOST_TEST( !sv.starts_with( "2" ) );
    }

    return boost_kahypar::report_errors();
}
