#include <boost_kahypar/config.hpp>

#ifndef _MSC_VER

int main()
{
}

#else

//
//  mem_fn_fastcall_ref_test.cpp - reference_wrapper, fastcall
//
//  Copyright 2009, 2024 Peter Dimov
//
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//

#define BOOST_MEM_FN_ENABLE_FASTCALL

#include <boost_kahypar/mem_fn.hpp>
#include <boost_kahypar/ref.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>

struct X
{
    int __fastcall f0() { return 1; }
    int __fastcall g0() const { return -1; }

    int __fastcall f1( int x1 ) { return x1; }
    int __fastcall g1( int x1 ) const { return -x1; }

    int __fastcall f2( int x1, int x2 ) { return x1+x2; }
    int __fastcall g2( int x1, int x2 ) const { return -x1-x2; }

    int __fastcall f3( int x1, int x2, int x3 ) { return x1+x2+x3; }
    int __fastcall g3( int x1, int x2, int x3 ) const { return -x1-x2-x3; }
};

int main()
{
    X x;

    BOOST_TEST_EQ( boost_kahypar::mem_fn( &X::f0 )( boost_kahypar::ref( x ) ), 1 );
    BOOST_TEST_EQ( boost_kahypar::mem_fn( &X::g0 )( boost_kahypar::cref( x ) ), -1 );

    BOOST_TEST_EQ( boost_kahypar::mem_fn( &X::f1 )( boost_kahypar::ref( x ), 1 ), 1 );
    BOOST_TEST_EQ( boost_kahypar::mem_fn( &X::g1 )( boost_kahypar::cref( x ), 1 ), -1 );

    BOOST_TEST_EQ( boost_kahypar::mem_fn( &X::f2 )( boost_kahypar::ref( x ), 1, 2 ), 1+2 );
    BOOST_TEST_EQ( boost_kahypar::mem_fn( &X::g2 )( boost_kahypar::cref( x ), 1, 2 ), -1-2 );

    BOOST_TEST_EQ( boost_kahypar::mem_fn( &X::f3 )( boost_kahypar::ref( x ), 1, 2, 3 ), 1+2+3 );
    BOOST_TEST_EQ( boost_kahypar::mem_fn( &X::g3 )( boost_kahypar::cref( x ), 1, 2, 3 ), -1-2-3 );

    return boost_kahypar::report_errors();
}

#endif
