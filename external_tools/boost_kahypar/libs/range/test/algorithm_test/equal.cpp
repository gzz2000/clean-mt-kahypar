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
#include <boost_kahypar/range/algorithm/equal.hpp>

#include <boost_kahypar/test/test_tools.hpp>
#include <boost_kahypar/test/unit_test.hpp>

#include <boost_kahypar/assign.hpp>
#include <algorithm>
#include <list>
#include <set>
#include <vector>

namespace boost_kahypar
{
    namespace
    {
        template< class Container1, class Container2 >
        void test_equal_impl()
        {
            using namespace boost_kahypar::assign;

            typedef BOOST_DEDUCED_TYPENAME boost_kahypar::remove_const<Container1>::type container1_t;
            typedef BOOST_DEDUCED_TYPENAME boost_kahypar::remove_const<Container2>::type container2_t;

            container1_t mcont1;
            container2_t mcont2;

            Container1& cont1 = mcont1;
            Container2& cont2 = mcont2;

            BOOST_CHECK( boost_kahypar::equal(cont1, cont2) );
            BOOST_CHECK( boost_kahypar::equal(boost_kahypar::make_iterator_range(cont1), cont2) );
            BOOST_CHECK( boost_kahypar::equal(cont1, boost_kahypar::make_iterator_range(cont2)) );
            BOOST_CHECK( boost_kahypar::equal(boost_kahypar::make_iterator_range(cont1), boost_kahypar::make_iterator_range(cont2)) );
            BOOST_CHECK( boost_kahypar::equal(cont1, cont2, std::equal_to<int>()) );
            BOOST_CHECK( boost_kahypar::equal(boost_kahypar::make_iterator_range(cont1), cont2, std::equal_to<int>()) );
            BOOST_CHECK( boost_kahypar::equal(cont1, boost_kahypar::make_iterator_range(cont2), std::equal_to<int>()) );
            BOOST_CHECK( boost_kahypar::equal(boost_kahypar::make_iterator_range(cont1), boost_kahypar::make_iterator_range(cont2), std::equal_to<int>()) );
            BOOST_CHECK( boost_kahypar::equal(cont1, cont2, std::not_equal_to<int>()) );
            BOOST_CHECK( boost_kahypar::equal(boost_kahypar::make_iterator_range(cont1), cont2, std::not_equal_to<int>()) );
            BOOST_CHECK( boost_kahypar::equal(boost_kahypar::make_iterator_range(cont1), boost_kahypar::make_iterator_range(cont2), std::not_equal_to<int>()) );

            mcont1 += 1;
            BOOST_CHECK( !boost_kahypar::equal(cont1, cont2) );
            BOOST_CHECK( !boost_kahypar::equal(boost_kahypar::make_iterator_range(cont1), cont2) );
            BOOST_CHECK( !boost_kahypar::equal(cont1, boost_kahypar::make_iterator_range(cont2)) );
            BOOST_CHECK( !boost_kahypar::equal(boost_kahypar::make_iterator_range(cont1), boost_kahypar::make_iterator_range(cont2)) );
            BOOST_CHECK( !boost_kahypar::equal(cont1, cont2, std::equal_to<int>()) );
            BOOST_CHECK( !boost_kahypar::equal(boost_kahypar::make_iterator_range(cont1), cont2, std::equal_to<int>()) );
            BOOST_CHECK( !boost_kahypar::equal(cont1, boost_kahypar::make_iterator_range(cont2), std::equal_to<int>()) );
            BOOST_CHECK( !boost_kahypar::equal(boost_kahypar::make_iterator_range(cont1), boost_kahypar::make_iterator_range(cont2), std::equal_to<int>()) );
            BOOST_CHECK( !boost_kahypar::equal(cont1, cont2, std::not_equal_to<int>()) );
            BOOST_CHECK( !boost_kahypar::equal(boost_kahypar::make_iterator_range(cont1), cont2, std::not_equal_to<int>()) );
            BOOST_CHECK( !boost_kahypar::equal(boost_kahypar::make_iterator_range(cont1), boost_kahypar::make_iterator_range(cont2), std::not_equal_to<int>()) );

            mcont1.clear();
            mcont2 += 1;
            BOOST_CHECK( !boost_kahypar::equal(cont1, cont2) );
            BOOST_CHECK( !boost_kahypar::equal(boost_kahypar::make_iterator_range(cont1), cont2) );
            BOOST_CHECK( !boost_kahypar::equal(boost_kahypar::make_iterator_range(cont1), boost_kahypar::make_iterator_range(cont2)) );
            BOOST_CHECK( !boost_kahypar::equal(cont1, cont2, std::equal_to<int>()) );
            BOOST_CHECK( !boost_kahypar::equal(boost_kahypar::make_iterator_range(cont1), cont2, std::equal_to<int>()) );
            BOOST_CHECK( !boost_kahypar::equal(boost_kahypar::make_iterator_range(cont1), boost_kahypar::make_iterator_range(cont2), std::equal_to<int>()) );
            BOOST_CHECK( !boost_kahypar::equal(cont1, cont2, std::not_equal_to<int>()) );
            BOOST_CHECK( !boost_kahypar::equal(boost_kahypar::make_iterator_range(cont1), cont2, std::not_equal_to<int>()) );
            BOOST_CHECK( !boost_kahypar::equal(boost_kahypar::make_iterator_range(cont1), boost_kahypar::make_iterator_range(cont2), std::not_equal_to<int>()) );

            mcont1 += 1;
            BOOST_CHECK( boost_kahypar::equal(cont1, cont2) );
            BOOST_CHECK( boost_kahypar::equal(boost_kahypar::make_iterator_range(cont1), cont2) );
            BOOST_CHECK( boost_kahypar::equal(cont1, boost_kahypar::make_iterator_range(cont2)) );
            BOOST_CHECK( boost_kahypar::equal(boost_kahypar::make_iterator_range(cont1), boost_kahypar::make_iterator_range(cont2)) );
            BOOST_CHECK( boost_kahypar::equal(cont1, cont2, std::equal_to<int>()) );
            BOOST_CHECK( boost_kahypar::equal(boost_kahypar::make_iterator_range(cont1), cont2, std::equal_to<int>()) );
            BOOST_CHECK( boost_kahypar::equal(cont1, boost_kahypar::make_iterator_range(cont2), std::equal_to<int>()) );
            BOOST_CHECK( boost_kahypar::equal(boost_kahypar::make_iterator_range(cont1), boost_kahypar::make_iterator_range(cont2), std::equal_to<int>()) );
            BOOST_CHECK( !boost_kahypar::equal(cont1, cont2, std::not_equal_to<int>()) );
            BOOST_CHECK( !boost_kahypar::equal(boost_kahypar::make_iterator_range(cont1), cont2, std::not_equal_to<int>()) );
            BOOST_CHECK( !boost_kahypar::equal(cont1, boost_kahypar::make_iterator_range(cont2), std::not_equal_to<int>()) );
            BOOST_CHECK( !boost_kahypar::equal(boost_kahypar::make_iterator_range(cont1), boost_kahypar::make_iterator_range(cont2), std::not_equal_to<int>()) );

            mcont1 += 2,3,4,5,6,7,8,9;
            mcont2 += 2,3,4,5,6,7,8,9;
            BOOST_CHECK( boost_kahypar::equal(cont1, cont2) );
            BOOST_CHECK( boost_kahypar::equal(boost_kahypar::make_iterator_range(cont1), cont2) );
            BOOST_CHECK( boost_kahypar::equal(cont1, boost_kahypar::make_iterator_range(cont2)) );
            BOOST_CHECK( boost_kahypar::equal(boost_kahypar::make_iterator_range(cont1), boost_kahypar::make_iterator_range(cont2)) );
            BOOST_CHECK( boost_kahypar::equal(cont1, cont2, std::equal_to<int>()) );
            BOOST_CHECK( boost_kahypar::equal(boost_kahypar::make_iterator_range(cont1), cont2, std::equal_to<int>()) );
            BOOST_CHECK( boost_kahypar::equal(cont1, boost_kahypar::make_iterator_range(cont2), std::equal_to<int>()) );
            BOOST_CHECK( boost_kahypar::equal(boost_kahypar::make_iterator_range(cont1), boost_kahypar::make_iterator_range(cont2), std::equal_to<int>()) );
            BOOST_CHECK( !boost_kahypar::equal(cont1, cont2, std::not_equal_to<int>()) );
            BOOST_CHECK( !boost_kahypar::equal(boost_kahypar::make_iterator_range(cont1), cont2, std::not_equal_to<int>()) );
            BOOST_CHECK( !boost_kahypar::equal(cont1, boost_kahypar::make_iterator_range(cont2), std::not_equal_to<int>()) );
            BOOST_CHECK( !boost_kahypar::equal(boost_kahypar::make_iterator_range(cont1), boost_kahypar::make_iterator_range(cont2), std::not_equal_to<int>()) );
        }

        template< class Container1, class Container2 >
        void test_driver()
        {
            typedef Container1 container1_t;
            typedef Container2 container2_t;
            typedef BOOST_DEDUCED_TYPENAME boost_kahypar::add_const<Container1>::type const_container1_t;
            typedef BOOST_DEDUCED_TYPENAME boost_kahypar::add_const<Container2>::type const_container2_t;

            test_equal_impl< const_container1_t, const_container2_t >();
            test_equal_impl< const_container1_t, container2_t >();
            test_equal_impl< container1_t, const_container2_t >();
            test_equal_impl< container1_t, container2_t >();
        }

        void test_equal()
        {
            test_driver< std::list<int>, std::list<int> >();
            test_driver< std::vector<int>, std::vector<int> >();
            test_driver< std::set<int>, std::set<int> >();
            test_driver< std::multiset<int>, std::multiset<int> >();
            test_driver< std::list<int>, std::vector<int> >();
            test_driver< std::vector<int>, std::list<int> >();
        }
    }
}


boost_kahypar::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    boost_kahypar::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.algorithm.equal" );

    test->add( BOOST_TEST_CASE( &boost_kahypar::test_equal ) );

    return test;
}
