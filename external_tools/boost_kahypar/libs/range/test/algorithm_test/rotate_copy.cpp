//  Copyright Neil Groves 2009. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
#include <boost_kahypar/range/algorithm/rotate_copy.hpp>

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
    template<class OutputIterator, class Value>
    void test_append(OutputIterator target, Value value)
    {
        *target++ = value;
    }

    template<class Container, class Iterator>
    void test_rotate_copy_impl(Container& cont, Iterator where_it)
    {
        typedef BOOST_DEDUCED_TYPENAME boost_kahypar::range_value<Container>::type
                                            value_type;

        std::vector<value_type> reference;
        std::vector<value_type> test;

        typedef BOOST_DEDUCED_TYPENAME boost_kahypar::range_iterator<Container>::type
                                            iterator_t BOOST_RANGE_UNUSED;

        test_append(
            std::rotate_copy(cont.begin(), where_it, cont.end(),
                std::back_inserter(reference)),
            value_type()
            );

        test_append(
            boost_kahypar::rotate_copy(cont, where_it, std::back_inserter(test)),
            value_type()
            );

        BOOST_CHECK_EQUAL_COLLECTIONS( reference.begin(), reference.end(),
                                       test.begin(), test.end() );
            
        test.clear();
        
        test_append(
            boost_kahypar::rotate_copy(boost_kahypar::make_iterator_range(cont), where_it,
                               std::back_inserter(test)),
            value_type()
            );
            
        BOOST_CHECK_EQUAL_COLLECTIONS( reference.begin(), reference.end(),
                                       test.begin(), test.end() );
    }

    template<class Container>
    void test_rotate_copy_impl(Container& cont)
    {
        typedef BOOST_DEDUCED_TYPENAME boost_kahypar::range_iterator<Container>::type iterator_t;

        iterator_t last = cont.end();
        for (iterator_t it = cont.begin(); it != last; ++it)
        {
            test_rotate_copy_impl(cont, it);
        }
    }

    template<class Container>
    void test_rotate_copy_impl()
    {
        using namespace boost_kahypar::assign;

        Container cont;
        test_rotate_copy_impl(cont);

        cont.clear();
        cont += 1;
        test_rotate_copy_impl(cont);

        cont.clear();
        cont += 1,2,3,4,5,6,7,8,9;
        test_rotate_copy_impl(cont);
    }

    void test_rotate_copy()
    {
        test_rotate_copy_impl< std::vector<int> >();
        test_rotate_copy_impl< std::list<int> >();
        test_rotate_copy_impl< std::deque<int> >();
    }
}

boost_kahypar::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    boost_kahypar::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.algorithm.rotate_copy" );

    test->add( BOOST_TEST_CASE( &test_rotate_copy ) );

    return test;
}
