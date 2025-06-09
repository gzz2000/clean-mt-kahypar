// Copyright 2021 Peter Dimov.
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/system/result.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>
#include <vector>

using namespace boost_kahypar::system;

result<std::vector<int>> f()
{
    return std::vector<int>{ 1, 2, 3 };
}

int main()
{
    {
        int s = 0;

        for( int x: f().value() )
        {
            s += x;
        }

        BOOST_TEST_EQ( s, 6 );
    }

    return boost_kahypar::report_errors();
}
