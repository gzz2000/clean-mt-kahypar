// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2008. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//

#include <boost_kahypar/range.hpp>
#include <iterator>         // for std::iterator_traits, std::distance()

namespace Foo
{
        //
        // Our sample UDT. A 'Pair'
        // will work as a range when the stored
        // elements are iterators.
        //
        template< class T >
        struct Pair
        {
                T first, last;
        };

} // namespace 'Foo'

namespace boost_kahypar
{
        //
        // Specialize metafunctions. We must include the range.hpp header.
        // We must open the 'boost' namespace.
        //
        /*
        template< class T >
        struct range_value< Foo::Pair<T> >
        {
                typedef typename std::iterator_traits<T>::value_type type;
        };
        */

        template< class T >
        struct range_iterator< Foo::Pair<T> >
        {
                typedef T type;
        };

        template< class T >
        struct range_const_iterator< Foo::Pair<T> >
        {
                //
                // Remark: this is defined similar to 'range_iterator'
                //         because the 'Pair' type does not distinguish
                //         between an iterator and a const_iterator.
                //
                typedef T type;
        };

        /*
    template< class T >
        struct range_difference< Foo::Pair<T> >
        {
                typedef typename std::iterator_traits<T>::difference_type type;
        };
        */

        template< class T >
    struct range_size< Foo::Pair<T> >
        {
                int static_assertion[ sizeof( std::size_t ) >=
                          sizeof( typename range_difference< Foo::Pair<T> >::type ) ];
                typedef std::size_t type;
        };

} // namespace 'boost'

namespace Foo
{
        //
        // The required functions. These should be defined in
        // the same namespace as 'Pair', in this case
        // in namespace 'Foo'.
        //

        template< class T >
        inline T boost_range_begin( Pair<T>& x )
        {
                return x.first;
        }

    template< class T >
        inline T boost_range_begin( const Pair<T>& x )
        {
                return x.first;
        }

        template< class T >
    inline T boost_range_end( Pair<T>& x )
        {
                return x.last;
        }

        template< class T >
    inline T boost_range_end( const Pair<T>& x )
        {
                return x.last;
        }

        template< class T >
        inline typename boost_kahypar::range_size< Pair<T> >::type
        boost_range_size( const Pair<T>& x )
        {
                return std::distance(x.first,x.last);
        }

} // namespace 'Foo'

#include <vector>

int main()
{
        typedef std::vector<int>::iterator  iter;
        std::vector<int>                    vec;
        vec.push_back( 42 );
        Foo::Pair<iter>                     pair  = { vec.begin(), vec.end() };
        const Foo::Pair<iter>&              cpair = pair;
        //
        // Notice that we call 'begin' etc with qualification.
        //
        iter i = boost_kahypar::begin( pair );
        iter e = boost_kahypar::end( pair );
        i      = boost_kahypar::begin( cpair );
        e      = boost_kahypar::end( cpair );
        boost_kahypar::range_size< Foo::Pair<iter> >::type s = boost_kahypar::size( pair );
        s      = boost_kahypar::size( cpair );
        boost_kahypar::range_const_reverse_iterator< Foo::Pair<iter> >::type
        ri     = boost_kahypar::rbegin( cpair ),
        re         = boost_kahypar::rend( cpair );

        //
        // Test metafunctions
        //

        boost_kahypar::range_value< Foo::Pair<iter> >::type
        v = *boost_kahypar::begin(pair);

        boost_kahypar::range_difference< Foo::Pair<iter> >::type
        d = boost_kahypar::end(pair) - boost_kahypar::begin(pair);
}

