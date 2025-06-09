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
//[copied_example
#include <boost_kahypar/range/adaptor/copied.hpp>
#include <boost_kahypar/range/algorithm/copy.hpp>
#include <boost_kahypar/assign.hpp>
#include <iterator>
#include <iostream>
#include <vector>

//<-
#include <boost_kahypar/range/algorithm_ext/push_back.hpp>

#include <boost_kahypar/test/test_tools.hpp>
#include <boost_kahypar/test/unit_test.hpp>

namespace
{
void copied_example_test()
//->
//=int main(int argc, const char* argv[])
{
    using namespace boost_kahypar::assign;
    using namespace boost_kahypar::adaptors;

    std::vector<int> input;
    input += 1,2,3,4,5,6,7,8,9,10;

    boost_kahypar::copy(
        input | copied(1, 5),
        std::ostream_iterator<int>(std::cout, ","));

//=    return 0;
//=}
//]
    std::vector<int> reference;
    reference += 2,3,4,5;

    std::vector<int> test;
    boost_kahypar::push_back(test, input | copied(1, 5));

    BOOST_CHECK_EQUAL_COLLECTIONS( reference.begin(), reference.end(),
        test.begin(), test.end() );
}
}

boost_kahypar::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    boost_kahypar::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.adaptor.copied_example" );

    test->add( BOOST_TEST_CASE( &copied_example_test ) );

    return test;
}
