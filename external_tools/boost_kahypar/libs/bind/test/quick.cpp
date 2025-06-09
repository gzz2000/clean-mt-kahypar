//
// quick.cpp - a quick test for boost/bind/bind.hpp
//
// Copyright 2017 Peter Dimov
//
// Distributed under the Boost Software License, Version 1.0.
//
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
//

#include <boost_kahypar/bind/bind.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>

using namespace boost_kahypar::placeholders;

//

int f( int a, int b, int c )
{
    return a + 10 * b + 100 * c;
}

int main()
{
    int const i = 1;

    BOOST_TEST_EQ( boost_kahypar::bind( f, _1, 2, 3 )( i ), 321 );

    return boost_kahypar::report_errors();
}
