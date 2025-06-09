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

#include <boost_kahypar/range/concepts.hpp>
#include <boost_kahypar/range/functions.hpp>
#include <boost_kahypar/range/metafunctions.hpp>
#include <boost_kahypar/static_assert.hpp>
#include <boost_kahypar/type_traits.hpp>
#include <boost_kahypar/test/test_tools.hpp>
#include <vector>
#include <iterator>
#include <utility>

void check_iterator_pair()
{
    typedef std::vector<int> vec_t;
    vec_t                    vec;
    vec.push_back( 4 );
    typedef std::pair<vec_t::iterator,vec_t::iterator>
                             pair_t;
    typedef std::pair<vec_t::const_iterator,vec_t::const_iterator>
                             const_pair_t;
    typedef const pair_t     const_pair_tt;
    pair_t                   pair       = std::make_pair( boost_kahypar::begin( vec ), boost_kahypar::end( vec ) );
    const_pair_t             const_pair = std::make_pair( boost_kahypar::begin( vec ), boost_kahypar::end( vec ) );
    const_pair_tt            constness_pair( pair );


    BOOST_STATIC_ASSERT(( boost_kahypar::is_same< boost_kahypar::range_value<pair_t>::type,
                          std::iterator_traits<pair_t::first_type>::value_type>::value ));
    BOOST_STATIC_ASSERT(( boost_kahypar::is_same< boost_kahypar::range_iterator<pair_t>::type, pair_t::first_type >::value ));
    BOOST_STATIC_ASSERT(( boost_kahypar::is_same< boost_kahypar::range_const_iterator<pair_t>::type, pair_t::first_type >::value ));
    BOOST_STATIC_ASSERT(( boost_kahypar::is_same< boost_kahypar::range_difference<pair_t>::type,
                          std::iterator_traits<pair_t::first_type>::difference_type >::value ));
    BOOST_STATIC_ASSERT(( boost_kahypar::is_same< boost_kahypar::range_size<pair_t>::type, std::size_t >::value ));
    BOOST_STATIC_ASSERT(( boost_kahypar::is_same< boost_kahypar::range_iterator<pair_t>::type, pair_t::first_type >::value ));
    BOOST_STATIC_ASSERT(( boost_kahypar::is_same< boost_kahypar::range_iterator<const_pair_t>::type, const_pair_t::first_type >::value ));

    BOOST_STATIC_ASSERT(( boost_kahypar::is_same< boost_kahypar::range_value<const_pair_tt>::type,
                          std::iterator_traits<const_pair_t::first_type>::value_type>::value ));
    BOOST_STATIC_ASSERT(( boost_kahypar::is_same< boost_kahypar::range_iterator<const_pair_tt>::type, const_pair_tt::first_type >::value ));
    //
    // This behavior is not supported with v2.
    //BOOST_STATIC_ASSERT(( is_same< range_const_iterator<const_pair_tt>::type, const_pair_tt::first_type >::value ));
    BOOST_STATIC_ASSERT(( boost_kahypar::is_same< boost_kahypar::range_difference<const_pair_tt>::type,
                          std::iterator_traits<const_pair_tt::first_type>::difference_type >::value ));
    BOOST_STATIC_ASSERT(( boost_kahypar::is_same< boost_kahypar::range_size<const_pair_tt>::type, std::size_t >::value ));
    BOOST_STATIC_ASSERT(( boost_kahypar::is_same< boost_kahypar::range_iterator<const_pair_tt>::type, const_pair_tt::first_type >::value ));
    BOOST_STATIC_ASSERT(( boost_kahypar::is_same< boost_kahypar::range_iterator<const_pair_tt>::type, const_pair_tt::first_type >::value ));

    BOOST_CHECK( boost_kahypar::begin( pair ) == pair.first );
    BOOST_CHECK( boost_kahypar::end( pair )   == pair.second );
    BOOST_CHECK( boost_kahypar::empty( pair ) == (pair.first == pair.second) );
    BOOST_CHECK( boost_kahypar::size( pair )  ==
                    static_cast<std::size_t>(
                        std::distance(pair.first, pair.second)) );

    BOOST_CHECK( boost_kahypar::begin( const_pair ) == const_pair.first );
    BOOST_CHECK( boost_kahypar::end( const_pair )   == const_pair.second );
    BOOST_CHECK( boost_kahypar::empty( const_pair ) == (const_pair.first == const_pair.second) );
    BOOST_CHECK( boost_kahypar::size( const_pair )  ==
                    static_cast<std::size_t>(
                        std::distance(const_pair.first, const_pair.second)) );

    BOOST_CHECK( boost_kahypar::begin( constness_pair ) == constness_pair.first );
    BOOST_CHECK( boost_kahypar::end( constness_pair )   == constness_pair.second );
    BOOST_CHECK( boost_kahypar::empty( constness_pair ) == (constness_pair.first == const_pair.second) );
    BOOST_CHECK( boost_kahypar::size( constness_pair )  ==
                    static_cast<std::size_t>(
                        std::distance(constness_pair.first,
                                      constness_pair.second)) );
}


#include <boost_kahypar/test/unit_test.hpp>

boost_kahypar::unit_test::test_suite* init_unit_test_suite( int argc, char* argv[] )
{
    boost_kahypar::unit_test::test_suite* test = BOOST_TEST_SUITE( "Range Test Suite" );

    test->add( BOOST_TEST_CASE( &check_iterator_pair ) );

    return test;
}






