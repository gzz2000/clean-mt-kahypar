// Copyright Thomas Witt 2003.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#include <boost_kahypar/iterator/indirect_iterator.hpp>
#include <boost_kahypar/iterator/reverse_iterator.hpp>
#include <boost_kahypar/concept_check.hpp>
#include <boost_kahypar/cstdlib.hpp>
#include <list>

int main()
{
  {
    typedef boost_kahypar::reverse_iterator<std::list<int*>::iterator>   rev_iter;
    typedef boost_kahypar::indirect_iterator<std::list<int*>::iterator>  ind_iter;

    ind_iter() == rev_iter();
  }

  return boost_kahypar::exit_success;
}
