#include <boost_kahypar/config.hpp>

#if defined(BOOST_MSVC)
#pragma warning(disable: 4786)  // identifier truncated in debug info
#pragma warning(disable: 4710)  // function not inlined
#pragma warning(disable: 4711)  // function selected for automatic inline expansion
#pragma warning(disable: 4514)  // unreferenced inline removed
#endif

//
// mem_fn_dm_test.cpp - data members
//
// Copyright 2005, 2024 Peter Dimov
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#include <boost_kahypar/mem_fn.hpp>
#include <boost_kahypar/shared_ptr.hpp>
#include <boost_kahypar/core/ref.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>
#include <boost_kahypar/config/workaround.hpp>

struct X
{
    int m;
};

int main()
{
    X x = { 0 };

    boost_kahypar::mem_fn( &X::m )( x ) = 401;

    BOOST_TEST( x.m == 401 );
    BOOST_TEST( boost_kahypar::mem_fn( &X::m )( x ) == 401 );

    boost_kahypar::mem_fn( &X::m )( &x ) = 502;

    BOOST_TEST( x.m == 502 );
    BOOST_TEST( boost_kahypar::mem_fn( &X::m )( &x ) == 502 );

    X * px = &x;

    boost_kahypar::mem_fn( &X::m )( px ) = 603;

    BOOST_TEST( x.m == 603 );
    BOOST_TEST( boost_kahypar::mem_fn( &X::m )( px ) == 603 );

    X const & cx = x;
    X const * pcx = &x;

    BOOST_TEST( boost_kahypar::mem_fn( &X::m )( cx ) == 603 );
    BOOST_TEST( boost_kahypar::mem_fn( &X::m )( pcx ) == 603 );

    BOOST_TEST_EQ( boost_kahypar::mem_fn( &X::m )( boost_kahypar::ref( x ) ), 603 );
    BOOST_TEST_EQ( boost_kahypar::mem_fn( &X::m )( boost_kahypar::cref( x ) ), 603 );

#if !BOOST_WORKAROUND(BOOST_MSVC, < 1900)

    boost_kahypar::mem_fn( &X::m )( boost_kahypar::ref( x ) ) = 704;
    BOOST_TEST_EQ( x.m, 704 );

#endif

    boost_kahypar::shared_ptr<X> sp( new X() );
    boost_kahypar::shared_ptr<X const> csp( sp );

    sp->m = 805;

    BOOST_TEST_EQ( boost_kahypar::mem_fn( &X::m )( sp ), 805 );
    BOOST_TEST_EQ( boost_kahypar::mem_fn( &X::m )( csp ), 805 );

#if !BOOST_WORKAROUND(BOOST_MSVC, < 1900)

    boost_kahypar::mem_fn( &X::m )( sp ) = 906;
    BOOST_TEST_EQ( sp->m, 906 );

#endif

    return boost_kahypar::report_errors();
}
