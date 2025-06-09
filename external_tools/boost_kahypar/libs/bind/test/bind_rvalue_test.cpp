#include <boost_kahypar/config.hpp>

#if defined( BOOST_MSVC )

#pragma warning(disable: 4786)  // identifier truncated in debug info
#pragma warning(disable: 4710)  // function not inlined
#pragma warning(disable: 4711)  // function selected for automatic inline expansion
#pragma warning(disable: 4514)  // unreferenced inline removed

#endif

//  bind_rvalue_test.cpp
//
//  Copyright (c) 2006 Peter Dimov
//
// Distributed under the Boost Software License, Version 1.0.
//
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost_kahypar/bind/bind.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>

using namespace boost_kahypar::placeholders;

//

int f( int x )
{
    return x;
}

int main()
{
    BOOST_TEST( 
        boost_kahypar::bind( f, _1 )
        ( 1 ) == 1 );

    BOOST_TEST( 
        boost_kahypar::bind( f, _2 )
        ( 1, 2 ) == 2 );

    BOOST_TEST( 
        boost_kahypar::bind( f, _3 )
        ( 1, 2, 3 ) == 3 );

    BOOST_TEST( 
        boost_kahypar::bind( f, _4 )
        ( 1, 2, 3, 4 ) == 4 );

    BOOST_TEST( 
        boost_kahypar::bind( f, _5 )
        ( 1, 2, 3, 4, 5 ) == 5 );

    BOOST_TEST( 
        boost_kahypar::bind( f, _6 )
        ( 1, 2, 3, 4, 5, 6 ) == 6 );

    BOOST_TEST( 
        boost_kahypar::bind( f, _7 )
        ( 1, 2, 3, 4, 5, 6, 7 ) == 7 );

    BOOST_TEST( 
        boost_kahypar::bind( f, _8 )
        ( 1, 2, 3, 4, 5, 6, 7, 8 ) == 8 );

    BOOST_TEST( 
        boost_kahypar::bind( f, _9 )
        ( 1, 2, 3, 4, 5, 6, 7, 8, 9 ) == 9 );

    return boost_kahypar::report_errors();
}
