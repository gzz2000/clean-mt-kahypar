//  Copyright Neil Groves 2009. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
#include <boost_kahypar/range/algorithm/min_element.hpp>

#include <boost_kahypar/test/test_tools.hpp>
#include <boost_kahypar/test/unit_test.hpp>

#include <boost_kahypar/assign.hpp>
#include <boost_kahypar/range/iterator.hpp>
#include "../test_driver/range_return_test_driver.hpp"
#include <algorithm>
#include <functional>
#include <list>
#include <numeric>
#include <deque>
#include <vector>

namespace boost_kahypar_range_test_algorithm_min_element
{
    class min_element_test_policy
    {
    public:
        template< class Container >
        BOOST_DEDUCED_TYPENAME boost_kahypar::range_iterator<Container>::type
        test_iter(Container& cont)
        {
            typedef BOOST_DEDUCED_TYPENAME boost_kahypar::range_iterator<Container>::type iter_t;
            iter_t result = boost_kahypar::min_element(cont);
            BOOST_CHECK( result == boost_kahypar::min_element(boost_kahypar::make_iterator_range(cont)) );
            return result;
        }

        template< boost_kahypar::range_return_value return_type >
        struct test_range
        {
            template< class Container, class Policy >
            BOOST_DEDUCED_TYPENAME boost_kahypar::range_return<Container,return_type>::type
            operator()(Policy&, Container& cont)
            {
                typedef BOOST_DEDUCED_TYPENAME boost_kahypar::range_return<Container,return_type>::type result_t;
                result_t result = boost_kahypar::min_element<return_type>(cont);
                BOOST_CHECK( result == boost_kahypar::min_element<return_type>(boost_kahypar::make_iterator_range(cont)) );
                return result;
            }
        };

        template< class Container >
        BOOST_DEDUCED_TYPENAME boost_kahypar::range_iterator<Container>::type
        reference(Container& cont)
        {
            return std::min_element(cont.begin(), cont.end());
        }
    };

    template<class Pred>
    class min_element_pred_test_policy
    {
    public:
        template< class Container >
        BOOST_DEDUCED_TYPENAME boost_kahypar::range_iterator<Container>::type
        test_iter(Container& cont)
        {
            typedef BOOST_DEDUCED_TYPENAME boost_kahypar::range_iterator<Container>::type iter_t;
            iter_t result = boost_kahypar::min_element(cont, Pred());
            BOOST_CHECK( result == boost_kahypar::min_element(
                                    boost_kahypar::make_iterator_range(cont), Pred()) );
            return result;
        }

        Pred pred() const { return Pred(); }

        template< boost_kahypar::range_return_value return_type >
        struct test_range
        {
            template< class Container, class Policy >
            BOOST_DEDUCED_TYPENAME boost_kahypar::range_return<Container,return_type>::type
            operator()(Policy& policy, Container& cont)
            {
                typedef BOOST_DEDUCED_TYPENAME boost_kahypar::range_return<Container,return_type>::type result_t;
                result_t result = boost_kahypar::min_element<return_type>(cont, policy.pred());
                BOOST_CHECK( result == boost_kahypar::min_element<return_type>(
                                boost_kahypar::make_iterator_range(cont), policy.pred()) );
                return result;
            }
        };

        template< class Container >
        BOOST_DEDUCED_TYPENAME boost_kahypar::range_iterator<Container>::type
        reference(Container& cont)
        {
            return std::min_element(cont.begin(), cont.end(), Pred());
        }
    };

    template<class Container, class TestPolicy>
    void test_min_element_impl(TestPolicy policy)
    {
        using namespace boost_kahypar::assign;

        typedef BOOST_DEDUCED_TYPENAME Container::value_type
                                                value_t BOOST_RANGE_UNUSED;

        typedef BOOST_DEDUCED_TYPENAME boost_kahypar::remove_const<Container>::type
                                                container_t;

        boost_kahypar::range_test::range_return_test_driver test_driver;

        container_t cont;

        test_driver(cont, policy);

        cont.clear();
        cont += 1;

        test_driver(cont, policy);

        cont.clear();
        cont += 1,2,2,2,3,4,5,6,7,8,9;

        test_driver(cont, policy);
    }

    template<class Container>
    void test_min_element_impl()
    {
        test_min_element_impl<Container>(min_element_test_policy());

        test_min_element_impl<Container>(
            min_element_pred_test_policy<std::less<int> >());

        test_min_element_impl<Container>(
            min_element_pred_test_policy<std::greater<int> >());
    }

    void test_min_element()
    {
        test_min_element_impl< const std::vector<int> >();
        test_min_element_impl< const std::deque<int> >();
        test_min_element_impl< const std::list<int> >();

        test_min_element_impl< std::vector<int> >();
        test_min_element_impl< std::deque<int> >();
        test_min_element_impl< std::list<int> >();
    }
}

boost_kahypar::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    boost_kahypar::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.algorithm.min_element" );

    test->add( BOOST_TEST_CASE( &boost_kahypar_range_test_algorithm_min_element::test_min_element ) );

    return test;
}
