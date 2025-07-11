//  Copyright Neil Groves 2009. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
#ifndef BOOST_RANGE_ALGORITHM_EQUAL_RANGE_HPP_INCLUDED
#define BOOST_RANGE_ALGORITHM_EQUAL_RANGE_HPP_INCLUDED

#include <boost_kahypar/concept_check.hpp>
#include <boost_kahypar/range/begin.hpp>
#include <boost_kahypar/range/end.hpp>
#include <boost_kahypar/range/concepts.hpp>
#include <algorithm>

namespace boost_kahypar
{
    namespace range
    {

/// \brief template function equal_range
///
/// range-based version of the equal_range std algorithm
///
/// \pre ForwardRange is a model of the ForwardRangeConcept
/// \pre SortPredicate is a model of the BinaryPredicateConcept
template<class ForwardRange, class Value>
inline std::pair<
        BOOST_DEDUCED_TYPENAME boost_kahypar::range_iterator<ForwardRange>::type,
        BOOST_DEDUCED_TYPENAME boost_kahypar::range_iterator<ForwardRange>::type
       >
equal_range(ForwardRange& rng, const Value& val)
{
    BOOST_RANGE_CONCEPT_ASSERT(( ForwardRangeConcept<ForwardRange> ));
    return std::equal_range(boost_kahypar::begin(rng), boost_kahypar::end(rng), val);
}

/// \overload
template<class ForwardRange, class Value>
inline std::pair<
        BOOST_DEDUCED_TYPENAME boost_kahypar::range_iterator<const ForwardRange>::type,
        BOOST_DEDUCED_TYPENAME boost_kahypar::range_iterator<const ForwardRange>::type
       >
equal_range(const ForwardRange& rng, const Value& val)
{
    BOOST_RANGE_CONCEPT_ASSERT(( ForwardRangeConcept<const ForwardRange> ));
    return std::equal_range(boost_kahypar::begin(rng), boost_kahypar::end(rng), val);
}

/// \overload
template<class ForwardRange, class Value, class SortPredicate>
inline std::pair<
        BOOST_DEDUCED_TYPENAME boost_kahypar::range_iterator<ForwardRange>::type,
        BOOST_DEDUCED_TYPENAME boost_kahypar::range_iterator<ForwardRange>::type
       >
equal_range(ForwardRange& rng, const Value& val, SortPredicate pred)
{
    BOOST_RANGE_CONCEPT_ASSERT(( ForwardRangeConcept<ForwardRange> ));
    return std::equal_range(boost_kahypar::begin(rng), boost_kahypar::end(rng), val, pred);
}

/// \overload
template<class ForwardRange, class Value, class SortPredicate>
inline std::pair<
        BOOST_DEDUCED_TYPENAME boost_kahypar::range_iterator<const ForwardRange>::type,
        BOOST_DEDUCED_TYPENAME boost_kahypar::range_iterator<const ForwardRange>::type
       >
equal_range(const ForwardRange& rng, const Value& val, SortPredicate pred)
{
    BOOST_RANGE_CONCEPT_ASSERT(( ForwardRangeConcept<const ForwardRange> ));
    return std::equal_range(boost_kahypar::begin(rng), boost_kahypar::end(rng), val, pred);
}

    } // namespace range
    using range::equal_range;
} // namespace boost_kahypar

#endif // include guard
