// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//

#ifndef BOOST_RANGE_EMPTY_HPP
#define BOOST_RANGE_EMPTY_HPP

#if defined(_MSC_VER)
# pragma once
#endif

#include <boost_kahypar/range/config.hpp>
#include <boost_kahypar/range/begin.hpp>
#include <boost_kahypar/range/end.hpp>

namespace boost_kahypar 
{ 

    template< class T >
    inline bool empty( const T& r )
    {
        return boost_kahypar::begin( r ) == boost_kahypar::end( r );
    }

} // namespace 'boost'


#endif
