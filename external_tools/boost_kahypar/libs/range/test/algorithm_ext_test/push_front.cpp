// Boost.Range library
//
//  Copyright Neil Groves 2010. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
#include <boost_kahypar/range/algorithm_ext/push_front.hpp>

#include <boost_kahypar/test/test_tools.hpp>
#include <boost_kahypar/test/unit_test.hpp>

#include <boost_kahypar/range/iterator.hpp>
#include <boost_kahypar/range/irange.hpp>
#include <algorithm>
#include <list>
#include <vector>

namespace
{
    struct DoubleValue
    {
        template< class Value >
        Value operator()(Value x)
        {
            return x * 2;
        }
    };

    template< class Container >
    void test_push_front_impl(std::size_t n)
    {
        Container reference;
        for (std::size_t i = 0; i < n; ++i)
            reference.push_back(i);

        Container test;
        boost_kahypar::push_front(test, boost_kahypar::irange<std::size_t>(0, n));

        BOOST_CHECK_EQUAL_COLLECTIONS( reference.begin(), reference.end(),
            test.begin(), test.end() );

        // copy the original reference sequence
        Container reference_copy(reference);
        std::transform(reference.begin(), reference.end(), reference.begin(), DoubleValue());

        // Do it again to push onto non-empty container
        reference.insert(reference.end(), reference_copy.begin(), reference_copy.end());

        boost_kahypar::push_front(test, boost_kahypar::irange<std::size_t>(0, n * 2, 2));

        BOOST_CHECK_EQUAL_COLLECTIONS( reference.begin(), reference.end(),
            test.begin(), test.end() );
    }

    template< class Container >
    void test_push_front_impl()
    {
        test_push_front_impl< Container >(0);
        test_push_front_impl< Container >(1);
        test_push_front_impl< Container >(2);
        test_push_front_impl< Container >(100);
    }

    void test_push_front()
    {
        test_push_front_impl< std::vector<std::size_t> >();
        test_push_front_impl< std::list<std::size_t> >();
    }
}

boost_kahypar::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    boost_kahypar::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.algorithm_ext.push_front" );

    test->add( BOOST_TEST_CASE( &test_push_front ) );

    return test;
}
