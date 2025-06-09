// (C) Copyright Jeremy Siek 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost_kahypar/iterator/iterator_concepts.hpp>
#include <boost_kahypar/iterator/iterator_categories.hpp>
#include <boost_kahypar/operators.hpp>

#include <iterator>
#include <cstddef>

struct new_random_access
  : std::random_access_iterator_tag
  , boost_kahypar::random_access_traversal_tag
{};

struct new_iterator
{
  typedef new_random_access iterator_category;
  typedef int value_type;
  typedef std::ptrdiff_t difference_type;
  typedef int* pointer;
  typedef int& reference;

  int& operator*() const { return *m_x; }
  new_iterator& operator++() { return *this; }
  new_iterator operator++(int) { return *this; }
  new_iterator& operator--() { return *this; }
  new_iterator operator--(int) { return *this; }
  new_iterator& operator+=(std::ptrdiff_t) { return *this; }
  new_iterator operator+(std::ptrdiff_t) { return *this; }
  new_iterator& operator-=(std::ptrdiff_t) { return *this; }
  std::ptrdiff_t operator-(const new_iterator&) const { return 0; }
  new_iterator operator-(std::ptrdiff_t) const { return *this; }
  bool operator==(const new_iterator&) const { return false; }
  bool operator!=(const new_iterator&) const { return false; }
  bool operator<(const new_iterator&) const { return false; }
  int* m_x;
};
new_iterator operator+(std::ptrdiff_t, new_iterator x) { return x; }

struct old_iterator
{
  typedef std::random_access_iterator_tag iterator_category;
  typedef int value_type;
  typedef std::ptrdiff_t difference_type;
  typedef int* pointer;
  typedef int& reference;

  int& operator*() const { return *m_x; }
  old_iterator& operator++() { return *this; }
  old_iterator operator++(int) { return *this; }
  old_iterator& operator--() { return *this; }
  old_iterator operator--(int) { return *this; }
  old_iterator& operator+=(std::ptrdiff_t) { return *this; }
  old_iterator operator+(std::ptrdiff_t) { return *this; }
  old_iterator& operator-=(std::ptrdiff_t) { return *this; }
  old_iterator operator-(std::ptrdiff_t) const { return *this; }
  std::ptrdiff_t operator-(const old_iterator&) const { return 0; }
  bool operator==(const old_iterator&) const { return false; }
  bool operator!=(const old_iterator&) const { return false; }
  bool operator<(const old_iterator&) const { return false; }
  int* m_x;
};
old_iterator operator+(std::ptrdiff_t, old_iterator x) { return x; }

int
main()
{
  boost_kahypar::iterator_traversal<new_iterator>::type tc;
  boost_kahypar::random_access_traversal_tag derived = tc;
  (void)derived;

  boost_kahypar::function_requires<
    boost_kahypar_concepts::WritableIteratorConcept<int*> >();
  boost_kahypar::function_requires<
    boost_kahypar_concepts::LvalueIteratorConcept<int*> >();
  boost_kahypar::function_requires<
    boost_kahypar_concepts::RandomAccessTraversalConcept<int*> >();

  boost_kahypar::function_requires<
    boost_kahypar_concepts::ReadableIteratorConcept<const int*> >();
  boost_kahypar::function_requires<
    boost_kahypar_concepts::LvalueIteratorConcept<const int*> >();
  boost_kahypar::function_requires<
    boost_kahypar_concepts::RandomAccessTraversalConcept<const int*> >();

  boost_kahypar::function_requires<
    boost_kahypar_concepts::WritableIteratorConcept<new_iterator> >();
  boost_kahypar::function_requires<
    boost_kahypar_concepts::LvalueIteratorConcept<new_iterator> >();
  boost_kahypar::function_requires<
    boost_kahypar_concepts::RandomAccessTraversalConcept<new_iterator> >();

  boost_kahypar::function_requires<
    boost_kahypar_concepts::WritableIteratorConcept<old_iterator> >();
  boost_kahypar::function_requires<
    boost_kahypar_concepts::LvalueIteratorConcept<old_iterator> >();
  boost_kahypar::function_requires<
    boost_kahypar_concepts::RandomAccessTraversalConcept<old_iterator> >();

  boost_kahypar::function_requires<
    boost_kahypar_concepts::InteroperableIteratorConcept<int*, int const*> >();

  return 0;
}
