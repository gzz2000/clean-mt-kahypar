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
#include <boost_kahypar/range/algorithm_ext/copy_n.hpp>

#include <boost_kahypar/test/test_tools.hpp>
#include <boost_kahypar/test/unit_test.hpp>

#include <boost_kahypar/range/iterator.hpp>
#include <algorithm>
#include <list>
#include <vector>

namespace
{
    template< class Container >
    void test_copy_n_impl()
    {
        std::vector<std::size_t> source;
        for (std::size_t i = 0; i < 10; ++i)
            source.push_back(i);

        for (std::size_t k = 0; k < 10; ++k)
        {
            std::vector<std::size_t> reference;
            for (std::size_t j = 0; j < k; ++j)
                reference.push_back(j);

            Container test;
            boost_kahypar::copy_n(source, k, std::back_inserter(test));

            BOOST_CHECK_EQUAL_COLLECTIONS( reference.begin(), reference.end(),
                test.begin(), test.end() );
        }
    }

    void test_copy_n()
    {
        test_copy_n_impl< std::vector<std::size_t> >();
        test_copy_n_impl< std::list<std::size_t> >();
    }
}

boost_kahypar::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    boost_kahypar::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.algorithm_ext.copy_n" );

    test->add( BOOST_TEST_CASE( &test_copy_n ) );

    return test;
}
