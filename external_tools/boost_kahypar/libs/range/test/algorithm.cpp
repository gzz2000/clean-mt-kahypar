// Boost.Range library
//
//  Copyright Thorsten Ottosen 2006. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//
//  (C) Copyright Eric Niebler 2004.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/*
 Revision history:
   13 December 2004 : Initial version.
*/

#ifdef _MSC_VER
// The 'secure' library warnings produce so much noise that it makes it
// impossible to see more useful warnings.
    #define _SCL_SECURE_NO_WARNINGS
#endif

#ifdef _MSC_VER
    // counting_iterator generates a warning about truncating an integer
    #pragma warning(push)
    #pragma warning(disable : 4244)
#endif
#include <boost_kahypar/iterator/counting_iterator.hpp>
#ifdef _MSC_VER
    template ::boost_kahypar::counting_iterator<int>;
    #pragma warning(pop)
#endif

#include <boost_kahypar/assign.hpp>
#include <boost_kahypar/config.hpp>
#include <boost_kahypar/array.hpp>
#include <boost_kahypar/range/numeric.hpp>
#include <boost_kahypar/range/algorithm.hpp>
#include <boost_kahypar/range/value_type.hpp>
#include <boost_kahypar/range/size_type.hpp>
#include <boost_kahypar/range/size.hpp>

#include <boost_kahypar/test/test_tools.hpp>
#include <boost_kahypar/test/unit_test.hpp>

#include <boost_kahypar/iterator/iterator_traits.hpp>

#include <algorithm>
#include <cstdlib>
#include <set>
#include <list>
#include <vector>
#include <iterator>
#include <functional>
///////////////////////////////////////////////////////////////////////////////
// dummy function object, used with algorithms
//
struct null_fun
{
    template<typename T>
        void operator()(T const &t) const
    {
    }
};

///////////////////////////////////////////////////////////////////////////////
// dummy predicate, used with algorithms
//
struct null_pred
{
    template<typename T>
    bool operator()(T const &t) const
    {
        return t == T();
    }
};

///////////////////////////////////////////////////////////////////////////////
// dummy unary op, used with algorithms
//
struct null_op1
{
    template<typename T>
    T const & operator()(T const & t) const
    {
        return t;
    }
};

///////////////////////////////////////////////////////////////////////////////
// dummy binary op, used with algorithms
//
struct null_op2
{
    template<typename T,typename U>
    T const & operator()(T const & t, U const & u) const
    {
        return t;
    }
};

template<typename Rng>
void test_random_algorithms(Rng & rng, std::random_access_iterator_tag)
{
    typedef BOOST_DEDUCED_TYPENAME boost_kahypar::range_iterator<Rng>::type iterator;

    typedef BOOST_DEDUCED_TYPENAME boost_kahypar::range_value<Rng>::type value_type;

    typedef BOOST_DEDUCED_TYPENAME boost_kahypar::range_size<Rng>::type
                                        size_type BOOST_RANGE_UNUSED;

    typedef BOOST_DEDUCED_TYPENAME boost_kahypar::iterator_category<iterator>::type
                                        iterator_category BOOST_RANGE_UNUSED;

    // just make sure these compile (for now)
    if(0)
    {
        boost_kahypar::random_shuffle(rng);

        // Must be a value since random_shuffle must take the generator by
        // reference to match the standard.
        null_op1 rng_generator; 
        boost_kahypar::random_shuffle(rng, rng_generator);

        boost_kahypar::sort(rng);
        boost_kahypar::sort(rng, std::less<value_type>());

        boost_kahypar::stable_sort(rng);
        boost_kahypar::stable_sort(rng, std::less<value_type>());

        boost_kahypar::partial_sort(rng, boost_kahypar::begin(rng));
        boost_kahypar::partial_sort(rng, boost_kahypar::begin(rng), std::less<value_type>());

        boost_kahypar::nth_element(rng, boost_kahypar::begin(rng));
        boost_kahypar::nth_element(rng, boost_kahypar::begin(rng), std::less<value_type>());

        boost_kahypar::push_heap(rng);
        boost_kahypar::push_heap(rng, std::less<value_type>());

        boost_kahypar::pop_heap(rng);
        boost_kahypar::pop_heap(rng, std::less<value_type>());

        boost_kahypar::make_heap(rng);
        boost_kahypar::make_heap(rng, std::less<value_type>());

        boost_kahypar::sort_heap(rng);
        boost_kahypar::sort_heap(rng, std::less<value_type>());
    }
}

template<typename Rng>
void test_random_algorithms(Rng & rng, std::input_iterator_tag)
{
    // no-op
}

template<typename Rng>
void test_algorithms(Rng & rng)
{
    typedef BOOST_DEDUCED_TYPENAME boost_kahypar::range_iterator<Rng>::type iterator;
    typedef BOOST_DEDUCED_TYPENAME boost_kahypar::range_value<Rng>::type value_type;
    typedef BOOST_DEDUCED_TYPENAME boost_kahypar::range_size<Rng>::type size_type;
    typedef BOOST_DEDUCED_TYPENAME boost_kahypar::iterator_category<iterator>::type iterator_category;

    // just make sure these compile (for now)
    if(0)
    {
        value_type val = value_type();

        value_type rng2[] = {value_type(),value_type(),value_type()};
        typedef value_type* iterator2;

        value_type out[100] = {};
        typedef value_type* out_iterator;

        null_fun f = null_fun();
        iterator i = iterator();
        bool b = bool();
        out_iterator o = out_iterator();
        size_type s = size_type();

        f = boost_kahypar::for_each(rng, null_fun());

        i = boost_kahypar::find(rng, val);
        i = boost_kahypar::find_if(rng, null_pred());

        i = boost_kahypar::find_end(rng, rng2);
        i = boost_kahypar::find_end(rng, rng2, std::equal_to<value_type>());

        i = boost_kahypar::find_first_of(rng, rng2);
        i = boost_kahypar::find_first_of(rng, rng2, std::equal_to<value_type>());

        i = boost_kahypar::adjacent_find(rng);
        i = boost_kahypar::adjacent_find(rng, std::equal_to<value_type>());

        s = boost_kahypar::count(rng, val);
        s = boost_kahypar::count_if(rng, null_pred());

        std::pair<iterator,iterator2> p1;
        p1 = boost_kahypar::mismatch(rng, rng2);
        p1 = boost_kahypar::mismatch(rng, rng2, std::equal_to<value_type>());

        b = boost_kahypar::equal(rng, rng2);
        b = boost_kahypar::equal(rng, rng2, std::equal_to<value_type>());

        i = boost_kahypar::search(rng, rng2);
        i = boost_kahypar::search(rng, rng2, std::equal_to<value_type>());

        o = boost_kahypar::copy(rng, boost_kahypar::begin(out));
        o = boost_kahypar::copy_backward(rng, boost_kahypar::end(out));

        o = boost_kahypar::transform(rng, boost_kahypar::begin(out), null_op1());
        o = boost_kahypar::transform(rng, rng2, boost_kahypar::begin(out), null_op2());

        boost_kahypar::replace(rng, val, val);
        boost_kahypar::replace_if(rng, null_pred(), val);

/*
        o = boost_kahypar::replace_copy(rng, boost_kahypar::begin(out), val, val);
        o = boost_kahypar::replace_copy_if(rng, boost_kahypar::begin(out), null_pred(), val);
*/

        boost_kahypar::fill(rng, val);
        //
        // size requires RandomAccess
        //
        //boost_kahypar::fill_n(rng, boost_kahypar::size(rng), val);
        //boost_kahypar::fill_n(rng, std::distance(boost_kahypar::begin(rng),boost_kahypar::end(rng)),val);

        boost_kahypar::generate(rng, &std::rand);
        //
        // size requires RandomAccess   
        //
        //boost_kahypar::generate_n(rng, boost_kahypar::size(rng), &std::rand);
        //boost_kahypar::generate_n(rng,std::distance(boost_kahypar::begin(rng),boost_kahypar::end(rng)), &std::rand);

        i = boost_kahypar::remove(rng, val);
        i = boost_kahypar::remove_if(rng, null_pred());

/*
        o = boost_kahypar::remove_copy(rng, boost_kahypar::begin(out), val);
        o = boost_kahypar::remove_copy_if(rng, boost_kahypar::begin(out), null_pred());
*/

        typename boost_kahypar::range_return<Rng, boost_kahypar::return_begin_found>::type rrng = boost_kahypar::unique(rng);
        rrng = boost_kahypar::unique(rng, std::equal_to<value_type>());

/*
        o = boost_kahypar::unique_copy(rng, boost_kahypar::begin(out));
        o = boost_kahypar::unique_copy(rng, boost_kahypar::begin(out), std::equal_to<value_type>());
*/

        boost_kahypar::reverse(rng);

/*
        o = boost_kahypar::reverse_copy(rng, boost_kahypar::begin(out));
*/

        boost_kahypar::rotate(rng, boost_kahypar::begin(rng));

/*
        o = boost_kahypar::rotate_copy(rng, boost_kahypar::begin(rng), boost_kahypar::begin(out));
*/

        i = boost_kahypar::partition(rng, null_pred());
        i = boost_kahypar::stable_partition(rng, null_pred());

/*
        o = boost_kahypar::partial_sort_copy(rng, out);
        o = boost_kahypar::partial_sort_copy(rng, out, std::less<value_type>());
*/

        i = boost_kahypar::lower_bound(rng, val);
        i = boost_kahypar::lower_bound(rng, val, std::less<value_type>());

        i = boost_kahypar::upper_bound(rng, val);
        i = boost_kahypar::upper_bound(rng, val, std::less<value_type>());

        std::pair<iterator,iterator> p2;
        p2 = boost_kahypar::equal_range(rng, val);
        p2 = boost_kahypar::equal_range(rng, val, std::less<value_type>());

        b = boost_kahypar::binary_search(rng, val);
        b = boost_kahypar::binary_search(rng, val, std::less<value_type>());

        boost_kahypar::inplace_merge(rng, boost_kahypar::begin(rng));
        boost_kahypar::inplace_merge(rng, boost_kahypar::begin(rng), std::less<value_type>());

        b = boost_kahypar::includes(rng, rng2);
        b = boost_kahypar::includes(rng, rng2, std::equal_to<value_type>());

        o = boost_kahypar::set_union(rng, rng2, boost_kahypar::begin(out));
        o = boost_kahypar::set_union(rng, rng2, boost_kahypar::begin(out), std::equal_to<value_type>());

        o = boost_kahypar::set_intersection(rng, rng2, boost_kahypar::begin(out));
        o = boost_kahypar::set_intersection(rng, rng2, boost_kahypar::begin(out), std::equal_to<value_type>());

        o = boost_kahypar::set_difference(rng, rng2, boost_kahypar::begin(out));
        o = boost_kahypar::set_difference(rng, rng2, boost_kahypar::begin(out), std::equal_to<value_type>());

        o = boost_kahypar::set_symmetric_difference(rng, rng2, boost_kahypar::begin(out));
        o = boost_kahypar::set_symmetric_difference(rng, rng2, boost_kahypar::begin(out), std::equal_to<value_type>());

        i = boost_kahypar::min_element(rng);
        i = boost_kahypar::min_element(rng, std::less<value_type>());

        i = boost_kahypar::max_element(rng);
        i = boost_kahypar::max_element(rng, std::less<value_type>());

        b = boost_kahypar::lexicographical_compare(rng, rng);
        b = boost_kahypar::lexicographical_compare(rng, rng, std::equal_to<value_type>());

        b = boost_kahypar::next_permutation(rng);
        b = boost_kahypar::next_permutation(rng, std::less<value_type>());

        b = boost_kahypar::prev_permutation(rng);
        b = boost_kahypar::prev_permutation(rng, std::less<value_type>());

        /////////////////////////////////////////////////////////////////////
        // numeric algorithms
        /////////////////////////////////////////////////////////////////////

        val = boost_kahypar::accumulate( rng, val );
        val = boost_kahypar::accumulate( rng, val, null_op2() );
        val = boost_kahypar::inner_product( rng, rng, val );
        val = boost_kahypar::inner_product( rng, rng, val, 
                                    null_op2(), null_op2() );
        o   = boost_kahypar::partial_sum( rng, boost_kahypar::begin(out) );
        o   = boost_kahypar::partial_sum( rng, boost_kahypar::begin(out), null_op2() );
        o   = boost_kahypar::adjacent_difference( rng, boost_kahypar::begin(out) );
        o   = boost_kahypar::adjacent_difference( rng, boost_kahypar::begin(out), 
                                          null_op2() );
        
        boost_kahypar::ignore_unused_variable_warning(b);
         
    }

    // test the algorithms that require a random-access range
    test_random_algorithms(rng, iterator_category());
}

int* addr(int &i) { return &i; }
bool true_(int) { return true; }

///////////////////////////////////////////////////////////////////////////////
// test_main
//   
void simple_compile_test()
{
    // int_iterator
    typedef ::boost_kahypar::counting_iterator<int> int_iterator;

    // define come containers
    std::list<int> my_list(int_iterator(1),int_iterator(6));


    std::vector<int> my_vector(int_iterator(1),int_iterator(6));

    std::pair<std::vector<int>::iterator,std::vector<int>::iterator> my_pair(my_vector.begin(),my_vector.end());

    // test the algorithms with list and const list
    test_algorithms(my_list);
    test_algorithms(my_vector);
    test_algorithms(my_pair);

    
    std::vector<int> v;
    std::vector<int>& cv = v;

    using namespace boost_kahypar;

#define BOOST_RANGE_RETURNS_TEST( function_name, cont ) \
    function_name (cont); \
    function_name <return_found> (cont); \
    function_name <return_next> (cont); \
    function_name <return_prior> (cont); \
    function_name <return_begin_found> (cont); \
    function_name <return_begin_next> (cont); \
    function_name <return_begin_prior> (cont); \
    function_name <return_found_end> (cont); \
    function_name <return_next_end>(cont); \
    function_name <return_prior_end>(cont);

    BOOST_RANGE_RETURNS_TEST( adjacent_find, cv );
    BOOST_RANGE_RETURNS_TEST( adjacent_find, v );
    BOOST_RANGE_RETURNS_TEST( max_element, cv );
    BOOST_RANGE_RETURNS_TEST( max_element, v );
    BOOST_RANGE_RETURNS_TEST( min_element, cv );
    BOOST_RANGE_RETURNS_TEST( min_element, v );
    BOOST_RANGE_RETURNS_TEST( unique, v );
#undef BOOST_RANGE_RETURNS_TEST

#define BOOST_RANGE_RETURNS_TEST1( function_name, cont, arg1 ) \
    function_name (cont, arg1); \
    function_name <return_found> (cont, arg1); \
    function_name <return_next> (cont, arg1); \
    function_name <return_prior> (cont, arg1); \
    function_name <return_begin_found> (cont, arg1); \
    function_name <return_begin_next> (cont, arg1); \
    function_name <return_begin_prior> (cont, arg1); \
    function_name <return_found_end> (cont, arg1); \
    function_name <return_next_end>(cont, arg1); \
    function_name <return_prior_end>(cont, arg1);

    BOOST_RANGE_RETURNS_TEST1( adjacent_find, cv, std::less<int>() );
    BOOST_RANGE_RETURNS_TEST1( adjacent_find, v, std::less<int>() );
    BOOST_RANGE_RETURNS_TEST1( find, cv, 0 );
    BOOST_RANGE_RETURNS_TEST1( find, v, 0 );
    BOOST_RANGE_RETURNS_TEST1( find_end, cv, cv );
    BOOST_RANGE_RETURNS_TEST1( find_end, cv, v );
    BOOST_RANGE_RETURNS_TEST1( find_end, v, cv );
    BOOST_RANGE_RETURNS_TEST1( find_end, v, v );
    BOOST_RANGE_RETURNS_TEST1( find_first_of, cv, cv );
    BOOST_RANGE_RETURNS_TEST1( find_first_of, cv, v );
    BOOST_RANGE_RETURNS_TEST1( find_first_of, v, cv );
    BOOST_RANGE_RETURNS_TEST1( find_first_of, v, v );
    BOOST_RANGE_RETURNS_TEST1( find_if, cv, std::negate<int>() );
    BOOST_RANGE_RETURNS_TEST1( find_if, v, std::negate<int>() );
    BOOST_RANGE_RETURNS_TEST1( search, cv, cv );
    BOOST_RANGE_RETURNS_TEST1( search, cv, v );
    BOOST_RANGE_RETURNS_TEST1( search, v, cv );
    BOOST_RANGE_RETURNS_TEST1( search, v, v );

    BOOST_RANGE_RETURNS_TEST1( remove, v, 0 );
    BOOST_RANGE_RETURNS_TEST1( remove_if, v, std::negate<int>() );

    BOOST_RANGE_RETURNS_TEST1( lower_bound, cv, 0 );
    BOOST_RANGE_RETURNS_TEST1( lower_bound, v, 0 );
    BOOST_RANGE_RETURNS_TEST1( max_element, cv, std::less<int>() );
    BOOST_RANGE_RETURNS_TEST1( max_element, v, std::less<int>() );
    BOOST_RANGE_RETURNS_TEST1( min_element, cv, std::less<int>() );
    BOOST_RANGE_RETURNS_TEST1( min_element, v, std::less<int>() );
    BOOST_RANGE_RETURNS_TEST1( upper_bound, cv, 0 );
    BOOST_RANGE_RETURNS_TEST1( upper_bound, v, 0 );
    BOOST_RANGE_RETURNS_TEST1( partition, cv, std::negate<int>() );
    BOOST_RANGE_RETURNS_TEST1( partition, v, std::negate<int>() );
    BOOST_RANGE_RETURNS_TEST1( stable_partition, cv, std::negate<int>() );
    BOOST_RANGE_RETURNS_TEST1( stable_partition, v, std::negate<int>() );

#undef BOOST_RANGE_RETURNS_TEST1

#define BOOST_RANGE_RETURNS_TEST2( function_name, arg1, arg2 ) \
    function_name (v, arg1, arg2); \
    function_name <return_found> (v, arg1, arg2); \
    function_name <return_next> (v, arg1, arg2); \
    function_name <return_prior> (v, arg1, arg2); \
    function_name <return_begin_found> (v, arg1, arg2); \
    function_name <return_begin_next> (v, arg1, arg2); \
    function_name <return_begin_prior> (v, arg1, arg2); \
    function_name <return_found_end> (v, arg1, arg2); \
    function_name <return_next_end>(v, arg1, arg2); \
    function_name <return_prior_end>(v, arg1, arg2);

    BOOST_RANGE_RETURNS_TEST2( find_end, v, std::less<int>() );
    BOOST_RANGE_RETURNS_TEST2( find_first_of, v, std::less<int>() );
    BOOST_RANGE_RETURNS_TEST2( boost_kahypar::search, v, std::less<int>() );
    BOOST_RANGE_RETURNS_TEST2( lower_bound, 0, std::less<int>() );
    BOOST_RANGE_RETURNS_TEST2( upper_bound, 0, std::less<int>() );

#undef BOOST_RANGE_RETURNS_TEST2
}

using boost_kahypar::unit_test::test_suite;

test_suite* init_unit_test_suite( int argc, char* argv[] )
{
    using namespace boost_kahypar;

    test_suite* test = BOOST_TEST_SUITE( "Range Test Suite - Algorithm" );

    test->add( BOOST_TEST_CASE( &simple_compile_test ) );

    return test;
}

