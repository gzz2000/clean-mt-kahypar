/*
*
* Copyright (c) 2015
* John Maddock
*
* Use, modification and distribution are subject to the
* Boost Software License, Version 1.0. (See accompanying file
* LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*
*/

#include <boost_kahypar/regex.hpp>
#include <boost_kahypar/range/concepts.hpp>

template <class T>
void use_val(const T&){}

template <class T>
void check()
{
   BOOST_CONCEPT_ASSERT((boost_kahypar::ForwardRangeConcept<T>));
   BOOST_CONCEPT_ASSERT((boost_kahypar_concepts::ReadableIteratorConcept<typename boost_kahypar::range_iterator<T>::type>));
   BOOST_CONCEPT_ASSERT((boost_kahypar_concepts::RandomAccessTraversalConcept<typename boost_kahypar::range_iterator<T>::type>));

#ifndef BOOST_NO_CXX11_RANGE_BASED_FOR
   const T val;
   for(auto item : val)
   {
      use_val(item);
   }
#endif
}

int main()
{
   check<boost_kahypar::smatch>();
   check<boost_kahypar::cmatch>();

   check <boost_kahypar::sub_match<const char*> >();
   return 0;
}
