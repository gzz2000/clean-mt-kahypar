// Copyright (C) 2018 Andrey Semashev
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost_kahypar/range/distance.hpp>
#include <boost_kahypar/range/iterator_range_core.hpp>
#include <boost_kahypar/iterator/distance.hpp>

int main()
{
    // Test that boost_kahypar::distance from Boost.Range works with boost_kahypar::distance from Boost.Iterator
    // (https://github.com/boostorg/iterator/commit/b844c8df530c474ec1856870b9b0de5f487b84d4#commitcomment-30603668)

    typedef boost_kahypar::iterator_range<const char*> range_type;
    range_type range;

    (void)boost_kahypar::distance(range);

    return 0;
}
