// Copyright 2006-2009 Daniel James.
// Copyright 2021 Peter Dimov.
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt)

#include <boost_kahypar/container_hash/hash.hpp>
#include <deque>

int main()
{
    std::deque<int> x;

    x.push_back( 1 );
    x.push_back( 2 );

    return boost_kahypar::hash< std::deque<int> >()( x ) == boost_kahypar::hash_value( x )? 0: 1;
}
