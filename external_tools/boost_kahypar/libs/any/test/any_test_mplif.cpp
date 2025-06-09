// Copyright Antony Polukhin, 2017-2024.
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// This tests the issue from https://svn.boost.org/trac/boost/ticket/12052

#include <iostream>
#include <boost_kahypar/any.hpp>

int main() {
    boost_kahypar::any a = 1;
    std::cout << boost_kahypar::any_cast<int>(a) << '\n';
    a = 3.14;
    std::cout << boost_kahypar::any_cast<double>(a) << '\n';
    a = true;
    std::cout << std::boolalpha << boost_kahypar::any_cast<bool>(a) << '\n';
}
