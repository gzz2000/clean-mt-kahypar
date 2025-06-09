/*
Copyright 2017 Glen Joseph Fernandes
(glenjofe@gmail.com)

Distributed under the Boost Software License, Version 1.0.
(http://www.boost.org/LICENSE_1_0.txt)
*/
#include <boost_kahypar/core/pointer_traits.hpp>
#include <boost_kahypar/core/lightweight_test_trait.hpp>
#include <boost_kahypar/core/detail/is_same.hpp>

template<class T>
struct P { };

int main()
{
    BOOST_TEST_TRAIT_TRUE((boost_kahypar::core::detail::is_same<int*,
        boost_kahypar::pointer_traits<int*>::pointer>));
    BOOST_TEST_TRAIT_TRUE((boost_kahypar::core::detail::is_same<P<int>,
        boost_kahypar::pointer_traits<P<int> >::pointer>));
    BOOST_TEST_TRAIT_TRUE((boost_kahypar::core::detail::is_same<void*,
        boost_kahypar::pointer_traits<void*>::pointer>));
    BOOST_TEST_TRAIT_TRUE((boost_kahypar::core::detail::is_same<P<void>,
        boost_kahypar::pointer_traits<P<void> >::pointer>));
    BOOST_TEST_TRAIT_TRUE((boost_kahypar::core::detail::is_same<const int*,
        boost_kahypar::pointer_traits<const int*>::pointer>));
    BOOST_TEST_TRAIT_TRUE((boost_kahypar::core::detail::is_same<P<const int>,
        boost_kahypar::pointer_traits<P<const int> >::pointer>));
    return boost_kahypar::report_errors();
}
