
#ifndef BOOST_MPL_VECTOR_VECTOR10_C_HPP_INCLUDED
#define BOOST_MPL_VECTOR_VECTOR10_C_HPP_INCLUDED

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

#if !defined(BOOST_MPL_PREPROCESSING_MODE)
#   include <boost_kahypar/mpl/vector/vector0_c.hpp>
#   include <boost_kahypar/mpl/vector/vector10.hpp>
#endif

#include <boost_kahypar/mpl/aux_/config/use_preprocessed.hpp>

#if !defined(BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS) \
    && !defined(BOOST_MPL_PREPROCESSING_MODE)

#   define BOOST_MPL_PREPROCESSED_HEADER vector10_c.hpp
#   include <boost_kahypar/mpl/vector/aux_/include_preprocessed.hpp>

#else

#   include <boost_kahypar/mpl/aux_/config/typeof.hpp>
#   include <boost_kahypar/mpl/aux_/config/ctps.hpp>
#   include <boost_kahypar/preprocessor/iterate.hpp>

namespace boost_kahypar { namespace mpl {

#   define BOOST_PP_ITERATION_PARAMS_1 \
    (3,(1, 10, <boost_kahypar/mpl/vector/aux_/numbered_c.hpp>))
#   include BOOST_PP_ITERATE()

}}

#endif // BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS

#endif // BOOST_MPL_VECTOR_VECTOR10_C_HPP_INCLUDED
