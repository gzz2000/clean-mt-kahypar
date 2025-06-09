//  Copyright Neil Groves 2009. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
#include <boost_kahypar/range/algorithm/sort.hpp>

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
        template<class Container>
        void test_sort_impl(Container& cont)
        {
            Container reference(cont);
            Container test(cont);

            boost_kahypar::sort(test);
            std::sort(reference.begin(), reference.end());

            BOOST_CHECK_EQUAL_COLLECTIONS( reference.begin(), reference.end(),
                                           test.begin(), test.end() );
                                           
            Container test2(cont);
            boost_kahypar::sort(boost_kahypar::make_iterator_range(test2));
            BOOST_CHECK_EQUAL_COLLECTIONS( reference.begin(), reference.end(),
                                           test2.begin(), test2.end() );
        }

        template<class Container, class BinaryPredicate>
        void test_sort_impl(Container& cont, BinaryPredicate pred)
        {
            Container reference(cont);
            Container test(cont);

            boost_kahypar::sort(test, pred);
            std::sort(reference.begin(), reference.end(), pred);

            BOOST_CHECK_EQUAL_COLLECTIONS(
                reference.begin(), reference.end(),
                test.begin(), test.end()
                );
                
            Container test2(cont);
            boost_kahypar::sort(boost_kahypar::make_iterator_range(test2), pred);
            BOOST_CHECK_EQUAL_COLLECTIONS( reference.begin(), reference.end(),
                                           test2.begin(), test2.end() );
        }

        template<class Container>
        void test_sort_impl()
        {
            using namespace boost_kahypar::assign;

            Container cont;
            test_sort_impl(cont);
            test_sort_impl(cont, std::less<int>());
            test_sort_impl(cont, std::greater<int>());

            cont.clear();
            cont += 1;
            test_sort_impl(cont);
            test_sort_impl(cont, std::less<int>());
            test_sort_impl(cont, std::greater<int>());

            cont.clear();
            cont += 1,2,3,4,5,6,7,8,9;
            test_sort_impl(cont);
            test_sort_impl(cont, std::less<int>());
            test_sort_impl(cont, std::greater<int>());
        }

        void test_sort()
        {
            test_sort_impl< std::vector<int> >();
            test_sort_impl< std::deque<int> >();
        }
    }
}

boost_kahypar::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    boost_kahypar::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.algorithm.sort" );

    test->add( BOOST_TEST_CASE( &boost_kahypar::test_sort ) );

    return test;
}
