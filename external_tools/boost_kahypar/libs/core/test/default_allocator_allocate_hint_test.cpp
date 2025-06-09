/*
Copyright 2021 Glen Joseph Fernandes
(glenjofe@gmail.com)

Distributed under the Boost Software License, Version 1.0.
(http://www.boost.org/LICENSE_1_0.txt)
*/
#include <boost_kahypar/core/default_allocator.hpp>
#include <boost_kahypar/core/allocator_access.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>

int main()
{
    boost_kahypar::default_allocator<int> a;
    int* p = boost_kahypar::allocator_allocate(a, 1, 0);
    BOOST_TEST(p != 0);
    a.deallocate(p, 1);
    return boost_kahypar::report_errors();
}
