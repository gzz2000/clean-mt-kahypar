// Copyright 2020 Peter Dimov.
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/system/errc.hpp>
#include <boost_kahypar/system/is_error_condition_enum.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>

int main()
{
    BOOST_TEST_EQ( static_cast<int>( boost_kahypar::system::errc::success ), 0 );
    BOOST_TEST_EQ( static_cast<int>( boost_kahypar::system::errc::no_such_file_or_directory ), ENOENT );
    BOOST_TEST_EQ( static_cast<int>( boost_kahypar::system::errc::address_family_not_supported ), EAFNOSUPPORT );

    BOOST_TEST( boost_kahypar::system::is_error_condition_enum< boost_kahypar::system::errc::errc_t >::value );

    return boost_kahypar::report_errors();
}
