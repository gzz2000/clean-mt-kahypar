//  (C) Copyright Jeremy Siek 1999-2004.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost_kahypar/config.hpp>
#include <algorithm>
#include <functional>
#include <iostream>
#include <boost_kahypar/iterator/filter_iterator.hpp>
#include <boost_kahypar/bind/bind.hpp>
#include <boost_kahypar/cstdlib.hpp> // for exit_success

struct is_positive_number {
  bool operator()(int x) { return 0 < x; }
};

int main()
{
  int numbers_[] = { 0, -1, 4, -3, 5, 8, -2 };
  const int N = sizeof(numbers_)/sizeof(int);

  typedef int* base_iterator;
  base_iterator numbers(numbers_);

  // Example using make_filter_iterator()
  std::copy(boost_kahypar::make_filter_iterator<is_positive_number>(numbers, numbers + N),
            boost_kahypar::make_filter_iterator<is_positive_number>(numbers + N, numbers + N),
            std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  // Example using filter_iterator
  typedef boost_kahypar::filter_iterator<is_positive_number, base_iterator>
    FilterIter;

  is_positive_number predicate;
  FilterIter filter_iter_first(predicate, numbers, numbers + N);
  FilterIter filter_iter_last(predicate, numbers + N, numbers + N);

  std::copy(filter_iter_first, filter_iter_last, std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  // Another example using make_filter_iterator()
  std::copy(
      boost_kahypar::make_filter_iterator(
          boost_kahypar::bind(std::greater<int>(), boost_kahypar::placeholders::_1, -2)
        , numbers, numbers + N)

    , boost_kahypar::make_filter_iterator(
          boost_kahypar::bind(std::greater<int>(), boost_kahypar::placeholders::_1, -2)
        , numbers + N, numbers + N)

    , std::ostream_iterator<int>(std::cout, " ")
  );

  std::cout << std::endl;

  return boost_kahypar::exit_success;
}
