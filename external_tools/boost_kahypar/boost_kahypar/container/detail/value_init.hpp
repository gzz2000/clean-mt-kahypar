//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2005-2013.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/container for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef BOOST_CONTAINER_DETAIL_VALUE_INIT_HPP
#define BOOST_CONTAINER_DETAIL_VALUE_INIT_HPP

#ifndef BOOST_CONFIG_HPP
#  include <boost_kahypar/config.hpp>
#endif

#if defined(BOOST_HAS_PRAGMA_ONCE)
#  pragma once
#endif

#include <boost_kahypar/container/detail/config_begin.hpp>
#include <boost_kahypar/container/detail/workaround.hpp>

namespace boost_kahypar {
namespace container {
namespace dtl {

template<class T>
struct value_init
{
   BOOST_CONTAINER_FORCEINLINE value_init()
      : m_t()
   {}

   BOOST_CONTAINER_FORCEINLINE operator T &() { return m_t; }

   BOOST_CONTAINER_FORCEINLINE T &get() { return m_t; }

   T m_t;
};

}  //namespace dtl {
}  //namespace container {
}  //namespace boost_kahypar {

#include <boost_kahypar/container/detail/config_end.hpp>

#endif   //#ifndef BOOST_CONTAINER_DETAIL_VALUE_INIT_HPP
