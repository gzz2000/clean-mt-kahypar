// Boost.Range library
//
//  Copyright Neil Groves 2011. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
#include <boost_kahypar/algorithm/string/join.hpp>
#include <boost_kahypar/range/join.hpp>

#include <boost_kahypar/test/test_tools.hpp>
#include <boost_kahypar/test/unit_test.hpp>

#include <vector>

namespace boost_kahypar
{
    namespace
    {
   
        // Ticket 5547 - boost_kahypar::join ambiguous with algorithm::join
        void test_ticket_5547()
        {
            std::vector<int> x;
            boost_kahypar::range::join(x,x);
        }
    }
}

boost_kahypar::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    boost_kahypar::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.ticket_5547" );

    test->add( BOOST_TEST_CASE( &boost_kahypar::test_ticket_5547 ) );

    return test;
}
