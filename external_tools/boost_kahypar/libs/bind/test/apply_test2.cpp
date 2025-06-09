// Copyright 2021 Peter Dimov
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/bind/apply.hpp>
#include <boost_kahypar/core/lightweight_test_trait.hpp>

int main()
{
    BOOST_TEST_TRAIT_SAME(void, boost_kahypar::apply<void>::result_type);
    BOOST_TEST_TRAIT_SAME(int&, boost_kahypar::apply<int&>::result_type);

    return boost_kahypar::report_errors();
}
