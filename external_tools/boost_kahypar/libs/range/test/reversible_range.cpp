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

#include <boost_kahypar/range/rbegin.hpp>
#include <boost_kahypar/range/rend.hpp>
#include <boost_kahypar/range/begin.hpp>
#include <boost_kahypar/range/end.hpp>
#include <boost_kahypar/static_assert.hpp>
#include <boost_kahypar/type_traits.hpp>
#include <boost_kahypar/test/test_tools.hpp>
#include <boost_kahypar/test/unit_test.hpp>
#include <vector>
#include <algorithm>

void check_iterator()
{
    typedef std::vector<int>                            vec_t;
    typedef vec_t::iterator                             iterator;
    typedef std::pair<iterator,iterator>                pair_t;
    typedef boost_kahypar::range_reverse_iterator<pair_t>::type rev_iterator;
    typedef std::pair<rev_iterator,rev_iterator>        rev_pair_t;

    vec_t                            vec;
    pair_t                           p    = std::make_pair( vec.begin(), vec.end() );
    rev_pair_t                       rp   = std::make_pair( boost_kahypar::rbegin( p ), boost_kahypar::rend( p ) );
    int                             a[]  = {1,2,3,4,5,6,7,8,9,10};
    const int                       ca[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    BOOST_CHECK( boost_kahypar::rbegin( vec ) == boost_kahypar::range_reverse_iterator<vec_t>::type( vec.end() ) );
    BOOST_CHECK( boost_kahypar::rend( vec ) == boost_kahypar::range_reverse_iterator<vec_t>::type( vec.begin() ) );
    BOOST_CHECK( std::distance( boost_kahypar::rbegin( vec ), boost_kahypar::rend( vec ) ) == std::distance( boost_kahypar::begin( vec ), boost_kahypar::end( vec ) ) );

    BOOST_CHECK( boost_kahypar::rbegin( p ) == boost_kahypar::begin( rp ) );
    BOOST_CHECK( boost_kahypar::rend( p ) == boost_kahypar::end( rp ) );
    BOOST_CHECK( std::distance( boost_kahypar::rbegin( p ), boost_kahypar::rend( p ) ) == std::distance( boost_kahypar::begin( rp ), boost_kahypar::end( rp ) ) );
    BOOST_CHECK( std::distance( boost_kahypar::begin( p ), boost_kahypar::end( p ) ) == std::distance( boost_kahypar::rbegin( rp ), boost_kahypar::rend( rp ) ) );


    BOOST_CHECK_EQUAL( &*boost_kahypar::begin( a ), &*( boost_kahypar::rend( a ) - 1 ) );
    BOOST_CHECK_EQUAL( &*( boost_kahypar::end( a ) - 1 ), &*boost_kahypar::rbegin( a ) );
    BOOST_CHECK_EQUAL( &*boost_kahypar::begin( ca ), &*( boost_kahypar::rend( ca ) - 1 ) );
    BOOST_CHECK_EQUAL( &*( boost_kahypar::end( ca ) - 1 ), &*boost_kahypar::rbegin( ca ) );
}


boost_kahypar::unit_test::test_suite* init_unit_test_suite( int argc, char* argv[] )
{
    boost_kahypar::unit_test::test_suite* test = BOOST_TEST_SUITE( "Range Test Suite" );

    test->add( BOOST_TEST_CASE( &check_iterator ) );

    return test;
}







