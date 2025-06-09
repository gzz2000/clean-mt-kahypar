// Copyright David Abrahams 2006. Distributed under the Boost
// Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost_kahypar/concept/usage.hpp>
#include <boost_kahypar/core/ignore_unused.hpp>

template <class T>
struct StringInitializable
{
    typedef int associated;
    BOOST_CONCEPT_USAGE(StringInitializable)
    {
        T x = "foo";
        boost_kahypar::ignore_unused(x);
    }
};

// Test that accessing an associated type will actually exercise usage
// requirements
typedef StringInitializable<int>::associated tee;



