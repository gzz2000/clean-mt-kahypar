
#ifndef BOOST_MPL_VECTOR_AUX_PUSH_BACK_HPP_INCLUDED
#define BOOST_MPL_VECTOR_AUX_PUSH_BACK_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <boost_kahypar/mpl/push_back_fwd.hpp>
#include <boost_kahypar/mpl/aux_/config/typeof.hpp>

#if defined(BOOST_MPL_CFG_TYPEOF_BASED_SEQUENCES)

#   include <boost_kahypar/mpl/vector/aux_/item.hpp>
#   include <boost_kahypar/mpl/vector/aux_/tag.hpp>

namespace boost_kahypar { namespace mpl {

template<>
struct push_back_impl< aux::vector_tag >
{
    template< typename Vector, typename T > struct apply
    {
        typedef v_item<T,Vector,0> type;
    };
};

}}

#endif 

#endif // BOOST_MPL_VECTOR_AUX_PUSH_BACK_HPP_INCLUDED
