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
//[reversed_example
#include <boost_kahypar/range/adaptor/reversed.hpp>
#include <boost_kahypar/range/algorithm/copy.hpp>
#include <boost_kahypar/assign.hpp>
#include <iterator>
#include <iostream>
#include <vector>

//<-
#include <boost_kahypar/test/test_tools.hpp>
#include <boost_kahypar/test/unit_test.hpp>

#include <boost_kahypar/range/algorithm_ext/push_back.hpp>

namespace 
{
void reversed_example_test()
//->
//=int main(int argc, const char* argv[])
{
    using namespace boost_kahypar::adaptors;
    using namespace boost_kahypar::assign;

    std::vector<int> input;
    input += 1,2,3,4,5,6,7,8,9;
    
    boost_kahypar::copy(
        input | reversed,
        std::ostream_iterator<int>(std::cout, ","));

//=    return 0;
//=}
//]
    std::vector<int> test;
    boost_kahypar::push_back(test, input | reversed);

    BOOST_CHECK_EQUAL_COLLECTIONS( input.rbegin(), input.rend(),
        test.begin(), test.end() );
}
}

boost_kahypar::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    boost_kahypar::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.adaptor.reversed_example" );

    test->add( BOOST_TEST_CASE( &reversed_example_test ) );

    return test;
}
