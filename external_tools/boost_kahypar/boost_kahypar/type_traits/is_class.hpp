//  (C) Copyright Dave Abrahams, Steve Cleary, Beman Dawes, Howard
//  Hinnant & John Maddock 2000-2003.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.


#ifndef BOOST_TT_IS_CLASS_HPP_INCLUDED
#define BOOST_TT_IS_CLASS_HPP_INCLUDED

#include <boost_kahypar/type_traits/detail/config.hpp>
#include <boost_kahypar/type_traits/intrinsics.hpp>
#include <boost_kahypar/type_traits/integral_constant.hpp>
#ifndef BOOST_IS_CLASS
#   include <boost_kahypar/type_traits/is_union.hpp>

#ifdef BOOST_TT_HAS_CONFORMING_IS_CLASS_IMPLEMENTATION
#   include <boost_kahypar/type_traits/detail/yes_no_type.hpp>
#else
#   include <boost_kahypar/type_traits/is_scalar.hpp>
#   include <boost_kahypar/type_traits/is_array.hpp>
#   include <boost_kahypar/type_traits/is_reference.hpp>
#   include <boost_kahypar/type_traits/is_void.hpp>
#   include <boost_kahypar/type_traits/is_function.hpp>
#endif

#endif // BOOST_IS_CLASS

namespace boost_kahypar {

namespace detail {

#ifndef BOOST_IS_CLASS
#ifdef BOOST_TT_HAS_CONFORMING_IS_CLASS_IMPLEMENTATION

// This is actually the conforming implementation which works with
// abstract classes.  However, enough compilers have trouble with
// it that most will use the one in
// boost/type_traits/object_traits.hpp. This implementation
// actually works with VC7.0, but other interactions seem to fail
// when we use it.

// is_class<> metafunction due to Paul Mensonides
// (leavings@attbi.com). For more details:
// http://groups.google.com/groups?hl=en&selm=000001c1cc83%24e154d5e0%247772e50c%40c161550a&rnum=1
#if defined(__GNUC__)  && !defined(__EDG_VERSION__)

template <class U> ::boost_kahypar::type_traits::yes_type is_class_tester(void(U::*)(void));
template <class U> ::boost_kahypar::type_traits::no_type is_class_tester(...);

template <typename T>
struct is_class_impl
{

    BOOST_STATIC_CONSTANT(bool, value =
            sizeof(is_class_tester<T>(0)) == sizeof(::boost_kahypar::type_traits::yes_type)
            && ! ::boost_kahypar::is_union<T>::value
        );
};

#else

template <typename T>
struct is_class_impl
{
    template <class U> static ::boost_kahypar::type_traits::yes_type is_class_tester(void(U::*)(void));
    template <class U> static ::boost_kahypar::type_traits::no_type is_class_tester(...);

    BOOST_STATIC_CONSTANT(bool, value =
            sizeof(is_class_tester<T>(0)) == sizeof(::boost_kahypar::type_traits::yes_type)
            && ! ::boost_kahypar::is_union<T>::value
        );
};

#endif

#else

template <typename T>
struct is_class_impl
{
    BOOST_STATIC_CONSTANT(bool, value =
        ! ::boost_kahypar::is_union<T>::value >::value
        && ! ::boost_kahypar::is_scalar<T>::value
        && ! ::boost_kahypar::is_array<T>::value
        && ! ::boost_kahypar::is_reference<T>::value
        && ! ::boost_kahypar::is_void<T>::value
        && ! ::boost_kahypar::is_function<T>::value
        );
};

# endif // BOOST_TT_HAS_CONFORMING_IS_CLASS_IMPLEMENTATION
# else // BOOST_IS_CLASS
template <typename T>
struct is_class_impl
{
    BOOST_STATIC_CONSTANT(bool, value = BOOST_IS_CLASS(T));
};
# endif // BOOST_IS_CLASS

} // namespace detail

template <class T> struct is_class : public integral_constant<bool, ::boost_kahypar::detail::is_class_impl<T>::value> {};
# ifdef __EDG_VERSION__
template <class T> struct is_class<const T> : public is_class<T>{};
template <class T> struct is_class<const volatile T> : public is_class<T>{};
template <class T> struct is_class<volatile T> : public is_class<T>{};
# endif
    
} // namespace boost_kahypar

#endif // BOOST_TT_IS_CLASS_HPP_INCLUDED
