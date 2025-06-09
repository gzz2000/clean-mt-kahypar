// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//


#include <boost_kahypar/detail/workaround.hpp>

#if BOOST_WORKAROUND(BOOST_BORLANDC, BOOST_TESTED_AT(0x564))
#  pragma warn -8091 // suppress warning in Boost.Test
#  pragma warn -8057 // unused argument argc/argv in Boost.Test
#endif

#include <boost_kahypar/range.hpp>
#include <boost_kahypar/test/test_tools.hpp>
#include <boost_kahypar/test/unit_test.hpp>
#include <string>

template< class T >
const T& as_const( const T& r )
{
    return r;
}

void check_const_ranges()
{
    std::string       foo( "foo" );
    const std::string bar( "bar" );

    BOOST_CHECK( boost_kahypar::const_begin( foo )  == boost_kahypar::begin( as_const( foo ) ) );
    BOOST_CHECK( boost_kahypar::const_end( foo )    == boost_kahypar::end( as_const( foo ) ) );
    BOOST_CHECK( boost_kahypar::const_rbegin( foo ) == boost_kahypar::rbegin( as_const( foo ) ) );
    BOOST_CHECK( boost_kahypar::const_rend( foo )   == boost_kahypar::rend( as_const( foo ) ) );

    BOOST_CHECK( boost_kahypar::const_begin( bar )  == boost_kahypar::begin( as_const( bar ) ) );
    BOOST_CHECK( boost_kahypar::const_end( bar )    == boost_kahypar::end( as_const( bar ) ) );
    BOOST_CHECK( boost_kahypar::const_rbegin( bar ) == boost_kahypar::rbegin( as_const( bar ) ) );
    BOOST_CHECK( boost_kahypar::const_rend( bar )   == boost_kahypar::rend( as_const( bar ) ) );

}

boost_kahypar::unit_test::test_suite* init_unit_test_suite( int argc, char* argv[] )
{
    boost_kahypar::unit_test::test_suite* test = BOOST_TEST_SUITE( "Range Test Suite" );

    test->add( BOOST_TEST_CASE( &check_const_ranges ) );

    return test;
}





