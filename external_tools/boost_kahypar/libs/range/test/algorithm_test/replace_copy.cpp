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
#include <boost_kahypar/range/algorithm/replace_copy.hpp>

#include <boost_kahypar/test/test_tools.hpp>
#include <boost_kahypar/test/unit_test.hpp>

#include <boost_kahypar/assign.hpp>
#include <algorithm>
#include <functional>
#include <list>
#include <numeric>
#include <deque>
#include <vector>

namespace
{
    template<typename Iterator, typename Value>
    void test_append(Iterator target, Value value)
    {
        *target++ = value;
    }

    template< class Container, class Value >
    void test_replace_copy_impl( const Container& c, Value to_replace )
    {
        const Value replace_with = to_replace * 2;

        typedef typename boost_kahypar::range_value<Container>::type value_type;
        std::vector<value_type> reference;

        typedef BOOST_DEDUCED_TYPENAME std::vector<value_type>::iterator
                                            iterator_t BOOST_RANGE_UNUSED;

        test_append(
            std::replace_copy(c.begin(), c.end(),
                                std::back_inserter(reference), to_replace, replace_with),
            to_replace);

        std::vector<value_type> test;
        test_append(
            boost_kahypar::replace_copy(c, std::back_inserter(test), to_replace, replace_with),
            to_replace);

        BOOST_CHECK_EQUAL_COLLECTIONS( reference.begin(), reference.end(),
                                       test.begin(), test.end() );
            
        std::vector<value_type> test2;
        test_append(
            boost_kahypar::replace_copy(boost_kahypar::make_iterator_range(c),
                                std::back_inserter(test2), to_replace,
                                replace_with),
            to_replace);
            
        BOOST_CHECK_EQUAL_COLLECTIONS( reference.begin(), reference.end(),
                                       test2.begin(), test2.end() );
    }

    template< class Container >
    void test_replace_copy_impl()
    {
        using namespace boost_kahypar::assign;

        Container cont;
        test_replace_copy_impl(cont, 0);

        cont.clear();
        cont += 1;
        test_replace_copy_impl(cont, 0);
        test_replace_copy_impl(cont, 1);

        cont.clear();
        cont += 1,1,1,1,1;
        test_replace_copy_impl(cont, 0);
        test_replace_copy_impl(cont, 1);

        cont.clear();
        cont += 1,2,3,4,5,6,7,8,9;
        test_replace_copy_impl(cont, 1);
        test_replace_copy_impl(cont, 9);
        test_replace_copy_impl(cont, 4);
    }

    void test_replace_copy()
    {
        test_replace_copy_impl< std::vector<int> >();
        test_replace_copy_impl< std::list<int> >();
        test_replace_copy_impl< std::deque<int> >();
    }
}

boost_kahypar::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    boost_kahypar::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.algorithm.replace_copy" );

    test->add( BOOST_TEST_CASE( &test_replace_copy ) );

    return test;
}

