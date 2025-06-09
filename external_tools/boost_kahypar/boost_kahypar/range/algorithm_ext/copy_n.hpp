//  Copyright Neil Groves 2009. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
#ifndef BOOST_RANGE_ALGORITHM_COPY_N_HPP_INCLUDED
#define BOOST_RANGE_ALGORITHM_COPY_N_HPP_INCLUDED

#include <boost_kahypar/assert.hpp>
#include <boost_kahypar/concept_check.hpp>
#include <boost_kahypar/range/begin.hpp>
#include <boost_kahypar/range/end.hpp>
#include <boost_kahypar/range/concepts.hpp>
#include <boost_kahypar/range/distance.hpp>
#include <boost_kahypar/range/iterator.hpp>
#include <boost_kahypar/range/iterator_range.hpp>
#include <algorithm>

namespace boost_kahypar
{
    namespace range
    {

/// \brief template function copy
///
/// range-based version of the copy std algorithm
///
/// \pre SinglePassRange is a model of the SinglePassRangeConcept
/// \pre OutputIterator is a model of the OutputIteratorConcept
/// \pre 0 <= n <= distance(rng)
template< class SinglePassRange, class Size, class OutputIterator >
inline OutputIterator copy_n(const SinglePassRange& rng, Size n, OutputIterator out)
{
    BOOST_RANGE_CONCEPT_ASSERT(( SinglePassRangeConcept<const SinglePassRange> ));
    BOOST_ASSERT( n <= static_cast<Size>(::boost_kahypar::distance(rng)) );
    BOOST_ASSERT( n >= static_cast<Size>(0) );

    BOOST_DEDUCED_TYPENAME range_iterator<const SinglePassRange>::type source = ::boost_kahypar::begin(rng);

    for (Size i = 0; i < n; ++i, ++out, ++source)
        *out = *source;

    return out;
}

    } // namespace range
    using ::boost_kahypar::range::copy_n;
} // namespace boost_kahypar

#endif // include guard
