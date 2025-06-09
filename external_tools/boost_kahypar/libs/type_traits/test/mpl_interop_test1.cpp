
//  (C) Copyright John Maddock 2000. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost_kahypar/type_traits/is_void.hpp>

template <class T>
int dispatch_test_imp(const boost_kahypar::mpl::bool_<true>&)
{
   return 0;
}
template <class T>
int dispatch_test_imp(const boost_kahypar::mpl::bool_<false>&)
{
   return 1;
}

template <class T>
int dispatch_test()
{
   return dispatch_test_imp<T>(boost_kahypar::is_void<T>());
}


int main()
{
   return (dispatch_test<int>() == 1) && (dispatch_test<void>() == 0) ? 0 : 1;
}
