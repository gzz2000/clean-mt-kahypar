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
#include <boost_kahypar/range/algorithm/fill.hpp>

#include <boost_kahypar/test/test_tools.hpp>
#include <boost_kahypar/test/unit_test.hpp>

#include <boost_kahypar/assign.hpp>
#include <algorithm>
#include <functional>
#include <list>
#include <numeric>
#include <deque>
#include <vector>

namespace boost_kahypar
{
    namespace
    {
        template< class Container >
        void test_fill_impl(Container& cont)
        {
            Container reference(cont);
            std::fill(reference.begin(), reference.end(), 1);

            Container target(cont);
            boost_kahypar::fill(target, 1);

            BOOST_CHECK_EQUAL_COLLECTIONS( reference.begin(), reference.end(),
                target.begin(), target.end() );

            Container target2(cont);
            boost_kahypar::fill(boost_kahypar::make_iterator_range(target2), 1);

            BOOST_CHECK_EQUAL_COLLECTIONS( reference.begin(), reference.end(),
                                           target2.begin(), target2.end() );
        }

        template< class Container >
        void test_fill_impl()
        {
            using namespace boost_kahypar::assign;

            Container cont;
            test_fill_impl(cont);

            cont.clear();
            cont += 2;
            test_fill_impl(cont);

            cont.clear();
            cont += 1,2;
            test_fill_impl(cont);

            cont.clear();
            cont += 1,2,3,4,5,6,7,8,9;
            test_fill_impl(cont);
        }

        void test_fill()
        {
            test_fill_impl< std::vector<int> >();
            test_fill_impl< std::list<int> >();
            test_fill_impl< std::deque<int> >();
        }
    }
}

boost_kahypar::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    boost_kahypar::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.algorithm.fill" );

    test->add( BOOST_TEST_CASE( &boost_kahypar::test_fill ) );

    return test;
}
