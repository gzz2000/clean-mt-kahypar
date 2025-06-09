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
#include <boost_kahypar/range/algorithm/copy.hpp>

#include <boost_kahypar/test/test_tools.hpp>
#include <boost_kahypar/test/unit_test.hpp>

#include <boost_kahypar/assign.hpp>
#include <boost_kahypar/range/iterator.hpp>
#include <algorithm>
#include <list>
#include <set>
#include <vector>

namespace boost_kahypar
{
    namespace
    {
        template< class Container >
        void test_copy_impl()
        {
            Container source;
            typedef BOOST_DEDUCED_TYPENAME Container::value_type value_t;

            std::vector<value_t> target;
            target.resize(source.size());

            typedef BOOST_DEDUCED_TYPENAME range_iterator< std::vector<value_t> >::type iterator_t;
            iterator_t it = boost_kahypar::copy(source, target.begin());

            BOOST_CHECK( it == target.end() );

            BOOST_CHECK_EQUAL_COLLECTIONS(
                target.begin(), target.end(),
                source.begin(), source.end()
                );

            it = boost_kahypar::copy(boost_kahypar::make_iterator_range(source), target.begin());
            
            BOOST_CHECK( it == target.end() );

            BOOST_CHECK_EQUAL_COLLECTIONS(target.begin(), target.end(),
                                          source.begin(), source.end());
        }

        void test_copy()
        {
            test_copy_impl< std::vector<int> >();
            test_copy_impl< std::list<int> >();
            test_copy_impl< std::set<int> >();
            test_copy_impl< std::multiset<int> >();
        }
    }
}


boost_kahypar::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    boost_kahypar::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.algorithm.copy" );

    test->add( BOOST_TEST_CASE( &boost_kahypar::test_copy ) );

    return test;
}
