// Boost.Range library
//
//  Copyright Neil Groves 2014. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
#include <boost_kahypar/range/adaptor/type_erased.hpp>
#include <boost_kahypar/range/adaptor/transformed.hpp>
#include <boost_kahypar/range/numeric.hpp>
#include "type_erased_test.hpp"

#include <boost_kahypar/test/unit_test.hpp>

#include <vector>

namespace boost_kahypar_range_adaptor_type_erased_test
{
    namespace
    {

typedef boost_kahypar::any_range<
    int,
    boost_kahypar::random_access_traversal_tag,
    int,
    std::ptrdiff_t
> any_integer_value_range;

struct get_fn
{
    typedef boost_kahypar::int32_t result_type;
    boost_kahypar::int32_t operator()(const MockType& val) const
    {
        return val.get();
    }
};

int accumulate_any_integer_value_range(any_integer_value_range rng)
{
    return boost_kahypar::accumulate(rng, 0);
}

void test_type_erased_transformed()
{
    std::vector<MockType> v(5, MockType(3));

    const int sum = accumulate_any_integer_value_range(
        v | boost_kahypar::adaptors::transformed(get_fn()));

    BOOST_CHECK_EQUAL(15, sum);
}

    } // anonymous namespace
} // namespace boost_kahypar_range_adaptor_type_erased_test

boost_kahypar::unit_test::test_suite*
init_unit_test_suite(int, char*[])
{
    boost_kahypar::unit_test::test_suite* test
        = BOOST_TEST_SUITE("RangeTestSuite.adaptor.type_erased_transformed");

    test->add(
        BOOST_TEST_CASE(
            &boost_kahypar_range_adaptor_type_erased_test::test_type_erased_transformed));

    return test;
}
