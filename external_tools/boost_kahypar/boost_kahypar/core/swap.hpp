// Copyright (C) 2007, 2008 Steven Watanabe, Joseph Gauterin, Niels Dekker
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
// For more information, see http://www.boost.org


#ifndef BOOST_CORE_SWAP_HPP
#define BOOST_CORE_SWAP_HPP

// Note: the implementation of this utility contains various workarounds:
// - boost_kahypar::swap has two template arguments, instead of one, to
// avoid ambiguity when swapping objects of a Boost type that does
// not have its own boost_kahypar::swap overload.

#include <boost_kahypar/core/enable_if.hpp>
#include <boost_kahypar/config.hpp>
#include <boost_kahypar/config/header_deprecated.hpp>
#include <boost_kahypar/core/invoke_swap.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

BOOST_HEADER_DEPRECATED("boost_kahypar/core/invoke_swap.hpp")

namespace boost_kahypar
{
  template<class T1, class T2>
  BOOST_GPU_ENABLED
  BOOST_DEPRECATED("This function is deprecated, use boost_kahypar::core::invoke_swap instead.")
  inline typename enable_if_c< !boost_kahypar_swap_impl::is_const<T1>::value && !boost_kahypar_swap_impl::is_const<T2>::value >::type
  swap(T1& left, T2& right)
  {
    boost_kahypar::core::invoke_swap(left, right);
  }
}

#endif // BOOST_CORE_SWAP_HPP
