/*
Copyright 2020 Glen Joseph Fernandes
(glenjofe@gmail.com)

Distributed under the Boost Software License, Version 1.0.
(http://www.boost.org/LICENSE_1_0.txt)
*/
#include <boost_kahypar/core/allocator_access.hpp>
#include <boost_kahypar/core/lightweight_test_trait.hpp>
#include <boost_kahypar/core/detail/is_same.hpp>

template<class T>
struct A1 {
    typedef T value_type;
    typedef int* const_pointer;
};

template<class T>
struct A2 {
    typedef T value_type;
};

int main()
{
    BOOST_TEST_TRAIT_TRUE((boost_kahypar::core::detail::is_same<int*,
        boost_kahypar::allocator_const_pointer<A1<char> >::type>));
    BOOST_TEST_TRAIT_TRUE((boost_kahypar::core::detail::is_same<const int*,
        boost_kahypar::allocator_const_pointer<A2<int> >::type>));
    return boost_kahypar::report_errors();
}
