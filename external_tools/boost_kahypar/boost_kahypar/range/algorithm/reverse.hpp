//  Copyright Neil Groves 2009. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
#ifndef BOOST_RANGE_ALGORITHM_REVERSE_HPP_INCLUDED
#define BOOST_RANGE_ALGORITHM_REVERSE_HPP_INCLUDED

#include <boost_kahypar/concept_check.hpp>
#include <boost_kahypar/range/begin.hpp>
#include <boost_kahypar/range/end.hpp>
#include <boost_kahypar/range/concepts.hpp>
#include <boost_kahypar/range/detail/range_return.hpp>
#include <algorithm>

namespace boost_kahypar
{
    namespace range
    {

/// \brief template function reverse
///
/// range-based version of the reverse std algorithm
///
/// \pre BidirectionalRange is a model of the BidirectionalRangeConcept
template<class BidirectionalRange>
inline BidirectionalRange& reverse(BidirectionalRange& rng)
{
    BOOST_RANGE_CONCEPT_ASSERT(( BidirectionalRangeConcept<BidirectionalRange> ));
    std::reverse(boost_kahypar::begin(rng), boost_kahypar::end(rng));
    return rng;
}

/// \overload
template<class BidirectionalRange>
inline const BidirectionalRange& reverse(const BidirectionalRange& rng)
{
    BOOST_RANGE_CONCEPT_ASSERT(( BidirectionalRangeConcept<const BidirectionalRange> ));
    std::reverse(boost_kahypar::begin(rng), boost_kahypar::end(rng));
    return rng;
}

    } // namespace range
    using range::reverse;
} // namespace boost_kahypar

#endif // include guard
