//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2014-2015. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/container for documentation.
//
//////////////////////////////////////////////////////////////////////////////
#ifndef BOOST_MOVE_DETAIL_ITERATOR_TO_RAW_POINTER_HPP
#define BOOST_MOVE_DETAIL_ITERATOR_TO_RAW_POINTER_HPP

#ifndef BOOST_CONFIG_HPP
#  include <boost_kahypar/config.hpp>
#endif

#if defined(BOOST_HAS_PRAGMA_ONCE)
#  pragma once
#endif

#include <boost_kahypar/move/detail/iterator_traits.hpp>
#include <boost_kahypar/move/detail/to_raw_pointer.hpp>
#include <boost_kahypar/move/detail/pointer_element.hpp>

namespace boost_kahypar {
namespace movelib {
namespace detail {

template <class T>
inline T* iterator_to_pointer(T* i)
{  return i; }

template <class Iterator>
inline typename boost_kahypar::movelib::iterator_traits<Iterator>::pointer
   iterator_to_pointer(const Iterator &i)
{  return i.operator->();  }

template <class Iterator>
struct iterator_to_element_ptr
{
   typedef typename boost_kahypar::movelib::iterator_traits<Iterator>::pointer  pointer;
   typedef typename boost_kahypar::movelib::pointer_element<pointer>::type      element_type;
   typedef element_type* type;
};

}  //namespace detail {

template <class Iterator>
inline typename boost_kahypar::movelib::detail::iterator_to_element_ptr<Iterator>::type
   iterator_to_raw_pointer(const Iterator &i)
{
   return ::boost_kahypar::movelib::to_raw_pointer
      (  ::boost_kahypar::movelib::detail::iterator_to_pointer(i)   );
}

}  //namespace movelib {
}  //namespace boost_kahypar {

#endif   //#ifndef BOOST_MOVE_DETAIL_ITERATOR_TO_RAW_POINTER_HPP
