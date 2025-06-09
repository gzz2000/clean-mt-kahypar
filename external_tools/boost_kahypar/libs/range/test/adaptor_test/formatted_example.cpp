// Boost.Range library
//
//  Copyright Neil Groves 2014. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
//[formatted_example
#include <boost_kahypar/range/adaptor/formatted.hpp>
#include <boost_kahypar/assign.hpp>
#include <iterator>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

//<-
#include <boost_kahypar/test/test_tools.hpp>
#include <boost_kahypar/test/unit_test.hpp>

#include <boost_kahypar/range/algorithm_ext/push_back.hpp>

namespace
{
void formatted_example_test()
//->
//=int main(int argc, const char* argv[])
{
    using namespace boost_kahypar::assign;

    std::vector<int> input;
    input += 1,2,3,4,5;
    
    std::cout << boost_kahypar::adaptors::format(input) << std::endl;

    // Alternatively this can be written:
    // std::cout << (input | boost_kahypar::adaptors::formatted()) << std::endl;

//=    return 0;
//=}
//]
    std::ostringstream test;
    test << boost_kahypar::adaptors::format(input);

    BOOST_CHECK_EQUAL(test.str(), "{1,2,3,4,5}");
}
}

boost_kahypar::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    boost_kahypar::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.adaptor.formatted_example" );

    test->add( BOOST_TEST_CASE( &formatted_example_test ) );

    return test;
}
