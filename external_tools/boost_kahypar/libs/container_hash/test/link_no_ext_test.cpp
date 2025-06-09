
// Copyright 2005-2009 Daniel James.
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include "./config.hpp"

#define BOOST_HASH_TEST_NAMESPACE boost_kahypar
#define BOOST_HASH_NO_EXTENSIONS
#include <boost_kahypar/container_hash/hash.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>

extern int f(std::size_t, int*);

int main() {
    BOOST_HASH_TEST_NAMESPACE::hash<int*> ptr_hasher;
    int x = 55;
    BOOST_TEST(!f(ptr_hasher(&x), &x));
    return boost_kahypar::report_errors();
}
