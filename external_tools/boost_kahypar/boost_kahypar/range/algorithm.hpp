///////////////////////////////////////////////////////////////////////////////
/// \file algorithm.hpp
///   Includes the range-based versions of the algorithms in the
///   C++ standard header file <algorithm>
//
/////////////////////////////////////////////////////////////////////////////

// Copyright 2009 Neil Groves.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// Acknowledgements:
// This code uses combinations of ideas, techniques and code snippets
// from: Thorsten Ottosen, Eric Niebler, Jeremy Siek,
// and Vladimir Prus'
//
// The original mutating algorithms that served as the first version
// were originally written by Vladimir Prus'
// <ghost@cs.msu.su> code from Boost Wiki

#if defined(_MSC_VER)
#pragma once
#endif

#ifndef BOOST_RANGE_ALGORITHM_HPP_INCLUDED_01012009
#define BOOST_RANGE_ALGORITHM_HPP_INCLUDED_01012009

#include <boost_kahypar/range/concepts.hpp>
#include <boost_kahypar/range/iterator_range.hpp>
#include <boost_kahypar/range/difference_type.hpp>
#include <boost_kahypar/range/detail/range_return.hpp>
#include <boost_kahypar/iterator/iterator_traits.hpp>
#include <boost_kahypar/next_prior.hpp>
#include <algorithm>

// Non-mutating algorithms
#include <boost_kahypar/range/algorithm/adjacent_find.hpp>
#include <boost_kahypar/range/algorithm/count.hpp>
#include <boost_kahypar/range/algorithm/count_if.hpp>
#include <boost_kahypar/range/algorithm/equal.hpp>
#include <boost_kahypar/range/algorithm/for_each.hpp>
#include <boost_kahypar/range/algorithm/find.hpp>
#include <boost_kahypar/range/algorithm/find_end.hpp>
#include <boost_kahypar/range/algorithm/find_first_of.hpp>
#include <boost_kahypar/range/algorithm/find_if.hpp>
#include <boost_kahypar/range/algorithm/lexicographical_compare.hpp>
#include <boost_kahypar/range/algorithm/mismatch.hpp>
#include <boost_kahypar/range/algorithm/search.hpp>
#include <boost_kahypar/range/algorithm/search_n.hpp>

// Mutating algorithms
#include <boost_kahypar/range/algorithm/copy.hpp>
#include <boost_kahypar/range/algorithm/copy_backward.hpp>
#include <boost_kahypar/range/algorithm/fill.hpp>
#include <boost_kahypar/range/algorithm/fill_n.hpp>
#include <boost_kahypar/range/algorithm/generate.hpp>
#include <boost_kahypar/range/algorithm/inplace_merge.hpp>
#include <boost_kahypar/range/algorithm/merge.hpp>
#include <boost_kahypar/range/algorithm/nth_element.hpp>
#include <boost_kahypar/range/algorithm/partial_sort.hpp>
#include <boost_kahypar/range/algorithm/partial_sort_copy.hpp>
#include <boost_kahypar/range/algorithm/partition.hpp>
#include <boost_kahypar/range/algorithm/random_shuffle.hpp>
#include <boost_kahypar/range/algorithm/remove.hpp>
#include <boost_kahypar/range/algorithm/remove_copy.hpp>
#include <boost_kahypar/range/algorithm/remove_copy_if.hpp>
#include <boost_kahypar/range/algorithm/remove_if.hpp>
#include <boost_kahypar/range/algorithm/replace.hpp>
#include <boost_kahypar/range/algorithm/replace_copy.hpp>
#include <boost_kahypar/range/algorithm/replace_copy_if.hpp>
#include <boost_kahypar/range/algorithm/replace_if.hpp>
#include <boost_kahypar/range/algorithm/reverse.hpp>
#include <boost_kahypar/range/algorithm/reverse_copy.hpp>
#include <boost_kahypar/range/algorithm/rotate.hpp>
#include <boost_kahypar/range/algorithm/rotate_copy.hpp>
#include <boost_kahypar/range/algorithm/sort.hpp>
#include <boost_kahypar/range/algorithm/stable_partition.hpp>
#include <boost_kahypar/range/algorithm/stable_sort.hpp>
#include <boost_kahypar/range/algorithm/transform.hpp>
#include <boost_kahypar/range/algorithm/unique.hpp>
#include <boost_kahypar/range/algorithm/unique_copy.hpp>

// Binary search
#include <boost_kahypar/range/algorithm/binary_search.hpp>
#include <boost_kahypar/range/algorithm/equal_range.hpp>
#include <boost_kahypar/range/algorithm/lower_bound.hpp>
#include <boost_kahypar/range/algorithm/upper_bound.hpp>

// Set operations of sorted ranges
#include <boost_kahypar/range/algorithm/set_algorithm.hpp>

// Heap operations
#include <boost_kahypar/range/algorithm/heap_algorithm.hpp>

// Minimum and Maximum
#include <boost_kahypar/range/algorithm/max_element.hpp>
#include <boost_kahypar/range/algorithm/min_element.hpp>

// Permutations
#include <boost_kahypar/range/algorithm/permutation.hpp>

#endif // include guard

