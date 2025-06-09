//  french.cpp  ----------------------------------------------------------//

//  Copyright 2010 Howard Hinnant
//  Copyright 2011 Vicente J. Botet Escriba
//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

// Adapted to Boost from the original Hawards's code

#include <iostream>
//#include <boost_kahypar/chrono/chrono_io.hpp>
#include <boost_kahypar/chrono/floor.hpp>
#include <boost_kahypar/chrono/round.hpp>
#include <boost_kahypar/chrono/ceil.hpp>

int main()
{
  boost_kahypar::chrono::milliseconds ms(2500);
  std::cout << __FILE__ << "[" << __LINE__ << "]" << std::endl;
  std::cout << boost_kahypar::chrono::floor<boost_kahypar::chrono::seconds>(ms).count()
      << " seconds\n";
  std::cout << __FILE__ << "[" << __LINE__ << "]" << std::endl;
  std::cout << boost_kahypar::chrono::round<boost_kahypar::chrono::seconds>(ms).count()
      << " seconds\n";
  std::cout << __FILE__ << "[" << __LINE__ << "]" << std::endl;
  std::cout << boost_kahypar::chrono::ceil<boost_kahypar::chrono::seconds>(ms).count()
      << " seconds\n";
  std::cout << __FILE__ << "[" << __LINE__ << "]" << std::endl;
  ms = boost_kahypar::chrono::milliseconds(2516);
  std::cout << __FILE__ << "[" << __LINE__ << "]" << std::endl;
  typedef boost_kahypar::chrono::duration<long, boost_kahypar::ratio<1, 30> > frame_rate;
  std::cout << __FILE__ << "[" << __LINE__ << "]" << std::endl;
  std::cout << boost_kahypar::chrono::floor<frame_rate>(ms).count()
      << " [1/30] seconds\n";
  std::cout << __FILE__ << "[" << __LINE__ << "]" << std::endl;
  std::cout << boost_kahypar::chrono::round<frame_rate>(ms).count()
      << " [1/30] seconds\n";
  std::cout << __FILE__ << "[" << __LINE__ << "]" << std::endl;
  std::cout << boost_kahypar::chrono::ceil<frame_rate>(ms).count()
      << " [1/30] seconds\n";
  std::cout << __FILE__ << "[" << __LINE__ << "]" << std::endl;

  return 0;
}
