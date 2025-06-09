//  Copyright 2015 Vicente J. Botet Escriba
//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt
//  See http://www.boost.org/libs/chrono for documentation.

#define BOOST_CHRONO_VERION 2
#include <iostream>
#include <boost_kahypar/chrono/chrono.hpp>
#include <boost_kahypar/chrono/chrono_io.hpp>

// a custom clock
// here based on boost's own system_clock
class MyMillenniumClock
{
public:
  typedef boost_kahypar::chrono::system_clock::rep rep;
  typedef boost_kahypar::chrono::system_clock::period period;
  typedef boost_kahypar::chrono::duration<rep, period> duration;
  typedef boost_kahypar::chrono::time_point<MyMillenniumClock> time_point;

  BOOST_STATIC_CONSTEXPR bool is_steady = boost_kahypar::chrono::system_clock::is_steady;

public:
  /// Returns a time_point representing the current value of the clock.
  static time_point now() {
    return time_point(boost_kahypar::chrono::system_clock::now().time_since_epoch() - boost_kahypar::chrono::hours(30*365));
  }
};


namespace boost_kahypar
{
  namespace chrono
  {
    template <class CharT>
    struct clock_string<MyMillenniumClock, CharT>
    {
      static std::basic_string<CharT> name() {
        static const CharT a[] = {'M', 'y', 'M', 'i', 'l', 'l', 'e', 'n', 'n', 'i', 'u', 'm', 'C', 'l', 'o', 'c', 'k'};
        return std::basic_string<CharT>(a, a + sizeof(a)/sizeof(a[0]));
      }
      static std::basic_string<CharT> since() {
        static const CharT a[] = {' ', 's', 'i', 'n', 'c', 'e', ' ', 'y', 'e', 'a', 'r', ' ', '2', 'k'};
        return std::basic_string<CharT>(a, a + sizeof(a)/sizeof(a[0]));
      }
    };
  }
}

template <typename CharT, typename TPUFacet>
std::basic_string<CharT> get_epoch_custom(MyMillenniumClock, TPUFacet&)
{
  return boost_kahypar::chrono::clock_string<MyMillenniumClock,CharT>::since();
}

int main()
{
    std::cout << boost_kahypar::chrono::steady_clock::now() << std::endl;
    std::cout << MyMillenniumClock::now() << std::endl;
    return 0;
}
