//  Copyright John Maddock 2012.  
//  Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt)

#include <boost_kahypar/integer.hpp>

typedef boost_kahypar::int_t<sizeof(boost_kahypar::intmax_t)*CHAR_BIT + 1>::exact fail_int_exact;
