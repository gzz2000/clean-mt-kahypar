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
#include <boost_kahypar/range/algorithm/count_if.hpp>

#include <boost_kahypar/test/test_tools.hpp>
#include <boost_kahypar/test/unit_test.hpp>

#include <boost_kahypar/assign.hpp>
#include "../test_function/false_predicate.hpp"
#include "../test_function/true_predicate.hpp"
#include "../test_function/equal_to_x.hpp"
#include <algorithm>
#include <list>
#include <set>
#include <vector>

namespace boost_kahypar
{
    namespace
    {
        template< class Container >
        void test_count_if_impl()
        {
            using namespace boost_kahypar::range_test_function;
            using namespace boost_kahypar::assign;

            typedef equal_to_x<int> pred_t;
            typedef BOOST_DEDUCED_TYPENAME std::iterator_traits<BOOST_DEDUCED_TYPENAME Container::iterator>::difference_type diff_t;

            Container cont;
            const Container& cref_cont = cont;

            BOOST_CHECK_EQUAL( 0u, boost_kahypar::count_if(cont, pred_t(0)) );
            BOOST_CHECK_EQUAL( 0u, boost_kahypar::count_if(cref_cont, pred_t(0)) );
            BOOST_CHECK_EQUAL( 0u, boost_kahypar::count_if(boost_kahypar::make_iterator_range(cont), pred_t(0)) );

            cont += 1;
            BOOST_CHECK_EQUAL( 0u, boost_kahypar::count_if(cont, pred_t(0)) );
            BOOST_CHECK_EQUAL( 0u, boost_kahypar::count_if(cref_cont, pred_t(0)) );
            BOOST_CHECK_EQUAL( 0u, boost_kahypar::count_if(boost_kahypar::make_iterator_range(cont), pred_t(0)) );
            BOOST_CHECK_EQUAL( 1u, boost_kahypar::count_if(cont, pred_t(1)) );
            BOOST_CHECK_EQUAL( 1u, boost_kahypar::count_if(cref_cont, pred_t(1)) );
            BOOST_CHECK_EQUAL( 1u, boost_kahypar::count_if(boost_kahypar::make_iterator_range(cont), pred_t(1)) );

            cont += 2,3,4,5,6,7,8,9;
            BOOST_CHECK_EQUAL( 0u, boost_kahypar::count_if(cont, pred_t(0)) );
            BOOST_CHECK_EQUAL( 0u, boost_kahypar::count_if(cref_cont, pred_t(0)) );
            BOOST_CHECK_EQUAL( 0u, boost_kahypar::count_if(boost_kahypar::make_iterator_range(cont), pred_t(0)) );
            BOOST_CHECK_EQUAL( 1u, boost_kahypar::count_if(cont, pred_t(1)) );
            BOOST_CHECK_EQUAL( 1u, boost_kahypar::count_if(cref_cont, pred_t(1)) );
            BOOST_CHECK_EQUAL( 1u, boost_kahypar::count_if(boost_kahypar::make_iterator_range(cont), pred_t(1)) );

            cont += 2;
            BOOST_CHECK_EQUAL( 0u, boost_kahypar::count_if(cont, pred_t(0)) );
            BOOST_CHECK_EQUAL( 0u, boost_kahypar::count_if(cref_cont, pred_t(0)) );
            BOOST_CHECK_EQUAL( 0u, boost_kahypar::count_if(boost_kahypar::make_iterator_range(cont), pred_t(0)) );
            BOOST_CHECK_EQUAL( 1u, boost_kahypar::count_if(cont, pred_t(1)) );
            BOOST_CHECK_EQUAL( 1u, boost_kahypar::count_if(cref_cont, pred_t(1)) );
            BOOST_CHECK_EQUAL( 1u, boost_kahypar::count_if(boost_kahypar::make_iterator_range(cont), pred_t(1)) );
            BOOST_CHECK_EQUAL( 2u, boost_kahypar::count_if(cont, pred_t(2)) );
            BOOST_CHECK_EQUAL( 2u, boost_kahypar::count_if(cref_cont, pred_t(2)) );
            BOOST_CHECK_EQUAL( 2u, boost_kahypar::count_if(boost_kahypar::make_iterator_range(cont), pred_t(2)) );

            BOOST_CHECK_EQUAL( 0u, boost_kahypar::count_if(cont, false_predicate()) );
            BOOST_CHECK_EQUAL( 0u, boost_kahypar::count_if(cref_cont, false_predicate()) );
            BOOST_CHECK_EQUAL( 0u, boost_kahypar::count_if(boost_kahypar::make_iterator_range(cont), false_predicate()) );

            BOOST_CHECK_EQUAL( static_cast<diff_t>(cont.size()), boost_kahypar::count_if(cont, true_predicate()) );
            BOOST_CHECK_EQUAL( static_cast<diff_t>(cont.size()), boost_kahypar::count_if(cref_cont, true_predicate()) );
            BOOST_CHECK_EQUAL( static_cast<diff_t>(cont.size()), boost_kahypar::count_if(boost_kahypar::make_iterator_range(cont), true_predicate()) );
        }

        void test_count_if()
        {
            test_count_if_impl< std::vector<int> >();
            test_count_if_impl< std::list<int> >();
            test_count_if_impl< std::multiset<int> >();
        }
    }
}


boost_kahypar::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    boost_kahypar::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.algorithm.count_if" );

    test->add( BOOST_TEST_CASE( &boost_kahypar::test_count_if ) );

    return test;
}
