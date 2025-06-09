
//  (C) Copyright John Maddock 2015.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef BOOST_TT_IS_DESTRUCTIBLE_HPP_INCLUDED
#define BOOST_TT_IS_DESTRUCTIBLE_HPP_INCLUDED

#include <cstddef> // size_t
#include <boost_kahypar/type_traits/integral_constant.hpp>
#include <boost_kahypar/detail/workaround.hpp>
#include <boost_kahypar/type_traits/is_complete.hpp>
#include <boost_kahypar/static_assert.hpp>

#if !defined(BOOST_NO_CXX11_DECLTYPE) && !BOOST_WORKAROUND(BOOST_MSVC, < 1800)

#include <boost_kahypar/type_traits/detail/yes_no_type.hpp>
#include <boost_kahypar/type_traits/declval.hpp>

namespace boost_kahypar{

   namespace detail{

      struct is_destructible_imp
      {
         template<typename T, typename = decltype(boost_kahypar::declval<T&>().~T())>
         static boost_kahypar::type_traits::yes_type test(int);
         template<typename>
         static boost_kahypar::type_traits::no_type test(...);
      };

   }

   template <class T> struct is_destructible : public integral_constant<bool, sizeof(boost_kahypar::detail::is_destructible_imp::test<T>(0)) == sizeof(boost_kahypar::type_traits::yes_type)>
   {
      BOOST_STATIC_ASSERT_MSG(boost_kahypar::is_complete<T>::value, "Arguments to is_destructible must be complete types");
   };

#else

#include <boost_kahypar/type_traits/is_pod.hpp>
#include <boost_kahypar/type_traits/is_class.hpp>

namespace boost_kahypar{

   // We don't know how to implement this:
   template <class T> struct is_destructible : public integral_constant<bool, is_pod<T>::value || is_class<T>::value>
   {
      BOOST_STATIC_ASSERT_MSG(boost_kahypar::is_complete<T>::value, "Arguments to is_destructible must be complete types");
   };
#endif

   template <> struct is_destructible<void> : public false_type{};
   template <> struct is_destructible<void const> : public false_type{};
   template <> struct is_destructible<void volatile> : public false_type{};
   template <> struct is_destructible<void const volatile> : public false_type{};
   template <class T> struct is_destructible<T&> : public is_destructible<T>{};
#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
   template <class T> struct is_destructible<T&&> : public is_destructible<T>{};
#endif
   template <class T, std::size_t N> struct is_destructible<T[N]> : public is_destructible<T>{};
   template <class T> struct is_destructible<T[]> : public is_destructible<T>{};

} // namespace boost_kahypar

#endif // BOOST_TT_IS_DESTRUCTIBLE_HPP_INCLUDED
