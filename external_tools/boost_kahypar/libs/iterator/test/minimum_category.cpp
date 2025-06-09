// Copyright Andrey Semashev 2014.
//
// Use, modification and distribution is subject to
// the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost_kahypar/iterator/minimum_category.hpp>
#include <boost_kahypar/core/lightweight_test_trait.hpp>
#include <boost_kahypar/type_traits/is_same.hpp>
#include <iterator>

using boost_kahypar::is_same;
using boost_kahypar::iterators::minimum_category;

int main(int, char*[])
{
    BOOST_TEST_TRAIT_TRUE((is_same<minimum_category<std::forward_iterator_tag, std::random_access_iterator_tag>::type, std::forward_iterator_tag>));
    BOOST_TEST_TRAIT_TRUE((is_same<minimum_category<std::random_access_iterator_tag, std::forward_iterator_tag>::type, std::forward_iterator_tag>));
    BOOST_TEST_TRAIT_TRUE((is_same<minimum_category<std::random_access_iterator_tag, std::random_access_iterator_tag>::type, std::random_access_iterator_tag>));

    return boost_kahypar::report_errors();
}
