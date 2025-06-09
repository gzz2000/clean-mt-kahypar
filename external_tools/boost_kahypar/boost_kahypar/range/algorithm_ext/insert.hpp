// Boost.Range library
//
//  Copyright Neil Groves 2009. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//
#ifndef BOOST_RANGE_ALGORITHM_EXT_INSERT_HPP_INCLUDED
#define BOOST_RANGE_ALGORITHM_EXT_INSERT_HPP_INCLUDED

#include <boost_kahypar/range/config.hpp>
#include <boost_kahypar/range/concepts.hpp>
#include <boost_kahypar/range/difference_type.hpp>
#include <boost_kahypar/range/begin.hpp>
#include <boost_kahypar/range/end.hpp>
#include <boost_kahypar/assert.hpp>

namespace boost_kahypar
{
    namespace range
    {

template< class Container, class Range >
inline Container& insert( Container& on,
                          BOOST_DEDUCED_TYPENAME Container::iterator before,
                          const Range& from )
{
    BOOST_RANGE_CONCEPT_ASSERT(( ForwardRangeConcept<Container> ));
    BOOST_RANGE_CONCEPT_ASSERT(( SinglePassRangeConcept<Range> ));
    on.insert( before, boost_kahypar::begin(from), boost_kahypar::end(from) );
    return on;
}

template< class Container, class Range >
inline Container& insert( Container& on, const Range& from )
{
    BOOST_RANGE_CONCEPT_ASSERT(( ForwardRangeConcept<Container> ));
    BOOST_RANGE_CONCEPT_ASSERT(( SinglePassRangeConcept<Range> ));
    on.insert(boost_kahypar::begin(from), boost_kahypar::end(from));
    return on;
}

    } // namespace range
    using range::insert;
} // namespace boost_kahypar

#endif // include guard
