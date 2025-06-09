// Copyright 2020 Peter Dimov
// Distributed under the Boost Software License, Version 1.0
// http://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/system/system_category.hpp>
#include <boost_kahypar/system/generic_category.hpp>
#include <boost_kahypar/system/error_condition.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>

namespace sys = boost_kahypar::system;

int main()
{
    sys::error_category const & cat = sys::system_category();

    // name
    BOOST_TEST_CSTR_EQ( cat.name(), "system" );

    // default_error_condition
    BOOST_TEST( cat.default_error_condition( 0 ) == sys::error_condition() );

    // No longer holds; returns a generic condition
    // BOOST_TEST( cat.default_error_condition( -1 ) == sys::error_condition( -1, cat ) );

#if defined(BOOST_WINDOWS_API)

    BOOST_TEST( cat.default_error_condition( 5 ) == sys::error_condition( EACCES, sys::generic_category() ) );

#else

    BOOST_TEST( cat.default_error_condition( EACCES ) == sys::error_condition( EACCES, sys::generic_category() ) );

#endif

    // failed
    BOOST_TEST( !cat.failed( 0 ) );
    BOOST_TEST( cat.failed( 5 ) );
    BOOST_TEST( cat.failed( -1 ) );

    return boost_kahypar::report_errors();
}
