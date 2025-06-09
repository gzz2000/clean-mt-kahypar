// Copyright 2017, 2021, 2022 Peter Dimov.
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/system/result.hpp>

using namespace boost_kahypar::system;

int main()
{
    int x = 1;
    result<int const&> r( x );
    r | 2;
}
