// Copyright 2020 Peter Dimov.
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/system/error_condition.hpp>
#include <boost_kahypar/system/errc.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>

namespace sys = boost_kahypar::system;

int main()
{
    sys::error_condition en( sys::errc::no_such_file_or_directory );

    BOOST_TEST_EQ( en.value(), ENOENT );

    BOOST_TEST( en );
    BOOST_TEST( !!en );

    BOOST_TEST( en == make_error_condition( sys::errc::no_such_file_or_directory ) );

    BOOST_TEST( en.category() == sys::error_condition().category() );

    return boost_kahypar::report_errors();
}
