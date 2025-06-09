// Boost.Range library
//
//  Copyright Neil Groves 2014. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//

#include <boost_kahypar/range/reference.hpp>
#include <boost_kahypar/static_assert.hpp>
#include <boost_kahypar/type_traits/is_same.hpp>

#include <boost_kahypar/test/test_tools.hpp>
#include <boost_kahypar/test/unit_test.hpp>

#include <vector>

namespace boost_kahypar_range_test
{
    namespace
    {

void test_reference()
{
    typedef std::vector<int> cont;

    BOOST_STATIC_ASSERT((
        boost_kahypar::is_same<
            cont::reference,
            boost_kahypar::range_reference<cont>::type
        >::value));

    BOOST_STATIC_ASSERT((
        boost_kahypar::is_same<
            cont::const_reference,
            boost_kahypar::range_reference<const cont>::type
        >::value));

#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
    BOOST_STATIC_ASSERT((
        boost_kahypar::is_same<
            cont::reference,
            boost_kahypar::range_reference<cont&&>::type
        >::value));
#endif
}

    } // anonymous namespace
} // namespace boost_kahypar_range_test

boost_kahypar::unit_test::test_suite* init_unit_test_suite( int argc, char* argv[] )
{
    boost_kahypar::unit_test::test_suite* test =
        BOOST_TEST_SUITE("Boost.Range range_reference meta-function");

    test->add(BOOST_TEST_CASE(&boost_kahypar_range_test::test_reference));

    return test;
}
