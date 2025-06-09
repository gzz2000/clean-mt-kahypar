//  Copyright Neil Groves 2009. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
#include <boost_kahypar/range/algorithm/heap_algorithm.hpp>

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
        template<class Container1, class Container2>
        void check_equal(const Container1& cont1, const Container2& cont2)
        {
            BOOST_CHECK_EQUAL_COLLECTIONS(
                cont1.begin(), cont1.end(),
                cont2.begin(), cont2.end()
                );
        }

        void test()
        {
            using namespace boost_kahypar::assign;

            std::vector<int> reference;
            reference += 1,2,3,4,5,6,7,8,9;

            std::vector<int> test_cont(reference);
            std::vector<int> test_cont2(reference);

            std::make_heap(reference.begin(), reference.end());
            boost_kahypar::make_heap(test_cont);
            check_equal(reference, test_cont);
            boost_kahypar::make_heap(boost_kahypar::make_iterator_range(test_cont2));
            check_equal(reference, test_cont2);

            std::push_heap(reference.begin(), reference.end());
            boost_kahypar::push_heap(test_cont);
            check_equal(reference, test_cont);
            boost_kahypar::push_heap(boost_kahypar::make_iterator_range(test_cont2));
            check_equal(reference, test_cont2);

            std::make_heap(reference.begin(), reference.end());
            boost_kahypar::make_heap(test_cont);
            boost_kahypar::make_heap(boost_kahypar::make_iterator_range(test_cont2));

            std::sort_heap(reference.begin(), reference.end());
            boost_kahypar::sort_heap(test_cont);
            check_equal(reference, test_cont);
            boost_kahypar::sort_heap(boost_kahypar::make_iterator_range(test_cont2));
            check_equal(reference, test_cont2);

            std::make_heap(reference.begin(), reference.end());
            boost_kahypar::make_heap(test_cont);
            boost_kahypar::make_heap(boost_kahypar::make_iterator_range(test_cont2));

            std::pop_heap(reference.begin(), reference.end());
            boost_kahypar::pop_heap(test_cont);
            check_equal(reference, test_cont);
            boost_kahypar::pop_heap(boost_kahypar::make_iterator_range(test_cont2));
            check_equal(reference, test_cont2);
        }

        template<class BinaryPredicate>
        void test_pred(BinaryPredicate pred)
        {
            using namespace boost_kahypar::assign;

            std::vector<int> reference;
            reference += 1,2,3,4,5,6,7,8,9;
            std::sort(reference.begin(), reference.end(), pred);

            std::vector<int> test_cont(reference);
            std::vector<int> test_cont2(reference);

            std::make_heap(reference.begin(), reference.end(), pred);
            boost_kahypar::make_heap(test_cont, pred);
            check_equal(reference, test_cont);
            boost_kahypar::make_heap(boost_kahypar::make_iterator_range(test_cont2), pred);
            check_equal(reference, test_cont2);

            reference.push_back(5);
            test_cont.push_back(5);
            test_cont2.push_back(5);
            std::push_heap(reference.begin(), reference.end(), pred);
            boost_kahypar::push_heap(test_cont, pred);
            check_equal(reference, test_cont);
            boost_kahypar::push_heap(boost_kahypar::make_iterator_range(test_cont2), pred);
            check_equal(reference, test_cont2);

            std::make_heap(reference.begin(), reference.end(), pred);
            boost_kahypar::make_heap(test_cont, pred);
            boost_kahypar::make_heap(boost_kahypar::make_iterator_range(test_cont2), pred);

            std::sort_heap(reference.begin(), reference.end(), pred);
            boost_kahypar::sort_heap(test_cont, pred);
            check_equal(reference, test_cont);
            boost_kahypar::sort_heap(boost_kahypar::make_iterator_range(test_cont2), pred);
            check_equal(reference, test_cont2);

            std::make_heap(reference.begin(), reference.end(), pred);
            boost_kahypar::make_heap(test_cont, pred);
            boost_kahypar::make_heap(boost_kahypar::make_iterator_range(test_cont2), pred);

            std::pop_heap(reference.begin(), reference.end(), pred);
            boost_kahypar::pop_heap(test_cont, pred);
            check_equal(reference, test_cont);
            boost_kahypar::pop_heap(boost_kahypar::make_iterator_range(test_cont2), pred);
            check_equal(reference, test_cont2);
        }

        void test_heap()
        {
            test();
            test_pred(std::less<int>());
            test_pred(std::greater<int>());
        }
    }
}

boost_kahypar::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    boost_kahypar::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.algorithm.heap" );

    test->add( BOOST_TEST_CASE( &boost_kahypar::test_heap ) );

    return test;
}
