//  auto_cpu_timer_example.cpp  ------------------------------------------------------//

//  Copyright Beman Dawes 2006

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/timer/timer.hpp>
#include <cmath>

int main()
{
  boost_kahypar::timer::auto_cpu_timer t;

  for ( long i = 0; i < 100000000; ++i )
    std::sqrt( 123.456L );  // burn some time

  return 0;
}
