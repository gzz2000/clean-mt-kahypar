//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2012-2013. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/container for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef BOOST_CONTAINER_THROW_EXCEPTION_HPP
#define BOOST_CONTAINER_THROW_EXCEPTION_HPP

#ifndef BOOST_CONFIG_HPP
#  include <boost_kahypar/config.hpp>
#endif

#if defined(BOOST_HAS_PRAGMA_ONCE)
#  pragma once
#endif

#include <boost_kahypar/container/detail/config_begin.hpp>
#include <boost_kahypar/container/detail/workaround.hpp>

#ifndef BOOST_NO_EXCEPTIONS
#include <exception> //for std exception base

#  if defined(BOOST_CONTAINER_USE_STD_EXCEPTIONS)
   #include <stdexcept> //for std::out_of_range, std::length_error, std::logic_error, std::runtime_error
   #include <string>    //for implicit std::string conversion
   #include <new>       //for std::bad_alloc

namespace boost_kahypar {
namespace container {

typedef std::bad_alloc bad_alloc_t;
typedef std::out_of_range out_of_range_t;
typedef std::length_error length_error_t;
typedef std::logic_error logic_error_t;
typedef std::runtime_error runtime_error_t;

}} //namespace boost_kahypar::container

#  else	//!BOOST_CONTAINER_USE_STD_EXCEPTIONS

namespace boost_kahypar {
namespace container {

class BOOST_SYMBOL_VISIBLE exception
   : public ::std::exception
{
   typedef ::std::exception std_exception_t;

   public:

   //msg must be a static string (guaranteed by callers)
   explicit exception(const char *msg)
      : std_exception_t(), m_msg(msg)
   {}

   virtual const char *what() const BOOST_NOEXCEPT_OR_NOTHROW BOOST_OVERRIDE
   {  return m_msg ? m_msg : "unknown boost_kahypar::container exception"; }

   private:
   const char *m_msg;
};

class BOOST_SYMBOL_VISIBLE bad_alloc
   : public exception
{
   public:
   bad_alloc()
      : exception("boost_kahypar::container::bad_alloc thrown")
   {}
};

typedef bad_alloc bad_alloc_t;

class BOOST_SYMBOL_VISIBLE out_of_range
   : public exception
{
   public:
   explicit out_of_range(const char *msg)
      : exception(msg)
   {}
};

typedef out_of_range out_of_range_t;

class BOOST_SYMBOL_VISIBLE length_error
   : public exception
{
   public:
   explicit length_error(const char *msg)
      : exception(msg)
   {}
};

typedef length_error length_error_t;

class BOOST_SYMBOL_VISIBLE logic_error
   : public exception
{
   public:
   explicit logic_error(const char *msg)
      : exception(msg)
   {}
};

typedef logic_error logic_error_t;

class BOOST_SYMBOL_VISIBLE runtime_error
   : public exception
{
   public:
   explicit runtime_error(const char *msg)
      : exception(msg)
   {}
};

typedef runtime_error runtime_error_t;

}  // namespace boost_kahypar {
}  // namespace container {

#  endif
#else
   #include <boost_kahypar/assert.hpp>
   #include <cstdlib>   //for std::abort
#endif

namespace boost_kahypar {
namespace container {

#if defined(BOOST_CONTAINER_USER_DEFINED_THROW_CALLBACKS)
   //The user must provide definitions for the following functions

   BOOST_NORETURN void throw_bad_alloc();

   BOOST_NORETURN void throw_out_of_range(const char* str);

   BOOST_NORETURN void throw_length_error(const char* str);

   BOOST_NORETURN void throw_logic_error(const char* str);

   BOOST_NORETURN void throw_runtime_error(const char* str);

#elif defined(BOOST_NO_EXCEPTIONS)

   BOOST_NORETURN inline void throw_bad_alloc()
   {
      BOOST_ASSERT(!"boost_kahypar::container bad_alloc thrown");
      std::abort();
   }

   BOOST_NORETURN inline void throw_out_of_range(const char* str)
   {
      boost_kahypar::container::ignore(str);
      BOOST_ASSERT_MSG(!"boost_kahypar::container out_of_range thrown", str);
      std::abort();
   }

   BOOST_NORETURN inline void throw_length_error(const char* str)
   {
      boost_kahypar::container::ignore(str);
      BOOST_ASSERT_MSG(!"boost_kahypar::container length_error thrown", str);
      std::abort();
   }

   BOOST_NORETURN inline void throw_logic_error(const char* str)
   {
      boost_kahypar::container::ignore(str);
      BOOST_ASSERT_MSG(!"boost_kahypar::container logic_error thrown", str);
      std::abort();
   }

   BOOST_NORETURN inline void throw_runtime_error(const char* str)
   {
      boost_kahypar::container::ignore(str);
      BOOST_ASSERT_MSG(!"boost_kahypar::container runtime_error thrown", str);
      std::abort();
   }

#else //defined(BOOST_NO_EXCEPTIONS)

   //! Exception callback called by Boost.Container when fails to allocate the requested storage space.
   //! <ul>
   //! <li>If BOOST_NO_EXCEPTIONS is NOT defined and BOOST_CONTAINER_USE_STD_EXCEPTIONS is NOT defined
   //!   <code>boost_kahypar::container::bad_alloc(str)</code> is thrown.</li>
   //!
   //! <li>If BOOST_NO_EXCEPTIONS is NOT defined and BOOST_CONTAINER_USE_STD_EXCEPTIONS is defined
   //!   <code>std::bad_alloc(str)</code> is thrown.</li>
   //!
   //! <li>If BOOST_NO_EXCEPTIONS is defined and BOOST_CONTAINER_USER_DEFINED_THROW_CALLBACKS
   //!   is NOT defined <code>BOOST_ASSERT(!"boost_kahypar::container bad_alloc thrown")</code> is called
   //!   and <code>std::abort()</code> if the former returns.</li>
   //!
   //! <li>If BOOST_NO_EXCEPTIONS and BOOST_CONTAINER_USER_DEFINED_THROW_CALLBACKS are defined
   //!   the user must provide an implementation and the function should not return.</li>
   //! </ul>
   BOOST_NORETURN inline void throw_bad_alloc()
   {
      throw bad_alloc_t();
   }

   //! Exception callback called by Boost.Container to signal arguments out of range.
   //! <ul>
   //! <li>If BOOST_NO_EXCEPTIONS is NOT defined and BOOST_CONTAINER_USE_STD_EXCEPTIONS is NOT defined
   //!   <code>boost_kahypar::container::out_of_range(str)</code> is thrown.</li>
   //!
   //! <li>If BOOST_NO_EXCEPTIONS is NOT defined and BOOST_CONTAINER_USE_STD_EXCEPTIONS is defined
   //!   <code>std::out_of_range(str)</code> is thrown.</li>
   //!
   //! <li>If BOOST_NO_EXCEPTIONS is defined and BOOST_CONTAINER_USER_DEFINED_THROW_CALLBACKS
   //!   is NOT defined <code>BOOST_ASSERT_MSG(!"boost_kahypar::container out_of_range thrown", str)</code> is called
   //!   and <code>std::abort()</code> if the former returns.</li>
   //!
   //! <li>If BOOST_NO_EXCEPTIONS and BOOST_CONTAINER_USER_DEFINED_THROW_CALLBACKS are defined
   //!   the user must provide an implementation and the function should not return.</li>
   //! </ul>
   BOOST_NORETURN inline void throw_out_of_range(const char* str)
   {
      throw out_of_range_t(str);
   }

   //! Exception callback called by Boost.Container to signal errors resizing.
   //! <ul>
   //!
   //! <li>If BOOST_NO_EXCEPTIONS is NOT defined and BOOST_CONTAINER_USE_STD_EXCEPTIONS is NOT defined
   //!   <code>boost_kahypar::container::length_error(str)</code> is thrown.</li>
   //!
   //! <li>If BOOST_NO_EXCEPTIONS is NOT defined and BOOST_CONTAINER_USE_STD_EXCEPTIONS is defined
   //!   <code>std::length_error(str)</code> is thrown.</li>
   //!
   //! <li>If BOOST_NO_EXCEPTIONS is defined and BOOST_CONTAINER_USER_DEFINED_THROW_CALLBACKS
   //!   is NOT defined <code>BOOST_ASSERT_MSG(!"boost_kahypar::container length_error thrown", str)</code> is called
   //!   and <code>std::abort()</code> if the former returns.</li>
   //!
   //! <li>If BOOST_NO_EXCEPTIONS and BOOST_CONTAINER_USER_DEFINED_THROW_CALLBACKS are defined
   //!   the user must provide an implementation and the function should not return.</li>
   //! </ul>
   BOOST_NORETURN inline void throw_length_error(const char* str)
   {
      throw length_error_t(str);
   }

   //! Exception callback called by Boost.Container  to report errors in the internal logical
   //! of the program, such as violation of logical preconditions or class invariants.
   //! <ul>
   //!
   //! <li>If BOOST_NO_EXCEPTIONS is NOT defined and BOOST_CONTAINER_USE_STD_EXCEPTIONS is NOT defined
   //!   <code>boost_kahypar::container::logic_error(str)</code> is thrown.</li>
   //!
   //! <li>If BOOST_NO_EXCEPTIONS is NOT defined and BOOST_CONTAINER_USE_STD_EXCEPTIONS is defined
   //!   <code>std::logic_error(str)</code> is thrown.</li>
   //!
   //! <li>If BOOST_NO_EXCEPTIONS is defined and BOOST_CONTAINER_USER_DEFINED_THROW_CALLBACKS
   //!   is NOT defined <code>BOOST_ASSERT_MSG(!"boost_kahypar::container logic_error thrown", str)</code> is called
   //!   and <code>std::abort()</code> if the former returns.</li>
   //!
   //! <li>If BOOST_NO_EXCEPTIONS and BOOST_CONTAINER_USER_DEFINED_THROW_CALLBACKS are defined
   //!   the user must provide an implementation and the function should not return.</li>
   //! </ul>
   BOOST_NORETURN inline void throw_logic_error(const char* str)
   {
      throw logic_error_t(str);
   }

   //! Exception callback called by Boost.Container  to report errors that can only be detected during runtime.
   //! <ul>
   //! <li>If BOOST_NO_EXCEPTIONS is NOT defined and BOOST_CONTAINER_USE_STD_EXCEPTIONS is NOT defined
   //!   <code>boost_kahypar::container::runtime_error(str)</code> is thrown.</li>
   //!
   //! <li>If BOOST_NO_EXCEPTIONS is NOT defined and BOOST_CONTAINER_USE_STD_EXCEPTIONS is defined
   //!   <code>std::runtime_error(str)</code> is thrown.</li>
   //!
   //! <li>If BOOST_NO_EXCEPTIONS is defined and BOOST_CONTAINER_USER_DEFINED_THROW_CALLBACKS
   //!   is NOT defined <code>BOOST_ASSERT_MSG(!"boost_kahypar::container runtime_error thrown", str)</code> is called
   //!   and <code>std::abort()</code> if the former returns.</li>
   //!
   //! <li>If BOOST_NO_EXCEPTIONS and BOOST_CONTAINER_USER_DEFINED_THROW_CALLBACKS are defined
   //!   the user must provide an implementation and the function should not return.</li>
   //! </ul>
   BOOST_NORETURN inline void throw_runtime_error(const char* str)
   {
      throw runtime_error_t(str);
   }

#endif

}}  //namespace boost_kahypar { namespace container {

#include <boost_kahypar/container/detail/config_end.hpp>

#endif //#ifndef BOOST_CONTAINER_THROW_EXCEPTION_HPP
