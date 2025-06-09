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
#include <boost_kahypar/concept_check.hpp>
#include <boost_kahypar/iterator/iterator_adaptor.hpp>
#include <boost_kahypar/range/concepts.hpp>
#include <boost_kahypar/range/iterator_range.hpp>

#include <boost_kahypar/test/test_tools.hpp>
#include <boost_kahypar/test/unit_test.hpp>

#include <vector>

namespace boost_kahypar
{
    typedef std::vector<int>::iterator iter_base;
    struct iter : boost_kahypar::iterator_adaptor<iter, iter_base, int, boost_kahypar::use_default, int> {}; // will be deduced as random-access traversal but input category
    typedef boost_kahypar::iterator_range<iter> iter_range;
    
    namespace
    {
        // Ticket 6944 - Some Range concepts use the incorrect Iterator concept
        void test_ticket_6944()
        {
            BOOST_CONCEPT_ASSERT(( boost_kahypar::RandomAccessRangeConcept<iter_range> ));
        }
    }
}

boost_kahypar::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    boost_kahypar::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.ticket_6944" );

    test->add( BOOST_TEST_CASE( &boost_kahypar::test_ticket_6944 ) );

    return test;
}
