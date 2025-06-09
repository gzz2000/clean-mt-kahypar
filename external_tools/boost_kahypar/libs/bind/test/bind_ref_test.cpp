//
//  bind_ref_test.cpp - reference_wrapper
//
//  Copyright (c) 2009 Peter Dimov
//
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//

#if defined(__GNUC__)
// -Warray-bounds false positive under GCC 14 UBSAN
// ./boost/bind/mem_fn.hpp:74:59: error: array subscript 'int (**)(...)[0]' is partly outside array bounds of 'X [1]' [-Werror=array-bounds=]
//    74 |         return (get_pointer( std::forward<U>( u ) )->*pm_)( std::forward<A>( a )... );
# pragma GCC diagnostic ignored "-Warray-bounds"
#endif

#include <boost_kahypar/bind/bind.hpp>
#include <boost_kahypar/ref.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>

using namespace boost_kahypar::placeholders;

//

struct X
{
    int f( int x )
    {
        return x;
    }

    int g( int x ) const
    {
        return -x;
    }
};

int main()
{
    X x;

    BOOST_TEST( boost_kahypar::bind( &X::f, _1, 1 )( boost_kahypar::ref( x ) ) == 1 );
    BOOST_TEST( boost_kahypar::bind( &X::g, _1, 2 )( boost_kahypar::cref( x ) ) == -2 );

    return boost_kahypar::report_errors();
}
