// Copyright 2022 Peter Dimov.
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/system/errc.hpp>
#include <boost_kahypar/assert/source_location.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>

int main()
{
    BOOST_STATIC_CONSTEXPR boost_kahypar::source_location loc = BOOST_CURRENT_LOCATION;

    BOOST_TEST( make_error_code( boost_kahypar::system::errc::no_such_file_or_directory, &loc ).has_location() );
    BOOST_TEST_EQ( make_error_code( boost_kahypar::system::errc::no_such_file_or_directory, &loc ).location().to_string(), loc.to_string() );

    return boost_kahypar::report_errors();
}
