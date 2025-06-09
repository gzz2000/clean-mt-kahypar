// Boost.Range library
//
//  Copyright Neil Groves 2009. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//
#ifndef BOOST_RANGE_ALGORITHM_EXT_IOTA_HPP_INCLUDED
#define BOOST_RANGE_ALGORITHM_EXT_IOTA_HPP_INCLUDED

#include <boost_kahypar/range/config.hpp>
#include <boost_kahypar/range/concepts.hpp>
#include <boost_kahypar/range/iterator.hpp>
#include <boost_kahypar/range/begin.hpp>
#include <boost_kahypar/range/end.hpp>

namespace boost_kahypar
{
    namespace range
    {

template< class ForwardRange, class Value >
inline ForwardRange& iota( ForwardRange& rng, Value x )
{
    BOOST_CONCEPT_ASSERT(( ForwardRangeConcept<ForwardRange> ));
    typedef BOOST_DEDUCED_TYPENAME range_iterator<ForwardRange>::type iterator_t;

    iterator_t last_target = ::boost_kahypar::end(rng);
    for (iterator_t target = ::boost_kahypar::begin(rng); target != last_target; ++target, ++x)
        *target = x;

    return rng;
}

template< class ForwardRange, class Value >
inline const ForwardRange& iota( const ForwardRange& rng, Value x )
{
    BOOST_CONCEPT_ASSERT(( ForwardRangeConcept<const ForwardRange> ));
    typedef BOOST_DEDUCED_TYPENAME range_iterator<const ForwardRange>::type iterator_t;
    
    iterator_t last_target = ::boost_kahypar::end(rng);
    for (iterator_t target = ::boost_kahypar::begin(rng); target != last_target; ++target, ++x)
        *target = x;
    
    return rng;
}

    } // namespace range
    using range::iota;
} // namespace boost_kahypar

#endif // include guard
