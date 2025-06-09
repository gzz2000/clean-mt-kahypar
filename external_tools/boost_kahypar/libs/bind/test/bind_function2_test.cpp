#include <boost_kahypar/config.hpp>
#include <boost_kahypar/config/pragma_message.hpp>

#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES) && ( defined(BOOST_GCC) && BOOST_GCC < 40600 )

BOOST_PRAGMA_MESSAGE( "Skipping test for GCC 4.4 -std=c++0x" )
int main() {}

#else

//
//  bind_function2_test.cpp - regression test
//
//  Copyright (c) 2015 Peter Dimov
//
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//

#include <boost_kahypar/bind/bind.hpp>
#include <boost_kahypar/function.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>

using namespace boost_kahypar::placeholders;

//

void fv1( int & a )
{
    a = 17041;
}

void fv2( int & a, int b )
{
    a = b;
}

void fv3( int & a, int b, int c )
{
    a = b + c;
}

void fv4( int & a, int b, int c, int d )
{
    a = b + c + d;
}

void fv5( int & a, int b, int c, int d, int e )
{
    a = b + c + d + e;
}

void fv6( int & a, int b, int c, int d, int e, int f )
{
    a = b + c + d + e + f;
}

void fv7( int & a, int b, int c, int d, int e, int f, int g )
{
    a = b + c + d + e + f + g;
}

void fv8( int & a, int b, int c, int d, int e, int f, int g, int h )
{
    a = b + c + d + e + f + g + h;
}

void fv9( int & a, int b, int c, int d, int e, int f, int g, int h, int i )
{
    a = b + c + d + e + f + g + h + i;
}

void function_test()
{
    int x = 0;

    {
        boost_kahypar::function<void(int&)> fw1 = boost_kahypar::bind( fv1, _1 );
        fw1( x ); BOOST_TEST( x == 17041 );
    }

    {
        boost_kahypar::function<void(int&, int)> fw2 = boost_kahypar::bind( fv2, _1, _2 );
        fw2( x, 1 ); BOOST_TEST( x == 1 );
    }

    {
        boost_kahypar::function<void(int&, int, int)> fw3 = boost_kahypar::bind( fv3, _1, _2, _3 );
        fw3( x, 1, 2 ); BOOST_TEST( x == 1+2 );
    }

    {
        boost_kahypar::function<void(int&, int, int, int)> fw4 = boost_kahypar::bind( fv4, _1, _2, _3, _4 );
        fw4( x, 1, 2, 3 ); BOOST_TEST( x == 1+2+3 );
    }

    {
        boost_kahypar::function<void(int&, int, int, int, int)> fw5 = boost_kahypar::bind( fv5, _1, _2, _3, _4, _5 );
        fw5( x, 1, 2, 3, 4 ); BOOST_TEST( x == 1+2+3+4 );
    }

    {
        boost_kahypar::function<void(int&, int, int, int, int, int)> fw6 = boost_kahypar::bind( fv6, _1, _2, _3, _4, _5, _6 );
        fw6( x, 1, 2, 3, 4, 5 ); BOOST_TEST( x == 1+2+3+4+5 );
    }

    {
        boost_kahypar::function<void(int&, int, int, int, int, int, int)> fw7 = boost_kahypar::bind( fv7, _1, _2, _3, _4, _5, _6, _7 );
        fw7( x, 1, 2, 3, 4, 5, 6 ); BOOST_TEST( x == 1+2+3+4+5+6 );
    }

    {
        boost_kahypar::function<void(int&, int, int, int, int, int, int, int)> fw8 = boost_kahypar::bind( fv8, _1, _2, _3, _4, _5, _6, _7, _8 );
        fw8( x, 1, 2, 3, 4, 5, 6, 7 ); BOOST_TEST( x == 1+2+3+4+5+6+7 );
    }

    {
        boost_kahypar::function<void(int&, int, int, int, int, int, int, int, int)> fw9 = boost_kahypar::bind( fv9, _1, _2, _3, _4, _5, _6, _7, _8, _9 );
        fw9( x, 1, 2, 3, 4, 5, 6, 7, 8 ); BOOST_TEST( x == 1+2+3+4+5+6+7+8 );
    }
}

int main()
{
    function_test();
    return boost_kahypar::report_errors();
}

#endif
