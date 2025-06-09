#include <boost_kahypar/config.hpp>

#if defined(BOOST_MSVC)
#pragma warning(disable: 4786)  // identifier truncated in debug info
#pragma warning(disable: 4710)  // function not inlined
#pragma warning(disable: 4711)  // function selected for automatic inline expansion
#pragma warning(disable: 4514)  // unreferenced inline removed
#endif

//  addressof_fn_test.cpp: addressof( f )
//
//  Copyright (c) 2008, 2009 Peter Dimov
//
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/utility/addressof.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>


void f0()
{
}

void f1(int)
{
}

void f2(int, int)
{
}

void f3(int, int, int)
{
}

void f4(int, int, int, int)
{
}

void f5(int, int, int, int, int)
{
}

void f6(int, int, int, int, int, int)
{
}

void f7(int, int, int, int, int, int, int)
{
}

void f8(int, int, int, int, int, int, int, int)
{
}

void f9(int, int, int, int, int, int, int, int, int)
{
}

int main()
{
    BOOST_TEST( boost_kahypar::addressof( f0 ) == &f0 );
    BOOST_TEST( boost_kahypar::addressof( f1 ) == &f1 );
    BOOST_TEST( boost_kahypar::addressof( f2 ) == &f2 );
    BOOST_TEST( boost_kahypar::addressof( f3 ) == &f3 );
    BOOST_TEST( boost_kahypar::addressof( f4 ) == &f4 );
    BOOST_TEST( boost_kahypar::addressof( f5 ) == &f5 );
    BOOST_TEST( boost_kahypar::addressof( f6 ) == &f6 );
    BOOST_TEST( boost_kahypar::addressof( f7 ) == &f7 );
    BOOST_TEST( boost_kahypar::addressof( f8 ) == &f8 );
    BOOST_TEST( boost_kahypar::addressof( f9 ) == &f9 );

    return boost_kahypar::report_errors();
}
