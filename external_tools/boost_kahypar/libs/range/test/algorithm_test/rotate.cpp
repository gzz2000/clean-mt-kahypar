//  Copyright Neil Groves 2009. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
#include <boost_kahypar/range/algorithm/rotate.hpp>

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
        template<class Container, class Iterator>
        void test_rotate_impl(Container& cont, Iterator where_it)
        {
            Container reference(cont);
            Container test(cont);

            Iterator reference_where_it = reference.begin();
            std::advance(reference_where_it,
                std::distance(cont.begin(), where_it));

            std::rotate(reference.begin(), reference_where_it, reference.end());

            Iterator test_where_it = test.begin();
            std::advance(test_where_it,
                std::distance(cont.begin(), where_it));

            boost_kahypar::rotate(test, test_where_it);

            BOOST_CHECK_EQUAL_COLLECTIONS( reference.begin(), reference.end(),
                                           test.begin(), test.end() );
                
            test = cont;
            test_where_it = test.begin();
            std::advance(test_where_it,
                         std::distance(cont.begin(), where_it));
                         
            boost_kahypar::rotate(boost_kahypar::make_iterator_range(test), test_where_it);
            
            BOOST_CHECK_EQUAL_COLLECTIONS( reference.begin(), reference.end(),
                                           test.begin(), test.end() );
        }

        template<class Container>
        void test_rotate_impl(Container& cont)
        {
            typedef BOOST_DEDUCED_TYPENAME range_iterator<Container>::type iterator_t;

            iterator_t last = cont.end();
            for (iterator_t it = cont.begin(); it != last; ++it)
            {
                test_rotate_impl(cont, it);
            }
        }

        template<class Container>
        void test_rotate_impl()
        {
            using namespace boost_kahypar::assign;

            Container cont;
            test_rotate_impl(cont);

            cont.clear();
            cont += 1;
            test_rotate_impl(cont);

            cont.clear();
            cont += 1,2,3,4,5,6,7,8,9;
            test_rotate_impl(cont);
        }

        void test_rotate()
        {
            test_rotate_impl< std::vector<int> >();
            test_rotate_impl< std::list<int> >();
            test_rotate_impl< std::deque<int> >();
        }
    }
}


boost_kahypar::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    boost_kahypar::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.algorithm.rotate" );

    test->add( BOOST_TEST_CASE( &boost_kahypar::test_rotate ) );

    return test;
}
