//  Copyright Neil Groves 2009. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
#ifndef BOOST_RANGE_ALGORITHM_COPY_BACKWARD_HPP_INCLUDED
#define BOOST_RANGE_ALGORITHM_COPY_BACKWARD_HPP_INCLUDED

#include <boost_kahypar/concept_check.hpp>
#include <boost_kahypar/range/begin.hpp>
#include <boost_kahypar/range/end.hpp>
#include <boost_kahypar/range/concepts.hpp>
#include <algorithm>

namespace boost_kahypar
{
    namespace range
    {

/// \brief template function copy_backward
///
/// range-based version of the copy_backwards std algorithm
///
/// \pre BidirectionalRange is a model of the BidirectionalRangeConcept
/// \pre BidirectionalTraversalWriteableIterator is a model of the BidirectionalIteratorConcept
/// \pre BidirectionalTraversalWriteableIterator is a model of the WriteableIteratorConcept
template< class BidirectionalRange, class BidirectionalTraversalWriteableIterator >
inline BidirectionalTraversalWriteableIterator
copy_backward(const BidirectionalRange& rng,
              BidirectionalTraversalWriteableIterator out)
{
    BOOST_RANGE_CONCEPT_ASSERT(( BidirectionalRangeConcept<const BidirectionalRange> ));
    return std::copy_backward(boost_kahypar::begin(rng), boost_kahypar::end(rng), out);
}

    } // namespace range
    using range::copy_backward;
} // namespace boost_kahypar

#endif // include guard
