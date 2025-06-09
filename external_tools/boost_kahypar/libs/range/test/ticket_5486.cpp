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
#include <boost_kahypar/range/adaptor/adjacent_filtered.hpp>
#include <boost_kahypar/range/algorithm_ext/push_back.hpp>

#include <boost_kahypar/test/test_tools.hpp>
#include <boost_kahypar/test/unit_test.hpp>

#include <vector>

namespace boost_kahypar
{
    namespace
    {
        class TestTicket5486Pred
        {
        public:
            typedef int first_argument_type;
            typedef int second_argument_type;
            typedef bool result_type;

            explicit TestTicket5486Pred(int x) {}
            bool operator()(int,int) const { return true; }
        private:
            TestTicket5486Pred();
        };
    
        // Ticket 5486 - pertained to predicates erroneous
        // requiring default construction
        void test_ticket_5486()
        {
            std::vector<int> v;
            boost_kahypar::push_back(v, v | boost_kahypar::adaptors::adjacent_filtered(TestTicket5486Pred(1)));
            
            BOOST_CHECK_EQUAL_COLLECTIONS( v.begin(), v.end(),
                                           v.begin(), v.end() );
        }
    }
}

boost_kahypar::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    boost_kahypar::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.ticket_5486" );

    test->add( BOOST_TEST_CASE( &boost_kahypar::test_ticket_5486 ) );

    return test;
}
