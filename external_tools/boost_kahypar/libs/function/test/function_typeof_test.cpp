// Boost.Function library

//  Copyright Douglas Gregor 2008. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// For more information, see http://www.boost.org
#include <boost_kahypar/function/function_typeof.hpp>
#include <boost_kahypar/function.hpp>
#include <boost_kahypar/typeof/typeof.hpp>
#include <boost_kahypar/type_traits/is_same.hpp>
#include <boost_kahypar/static_assert.hpp>

void f(boost_kahypar::function0<void> f, boost_kahypar::function0<void> g)
{
  BOOST_STATIC_ASSERT((boost_kahypar::is_same<boost_kahypar::function0<void>, BOOST_TYPEOF(f = g)>::value));
}
