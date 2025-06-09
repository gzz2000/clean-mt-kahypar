// (C) Copyright Jeremy Siek 2000.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost_kahypar/concept_check.hpp>

/*

  This file verifies that the BOOST_CLASS_REQUIRE macro of the Boost
  Concept Checking Library does not cause errors when it is not suppose
  to.

*/

struct foo { bool operator()(int) { return true; } };
struct bar { bool operator()(int, char) { return true; } };

class class_requires_test
{
    BOOST_CONCEPT_ASSERT((boost_kahypar::EqualityComparable<int>));
    typedef int* int_ptr; typedef const int* const_int_ptr;
    BOOST_CONCEPT_ASSERT((boost_kahypar::EqualOp<int_ptr,const_int_ptr>));
    BOOST_CONCEPT_ASSERT((boost_kahypar::UnaryFunction<foo,bool,int>));
    BOOST_CONCEPT_ASSERT((boost_kahypar::BinaryFunction<bar,bool,int,char>));
};

int
main()
{
    class_requires_test x;
    boost_kahypar::ignore_unused_variable_warning(x);
    return 0;
}
