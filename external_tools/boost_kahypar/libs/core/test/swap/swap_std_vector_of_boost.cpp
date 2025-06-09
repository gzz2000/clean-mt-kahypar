// Copyright (c) 2008 Joseph Gauterin, Niels Dekker
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// Tests swapping std::vector objects by means of boost_kahypar::core::invoke_swap,
// having boost_kahypar::swap_test_class as vector element type.

#include <boost_kahypar/core/invoke_swap.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>
#define BOOST_CHECK BOOST_TEST
#define BOOST_CHECK_EQUAL BOOST_TEST_EQ

#include <vector>

//Put test class in namespace boost_kahypar
namespace boost_kahypar
{
  #include "./swap_test_class.hpp"
}

//Provide swap function in namespace boost_kahypar
namespace boost_kahypar
{
  void swap(swap_test_class& left, swap_test_class& right)
  {
    left.swap(right);
  }
}

int main()
{
  typedef boost_kahypar::swap_test_class swap_test_class_type;
  typedef std::vector<swap_test_class_type> vector_type;

  const vector_type::size_type initial_size1 = 1;
  const vector_type::size_type initial_size2 = 2;

  const vector_type initial_value1(initial_size1, swap_test_class_type(1));
  const vector_type initial_value2(initial_size2, swap_test_class_type(2));

  vector_type object1 = initial_value1;
  vector_type object2 = initial_value2;

  swap_test_class_type::reset();

  boost_kahypar::core::invoke_swap(object1,object2);

  BOOST_CHECK_EQUAL(object1.size(),initial_size2);
  BOOST_CHECK_EQUAL(object2.size(),initial_size1);

  BOOST_CHECK(object1 == initial_value2);
  BOOST_CHECK(object2 == initial_value1);

  BOOST_CHECK_EQUAL(swap_test_class_type::swap_count(),0);
  BOOST_CHECK_EQUAL(swap_test_class_type::copy_count(),0);

  return boost_kahypar::report_errors();
}

