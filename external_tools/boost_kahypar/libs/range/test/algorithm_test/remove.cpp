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
#include <boost_kahypar/range/algorithm/remove.hpp>

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
        template< class Container, class Value >
        void test_remove_impl( const Container& c, Value to_remove )
        {
            Container reference(c);

            typedef BOOST_DEDUCED_TYPENAME Container::iterator iterator_t;

            iterator_t reference_it
                = std::remove(reference.begin(), reference.end(), to_remove);

            Container test(c);
            iterator_t test_it = boost_kahypar::remove(test, to_remove);

            BOOST_CHECK_EQUAL( std::distance(test.begin(), test_it),
                               std::distance(reference.begin(), reference_it) );

            BOOST_CHECK_EQUAL_COLLECTIONS( reference.begin(), reference.end(),
                                           test.begin(), test.end() );
                                           
            Container test2(c);
            iterator_t test_it2 = boost_kahypar::remove(test2, to_remove);
            
            BOOST_CHECK_EQUAL( std::distance(test2.begin(), test_it2),
                               std::distance(reference.begin(), reference_it) );
                               
            BOOST_CHECK_EQUAL_COLLECTIONS( reference.begin(), reference.end(),
                                           test2.begin(), test2.end() );
        }

        template< class Container >
        void test_remove_impl()
        {
            using namespace boost_kahypar::assign;

            Container cont;
            test_remove_impl(cont, 0);

            cont.clear();
            cont += 1;
            test_remove_impl(cont, 0);
            test_remove_impl(cont, 1);

            cont.clear();
            cont += 1,1,1,1,1;
            test_remove_impl(cont, 0);
            test_remove_impl(cont, 1);

            cont.clear();
            cont += 1,2,3,4,5,6,7,8,9;
            test_remove_impl(cont, 1);
            test_remove_impl(cont, 9);
            test_remove_impl(cont, 4);
        }

        void test_remove()
        {
            test_remove_impl< std::vector<int> >();
            test_remove_impl< std::list<int> >();
            test_remove_impl< std::deque<int> >();
        }
    }
}

boost_kahypar::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    boost_kahypar::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.algorithm.remove" );

    test->add( BOOST_TEST_CASE( &boost_kahypar::test_remove ) );

    return test;
}
