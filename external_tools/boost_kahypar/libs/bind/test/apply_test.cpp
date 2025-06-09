// Copyright 2021 Peter Dimov
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/bind/apply.hpp>
#include <boost_kahypar/bind/protect.hpp>
#include <boost_kahypar/bind/bind.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>

using namespace boost_kahypar::placeholders;

int f( int x )
{
    return x;
}

int main()
{
    BOOST_TEST_EQ( boost_kahypar::bind( boost_kahypar::apply<int>(), boost_kahypar::protect( boost_kahypar::bind( f, _1 ) ), 1 )(), 1 );
    BOOST_TEST_EQ( boost_kahypar::bind( boost_kahypar::apply<int>(), boost_kahypar::protect( boost_kahypar::bind( f, _2 ) ), 1, 2 )(), 2 );
    BOOST_TEST_EQ( boost_kahypar::bind( boost_kahypar::apply<int>(), boost_kahypar::protect( boost_kahypar::bind( f, _3 ) ), 1, 2, 3 )(), 3 );
    BOOST_TEST_EQ( boost_kahypar::bind( boost_kahypar::apply<int>(), boost_kahypar::protect( boost_kahypar::bind( f, _4 ) ), 1, 2, 3, 4 )(), 4 );
    BOOST_TEST_EQ( boost_kahypar::bind( boost_kahypar::apply<int>(), boost_kahypar::protect( boost_kahypar::bind( f, _5 ) ), 1, 2, 3, 4, 5 )(), 5 );
    BOOST_TEST_EQ( boost_kahypar::bind( boost_kahypar::apply<int>(), boost_kahypar::protect( boost_kahypar::bind( f, _6 ) ), 1, 2, 3, 4, 5, 6 )(), 6 );
    BOOST_TEST_EQ( boost_kahypar::bind( boost_kahypar::apply<int>(), boost_kahypar::protect( boost_kahypar::bind( f, _7 ) ), 1, 2, 3, 4, 5, 6, 7 )(), 7 );
    BOOST_TEST_EQ( boost_kahypar::bind( boost_kahypar::apply<int>(), boost_kahypar::protect( boost_kahypar::bind( f, _8 ) ), 1, 2, 3, 4, 5, 6, 7, 8 )(), 8 );

    return boost_kahypar::report_errors();
}
