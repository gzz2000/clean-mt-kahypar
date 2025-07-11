//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2012-2012.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/move for documentation.
//
//////////////////////////////////////////////////////////////////////////////

//! \file
//! This header defines core utilities to ease the development
//! of move-aware functions. This header minimizes dependencies
//! from other libraries.

#ifndef BOOST_MOVE_MOVE_UTILITY_CORE_HPP
#define BOOST_MOVE_MOVE_UTILITY_CORE_HPP

#ifndef BOOST_CONFIG_HPP
#  include <boost_kahypar/config.hpp>
#endif
#
#if defined(BOOST_HAS_PRAGMA_ONCE)
#  pragma once
#endif

#include <boost_kahypar/move/detail/config_begin.hpp>
#include <boost_kahypar/move/detail/workaround.hpp>  //forceinline
#include <boost_kahypar/move/core.hpp>
#include <boost_kahypar/move/detail/meta_utils.hpp>

#if defined(BOOST_NO_CXX11_RVALUE_REFERENCES) && !defined(BOOST_MOVE_DOXYGEN_INVOKED)

   namespace boost_kahypar {

   template<class T>
   struct enable_move_utility_emulation
   {
      static const bool value = true;
   };
    
   //////////////////////////////////////////////////////////////////////////////
   //
   //                            move()
   //
   //////////////////////////////////////////////////////////////////////////////

   template <class T>
   BOOST_MOVE_FORCEINLINE typename ::boost_kahypar::move_detail::enable_if_and
      < T &
      , enable_move_utility_emulation<T>
      , has_move_emulation_disabled<T>
      >::type
         move(T& x) BOOST_NOEXCEPT
   {
      return x;
   }

   template <class T>
   BOOST_MOVE_FORCEINLINE typename ::boost_kahypar::move_detail::enable_if_and
      < rv<T>&
      , enable_move_utility_emulation<T>
      , has_move_emulation_enabled<T>
      >::type
         move(T& x) BOOST_NOEXCEPT
   {
      return *BOOST_MOVE_TO_RV_CAST(::boost_kahypar::rv<T>*, ::boost_kahypar::move_detail::addressof(x) );
   }

   template <class T>
   BOOST_MOVE_FORCEINLINE typename ::boost_kahypar::move_detail::enable_if_and
      < rv<T>&
      , enable_move_utility_emulation<T>
      , has_move_emulation_enabled<T>
      >::type
         move(rv<T>& x) BOOST_NOEXCEPT
   {
      return x;
   }

   //////////////////////////////////////////////////////////////////////////////
   //
   //                            forward()
   //
   //////////////////////////////////////////////////////////////////////////////

   template <class T>
   BOOST_MOVE_FORCEINLINE typename ::boost_kahypar::move_detail::enable_if_and
      < T &
      , enable_move_utility_emulation<T>
      , ::boost_kahypar::move_detail::is_rv<T>
      >::type
         forward(const typename ::boost_kahypar::move_detail::identity<T>::type &x) BOOST_NOEXCEPT
   {
      return const_cast<T&>(x);
   }

   template <class T>
   BOOST_MOVE_FORCEINLINE typename ::boost_kahypar::move_detail::enable_if_and
      < const T &
      , enable_move_utility_emulation<T>
      , ::boost_kahypar::move_detail::is_not_rv<T>
      >::type
         forward(const typename ::boost_kahypar::move_detail::identity<T>::type &x) BOOST_NOEXCEPT
   {
      return x;
   }

   //////////////////////////////////////////////////////////////////////////////
   //
   //                        move_if_not_lvalue_reference()
   //
   //////////////////////////////////////////////////////////////////////////////

   template <class T>
   BOOST_MOVE_FORCEINLINE typename ::boost_kahypar::move_detail::enable_if_and
      < T &
      , enable_move_utility_emulation<T>
      , ::boost_kahypar::move_detail::is_rv<T>
      >::type
         move_if_not_lvalue_reference(const typename ::boost_kahypar::move_detail::identity<T>::type &x) BOOST_NOEXCEPT
   {
      return const_cast<T&>(x);
   }

   template <class T>
   BOOST_MOVE_FORCEINLINE typename ::boost_kahypar::move_detail::enable_if_and
      < typename ::boost_kahypar::move_detail::add_lvalue_reference<T>::type
      , enable_move_utility_emulation<T>
      , ::boost_kahypar::move_detail::is_not_rv<T>
      , ::boost_kahypar::move_detail::or_
         < ::boost_kahypar::move_detail::is_lvalue_reference<T>
         , has_move_emulation_disabled<T>
         >
      >::type
         move_if_not_lvalue_reference(typename ::boost_kahypar::move_detail::remove_reference<T>::type &x) BOOST_NOEXCEPT
   {
      return x;
   }

   template <class T>
   BOOST_MOVE_FORCEINLINE typename ::boost_kahypar::move_detail::enable_if_and
      < rv<T>&
      , enable_move_utility_emulation<T>
      , ::boost_kahypar::move_detail::is_not_rv<T>
      , ::boost_kahypar::move_detail::and_
         < ::boost_kahypar::move_detail::not_< ::boost_kahypar::move_detail::is_lvalue_reference<T> >
         , has_move_emulation_enabled<T>
         >
      >::type
         move_if_not_lvalue_reference(typename ::boost_kahypar::move_detail::remove_reference<T>::type &x) BOOST_NOEXCEPT
   {
      return move(x);
   }

   }  //namespace boost_kahypar

#else    //#if defined(BOOST_NO_CXX11_RVALUE_REFERENCES) && !defined(BOOST_MOVE_DOXYGEN_INVOKED)

   #if defined(BOOST_MOVE_USE_STANDARD_LIBRARY_MOVE)
      #include <utility>

      namespace boost_kahypar{

      using ::std::move;
      using ::std::forward;

      }  //namespace boost_kahypar

   #else //!BOOST_MOVE_USE_STANDARD_LIBRARY_MOVE

      namespace boost_kahypar {

      //! This trait's internal boolean `value` is false in compilers with rvalue references
      //! and true in compilers without rvalue references.
      //!
      //! A user can specialize this trait for a type T to false to SFINAE out `move` and `forward`
      //! so that the user can define a different move emulation for that type in namespace boost_kahypar
      //! (e.g. another Boost library for its types) and avoid any overload ambiguity.
      template<class T>
      struct enable_move_utility_emulation
      {
         static const bool value = false;
      };

      //////////////////////////////////////////////////////////////////////////////
      //
      //                                  move
      //
      //////////////////////////////////////////////////////////////////////////////

      #if defined(BOOST_MOVE_DOXYGEN_INVOKED)
         //! This function provides a way to convert a reference into a rvalue reference
         //! in compilers with rvalue references. For other compilers if `T` is Boost.Move
         //! enabled type then it converts `T&` into <tt>::boost_kahypar::rv<T> &</tt> so that
         //! move emulation is activated, else it returns `T &`.
         template <class T>
         rvalue_reference move(input_reference) noexcept;

      #elif defined(BOOST_MOVE_OLD_RVALUE_REF_BINDING_RULES)

         //Old move approach, lvalues could bind to rvalue references
         template <class T>
         BOOST_MOVE_FORCEINLINE typename ::boost_kahypar::move_detail::remove_reference<T>::type && move(T&& t) BOOST_NOEXCEPT
         {  return t;   }

      #else //BOOST_MOVE_OLD_RVALUE_REF_BINDING_RULES

         template <class T>
         BOOST_MOVE_INTRINSIC_CAST
         typename ::boost_kahypar::move_detail::remove_reference<T>::type && move(T&& t) BOOST_NOEXCEPT
         { return static_cast<typename ::boost_kahypar::move_detail::remove_reference<T>::type &&>(t); }

      #endif   //BOOST_MOVE_OLD_RVALUE_REF_BINDING_RULES

      //////////////////////////////////////////////////////////////////////////////
      //
      //                                  forward
      //
      //////////////////////////////////////////////////////////////////////////////


      #if defined(BOOST_MOVE_DOXYGEN_INVOKED)
         //! This function provides limited form of forwarding that is usually enough for
         //! in-place construction and avoids the exponential overloading for
         //! achieve the limited forwarding in C++03.
         //!
         //! For compilers with rvalue references this function provides perfect forwarding.
         //!
         //! Otherwise:
         //! * If input_reference binds to const ::boost_kahypar::rv<T> & then it output_reference is
         //!   ::boost_kahypar::rv<T> &
         //!
         //! * Else, output_reference is equal to input_reference.
         template <class T> output_reference forward(input_reference) noexcept;
      #elif defined(BOOST_MOVE_OLD_RVALUE_REF_BINDING_RULES)

         //Old move approach, lvalues could bind to rvalue references

         template <class T>
         BOOST_MOVE_FORCEINLINE T&& forward(typename ::boost_kahypar::move_detail::identity<T>::type&& t) BOOST_NOEXCEPT
         {  return t;   }

      #else //Old move

         template <class T>
         BOOST_MOVE_INTRINSIC_CAST
         T&& forward(typename ::boost_kahypar::move_detail::remove_reference<T>::type& t) BOOST_NOEXCEPT
         {  return static_cast<T&&>(t);   }

         template <class T>
         BOOST_MOVE_INTRINSIC_CAST
         T&& forward(typename ::boost_kahypar::move_detail::remove_reference<T>::type&& t) BOOST_NOEXCEPT
         {
            //"boost_kahypar::forward<T> error: 'T' is a lvalue reference, can't forward as rvalue.";
            BOOST_MOVE_STATIC_ASSERT(!boost_kahypar::move_detail::is_lvalue_reference<T>::value);
            return static_cast<T&&>(t);
         }

      #endif   //BOOST_MOVE_DOXYGEN_INVOKED

      }  //namespace boost_kahypar {

   #endif   //BOOST_MOVE_USE_STANDARD_LIBRARY_MOVE

   //////////////////////////////////////////////////////////////////////////////
   //
   //                         move_if_not_lvalue_reference
   //
   //////////////////////////////////////////////////////////////////////////////

   namespace boost_kahypar {

   #if defined(BOOST_MOVE_DOXYGEN_INVOKED)
      //! <b>Effects</b>: Calls `boost_kahypar::move` if `input_reference` is not a lvalue reference.
      //!   Otherwise returns the reference
      template <class T> output_reference move_if_not_lvalue_reference(input_reference) noexcept;
   #elif defined(BOOST_MOVE_OLD_RVALUE_REF_BINDING_RULES)

      //Old move approach, lvalues could bind to rvalue references

      template <class T>
      BOOST_MOVE_FORCEINLINE T&& move_if_not_lvalue_reference(typename ::boost_kahypar::move_detail::identity<T>::type&& t) BOOST_NOEXCEPT
      {  return t;   }

   #else //Old move

      template <class T>
      BOOST_MOVE_FORCEINLINE T&& move_if_not_lvalue_reference(typename ::boost_kahypar::move_detail::remove_reference<T>::type& t) BOOST_NOEXCEPT
      {  return static_cast<T&&>(t);   }

      template <class T>
      BOOST_MOVE_FORCEINLINE T&& move_if_not_lvalue_reference(typename ::boost_kahypar::move_detail::remove_reference<T>::type&& t) BOOST_NOEXCEPT
      {
         //"boost_kahypar::forward<T> error: 'T' is a lvalue reference, can't forward as rvalue.";
         BOOST_MOVE_STATIC_ASSERT(!boost_kahypar::move_detail::is_lvalue_reference<T>::value);
         return static_cast<T&&>(t);
      }

   #endif   //BOOST_MOVE_DOXYGEN_INVOKED

   }  //namespace boost_kahypar {

#endif   //BOOST_NO_CXX11_RVALUE_REFERENCES

#if !defined(BOOST_MOVE_DOXYGEN_INVOKED)

namespace boost_kahypar{
namespace move_detail{

template <typename T>
typename boost_kahypar::move_detail::add_rvalue_reference<T>::type declval();

}  //namespace move_detail{
}  //namespace boost_kahypar{

#endif   //#if !defined(BOOST_MOVE_DOXYGEN_INVOKED)


#include <boost_kahypar/move/detail/config_end.hpp>

#endif //#ifndef BOOST_MOVE_MOVE_UTILITY_CORE_HPP
