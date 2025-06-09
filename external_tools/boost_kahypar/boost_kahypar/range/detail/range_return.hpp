//  Copyright Neil Groves 2009. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
#ifndef BOOST_RANGE_DETAIL_RANGE_RETURN_HPP_INCLUDED
#define BOOST_RANGE_DETAIL_RANGE_RETURN_HPP_INCLUDED

#include <boost_kahypar/range/begin.hpp>
#include <boost_kahypar/range/end.hpp>
#include <boost_kahypar/range/iterator_range.hpp>
#include <boost_kahypar/next_prior.hpp>

namespace boost_kahypar
{
    enum range_return_value
    {
        // (*) indicates the most common values
        return_found,       // only the found resulting iterator (*)
        return_next,        // next(found) iterator
        return_prior,       // prior(found) iterator
        return_begin_found, // [begin, found) range (*)
        return_begin_next,  // [begin, next(found)) range
        return_begin_prior, // [begin, prior(found)) range
        return_found_end,   // [found, end) range (*)
        return_next_end,    // [next(found), end) range
        return_prior_end,   // [prior(found), end) range
        return_begin_end    // [begin, end) range
    };

    template< class SinglePassRange, range_return_value >
    struct range_return
    {
        typedef boost_kahypar::iterator_range<
            BOOST_DEDUCED_TYPENAME range_iterator<SinglePassRange>::type > type;

        static type pack(BOOST_DEDUCED_TYPENAME range_iterator<SinglePassRange>::type found,
                         SinglePassRange& rng)
        {
            return type(found, boost_kahypar::end(rng));
        }
    };

    template< class SinglePassRange >
    struct range_return< SinglePassRange, return_found >
    {
        typedef BOOST_DEDUCED_TYPENAME range_iterator<SinglePassRange>::type type;

        static type pack(type found, SinglePassRange&)
        {
            return found;
        }
    };

    template< class SinglePassRange >
    struct range_return< SinglePassRange, return_next >
    {
        typedef BOOST_DEDUCED_TYPENAME range_iterator<SinglePassRange>::type type;

        static type pack(type found, SinglePassRange& rng)
        {
            return found == boost_kahypar::end(rng)
                ? found
                : boost_kahypar::next(found);
        }
    };

    template< class BidirectionalRange >
    struct range_return< BidirectionalRange, return_prior >
    {
        typedef BOOST_DEDUCED_TYPENAME range_iterator<BidirectionalRange>::type type;

        static type pack(type found, BidirectionalRange& rng)
        {
            return found == boost_kahypar::begin(rng)
                ? found
                : boost_kahypar::prior(found);
        }
    };

    template< class SinglePassRange >
    struct range_return< SinglePassRange, return_begin_found >
    {
        typedef boost_kahypar::iterator_range<
            BOOST_DEDUCED_TYPENAME range_iterator<SinglePassRange>::type > type;

        static type pack(BOOST_DEDUCED_TYPENAME range_iterator<SinglePassRange>::type found,
                         SinglePassRange& rng)
        {
            return type(boost_kahypar::begin(rng), found);
        }
    };

    template< class SinglePassRange >
    struct range_return< SinglePassRange, return_begin_next >
    {
        typedef boost_kahypar::iterator_range<
            BOOST_DEDUCED_TYPENAME range_iterator<SinglePassRange>::type > type;

        static type pack(BOOST_DEDUCED_TYPENAME range_iterator<SinglePassRange>::type found,
                         SinglePassRange& rng)
        {
            return type( boost_kahypar::begin(rng), 
                         found == boost_kahypar::end(rng) ? found : boost_kahypar::next(found) );
        }
    };

    template< class BidirectionalRange >
    struct range_return< BidirectionalRange, return_begin_prior >
    {
        typedef boost_kahypar::iterator_range<
            BOOST_DEDUCED_TYPENAME range_iterator<BidirectionalRange>::type > type;

        static type pack(BOOST_DEDUCED_TYPENAME range_iterator<BidirectionalRange>::type found,
                         BidirectionalRange& rng)
        {
            return type( boost_kahypar::begin(rng),
                         found == boost_kahypar::begin(rng) ? found : boost_kahypar::prior(found) );
        }
    };

    template< class SinglePassRange >
    struct range_return< SinglePassRange, return_found_end >
    {
        typedef boost_kahypar::iterator_range<
            BOOST_DEDUCED_TYPENAME range_iterator<SinglePassRange>::type > type;

        static type pack(BOOST_DEDUCED_TYPENAME range_iterator<SinglePassRange>::type found,
                         SinglePassRange& rng)
        {
            return type(found, boost_kahypar::end(rng));
        }
    };

    template< class SinglePassRange >
    struct range_return< SinglePassRange, return_next_end >
    {
        typedef boost_kahypar::iterator_range<
            BOOST_DEDUCED_TYPENAME range_iterator<SinglePassRange>::type > type;

        static type pack(BOOST_DEDUCED_TYPENAME range_iterator<SinglePassRange>::type found,
                         SinglePassRange& rng)
        {
            return type( found == boost_kahypar::end(rng) ? found : boost_kahypar::next(found),
                         boost_kahypar::end(rng) );
        }
    };

    template< class BidirectionalRange >
    struct range_return< BidirectionalRange, return_prior_end >
    {
        typedef boost_kahypar::iterator_range<
            BOOST_DEDUCED_TYPENAME range_iterator<BidirectionalRange>::type > type;

        static type pack(BOOST_DEDUCED_TYPENAME range_iterator<BidirectionalRange>::type found,
                         BidirectionalRange& rng)
        {
            return type( found == boost_kahypar::begin(rng) ? found : boost_kahypar::prior(found),
                         boost_kahypar::end(rng) );
        }
    };

    template< class SinglePassRange >
    struct range_return< SinglePassRange, return_begin_end >
    {
        typedef boost_kahypar::iterator_range<
            BOOST_DEDUCED_TYPENAME range_iterator<SinglePassRange>::type > type;

        static type pack(BOOST_DEDUCED_TYPENAME range_iterator<SinglePassRange>::type,
                         SinglePassRange& rng)
        {
            return type(boost_kahypar::begin(rng), boost_kahypar::end(rng));
        }
    };

}

#endif // include guard
