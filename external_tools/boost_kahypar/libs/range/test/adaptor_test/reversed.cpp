// Boost.Range library
//
//  Copyright Neil Groves 2009. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
#include <boost_kahypar/range/adaptor/reversed.hpp>

#include <boost_kahypar/test/test_tools.hpp>
#include <boost_kahypar/test/unit_test.hpp>

#include <boost_kahypar/assign.hpp>
#include <boost_kahypar/range/algorithm_ext.hpp>

#include <algorithm>
#include <list>
#include <set>
#include <vector>

namespace boost_kahypar
{
    template< class Container >
    void reversed_test_impl( Container& c )
    {
        using namespace boost_kahypar::adaptors;

        std::vector< int > test_result1;
        boost_kahypar::push_back(test_result1, c | reversed);

        std::vector< int > test_result2;
        boost_kahypar::push_back(test_result2, adaptors::reverse(c));

        std::vector< int > reference( c.rbegin(), c.rend() );

        BOOST_CHECK_EQUAL_COLLECTIONS( reference.begin(), reference.end(),
                                       test_result1.begin(), test_result1.end() );

        BOOST_CHECK_EQUAL_COLLECTIONS( reference.begin(), reference.end(),
                                       test_result2.begin(), test_result2.end() );
    }

    template< class Container >
    void reversed_test_impl()
    {
        using namespace boost_kahypar::assign;

        Container c;

        // Test empty
        reversed_test_impl(c);

        // Test one
        c += 1;
        reversed_test_impl(c);

        // Test many
        c += 1,1,1,2,2,2,2,2,3,3,3,3,3,3,4,5,6,7,8,9;
        reversed_test_impl(c);
    }

    void reversed_test()
    {
        reversed_test_impl< std::vector< int > >();
        reversed_test_impl< std::list< int > >();
        reversed_test_impl< std::set< int > >();
        reversed_test_impl< std::multiset< int > >();
    }
}


boost_kahypar::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    boost_kahypar::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.adaptor.reversed" );

    test->add( BOOST_TEST_CASE( &boost_kahypar::reversed_test ) );

    return test;
}
