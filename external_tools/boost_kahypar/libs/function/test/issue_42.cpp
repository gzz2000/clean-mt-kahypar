// Copyright 2022 Peter Dimov.
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt
//
// https://github.com/boostorg/function/issues/42

#include <boost_kahypar/function.hpp>

struct F
{
    int operator()( int x ) const { return -x; }
};

struct X
{
    boost_kahypar::function<int(int)> f_;
    explicit X( boost_kahypar::function<int(int)> f ): f_( f ) {}
};

F f2;
X x( f2 ); // -Wuninitialized under GCC 12
