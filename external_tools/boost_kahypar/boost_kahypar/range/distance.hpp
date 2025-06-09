// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2006. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//

#ifndef BOOST_RANGE_DISTANCE_HPP
#define BOOST_RANGE_DISTANCE_HPP

#if defined(_MSC_VER)
# pragma once
#endif

#include <boost_kahypar/iterator/distance.hpp>
#include <boost_kahypar/range/begin.hpp>
#include <boost_kahypar/range/end.hpp>
#include <boost_kahypar/range/difference_type.hpp>

namespace boost_kahypar
{

    namespace range_distance_adl_barrier
    {
        template< class T >
        inline BOOST_CXX14_CONSTEXPR BOOST_DEDUCED_TYPENAME range_difference<T>::type
        distance( const T& r )
        {
            return boost_kahypar::iterators::distance( boost_kahypar::begin( r ), boost_kahypar::end( r ) );
        }
    }

    using namespace range_distance_adl_barrier;

} // namespace 'boost'

#endif
