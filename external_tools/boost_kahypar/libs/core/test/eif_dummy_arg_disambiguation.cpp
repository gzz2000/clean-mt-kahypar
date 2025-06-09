// Boost enable_if library

// Copyright 2003 (c) The Trustees of Indiana University.

// Use, modification, and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

//    Authors: Jaakko Jarvi (jajarvi at osl.iu.edu)
//             Jeremiah Willcock (jewillco at osl.iu.edu)
//             Andrew Lumsdaine (lums at osl.iu.edu)

#include <boost_kahypar/utility/enable_if.hpp>
#include <boost_kahypar/type_traits/is_arithmetic.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>

using boost_kahypar::enable_if;
using boost_kahypar::disable_if;
using boost_kahypar::is_arithmetic;

template <int N> struct dummy {
  dummy(int) {};
};

template<class T>
typename enable_if<is_arithmetic<T>, bool>::type
arithmetic_object(T /*t*/, dummy<0> = 0) { return true; }

template<class T>
typename disable_if<is_arithmetic<T>, bool>::type
arithmetic_object(T /*t*/, dummy<1> = 0) { return false; }


int main()
{
 
  BOOST_TEST(arithmetic_object(1));
  BOOST_TEST(arithmetic_object(1.0));

  BOOST_TEST(!arithmetic_object("1"));  
  BOOST_TEST(!arithmetic_object(static_cast<void*>(0)));  

  return boost_kahypar::report_errors();
}
