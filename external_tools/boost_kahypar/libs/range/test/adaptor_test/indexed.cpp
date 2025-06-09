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
#include <boost_kahypar/range/adaptor/indexed.hpp>

#include <boost_kahypar/test/test_tools.hpp>
#include <boost_kahypar/test/unit_test.hpp>

#include <boost_kahypar/assign.hpp>
#include <boost_kahypar/foreach.hpp>
#include <boost_kahypar/range/algorithm_ext.hpp>
#include <boost_kahypar/range/concepts.hpp>

#include <algorithm>
#include <list>
#include <vector>

#include "../test_utils.hpp"

namespace boost_kahypar_range_test
{
    namespace
    {

template<typename Container, typename AdaptedRange>
void check_result(
    const Container&    reference_range,
    const AdaptedRange& adapted_range,
    std::ptrdiff_t      start_index
    )
{
    typedef typename boost_kahypar::range_iterator<const Container>::type
                reference_iterator;

    typedef typename boost_kahypar::range_iterator<const AdaptedRange>::type
                adapted_iterator;

    BOOST_REQUIRE_EQUAL(boost_kahypar::size(reference_range),
                        boost_kahypar::size(adapted_range));

    reference_iterator reference_it = boost_kahypar::begin(reference_range);
    adapted_iterator adapted_it = boost_kahypar::begin(adapted_range);
    for (std::ptrdiff_t i = start_index;
            reference_it != boost_kahypar::end(reference_range);
            ++reference_it, ++adapted_it, ++i)
    {
        BOOST_CHECK_EQUAL(i, adapted_it->index());
        BOOST_CHECK_EQUAL(*reference_it, adapted_it->value());
    }
}

template<typename Container>
void indexed_test_impl(Container& c, std::ptrdiff_t start_index)
{
    // This is my preferred syntax using the | operator.
    check_result(c, c | boost_kahypar::adaptors::indexed(), 0);
    check_result(c, c | boost_kahypar::adaptors::indexed(start_index), start_index);

    // This is the function syntax
    check_result(c, boost_kahypar::adaptors::index(c), 0);
    check_result(c, boost_kahypar::adaptors::index(c, start_index), start_index);
}

template<typename Container>
void indexed_test_impl(Container& c)
{
    indexed_test_impl(c, 0);
    indexed_test_impl(c, -1);
    indexed_test_impl(c, 4);
}

template<typename Container>
void indexed_test_impl()
{
    using namespace boost_kahypar::assign;

    Container c;

    // test empty container
    indexed_test_impl(c);

    // test one element
    c += 1;
    indexed_test_impl(c);

    // test many elements
    c += 1,2,2,2,3,4,4,4,4,5,6,7,8,9,9;
    indexed_test_impl(c);
}

template<typename Traversal, typename Range>
void check_traversal(const Range& rng)
{
    BOOST_STATIC_ASSERT(
        boost_kahypar::is_convertible<
            typename boost_kahypar::range_traversal<const Range>::type,
            Traversal
        >::value);
}

template<typename Traversal, typename Range>
void check_not_traversal(const Range& rng)
{
    BOOST_STATIC_ASSERT(
        !boost_kahypar::is_convertible<
            typename boost_kahypar::range_traversal<const Range>::type,
            Traversal
        >::value);
}

void indexed_test()
{
    indexed_test_impl< std::vector< int > >();
    indexed_test_impl< std::list< int > >();

    std::vector<int> vi;

    check_traversal<boost_kahypar::random_access_traversal_tag>(
        vi | boost_kahypar::adaptors::indexed());

    std::list<int> li;

    check_traversal<boost_kahypar::forward_traversal_tag>(
        li | boost_kahypar::adaptors::indexed());

    check_not_traversal<boost_kahypar::bidirectional_traversal_tag>(
        li | boost_kahypar::adaptors::indexed());

    check_not_traversal<boost_kahypar::random_access_traversal_tag>(
        li | boost_kahypar::adaptors::indexed());
}

    } // anonymous namesapce
} // namespace boost_kahypar_range_test

boost_kahypar::unit_test::test_suite*
init_unit_test_suite(int, char*[])
{
    boost_kahypar::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "Boost.Range indexed adaptor test suite" );

    test->add(BOOST_TEST_CASE(&boost_kahypar_range_test::indexed_test));

    return test;
}
