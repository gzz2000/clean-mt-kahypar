// Copyright 2019 Peter Dimov

// Use, modification and distribution is subject to the Boost Software License, Version 1.0.
// See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/function.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>

static int f( int x )
{
    return x + 1;
}

int main()
{
    boost_kahypar::function<int(int)> fn( f );

    BOOST_TEST_EQ( fn( 5 ), 6 );

    return boost_kahypar::report_errors();
}
