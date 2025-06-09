// Copyright (c) 2008 Joseph Gauterin, Niels Dekker
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// boost_kahypar::core::invoke_swap internally does an unqualified function call to swap.
// This could have led to ambiguity or infinite recursion, when the
// objects to be swapped would themselves be from the boost namespace.
// If so, boost_kahypar::core::invoke_swap itself might be found by argument dependent lookup.
// The implementation of boost_kahypar::core::invoke_swap resolves this issue by giving
// boost_kahypar::core::invoke_swap two template argumetns, thereby making it less specialized
// than std::swap.

#include <boost_kahypar/core/invoke_swap.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>
#define BOOST_CHECK BOOST_TEST
#define BOOST_CHECK_EQUAL BOOST_TEST_EQ

//Put test class in namespace boost_kahypar
namespace boost_kahypar
{
  #include "./swap_test_class.hpp"
}


int main()
{
  const boost_kahypar::swap_test_class initial_value1(1);
  const boost_kahypar::swap_test_class initial_value2(2);

  boost_kahypar::swap_test_class object1 = initial_value1;
  boost_kahypar::swap_test_class object2 = initial_value2;

  boost_kahypar::swap_test_class::reset();
  boost_kahypar::core::invoke_swap(object1,object2);

  BOOST_CHECK(object1 == initial_value2);
  BOOST_CHECK(object2 == initial_value1);
  BOOST_CHECK_EQUAL(boost_kahypar::swap_test_class::swap_count(),0);
  BOOST_CHECK_EQUAL(boost_kahypar::swap_test_class::copy_count(),3);

  return boost_kahypar::report_errors();
}

