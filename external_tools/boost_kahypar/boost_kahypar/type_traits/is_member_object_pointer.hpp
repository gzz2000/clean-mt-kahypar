
//  (C) Copyright John Maddock 2005.  
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.


#ifndef BOOST_TT_IS_MEMBER_OBJECT_POINTER_HPP_INCLUDED
#define BOOST_TT_IS_MEMBER_OBJECT_POINTER_HPP_INCLUDED

#include <boost_kahypar/type_traits/is_member_pointer.hpp>
#include <boost_kahypar/type_traits/is_member_function_pointer.hpp>

namespace boost_kahypar {

template <class T> struct is_member_object_pointer 
   : public integral_constant<bool, 
   ::boost_kahypar::is_member_pointer<T>::value && !::boost_kahypar::is_member_function_pointer<T>::value>{};

} // namespace boost_kahypar

#endif // BOOST_TT_IS_MEMBER_FUNCTION_POINTER_HPP_INCLUDED
