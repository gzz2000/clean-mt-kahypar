// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//

#ifndef BOOST_RANGE_DIFFERENCE_TYPE_HPP
#define BOOST_RANGE_DIFFERENCE_TYPE_HPP

#if defined(_MSC_VER)
# pragma once
#endif

#include <boost_kahypar/mpl/and.hpp>
#include <boost_kahypar/range/config.hpp>
#include <boost_kahypar/range/iterator.hpp>
#include <boost_kahypar/range/has_range_iterator.hpp>
#include <boost_kahypar/iterator/iterator_traits.hpp>
#include <boost_kahypar/type_traits/remove_reference.hpp>

namespace boost_kahypar
{
    namespace range_detail
    {
        template< class T, bool B = has_type<range_iterator<T> >::value >
        struct range_difference
        { };

        template< class T >
        struct range_difference<T, true>
          : iterator_difference<
                BOOST_DEDUCED_TYPENAME range_iterator<T>::type
            >
        { };
    }

    template< class T >
    struct range_difference
      : range_detail::range_difference<BOOST_DEDUCED_TYPENAME remove_reference<T>::type>
    { };
}

#endif
