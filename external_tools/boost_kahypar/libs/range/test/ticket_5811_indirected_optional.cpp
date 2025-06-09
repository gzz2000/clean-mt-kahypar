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
#include <boost_kahypar/range/adaptor/indirected.hpp>
#include <boost_kahypar/optional.hpp>
#include <boost_kahypar/optional/optional_io.hpp>

#include <boost_kahypar/test/test_tools.hpp>
#include <boost_kahypar/test/unit_test.hpp>

#include <vector>

namespace boost_kahypar
{
    namespace
    {
        void test_ticket_5811_indirected_optional()
        {
            std::vector<boost_kahypar::optional<int> > v;
            std::vector<int> r;
            for (int i = 0; i < 10; ++i)
            {
                v.push_back(i);
                r.push_back(i);
            }
            BOOST_CHECK_EQUAL_COLLECTIONS(r.begin(), r.end(),
                                          v.begin(), v.end());
        }
    }
}

boost_kahypar::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    boost_kahypar::unit_test::test_suite* test
        = BOOST_TEST_SUITE("RangeTestSuite.ticket_5811_indirected_optional");

    test->add(BOOST_TEST_CASE(&boost_kahypar::test_ticket_5811_indirected_optional));

    return test;
}
