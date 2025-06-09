// Copyright 2021, 2022 Peter Dimov.
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/container_hash/hash.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>
#include <algorithm>
#include <vector>

int main()
{
    int const N = 16;

    std::vector<int> v;

    for( int i = 0; i < N; ++i )
    {
        v.push_back( i );
    }

    std::size_t h0 = boost_kahypar::hash_unordered_range( v.begin(), v.end() );

    int const M = 256;

    for( int i = 0; i < M; ++i )
    {
        std::next_permutation( v.begin(), v.end() );
        std::size_t h1 = boost_kahypar::hash_unordered_range( v.begin(), v.end() );
        BOOST_TEST_EQ( h0, h1 );
    }

    return boost_kahypar::report_errors();
}
