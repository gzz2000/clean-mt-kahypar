//  boost win32_test.cpp  -----------------------------------------------------//

//  Copyright 2010 Vicente J. Botet Escriba

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

//  See http://www.boost.org/libs/chrono for documentation.
#include <iostream>
#include <boost_kahypar/chrono/chrono.hpp>
#include <boost_kahypar/chrono/chrono_io.hpp>

void another() {
  boost_kahypar::chrono::steady_clock::time_point t1=boost_kahypar::chrono::steady_clock::now();
  boost_kahypar::chrono::steady_clock::time_point t2=boost_kahypar::chrono::steady_clock::now();
  std::cout << t2-t1 << std::endl;
  return ;
}

