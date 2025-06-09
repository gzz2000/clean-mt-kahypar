//
// Test that an rvalue can't be passed to ref()
//
// Copyright 2014 Agustin Berge
//
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
//

#include <boost_kahypar/core/ref.hpp>

int main()
{
    boost_kahypar::reference_wrapper<int> r = boost_kahypar::ref( 2 ); // this should produce an ERROR
    (void)r;
}
