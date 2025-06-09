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
#include <boost_kahypar/range/algorithm/replace_if.hpp>

#include <boost_kahypar/test/test_tools.hpp>
#include <boost_kahypar/test/unit_test.hpp>

#include <boost_kahypar/assign.hpp>
#include <boost_kahypar/bind/bind.hpp>
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
        template< class Container, class UnaryPredicate >
        void test_replace_if_impl(Container& cont, UnaryPredicate pred)
        {
            using namespace boost_kahypar::placeholders;

            const int what = 2;
            const int with_what = 5;

            std::vector<int> reference(cont.begin(), cont.end());
            std::replace_if(reference.begin(), reference.end(),
                boost_kahypar::bind(pred, _1, what), with_what);

            std::vector<int> target(cont.begin(), cont.end());
            boost_kahypar::replace_if(target, boost_kahypar::bind(pred, _1, what), with_what);

            BOOST_CHECK_EQUAL_COLLECTIONS( reference.begin(), reference.end(),
                                           target.begin(), target.end() );
                
            std::vector<int> target2(cont.begin(), cont.end());
            boost_kahypar::replace_if(boost_kahypar::make_iterator_range(target2),
                              boost_kahypar::bind(pred, _1, what), with_what);
                              
            BOOST_CHECK_EQUAL_COLLECTIONS( reference.begin(), reference.end(),
                                           target2.begin(), target2.end() );
        }

        template< class Container >
        void test_replace_if_impl(Container& cont)
        {
            test_replace_if_impl(cont, std::equal_to<int>());
            test_replace_if_impl(cont, std::not_equal_to<int>());
        }

        template< class Container >
        void test_replace_if_impl()
        {
            using namespace boost_kahypar::assign;

            Container cont;
            test_replace_if_impl(cont);

            cont.clear();
            cont += 1;
            test_replace_if_impl(cont);

            cont.clear();
            cont += 1,2,3,4,5,6,7,8,9;
            test_replace_if_impl(cont);
        }

        void test_replace_if()
        {
            test_replace_if_impl< std::vector<int> >();
            test_replace_if_impl< std::list<int> >();
            test_replace_if_impl< std::deque<int> >();
        }
    }
}


boost_kahypar::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    boost_kahypar::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.algorithm.replace_if" );

    test->add( BOOST_TEST_CASE( &boost_kahypar::test_replace_if ) );

    return test;
}
