// Copyright David Abrahams 2003, Jeremy Siek 2004.

// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost_kahypar/iterator/filter_iterator.hpp>
#include <boost_kahypar/iterator/reverse_iterator.hpp>
#include <boost_kahypar/iterator/new_iterator_tests.hpp>
#include <boost_kahypar/type_traits/is_convertible.hpp>
#include <boost_kahypar/concept_check.hpp>
#include <boost_kahypar/concept_archetype.hpp>
#include <boost_kahypar/iterator/iterator_concepts.hpp>
#include <boost_kahypar/iterator/iterator_archetypes.hpp>
#include <boost_kahypar/cstdlib.hpp>

#include <deque>
#include <iostream>

using boost_kahypar::dummyT;

struct one_or_four
{
    bool operator()(dummyT x) const
    {
        return x.foo() == 1 || x.foo() == 4;
    }
};

template <class T> struct undefined;

template <class T> struct see_type;

// Test filter iterator
int main()
{
    // Concept checks
    // Adapting old-style iterators
    {
      typedef boost_kahypar::filter_iterator<one_or_four, boost_kahypar::input_iterator_archetype<dummyT> > Iter;
      boost_kahypar::function_requires< boost_kahypar::InputIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::ReadableIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::SinglePassIteratorConcept<Iter> >();
    }
    {
      typedef boost_kahypar::filter_iterator<one_or_four, boost_kahypar::input_output_iterator_archetype<dummyT> > Iter;
      boost_kahypar::function_requires< boost_kahypar::InputIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar::OutputIteratorConcept<Iter, dummyT> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::ReadableIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::WritableIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::SinglePassIteratorConcept<Iter> >();
    }
    {
      typedef boost_kahypar::filter_iterator<one_or_four, boost_kahypar::forward_iterator_archetype<dummyT> > Iter;
      boost_kahypar::function_requires< boost_kahypar::ForwardIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::ReadableIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::ForwardTraversalConcept<Iter> >();
    }
    {
      typedef boost_kahypar::filter_iterator<one_or_four, boost_kahypar::mutable_forward_iterator_archetype<dummyT> > Iter;
      boost_kahypar::function_requires< boost_kahypar::Mutable_ForwardIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::ReadableIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::WritableIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::ForwardTraversalConcept<Iter> >();
    }
    {
      typedef boost_kahypar::filter_iterator<one_or_four, boost_kahypar::bidirectional_iterator_archetype<dummyT> > Iter;
      boost_kahypar::function_requires< boost_kahypar::BidirectionalIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::ReadableIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::BidirectionalTraversalConcept<Iter> >();
    }
    {
      typedef boost_kahypar::filter_iterator<one_or_four, boost_kahypar::mutable_bidirectional_iterator_archetype<dummyT> > Iter;
      boost_kahypar::function_requires< boost_kahypar::Mutable_BidirectionalIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::ReadableIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::WritableIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::BidirectionalTraversalConcept<Iter> >();
    }
    {
      typedef boost_kahypar::filter_iterator<one_or_four, boost_kahypar::random_access_iterator_archetype<dummyT> > Iter;
      boost_kahypar::function_requires< boost_kahypar::BidirectionalIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::ReadableIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::BidirectionalTraversalConcept<Iter> >();
    }
    {
      typedef boost_kahypar::filter_iterator<one_or_four, boost_kahypar::mutable_random_access_iterator_archetype<dummyT> > Iter;
      boost_kahypar::function_requires< boost_kahypar::Mutable_BidirectionalIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::ReadableIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::WritableIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::BidirectionalTraversalConcept<Iter> >();
    }
    // Adapting new-style iterators
    {
      typedef boost_kahypar::iterator_archetype<
          const dummyT
        , boost_kahypar::iterator_archetypes::readable_iterator_t
        , boost_kahypar::single_pass_traversal_tag
      > BaseIter;
      typedef boost_kahypar::filter_iterator<one_or_four, BaseIter> Iter;
      boost_kahypar::function_requires< boost_kahypar::InputIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::ReadableIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::SinglePassIteratorConcept<Iter> >();
    }
#if !BOOST_WORKAROUND(BOOST_MSVC, == 1200)  // Causes Internal Error in linker.
    {
      typedef boost_kahypar::iterator_archetype<
          dummyT
        , boost_kahypar::iterator_archetypes::readable_writable_iterator_t
        , boost_kahypar::single_pass_traversal_tag
      > BaseIter;
      typedef boost_kahypar::filter_iterator<one_or_four, BaseIter> Iter;

      boost_kahypar::function_requires< boost_kahypar::InputIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar::OutputIteratorConcept<Iter, dummyT> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::ReadableIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::WritableIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::SinglePassIteratorConcept<Iter> >();
    }
#endif
    {
      typedef boost_kahypar::iterator_archetype<
          const dummyT
        , boost_kahypar::iterator_archetypes::readable_iterator_t
        , boost_kahypar::forward_traversal_tag
      > BaseIter;
      typedef boost_kahypar::filter_iterator<one_or_four, BaseIter> Iter;
      boost_kahypar::function_requires< boost_kahypar::InputIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::ReadableIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::ForwardTraversalConcept<Iter> >();
    }

#if !BOOST_WORKAROUND(BOOST_MSVC, == 1200)  // Causes Internal Error in linker.
    {
      typedef boost_kahypar::iterator_archetype<
          dummyT
        , boost_kahypar::iterator_archetypes::readable_writable_iterator_t
        , boost_kahypar::forward_traversal_tag
      > BaseIter;
      typedef boost_kahypar::filter_iterator<one_or_four, BaseIter> Iter;
      boost_kahypar::function_requires< boost_kahypar_concepts::ReadableIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::WritableIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::ForwardTraversalConcept<Iter> >();
    }
    {
      typedef boost_kahypar::iterator_archetype<
          const dummyT
        , boost_kahypar::iterator_archetypes::readable_lvalue_iterator_t
        , boost_kahypar::forward_traversal_tag
      > BaseIter;
      typedef boost_kahypar::filter_iterator<one_or_four, BaseIter> Iter;
      boost_kahypar::function_requires< boost_kahypar::ForwardIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::ReadableIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::LvalueIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::ForwardTraversalConcept<Iter> >();
    }
    {
      typedef boost_kahypar::iterator_archetype<
          dummyT
        , boost_kahypar::iterator_archetypes::writable_lvalue_iterator_t
        , boost_kahypar::forward_traversal_tag
      > BaseIter;
      typedef boost_kahypar::filter_iterator<one_or_four, BaseIter> Iter;
      boost_kahypar::function_requires< boost_kahypar::Mutable_ForwardIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::WritableIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::LvalueIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::ForwardTraversalConcept<Iter> >();
    }
#endif

    {
      typedef boost_kahypar::iterator_archetype<
          const dummyT
        , boost_kahypar::iterator_archetypes::readable_iterator_t
        , boost_kahypar::random_access_traversal_tag
      > BaseIter;
      typedef boost_kahypar::filter_iterator<one_or_four, BaseIter> Iter;
      boost_kahypar::function_requires< boost_kahypar::InputIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::ReadableIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::BidirectionalTraversalConcept<Iter> >();
    }

#if !BOOST_WORKAROUND(BOOST_MSVC, == 1200)  // Causes Internal Error in linker.
    {
      typedef boost_kahypar::iterator_archetype<
          dummyT
        , boost_kahypar::iterator_archetypes::readable_writable_iterator_t
        , boost_kahypar::random_access_traversal_tag
      > BaseIter;
      typedef boost_kahypar::filter_iterator<one_or_four, BaseIter> Iter;
      boost_kahypar::function_requires< boost_kahypar_concepts::ReadableIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::WritableIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::BidirectionalTraversalConcept<Iter> >();
    }
    {
      typedef boost_kahypar::iterator_archetype<
          const dummyT
        , boost_kahypar::iterator_archetypes::readable_lvalue_iterator_t
        , boost_kahypar::random_access_traversal_tag
      > BaseIter;
      typedef boost_kahypar::filter_iterator<one_or_four, BaseIter> Iter;
      boost_kahypar::function_requires< boost_kahypar::BidirectionalIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::ReadableIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::LvalueIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::BidirectionalTraversalConcept<Iter> >();
    }
    {
      typedef boost_kahypar::iterator_archetype<
          dummyT
        , boost_kahypar::iterator_archetypes::writable_lvalue_iterator_t
        , boost_kahypar::random_access_traversal_tag
      > BaseIter;
      typedef boost_kahypar::filter_iterator<one_or_four, BaseIter> Iter;
      boost_kahypar::function_requires< boost_kahypar::Mutable_BidirectionalIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::WritableIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::LvalueIteratorConcept<Iter> >();
      boost_kahypar::function_requires< boost_kahypar_concepts::BidirectionalTraversalConcept<Iter> >();
    }
#endif

    // Run-time tests

    dummyT array[] = { dummyT(0), dummyT(1), dummyT(2),
                       dummyT(3), dummyT(4), dummyT(5) };
    const int N = sizeof(array)/sizeof(dummyT);

    typedef boost_kahypar::filter_iterator<one_or_four, dummyT*> filter_iter;

    boost_kahypar::bidirectional_readable_iterator_test(
        filter_iter(one_or_four(), array, array+N)
        , dummyT(1), dummyT(4));

    BOOST_STATIC_ASSERT(
        (!boost_kahypar::is_convertible<
             boost_kahypar::iterator_traversal<filter_iter>::type
           , boost_kahypar::random_access_traversal_tag
         >::value
        ));

    //# endif

    // On compilers not supporting partial specialization, we can do more type
    // deduction with deque iterators than with pointers... unless the library
    // is broken ;-(
    std::deque<dummyT> array2;
    std::copy(array+0, array+N, std::back_inserter(array2));
    boost_kahypar::bidirectional_readable_iterator_test(
        boost_kahypar::make_filter_iterator(one_or_four(), array2.begin(), array2.end()),
        dummyT(1), dummyT(4));

    boost_kahypar::bidirectional_readable_iterator_test(
        boost_kahypar::make_filter_iterator(one_or_four(), array2.begin(), array2.end()),
        dummyT(1), dummyT(4));

    boost_kahypar::bidirectional_readable_iterator_test(
        boost_kahypar::make_filter_iterator(
              one_or_four()
            , boost_kahypar::make_reverse_iterator(array2.end())
            , boost_kahypar::make_reverse_iterator(array2.begin())
            ),
        dummyT(4), dummyT(1));

    boost_kahypar::bidirectional_readable_iterator_test(
        filter_iter(array+0, array+N),
        dummyT(1), dummyT(4));

    boost_kahypar::bidirectional_readable_iterator_test(
        filter_iter(one_or_four(), array, array + N),
        dummyT(1), dummyT(4));


    return boost_kahypar::report_errors();
}
