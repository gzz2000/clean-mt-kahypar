
//  (C) Copyright John Maddock 2000. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost_kahypar/type_traits/is_void.hpp>
#include <boost_kahypar/type_traits/add_const.hpp>
#include <boost_kahypar/mpl/list.hpp>
#include <boost_kahypar/mpl/front.hpp>
#include <boost_kahypar/mpl/remove_if.hpp>
#include <boost_kahypar/mpl/transform.hpp>
#include <boost_kahypar/static_assert.hpp>

template <class List>
struct lambda_test
{
   typedef typename boost_kahypar::mpl::remove_if<List, boost_kahypar::is_void<boost_kahypar::mpl::_> >::type reduced_list;
   typedef typename boost_kahypar::mpl::transform<reduced_list, boost_kahypar::add_const<boost_kahypar::mpl::_> >::type const_list;
   typedef typename boost_kahypar::mpl::front<const_list>::type type;
};


int main()
{
   typedef boost_kahypar::mpl::list<const void, int, float, void, double> list_type;

   lambda_test<list_type>::type i = 0;
   return i;
}
