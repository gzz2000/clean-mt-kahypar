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
#include <boost_kahypar/range/adaptor/copied.hpp>

#include <boost_kahypar/test/test_tools.hpp>
#include <boost_kahypar/test/unit_test.hpp>

#include <boost_kahypar/assign.hpp>

#include <algorithm>
#include <deque>
#include <string>
#include <vector>
#include <boost_kahypar/range/algorithm_ext.hpp>

namespace boost_kahypar
{
    namespace
    {
        template< class Container >
        void copied_test_impl( Container& c )
        {
            using namespace boost_kahypar::adaptors;

            // This is my preferred syntax using the | operator.
            std::vector< int > test_result1;
            boost_kahypar::push_back(test_result1, c | copied(0u, c.size()));

            // This is the alternative syntax preferred by some.
            std::vector< int > test_result2;
            boost_kahypar::push_back(test_result2, adaptors::copy(c, 0u, c.size()));

            BOOST_CHECK_EQUAL_COLLECTIONS( test_result1.begin(), test_result1.end(),
                                           c.begin(), c.end() );

            BOOST_CHECK_EQUAL_COLLECTIONS( test_result2.begin(), test_result2.end(),
                                           c.begin(), c.end() );
        }

        template< class Container >
        void copied_test_impl()
        {
            using namespace boost_kahypar::assign;

            Container c;

            // test empty collection
            copied_test_impl(c);

            // test one element
            c += 1;
            copied_test_impl(c);

            // test many elements
            c += 1,2,2,2,3,4,4,4,4,5,6,7,8,9,9;
            copied_test_impl(c);
        }

        void copied_test()
        {
            copied_test_impl< std::vector< int > >();
            copied_test_impl< std::deque< int > >();
        }
    }
}

boost_kahypar::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    boost_kahypar::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.adaptor.copied" );

    test->add( BOOST_TEST_CASE( &boost_kahypar::copied_test ) );

    return test;
}
