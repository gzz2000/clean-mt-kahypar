//  Copyright Neil Groves 2010. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
#ifndef BOOST_RANGE_COUNTING_RANGE_HPP_INCLUDED
#define BOOST_RANGE_COUNTING_RANGE_HPP_INCLUDED

#include <boost_kahypar/config.hpp>
#if BOOST_MSVC >= 1400
#pragma warning(push)
#pragma warning(disable : 4244)
#endif

#include <boost_kahypar/range/iterator_range_core.hpp>
#include <boost_kahypar/range/value_type.hpp>
#include <boost_kahypar/range/iterator.hpp>
#include <boost_kahypar/iterator/counting_iterator.hpp>

namespace boost_kahypar
{
    template<class Value>
    inline iterator_range<counting_iterator<Value> >
    counting_range(Value first, Value last)
    {
        typedef counting_iterator<Value> counting_iterator_t;
        typedef iterator_range<counting_iterator_t> result_t;
        return result_t(counting_iterator_t(first),
                        counting_iterator_t(last));
    }

    template<class Range>
    inline iterator_range<
        counting_iterator<
            BOOST_DEDUCED_TYPENAME range_iterator<const Range>::type
        >
    >
    counting_range(const Range& rng)
    {
        typedef counting_iterator<
            BOOST_DEDUCED_TYPENAME range_iterator<const Range>::type
        > counting_iterator_t;

        typedef iterator_range<counting_iterator_t> result_t;

        return result_t(counting_iterator_t(boost_kahypar::begin(rng)),
                        counting_iterator_t(boost_kahypar::end(rng)));
    }

    template<class Range>
    inline iterator_range<
        counting_iterator<
            BOOST_DEDUCED_TYPENAME range_iterator<Range>::type
        >
    >
    counting_range(Range& rng)
    {
        typedef counting_iterator<
            BOOST_DEDUCED_TYPENAME range_iterator<Range>::type
        > counting_iterator_t;

        typedef iterator_range<counting_iterator_t> result_t;

        return result_t(counting_iterator_t(boost_kahypar::begin(rng)),
                        counting_iterator_t(boost_kahypar::end(rng)));
    }
} // namespace boost_kahypar

#if BOOST_MSVC >= 1400
#pragma warning(pop)
#endif

#endif // include guard
