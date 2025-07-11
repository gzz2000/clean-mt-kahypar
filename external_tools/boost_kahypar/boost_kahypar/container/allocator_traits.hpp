//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Pablo Halpern 2009. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2011-2013. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/container for documentation.
//
//////////////////////////////////////////////////////////////////////////////
#ifndef BOOST_CONTAINER_ALLOCATOR_ALLOCATOR_TRAITS_HPP
#define BOOST_CONTAINER_ALLOCATOR_ALLOCATOR_TRAITS_HPP

#ifndef BOOST_CONFIG_HPP
#  include <boost_kahypar/config.hpp>
#endif

#if defined(BOOST_HAS_PRAGMA_ONCE)
#  pragma once
#endif

#include <boost_kahypar/container/detail/config_begin.hpp>
#include <boost_kahypar/container/detail/workaround.hpp>

// container
#include <boost_kahypar/container/container_fwd.hpp>
#include <boost_kahypar/container/detail/mpl.hpp>
#include <boost_kahypar/container/detail/type_traits.hpp>  //is_empty
#include <boost_kahypar/container/detail/placement_new.hpp>
#include <boost_kahypar/container/detail/is_pair.hpp>
#include <boost_kahypar/container/detail/addressof.hpp>
#ifndef BOOST_CONTAINER_DETAIL_STD_FWD_HPP
#include <boost_kahypar/container/detail/std_fwd.hpp>
#endif
// intrusive
#include <boost_kahypar/intrusive/pointer_traits.hpp>
#include <boost_kahypar/intrusive/detail/mpl.hpp>
// move
#include <boost_kahypar/move/utility_core.hpp>
// move/detail
#if defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
#include <boost_kahypar/move/detail/fwd_macros.hpp>
#endif

#ifndef BOOST_CONTAINER_DOXYGEN_INVOKED

#if defined(BOOST_CONTAINER_GCC_COMPATIBLE_HAS_DIAGNOSTIC_IGNORED)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

#define BOOST_INTRUSIVE_HAS_MEMBER_FUNCTION_CALLABLE_WITH_FUNCNAME allocate
#define BOOST_INTRUSIVE_HAS_MEMBER_FUNCTION_CALLABLE_WITH_NS_BEG namespace boost_kahypar { namespace container { namespace dtl {
#define BOOST_INTRUSIVE_HAS_MEMBER_FUNCTION_CALLABLE_WITH_NS_END   }}}
#define BOOST_INTRUSIVE_HAS_MEMBER_FUNCTION_CALLABLE_WITH_MIN 2
#define BOOST_INTRUSIVE_HAS_MEMBER_FUNCTION_CALLABLE_WITH_MAX 2
#include <boost_kahypar/intrusive/detail/has_member_function_callable_with.hpp>

#define BOOST_INTRUSIVE_HAS_MEMBER_FUNCTION_CALLABLE_WITH_FUNCNAME destroy
#define BOOST_INTRUSIVE_HAS_MEMBER_FUNCTION_CALLABLE_WITH_NS_BEG namespace boost_kahypar { namespace container { namespace dtl {
#define BOOST_INTRUSIVE_HAS_MEMBER_FUNCTION_CALLABLE_WITH_NS_END   }}}
#define BOOST_INTRUSIVE_HAS_MEMBER_FUNCTION_CALLABLE_WITH_MIN 1
#define BOOST_INTRUSIVE_HAS_MEMBER_FUNCTION_CALLABLE_WITH_MAX 1
#include <boost_kahypar/intrusive/detail/has_member_function_callable_with.hpp>

#define BOOST_INTRUSIVE_HAS_MEMBER_FUNCTION_CALLABLE_WITH_FUNCNAME construct
#define BOOST_INTRUSIVE_HAS_MEMBER_FUNCTION_CALLABLE_WITH_NS_BEG namespace boost_kahypar { namespace container { namespace dtl {
#define BOOST_INTRUSIVE_HAS_MEMBER_FUNCTION_CALLABLE_WITH_NS_END   }}}
#define BOOST_INTRUSIVE_HAS_MEMBER_FUNCTION_CALLABLE_WITH_MIN 1
#define BOOST_INTRUSIVE_HAS_MEMBER_FUNCTION_CALLABLE_WITH_MAX 9
#include <boost_kahypar/intrusive/detail/has_member_function_callable_with.hpp>

#if defined(BOOST_CONTAINER_GCC_COMPATIBLE_HAS_DIAGNOSTIC_IGNORED)
#pragma GCC diagnostic pop
#endif

#endif   //#ifndef BOOST_CONTAINER_DOXYGEN_INVOKED

namespace boost_kahypar {
namespace container {
namespace dtl {

#if !defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)

template<class T, class ...Args>
BOOST_CONTAINER_FORCEINLINE void construct_type(T *p, BOOST_FWD_REF(Args) ...args)
{
   ::new((void*)p, boost_container_new_t()) T(::boost_kahypar::forward<Args>(args)...);
}

template < class Pair, class KeyType, class ... Args>
typename dtl::enable_if< dtl::is_pair<Pair>, void >::type
construct_type
   (Pair* p, try_emplace_t, BOOST_FWD_REF(KeyType) k, BOOST_FWD_REF(Args) ...args)
{
   construct_type(dtl::addressof(p->first), ::boost_kahypar::forward<KeyType>(k));
   BOOST_CONTAINER_TRY{
      construct_type(dtl::addressof(p->second), ::boost_kahypar::forward<Args>(args)...);
   }
   BOOST_CONTAINER_CATCH(...) {
      typedef typename Pair::first_type first_type;
      dtl::addressof(p->first)->~first_type();
      BOOST_CONTAINER_RETHROW
   }
   BOOST_CONTAINER_CATCH_END
}

#else

#define BOOST_CONTAINER_ALLOCATOR_TRAITS_CONSTRUCT_TYPEJ(N) \
template<class T BOOST_MOVE_I##N BOOST_MOVE_CLASS##N>\
BOOST_CONTAINER_FORCEINLINE \
   typename dtl::disable_if_c<dtl::is_pair<T>::value, void >::type \
construct_type(T *p BOOST_MOVE_I##N BOOST_MOVE_UREF##N)\
{\
   ::new((void*)p, boost_container_new_t()) T( BOOST_MOVE_FWD##N );\
}\
//
BOOST_MOVE_ITERATE_0TO8(BOOST_CONTAINER_ALLOCATOR_TRAITS_CONSTRUCT_TYPEJ)
#undef BOOST_CONTAINER_ALLOCATOR_TRAITS_CONSTRUCT_TYPEJ

#define BOOST_CONTAINER_ALLOCATOR_TRAITS_CONSTRUCT_TYPE(N) \
template < class Pair, class KeyType BOOST_MOVE_I##N BOOST_MOVE_CLASS##N>\
typename dtl::enable_if< dtl::is_pair<Pair>, void >::type construct_type\
   (Pair* p, try_emplace_t, BOOST_FWD_REF(KeyType) k BOOST_MOVE_I##N BOOST_MOVE_UREF##N)\
{\
   construct_type(dtl::addressof(p->first), ::boost_kahypar::forward<KeyType>(k));\
   BOOST_CONTAINER_TRY{\
      construct_type(dtl::addressof(p->second) BOOST_MOVE_I##N BOOST_MOVE_FWD##N);\
   }\
   BOOST_CONTAINER_CATCH(...) {\
      typedef typename Pair::first_type first_type;\
      dtl::addressof(p->first)->~first_type();\
      BOOST_CONTAINER_RETHROW\
   }\
   BOOST_CONTAINER_CATCH_END\
}\
//
BOOST_MOVE_ITERATE_0TO8(BOOST_CONTAINER_ALLOCATOR_TRAITS_CONSTRUCT_TYPE)
#undef BOOST_CONTAINER_ALLOCATOR_TRAITS_CONSTRUCT_TYPE

#endif

template<class T>
inline
typename dtl::enable_if<dtl::is_pair<T>, void >::type
construct_type(T* p)
{
   dtl::construct_type(dtl::addressof(p->first));
   BOOST_CONTAINER_TRY{
      dtl::construct_type(dtl::addressof(p->second));
   }
   BOOST_CONTAINER_CATCH(...) {
      typedef typename T::first_type first_type;
      dtl::addressof(p->first)->~first_type();
      BOOST_CONTAINER_RETHROW
   }
   BOOST_CONTAINER_CATCH_END
}


template<class T, class U>
inline
typename dtl::enable_if_c
   <  dtl::is_pair<T>::value
   , void >::type
construct_type(T* p, U &u)
{
   dtl::construct_type(dtl::addressof(p->first), u.first);
   BOOST_CONTAINER_TRY{
      dtl::construct_type(dtl::addressof(p->second), u.second);
   }
   BOOST_CONTAINER_CATCH(...) {
      typedef typename T::first_type first_type;
      dtl::addressof(p->first)->~first_type();
      BOOST_CONTAINER_RETHROW
   }
   BOOST_CONTAINER_CATCH_END
}

template<class T, class U>
inline
typename dtl::enable_if_c
   <  dtl::is_pair<typename dtl::remove_reference<T>::type>::value &&
      !boost_kahypar::move_detail::is_reference<U>::value  //This is needed for MSVC10 and ambiguous overloads
   , void >::type
construct_type(T* p, BOOST_RV_REF(U) u)
{
   dtl::construct_type(dtl::addressof(p->first), ::boost_kahypar::move(u.first));
   BOOST_CONTAINER_TRY{
      dtl::construct_type(dtl::addressof(p->second), ::boost_kahypar::move(u.second));
   }
   BOOST_CONTAINER_CATCH(...) {
      typedef typename T::first_type first_type;
      dtl::addressof(p->first)->~first_type();
      BOOST_CONTAINER_RETHROW
   }
   BOOST_CONTAINER_CATCH_END
}

template<class T, class U, class V>
inline
typename dtl::enable_if<dtl::is_pair<T>, void >::type
construct_type(T* p, BOOST_FWD_REF(U) x, BOOST_FWD_REF(V) y)
{
   dtl::construct_type(dtl::addressof(p->first), ::boost_kahypar::forward<U>(x));
   BOOST_CONTAINER_TRY{
      dtl::construct_type(dtl::addressof(p->second), ::boost_kahypar::forward<V>(y));
   }
   BOOST_CONTAINER_CATCH(...) {
      typedef typename T::first_type first_type;
      dtl::addressof(p->first)->~first_type();
      BOOST_CONTAINER_RETHROW
   }
   BOOST_CONTAINER_CATCH_END
}

}  //namespace dtl

#ifndef BOOST_CONTAINER_DOXYGEN_INVOKED

template<class T, class VoidAllocator, class Options>
class small_vector_allocator;

namespace allocator_traits_detail {

BOOST_INTRUSIVE_HAS_STATIC_MEMBER_FUNC_SIGNATURE(has_max_size, max_size)
BOOST_INTRUSIVE_HAS_STATIC_MEMBER_FUNC_SIGNATURE(has_select_on_container_copy_construction, select_on_container_copy_construction)

}  //namespace allocator_traits_detail {

namespace dtl {

//workaround needed for C++03 compilers with no construct()
//supporting rvalue references
template<class Allocator>
struct is_std_allocator
{  BOOST_STATIC_CONSTEXPR bool value = false; };

template<class T>
struct is_std_allocator< std::allocator<T> >
{  BOOST_STATIC_CONSTEXPR bool value = true; };

template<class T, class Options>
struct is_std_allocator< small_vector_allocator<T, std::allocator<T>, Options > >
{  BOOST_STATIC_CONSTEXPR bool value = true; };

template<class Allocator>
struct is_not_std_allocator
{  BOOST_STATIC_CONSTEXPR bool value = !is_std_allocator<Allocator>::value; };

BOOST_INTRUSIVE_INSTANTIATE_DEFAULT_TYPE_TMPLT(pointer)
BOOST_INTRUSIVE_INSTANTIATE_EVAL_DEFAULT_TYPE_TMPLT(const_pointer)
BOOST_INTRUSIVE_INSTANTIATE_DEFAULT_TYPE_TMPLT(reference)
BOOST_INTRUSIVE_INSTANTIATE_DEFAULT_TYPE_TMPLT(const_reference)
BOOST_INTRUSIVE_INSTANTIATE_EVAL_DEFAULT_TYPE_TMPLT(void_pointer)
BOOST_INTRUSIVE_INSTANTIATE_EVAL_DEFAULT_TYPE_TMPLT(const_void_pointer)
BOOST_INTRUSIVE_INSTANTIATE_DEFAULT_TYPE_TMPLT(size_type)
BOOST_INTRUSIVE_INSTANTIATE_DEFAULT_TYPE_TMPLT(propagate_on_container_copy_assignment)
BOOST_INTRUSIVE_INSTANTIATE_DEFAULT_TYPE_TMPLT(propagate_on_container_move_assignment)
BOOST_INTRUSIVE_INSTANTIATE_DEFAULT_TYPE_TMPLT(propagate_on_container_swap)
BOOST_INTRUSIVE_INSTANTIATE_DEFAULT_TYPE_TMPLT(is_always_equal)
BOOST_INTRUSIVE_INSTANTIATE_DEFAULT_TYPE_TMPLT(difference_type)
BOOST_INTRUSIVE_INSTANTIATE_DEFAULT_TYPE_TMPLT(is_partially_propagable)

}  //namespace dtl {

#endif   //#ifndef BOOST_CONTAINER_DOXYGEN_INVOKED

//! The class template allocator_traits supplies a uniform interface to all allocator types.
//! This class is a C++03-compatible implementation of std::allocator_traits
template <typename Allocator>
struct allocator_traits
{
   //allocator_type
   typedef Allocator allocator_type;
   //value_type
   typedef typename allocator_type::value_type value_type;

   #if defined(BOOST_CONTAINER_DOXYGEN_INVOKED)
      //! Allocator::pointer if such a type exists; otherwise, value_type*
      //!
      typedef unspecified pointer;
      //! Allocator::const_pointer if such a type exists ; otherwise, pointer_traits<pointer>::rebind<const
      //!
      typedef see_documentation const_pointer;
      //! Non-standard extension
      //! Allocator::reference if such a type exists; otherwise, value_type&
      typedef see_documentation reference;
      //! Non-standard extension
      //! Allocator::const_reference if such a type exists ; otherwise, const value_type&
      typedef see_documentation const_reference;
      //! Allocator::void_pointer if such a type exists ; otherwise, pointer_traits<pointer>::rebind<void>.
      //!
      typedef see_documentation void_pointer;
      //! Allocator::const_void_pointer if such a type exists ; otherwise, pointer_traits<pointer>::rebind<const
      //!
      typedef see_documentation const_void_pointer;
      //! Allocator::difference_type if such a type exists ; otherwise, pointer_traits<pointer>::difference_type.
      //!
      typedef see_documentation difference_type;
      //! Allocator::size_type if such a type exists ; otherwise, make_unsigned<difference_type>::type
      //!
      typedef see_documentation size_type;
      //! Allocator::propagate_on_container_copy_assignment if such a type exists, otherwise a type
      //! with an internal constant static boolean member <code>value</code> == false.
      typedef see_documentation propagate_on_container_copy_assignment;
      //! Allocator::propagate_on_container_move_assignment if such a type exists, otherwise a type
      //! with an internal constant static boolean member <code>value</code> == false.
      typedef see_documentation propagate_on_container_move_assignment;
      //! Allocator::propagate_on_container_swap if such a type exists, otherwise a type
      //! with an internal constant static boolean member <code>value</code> == false.
      typedef see_documentation propagate_on_container_swap;
      //! Allocator::is_always_equal if such a type exists, otherwise a type
      //! with an internal constant static boolean member <code>value</code> == is_empty<Allocator>::value
      typedef see_documentation is_always_equal;
      //! Allocator::is_partially_propagable if such a type exists, otherwise a type
      //! with an internal constant static boolean member <code>value</code> == false
      //! <b>Note</b>: Non-standard extension used to implement `small_vector_allocator`.
      typedef see_documentation is_partially_propagable;
      //! Defines an allocator: Allocator::rebind<T>::other if such a type exists; otherwise, Allocator<T, Args>
      //! if Allocator is a class template instantiation of the form Allocator<U, Args>, where Args is zero or
      //! more type arguments ; otherwise, the instantiation of rebind_alloc is ill-formed.
      //!
      //! In C++03 compilers <code>rebind_alloc</code> is a struct derived from an allocator
      //! deduced by previously detailed rules.
      template <class T> using rebind_alloc = see_documentation;

      //! In C++03 compilers <code>rebind_traits</code> is a struct derived from
      //! <code>allocator_traits<OtherAlloc></code>, where <code>OtherAlloc</code> is
      //! the allocator deduced by rules explained in <code>rebind_alloc</code>.
      template <class T> using rebind_traits = allocator_traits<rebind_alloc<T> >;

      //! Non-standard extension: Portable allocator rebind for C++03 and C++11 compilers.
      //! <code>type</code> is an allocator related to Allocator deduced deduced by rules explained in <code>rebind_alloc</code>.
      template <class T>
      struct portable_rebind_alloc
      {  typedef see_documentation type;  };
   #else
      //pointer
      typedef BOOST_INTRUSIVE_OBTAIN_TYPE_WITH_DEFAULT(boost_kahypar::container::dtl::, Allocator,
         pointer, value_type*)
            pointer;
      //const_pointer
      typedef BOOST_INTRUSIVE_OBTAIN_TYPE_WITH_EVAL_DEFAULT(boost_kahypar::container::dtl::, Allocator,
         const_pointer, typename boost_kahypar::intrusive::pointer_traits<pointer>::template
            rebind_pointer<const value_type>)
               const_pointer;
      //reference
      typedef BOOST_INTRUSIVE_OBTAIN_TYPE_WITH_DEFAULT(boost_kahypar::container::dtl::, Allocator,
         reference, typename dtl::unvoid_ref<value_type>::type)
            reference;
      //const_reference
      typedef BOOST_INTRUSIVE_OBTAIN_TYPE_WITH_DEFAULT(boost_kahypar::container::dtl::, Allocator,
         const_reference, typename dtl::unvoid_ref<const value_type>::type)
               const_reference;
      //void_pointer
      typedef BOOST_INTRUSIVE_OBTAIN_TYPE_WITH_EVAL_DEFAULT(boost_kahypar::container::dtl::, Allocator,
         void_pointer, typename boost_kahypar::intrusive::pointer_traits<pointer>::template
            rebind_pointer<void>)
               void_pointer;
      //const_void_pointer
      typedef BOOST_INTRUSIVE_OBTAIN_TYPE_WITH_EVAL_DEFAULT(boost_kahypar::container::dtl::, Allocator,
         const_void_pointer, typename boost_kahypar::intrusive::pointer_traits<pointer>::template
            rebind_pointer<const void>)
               const_void_pointer;
      //difference_type
      typedef BOOST_INTRUSIVE_OBTAIN_TYPE_WITH_DEFAULT(boost_kahypar::container::dtl::, Allocator,
         difference_type, std::ptrdiff_t)
            difference_type;
      //size_type
      typedef BOOST_INTRUSIVE_OBTAIN_TYPE_WITH_DEFAULT(boost_kahypar::container::dtl::, Allocator,
         size_type, std::size_t)
            size_type;
      //propagate_on_container_copy_assignment
      typedef BOOST_INTRUSIVE_OBTAIN_TYPE_WITH_DEFAULT(boost_kahypar::container::dtl::, Allocator,
         propagate_on_container_copy_assignment, dtl::false_type)
            propagate_on_container_copy_assignment;
      //propagate_on_container_move_assignment
      typedef BOOST_INTRUSIVE_OBTAIN_TYPE_WITH_DEFAULT(boost_kahypar::container::dtl::, Allocator,
         propagate_on_container_move_assignment, dtl::false_type)
            propagate_on_container_move_assignment;
      //propagate_on_container_swap
      typedef BOOST_INTRUSIVE_OBTAIN_TYPE_WITH_DEFAULT(boost_kahypar::container::dtl::, Allocator,
         propagate_on_container_swap, dtl::false_type)
            propagate_on_container_swap;
      //is_always_equal
      typedef BOOST_INTRUSIVE_OBTAIN_TYPE_WITH_DEFAULT(boost_kahypar::container::dtl::, Allocator,
         is_always_equal, dtl::is_empty<Allocator>)
            is_always_equal;
      //is_partially_propagable
      typedef BOOST_INTRUSIVE_OBTAIN_TYPE_WITH_DEFAULT(boost_kahypar::container::dtl::, Allocator,
         is_partially_propagable, dtl::false_type)
            is_partially_propagable;

      //rebind_alloc & rebind_traits
      #if !defined(BOOST_NO_CXX11_TEMPLATE_ALIASES)
         //C++11
         template <typename T> using rebind_alloc  = typename boost_kahypar::intrusive::pointer_rebind<Allocator, T>::type;
         template <typename T> using rebind_traits = allocator_traits< rebind_alloc<T> >;
      #else    // #if !defined(BOOST_NO_CXX11_TEMPLATE_ALIASES)
         //Some workaround for C++03 or C++11 compilers with no template aliases
         template <typename T>
         struct rebind_alloc : boost_kahypar::intrusive::pointer_rebind<Allocator,T>::type
         {
            typedef typename boost_kahypar::intrusive::pointer_rebind<Allocator,T>::type Base;
            #if !defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
               template <typename... Args>
               rebind_alloc(BOOST_FWD_REF(Args)... args) : Base(boost_kahypar::forward<Args>(args)...) {}
            #else    // #if !defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
               #define BOOST_CONTAINER_ALLOCATOR_TRAITS_REBIND_ALLOC(N) \
               BOOST_MOVE_TMPL_LT##N BOOST_MOVE_CLASS##N BOOST_MOVE_GT##N\
               explicit rebind_alloc(BOOST_MOVE_UREF##N) : Base(BOOST_MOVE_FWD##N){}\
               //
               BOOST_MOVE_ITERATE_0TO9(BOOST_CONTAINER_ALLOCATOR_TRAITS_REBIND_ALLOC)
               #undef BOOST_CONTAINER_ALLOCATOR_TRAITS_REBIND_ALLOC
            #endif   // #if !defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
         };

         template <typename T>
         struct rebind_traits
            : allocator_traits<typename boost_kahypar::intrusive::pointer_rebind<Allocator, T>::type>
         {};
      #endif   // #if !defined(BOOST_NO_CXX11_TEMPLATE_ALIASES)

      //portable_rebind_alloc
      template <class T>
      struct portable_rebind_alloc
      {  typedef typename boost_kahypar::intrusive::pointer_rebind<Allocator, T>::type type;  };
   #endif   //BOOST_CONTAINER_DOXYGEN_INVOKED

   //! <b>Returns</b>: <code>a.allocate(n)</code>
   //!
   inline static pointer allocate(Allocator &a, size_type n)
   {  return a.allocate(n);  }

   //! <b>Returns</b>: <code>a.deallocate(p, n)</code>
   //!
   //! <b>Throws</b>: Nothing
   inline static void deallocate(Allocator &a, pointer p, size_type n)
   {  a.deallocate(p, n);  }

   //! <b>Effects</b>: calls <code>a.allocate(n, p)</code> if that call is well-formed;
   //! otherwise, invokes <code>a.allocate(n)</code>
   inline static pointer allocate(Allocator &a, size_type n, const_void_pointer p)
   {
      const bool value = boost_kahypar::container::dtl::
         has_member_function_callable_with_allocate
            <Allocator, const size_type, const const_void_pointer>::value;
      dtl::bool_<value> flag;
      return allocator_traits::priv_allocate(flag, a, n, p);
   }

   //! <b>Effects</b>: calls <code>a.destroy(p)</code> if that call is well-formed;
   //! otherwise, invokes <code>p->~T()</code>.
   template<class T>
   inline static void destroy(Allocator &a, T*p) BOOST_NOEXCEPT_OR_NOTHROW
   {
      typedef T* destroy_pointer;
      const bool value = boost_kahypar::container::dtl::
         has_member_function_callable_with_destroy
            <Allocator, const destroy_pointer>::value;
      dtl::bool_<value> flag;
      allocator_traits::priv_destroy(flag, a, p);
   }

   //! <b>Returns</b>: <code>a.max_size()</code> if that expression is well-formed; otherwise,
   //! <code>numeric_limits<size_type>::max()</code>.
   inline static size_type max_size(const Allocator &a) BOOST_NOEXCEPT_OR_NOTHROW
   {
      const bool value = allocator_traits_detail::has_max_size<Allocator, size_type (Allocator::*)() const>::value;
      dtl::bool_<value> flag;
      return allocator_traits::priv_max_size(flag, a);
   }

   //! <b>Returns</b>: <code>a.select_on_container_copy_construction()</code> if that expression is well-formed;
   //! otherwise, a.
   inline static BOOST_CONTAINER_DOC1ST(Allocator,
      typename dtl::if_c
         < allocator_traits_detail::has_select_on_container_copy_construction<Allocator BOOST_MOVE_I Allocator (Allocator::*)() const>::value
         BOOST_MOVE_I Allocator BOOST_MOVE_I const Allocator & >::type)
   select_on_container_copy_construction(const Allocator &a)
   {
      const bool value = allocator_traits_detail::has_select_on_container_copy_construction
         <Allocator, Allocator (Allocator::*)() const>::value;
      dtl::bool_<value> flag;
      return allocator_traits::priv_select_on_container_copy_construction(flag, a);
   }

   #if !defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES) || defined(BOOST_CONTAINER_DOXYGEN_INVOKED)
      //! <b>Effects</b>: calls <code>a.construct(p, std::forward<Args>(args)...)</code> if that call is well-formed;
      //! otherwise, invokes <code>`placement new` (static_cast<void*>(p)) T(std::forward<Args>(args)...)</code>
      template <class T, class ...Args>
      inline static void construct(Allocator & a, T* p, BOOST_FWD_REF(Args)... args)
      {
         BOOST_STATIC_CONSTEXPR bool value = ::boost_kahypar::move_detail::and_
            < dtl::is_not_std_allocator<Allocator>
            , boost_kahypar::container::dtl::has_member_function_callable_with_construct
                  < Allocator, T*, Args... >
            >::value;
         dtl::bool_<value> flag;
         allocator_traits::priv_construct(flag, a, p, ::boost_kahypar::forward<Args>(args)...);
      }
   #endif

   //! <b>Returns</b>: <code>a.storage_is_unpropagable(p)</code> if is_partially_propagable::value is true; otherwise,
   //! <code>false</code>.
   inline static bool storage_is_unpropagable(const Allocator &a, pointer p) BOOST_NOEXCEPT_OR_NOTHROW
   {
      dtl::bool_<is_partially_propagable::value> flag;
      return allocator_traits::priv_storage_is_unpropagable(flag, a, p);
   }

   //! <b>Returns</b>: <code>true</code> if <code>is_always_equal::value == true</code>, otherwise,
   //! <code>a == b</code>.
   inline static bool equal(const Allocator &a, const Allocator &b) BOOST_NOEXCEPT_OR_NOTHROW
   {
      dtl::bool_<is_always_equal::value> flag;
      return allocator_traits::priv_equal(flag, a, b);
   }

   #if !defined(BOOST_CONTAINER_DOXYGEN_INVOKED)
   private:
   inline static pointer priv_allocate(dtl::true_type, Allocator &a, size_type n, const_void_pointer p)
   {  return a.allocate(n, p);  }

   inline static pointer priv_allocate(dtl::false_type, Allocator &a, size_type n, const_void_pointer)
   {  return a.allocate(n);  }

   template<class T>
   inline static void priv_destroy(dtl::true_type, Allocator &a, T* p) BOOST_NOEXCEPT_OR_NOTHROW
   {  a.destroy(p);  }

   template<class T>
   inline static void priv_destroy(dtl::false_type, Allocator &, T* p) BOOST_NOEXCEPT_OR_NOTHROW
   {  p->~T(); (void)p;  }

   inline static size_type priv_max_size(dtl::true_type, const Allocator &a) BOOST_NOEXCEPT_OR_NOTHROW
   {  return a.max_size();  }

   inline static size_type priv_max_size(dtl::false_type, const Allocator &) BOOST_NOEXCEPT_OR_NOTHROW
   {  return size_type(-1)/sizeof(value_type);  }

   inline static Allocator priv_select_on_container_copy_construction(dtl::true_type, const Allocator &a)
   {  return a.select_on_container_copy_construction();  }

   inline static const Allocator &priv_select_on_container_copy_construction(dtl::false_type, const Allocator &a) BOOST_NOEXCEPT_OR_NOTHROW
   {  return a;  }

   #if !defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
      template<class T, class ...Args>
      inline static void priv_construct(dtl::true_type, Allocator &a, T *p, BOOST_FWD_REF(Args) ...args)
      {  a.construct( p, ::boost_kahypar::forward<Args>(args)...);  }

      template<class T, class ...Args>
      inline static void priv_construct(dtl::false_type, Allocator &, T *p, BOOST_FWD_REF(Args) ...args)
      {  dtl::construct_type(p, ::boost_kahypar::forward<Args>(args)...); }
   #else // #if !defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
      public:

      #define BOOST_CONTAINER_ALLOCATOR_TRAITS_CONSTRUCT_IMPL(N) \
      template<class T BOOST_MOVE_I##N BOOST_MOVE_CLASS##N >\
      inline static void construct(Allocator &a, T *p BOOST_MOVE_I##N BOOST_MOVE_UREF##N)\
      {\
         BOOST_STATIC_CONSTEXPR bool value = ::boost_kahypar::move_detail::and_ \
            < dtl::is_not_std_allocator<Allocator> \
            , boost_kahypar::container::dtl::has_member_function_callable_with_construct \
                  < Allocator, T* BOOST_MOVE_I##N BOOST_MOVE_FWD_T##N > \
            >::value; \
         dtl::bool_<value> flag;\
         (priv_construct)(flag, a, p BOOST_MOVE_I##N BOOST_MOVE_FWD##N);\
      }\
      //
      BOOST_MOVE_ITERATE_0TO8(BOOST_CONTAINER_ALLOCATOR_TRAITS_CONSTRUCT_IMPL)
      #undef BOOST_CONTAINER_ALLOCATOR_TRAITS_CONSTRUCT_IMPL

      private:
      /////////////////////////////////
      // priv_construct
      /////////////////////////////////
      #define BOOST_CONTAINER_ALLOCATOR_TRAITS_PRIV_CONSTRUCT_IMPL(N) \
      template<class T BOOST_MOVE_I##N BOOST_MOVE_CLASS##N >\
      inline static void priv_construct(dtl::true_type, Allocator &a, T *p BOOST_MOVE_I##N BOOST_MOVE_UREF##N)\
      {  a.construct( p BOOST_MOVE_I##N BOOST_MOVE_FWD##N );  }\
      \
      template<class T BOOST_MOVE_I##N BOOST_MOVE_CLASS##N >\
      inline static void priv_construct(dtl::false_type, Allocator &, T *p BOOST_MOVE_I##N BOOST_MOVE_UREF##N)\
      {  dtl::construct_type(p BOOST_MOVE_I##N BOOST_MOVE_FWD##N); }\
      //
      BOOST_MOVE_ITERATE_0TO8(BOOST_CONTAINER_ALLOCATOR_TRAITS_PRIV_CONSTRUCT_IMPL)
      #undef BOOST_CONTAINER_ALLOCATOR_TRAITS_PRIV_CONSTRUCT_IMPL

   #endif   // #if !defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)

   template<class T>
   inline static void priv_construct(dtl::false_type, Allocator &, T *p, const ::boost_kahypar::container::default_init_t&)
   {  ::new((void*)p, boost_container_new_t()) T; }

   inline static bool priv_storage_is_unpropagable(dtl::true_type, const Allocator &a, pointer p)
   {  return a.storage_is_unpropagable(p);  }

   inline static bool priv_storage_is_unpropagable(dtl::false_type, const Allocator &, pointer)
   {  return false;  }

   inline static bool priv_equal(dtl::true_type,  const Allocator &, const Allocator &)
   {  return true;  }

   inline static bool priv_equal(dtl::false_type, const Allocator &a, const Allocator &b)
   {  return a == b;  }

   #endif   //#if defined(BOOST_CONTAINER_DOXYGEN_INVOKED)
};

#if !defined(BOOST_CONTAINER_DOXYGEN_INVOKED)

template<class T, class AllocatorOrVoid>
struct real_allocator
{
   typedef AllocatorOrVoid type;
};

template<class T>
struct real_allocator<T, void>
{
   typedef new_allocator<T> type;
};

#endif   //#if defined(BOOST_CONTAINER_DOXYGEN_INVOKED)

}  //namespace container {
}  //namespace boost_kahypar {

#include <boost_kahypar/container/detail/config_end.hpp>

#endif // ! defined(BOOST_CONTAINER_ALLOCATOR_ALLOCATOR_TRAITS_HPP)
