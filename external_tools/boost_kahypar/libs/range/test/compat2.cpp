// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//

#include <boost_kahypar/static_assert.hpp>
#include <boost_kahypar/type_traits.hpp>
#include <boost_kahypar/concept_check.hpp>
#include <boost_kahypar/config.hpp>

enum Container {};
enum String {};

template< typename T >
struct range_iterator;

template<>
struct range_iterator<Container>
{
    template< typename C >
    struct pts
    {
        typedef BOOST_DEDUCED_TYPENAME C::iterator type;
    };
};

template<>
struct range_iterator<String>
{
    template< typename C >
    struct pts
    {
        typedef C type;
    };
};

template< typename C >
class iterator_of
{
public:
    typedef BOOST_DEDUCED_TYPENAME range_iterator<Container>::BOOST_NESTED_TEMPLATE pts<C>::type type; 
};

#include <vector>

void compat1()
{
    std::vector<int> v;
    iterator_of< std::vector<int> >::type i = v.begin();
    boost_kahypar::ignore_unused_variable_warning(i);
}

#include <boost_kahypar/test/included/unit_test.hpp> 

using boost_kahypar::unit_test::test_suite;

test_suite* init_unit_test_suite( int argc, char* argv[] )
{
    test_suite* test = BOOST_TEST_SUITE( "Range Test Suite" );

    test->add( BOOST_TEST_CASE( &compat1 ) );

    return test;
}






