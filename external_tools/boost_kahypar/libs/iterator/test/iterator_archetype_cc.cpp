//
// Copyright Thomas Witt 2003.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include <boost_kahypar/iterator/iterator_archetypes.hpp>
#include <boost_kahypar/iterator/iterator_categories.hpp>
#include <boost_kahypar/iterator/iterator_concepts.hpp>
#include <boost_kahypar/concept_check.hpp>
#include <boost_kahypar/cstdlib.hpp>

int main()
{
  {
    typedef boost_kahypar::iterator_archetype<
        int
      , boost_kahypar::iterator_archetypes::readable_iterator_t
      , boost_kahypar::random_access_traversal_tag
    > iter;

    boost_kahypar::function_requires< boost_kahypar_concepts::ReadableIteratorConcept<iter> >();
    boost_kahypar::function_requires< boost_kahypar_concepts::RandomAccessTraversalConcept<iter> >();
  }
  {
    typedef boost_kahypar::iterator_archetype<
        int
      , boost_kahypar::iterator_archetypes::readable_writable_iterator_t
      , boost_kahypar::random_access_traversal_tag
    > iter;

    boost_kahypar::function_requires< boost_kahypar_concepts::ReadableIteratorConcept<iter> >();
    boost_kahypar::function_requires< boost_kahypar_concepts::WritableIteratorConcept<iter> >();
    boost_kahypar::function_requires< boost_kahypar_concepts::RandomAccessTraversalConcept<iter> >();
  }
  {
    typedef boost_kahypar::iterator_archetype<
        const int // I don't like adding const to Value. It is redundant. -JGS
      , boost_kahypar::iterator_archetypes::readable_lvalue_iterator_t
      , boost_kahypar::random_access_traversal_tag
    > iter;

    boost_kahypar::function_requires< boost_kahypar_concepts::ReadableIteratorConcept<iter> >();
    boost_kahypar::function_requires< boost_kahypar_concepts::LvalueIteratorConcept<iter> >();
    boost_kahypar::function_requires< boost_kahypar_concepts::RandomAccessTraversalConcept<iter> >();
  }
  {
    typedef boost_kahypar::iterator_archetype<
        int
      , boost_kahypar::iterator_archetypes::writable_lvalue_iterator_t
      , boost_kahypar::random_access_traversal_tag
    > iter;

    boost_kahypar::function_requires< boost_kahypar_concepts::WritableIteratorConcept<iter> >();
    boost_kahypar::function_requires< boost_kahypar_concepts::LvalueIteratorConcept<iter> >();
    boost_kahypar::function_requires< boost_kahypar_concepts::RandomAccessTraversalConcept<iter> >();
  }

  return boost_kahypar::exit_success;
}

