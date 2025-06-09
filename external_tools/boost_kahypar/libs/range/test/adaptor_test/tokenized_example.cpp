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
//[tokenized_example
#include <boost_kahypar/range/adaptor/tokenized.hpp>
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
void tokenized_example_test()
//->
//=int main(int argc, const char* argv[])
{
    using namespace boost_kahypar::adaptors;
    
    typedef boost_kahypar::sub_match< std::string::iterator > match_type;
    
    std::string input = " a b c d e f g hijklmnopqrstuvwxyz";
    boost_kahypar::copy(
        input | tokenized(boost_kahypar::regex("\\w+")),
        std::ostream_iterator<match_type>(std::cout, "\n"));

//=    return 0;
//=}
//]
    using namespace boost_kahypar::assign;

    std::vector<std::string> reference;
    reference += "a","b","c","d","e","f","g","hijklmnopqrstuvwxyz";
    
    std::vector<match_type> test;
    boost_kahypar::push_back(test, input | tokenized(boost_kahypar::regex("\\w+")));
    
    BOOST_CHECK_EQUAL_COLLECTIONS( reference.begin(), reference.end(),
        test.begin(), test.end() );
}
}

boost_kahypar::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    boost_kahypar::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.adaptor.tokenized_example" );

    test->add( BOOST_TEST_CASE( &tokenized_example_test ) );

    return test;
}
