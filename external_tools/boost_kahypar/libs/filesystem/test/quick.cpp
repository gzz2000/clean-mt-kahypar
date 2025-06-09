
// Copyright 2017 Peter Dimov.
//
// Distributed under the Boost Software License, Version 1.0.
//
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt

// See library home page at http://www.boost.org/libs/system

#include <boost_kahypar/filesystem.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>

namespace fs = boost_kahypar::filesystem;

int main()
{
    fs::path p1("a");
    fs::path p2 = p1 / "b";

    BOOST_TEST_EQ(p2, "a/b");

    return boost_kahypar::report_errors();
}
