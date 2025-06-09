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
#include <boost_kahypar/range/iterator_range.hpp>
#include <boost_kahypar/range/begin.hpp>
#include <boost_kahypar/range/end.hpp>
#include <boost_kahypar/array.hpp>
#include <boost_kahypar/test/test_tools.hpp>
#include <boost_kahypar/test/unit_test.hpp>
#include <iostream>
#include <vector>

namespace
{
    void test_pointer_as_iterator()
    {
        boost_kahypar::array<int,3> arr;
        boost_kahypar::iterator_range<const int*> r(arr.begin(), arr.end());
        r[0];
    }
} // anonymous namespace

boost_kahypar::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    boost_kahypar::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.pointer_as_iterator" );

    test->add(BOOST_TEST_CASE( &test_pointer_as_iterator ));

    return test;
}
