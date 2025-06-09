//
// Test that ref(ref(x)) does NOT collapse to ref(x)
//
// This irregularity of std::ref is questionable and breaks
// existing Boost code such as proto::make_expr
//
// Copyright 2014 Peter Dimov
//
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
//

#include <boost_kahypar/core/ref.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>

template<class T> void test( T const & t )
{
    {
        boost_kahypar::reference_wrapper< T const > r = boost_kahypar::ref( t );
        BOOST_TEST_EQ( &r.get(), &t );
    }

    {
        boost_kahypar::reference_wrapper< T const > r = boost_kahypar::cref( t );
        BOOST_TEST_EQ( &r.get(), &t );
    }
}

template<class T> void test_nonconst( T & t )
{
    {
        boost_kahypar::reference_wrapper< T > r = boost_kahypar::ref( t );
        BOOST_TEST_EQ( &r.get(), &t );
    }

    {
        boost_kahypar::reference_wrapper< T const > r = boost_kahypar::cref( t );
        BOOST_TEST_EQ( &r.get(), &t );
    }
}

int main()
{
    int x = 0;

    test( x );
    test( boost_kahypar::ref( x ) );
    test( boost_kahypar::cref( x ) );

    test_nonconst( x );

    {
        boost_kahypar::reference_wrapper< int > r = boost_kahypar::ref( x );
        test_nonconst( r );
    }

    {
        boost_kahypar::reference_wrapper< int const > r = boost_kahypar::cref( x );
        test_nonconst( r );
    }

    return boost_kahypar::report_errors();
}
