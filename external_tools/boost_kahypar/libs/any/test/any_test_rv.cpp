//  Unit test for boost_kahypar::any.
//
//  See http://www.boost.org for most recent version, including documentation.
//
//  Copyright Antony Polukhin, 2013-2024.
//
//  Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt).

#include <boost_kahypar/any.hpp>

#include "move_test.hpp"

int main() {
    return any_tests::move_tests<boost_kahypar::any>::run_tests();
}
