// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2006. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//

#ifndef BOOST_RANGE_CATEGORY_HPP
#define BOOST_RANGE_CATEGORY_HPP

#if defined(_MSC_VER)
# pragma once
#endif

#include <boost_kahypar/range/config.hpp>
#include <boost_kahypar/range/iterator.hpp>
#include <boost_kahypar/iterator/iterator_traits.hpp>

namespace boost_kahypar
{
    template< class T >
    struct range_category : iterator_category< typename range_iterator<T>::type >
    { };
}

#endif
