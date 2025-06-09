// Copyright (c) 2007 Joseph Gauterin
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost_kahypar/core/invoke_swap.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>
#define BOOST_CHECK BOOST_TEST
#define BOOST_CHECK_EQUAL BOOST_TEST_EQ

int main()
{
  int object1 = 1;
  int object2 = 2;

  boost_kahypar::core::invoke_swap(object1,object2);

  BOOST_CHECK_EQUAL(object1,2);
  BOOST_CHECK_EQUAL(object2,1);

  return boost_kahypar::report_errors();
}

