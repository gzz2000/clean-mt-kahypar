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
// Credits:
//  awulkiew highlighted that this test was not successfully testing the
//  algorithm.
//
#include <boost_kahypar/range/algorithm/copy_backward.hpp>

#include <boost_kahypar/test/test_tools.hpp>
#include <boost_kahypar/test/unit_test.hpp>

#include <boost_kahypar/assign.hpp>
#include <boost_kahypar/range/iterator.hpp>
#include <algorithm>
#include <list>
#include <vector>

namespace boost_kahypar_range_test
{
    namespace
    {
template<typename Container>
void test_copy_backward_impl(std::size_t n)
{
    Container source;
    typedef typename Container::value_type value_t;
    for (std::size_t i = 0; i < n; ++i)
        source.push_back(static_cast<value_t>(i));

    std::vector<value_t> target(n);

    typedef typename boost_kahypar::range_iterator<
        std::vector<value_t>
    >::type iterator_t;

    iterator_t it = boost_kahypar::copy_backward(source, target.end());

    BOOST_CHECK(it == target.begin());

    BOOST_CHECK_EQUAL_COLLECTIONS(target.begin(), target.end(),
                                  source.begin(), source.end());

    BOOST_CHECK(it == boost_kahypar::copy_backward(
                        boost_kahypar::make_iterator_range(source), target.end()));

    BOOST_CHECK_EQUAL_COLLECTIONS(target.begin(), target.end(),
                                  source.begin(), source.end());
}

template<typename Container>
void test_copy_backward_impl()
{
    test_copy_backward_impl<Container>(0u);
    test_copy_backward_impl<Container>(1u);
    test_copy_backward_impl<Container>(100u);
}

void test_copy_backward()
{
    test_copy_backward_impl<std::vector<int> >();
    test_copy_backward_impl<std::list<int> >();
}
    } // anonymous namespace
} // namespace boost_kahypar_range_test


boost_kahypar::unit_test::test_suite*
init_unit_test_suite(int, char*[])
{
    boost_kahypar::unit_test::test_suite* test
        = BOOST_TEST_SUITE("RangeTestSuite.algorithm.copy_backward");

    test->add(BOOST_TEST_CASE(&boost_kahypar_range_test::test_copy_backward));

    return test;
}
