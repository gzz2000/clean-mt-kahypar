#include <boost_kahypar/config.hpp>

#if defined(BOOST_MSVC)
#pragma warning(disable: 4786)  // identifier truncated in debug info
#pragma warning(disable: 4710)  // function not inlined
#pragma warning(disable: 4711)  // function selected for automatic inline expansion
#pragma warning(disable: 4514)  // unreferenced inline removed
#endif

//
//  bind_function_test.cpp - function<>
//
//  Copyright (c) 2005 Peter Dimov
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#include <boost_kahypar/bind/bind.hpp>
#include <boost_kahypar/function.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>

//

int f( int x )
{
    return x;
}

int g( int x )
{
    return x + 1;
}

int main()
{
    boost_kahypar::function0<int> fn;

    BOOST_TEST( !fn.contains( boost_kahypar::bind( f, 1 ) ) );
    BOOST_TEST( !fn.contains( boost_kahypar::bind( f, 2 ) ) );
    BOOST_TEST( !fn.contains( boost_kahypar::bind( g, 1 ) ) );

    fn = boost_kahypar::bind( f, 1 );

    BOOST_TEST( fn() == 1 );

    BOOST_TEST( fn.contains( boost_kahypar::bind( f, 1 ) ) );
    BOOST_TEST( !fn.contains( boost_kahypar::bind( f, 2 ) ) );
    BOOST_TEST( !fn.contains( boost_kahypar::bind( g, 1 ) ) );

    fn = boost_kahypar::bind( f, 2 );

    BOOST_TEST( fn() == 2 );

    BOOST_TEST( !fn.contains( boost_kahypar::bind( f, 1 ) ) );
    BOOST_TEST( fn.contains( boost_kahypar::bind( f, 2 ) ) );
    BOOST_TEST( !fn.contains( boost_kahypar::bind( g, 1 ) ) );

    fn = boost_kahypar::bind( g, 1 );

    BOOST_TEST( fn() == 2 );

    BOOST_TEST( !fn.contains( boost_kahypar::bind( f, 1 ) ) );
    BOOST_TEST( !fn.contains( boost_kahypar::bind( f, 2 ) ) );
    BOOST_TEST( fn.contains( boost_kahypar::bind( g, 1 ) ) );

    return boost_kahypar::report_errors();
}
