// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//


#include <boost_kahypar/detail/workaround.hpp>

#if BOOST_WORKAROUND(BOOST_BORLANDC, BOOST_TESTED_AT(0x564))
#  pragma warn -8091 // suppress warning in Boost.Test
#  pragma warn -8057 // unused argument argc/argv in Boost.Test
#endif

#include <boost_kahypar/range.hpp>
#include <boost_kahypar/test/test_tools.hpp>
#include <boost_kahypar/test/unit_test.hpp>
#include <vector>

//
// Generic range algorithm
//
template< class Rng >
typename boost_kahypar::range_iterator<Rng>::type foo_algo( Rng& r )
{
        //
        // This will only compile for Rng = UDT if the qualified calls
        // find boost_range_XXX via ADL.
        //
        return boost_kahypar::size(r) == 0u ? boost_kahypar::begin(r) : boost_kahypar::end(r);
}

namespace Foo
{
        //
        // Our sample UDT
        //
        struct X
        {
          X() : vec() { }

                typedef std::vector<int>       data_t;
                typedef data_t::iterator       iterator;
                typedef data_t::const_iterator const_iterator;

                data_t vec;

                void push_back( int i )
                { vec.push_back(i); }
        };

        //
        // The required functions. No type-traits need
        // to be defined because X defines the proper set of
        // nested types.
        //
        inline X::iterator range_begin( X& x )
        {
                return x.vec.begin();
        }


        inline X::const_iterator range_begin( const X& x )
        {
                return x.vec.begin();
        }


        inline X::iterator range_end( X& x )
        {
                return x.vec.end();
        }

        inline X::const_iterator range_end( const X& x )
        {
                return x.vec.end();
        }

}

void check_extension()
{
        Foo::X x;
        x.push_back(3);
        const Foo::X x2;

        foo_algo( x );
        foo_algo( x2 );
}

using boost_kahypar::unit_test::test_suite;

test_suite* init_unit_test_suite( int argc, char* argv[] )
{
    test_suite* test = BOOST_TEST_SUITE( "Range Test Suite" );

    test->add( BOOST_TEST_CASE( &check_extension ) );

    return test;
}





