// Boost.Range library
//
//  Copyright Neil Groves 2009. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//
#ifndef BOOST_RANGE_ALGORITHM_EXT_OVERWRITE_HPP_INCLUDED
#define BOOST_RANGE_ALGORITHM_EXT_OVERWRITE_HPP_INCLUDED

#include <boost_kahypar/range/config.hpp>
#include <boost_kahypar/range/concepts.hpp>
#include <boost_kahypar/range/difference_type.hpp>
#include <boost_kahypar/range/iterator.hpp>
#include <boost_kahypar/range/begin.hpp>
#include <boost_kahypar/range/end.hpp>
#include <boost_kahypar/assert.hpp>

namespace boost_kahypar
{
    namespace range
    {

template< class SinglePassRange1, class SinglePassRange2 >
inline void overwrite( const SinglePassRange1& from, SinglePassRange2& to )
{
    BOOST_RANGE_CONCEPT_ASSERT(( SinglePassRangeConcept<const SinglePassRange1> ));
    BOOST_RANGE_CONCEPT_ASSERT(( SinglePassRangeConcept<SinglePassRange2> ));

    BOOST_DEDUCED_TYPENAME range_iterator<const SinglePassRange1>::type
        i = boost_kahypar::begin(from), e = boost_kahypar::end(from);

    BOOST_DEDUCED_TYPENAME range_iterator<SinglePassRange2>::type
        out = boost_kahypar::begin(to);

#ifndef NDEBUG
    BOOST_DEDUCED_TYPENAME range_iterator<SinglePassRange2>::type
        last_out = boost_kahypar::end(to);
#endif

    for( ; i != e; ++out, ++i )
    {
#ifndef NDEBUG
        BOOST_ASSERT( out != last_out
            && "out of bounds in boost_kahypar::overwrite()" );
#endif
        *out = *i;
    }
}

template< class SinglePassRange1, class SinglePassRange2 >
inline void overwrite( const SinglePassRange1& from, const SinglePassRange2& to )
{
    BOOST_RANGE_CONCEPT_ASSERT(( SinglePassRangeConcept<const SinglePassRange1> ));
    BOOST_RANGE_CONCEPT_ASSERT(( SinglePassRangeConcept<const SinglePassRange2> ));

    BOOST_DEDUCED_TYPENAME range_iterator<const SinglePassRange1>::type
        i = boost_kahypar::begin(from), e = boost_kahypar::end(from);

    BOOST_DEDUCED_TYPENAME range_iterator<const SinglePassRange2>::type
        out = boost_kahypar::begin(to);

#ifndef NDEBUG
    BOOST_DEDUCED_TYPENAME range_iterator<const SinglePassRange2>::type
        last_out = boost_kahypar::end(to);
#endif

    for( ; i != e; ++out, ++i )
    {
#ifndef NDEBUG
        BOOST_ASSERT( out != last_out
            && "out of bounds in boost_kahypar::overwrite()" );
#endif
        *out = *i;
    }
}

    } // namespace range
    using range::overwrite;
} // namespace boost_kahypar

#endif // include guard
