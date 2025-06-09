// Copyright (C) 2004 Jeremy Siek <jsiek@cs.indiana.edu>
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost_kahypar/iterator/iterator_concepts.hpp>
#include <boost_kahypar/iterator/iterator_archetypes.hpp>
#include <boost_kahypar/cstdlib.hpp>

int main()
{
  typedef boost_kahypar::iterator_archetype<
        int
      , boost_kahypar::iterator_archetypes::readable_iterator_t
      , boost_kahypar::single_pass_traversal_tag
    > Iter;
  boost_kahypar::function_requires<
    boost_kahypar_concepts::LvalueIteratorConcept<Iter> >();
  return boost_kahypar::exit_success;
}
