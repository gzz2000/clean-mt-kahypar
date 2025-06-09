//  Copyright Neil Groves 2014. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
#ifndef BOOST_RANGE_DETAIL_COMBINE_CXX11_HPP
#define BOOST_RANGE_DETAIL_COMBINE_CXX11_HPP

#include <boost_kahypar/range/iterator_range_core.hpp>
#include <boost_kahypar/range/iterator.hpp>
#include <boost_kahypar/range/begin.hpp>
#include <boost_kahypar/range/end.hpp>
#include <boost_kahypar/iterator/zip_iterator.hpp>

namespace boost_kahypar
{
    namespace range
    {

template<typename... Ranges>
auto combine(Ranges&&... rngs) ->
    combined_range<decltype(boost_kahypar::make_tuple(boost_kahypar::begin(rngs)...))>
{
    return combined_range<decltype(boost_kahypar::make_tuple(boost_kahypar::begin(rngs)...))>(
                boost_kahypar::make_tuple(boost_kahypar::begin(rngs)...),
                boost_kahypar::make_tuple(boost_kahypar::end(rngs)...));
}

    } // namespace range

using range::combine;

} // namespace boost_kahypar

#endif // include guard
