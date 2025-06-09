/*
Copyright 2019 Glen Joseph Fernandes
(glenjofe@gmail.com)

Distributed under the Boost Software License, Version 1.0.
(http://www.boost.org/LICENSE_1_0.txt)
*/
#include <boost_kahypar/config.hpp>
#if !defined(BOOST_NO_CXX11_CONSTEXPR) && !defined(BOOST_NO_CXX11_DECLTYPE)
#include <boost_kahypar/core/span.hpp>
#include <boost_kahypar/core/lightweight_test_trait.hpp>

void test_element_type()
{
    BOOST_TEST_TRAIT_SAME(int,
        boost_kahypar::span<int>::element_type);
    BOOST_TEST_TRAIT_SAME(char,
        boost_kahypar::span<char>::element_type);
}

void test_value_type()
{
    BOOST_TEST_TRAIT_SAME(char,
        boost_kahypar::span<char>::value_type);
    BOOST_TEST_TRAIT_SAME(int,
        boost_kahypar::span<int>::value_type);
    BOOST_TEST_TRAIT_SAME(int,
        boost_kahypar::span<const int>::value_type);
    BOOST_TEST_TRAIT_SAME(int,
        boost_kahypar::span<volatile int>::value_type);
    BOOST_TEST_TRAIT_SAME(int,
        boost_kahypar::span<const volatile int>::value_type);
}

void test_size_type()
{
    BOOST_TEST_TRAIT_SAME(std::size_t,
        boost_kahypar::span<char>::size_type);
    BOOST_TEST_TRAIT_SAME(std::size_t,
        boost_kahypar::span<int>::size_type);
}

void test_difference_type()
{
    BOOST_TEST_TRAIT_SAME(std::ptrdiff_t,
        boost_kahypar::span<char>::difference_type);
    BOOST_TEST_TRAIT_SAME(std::ptrdiff_t,
        boost_kahypar::span<int>::difference_type);
}

void test_pointer()
{
    BOOST_TEST_TRAIT_SAME(char*,
        boost_kahypar::span<char>::pointer);
    BOOST_TEST_TRAIT_SAME(int*,
        boost_kahypar::span<int>::pointer);
}

void test_const_pointer()
{
    BOOST_TEST_TRAIT_SAME(const char*,
        boost_kahypar::span<char>::const_pointer);
    BOOST_TEST_TRAIT_SAME(const int*,
        boost_kahypar::span<int>::const_pointer);
}

void test_reference()
{
    BOOST_TEST_TRAIT_SAME(char&,
        boost_kahypar::span<char>::reference);
    BOOST_TEST_TRAIT_SAME(int&,
        boost_kahypar::span<int>::reference);
}

void test_const_reference()
{
    BOOST_TEST_TRAIT_SAME(const char&,
        boost_kahypar::span<char>::const_reference);
    BOOST_TEST_TRAIT_SAME(const int&,
        boost_kahypar::span<int>::const_reference);
}

void test_iterator()
{
    BOOST_TEST_TRAIT_SAME(char*,
        boost_kahypar::span<char>::iterator);
    BOOST_TEST_TRAIT_SAME(int*,
        boost_kahypar::span<int>::iterator);
}

void test_const_iterator()
{
    BOOST_TEST_TRAIT_SAME(const char*,
        boost_kahypar::span<char>::const_iterator);
    BOOST_TEST_TRAIT_SAME(const int*,
        boost_kahypar::span<int>::const_iterator);
}

void test_reverse_iterator()
{
    BOOST_TEST_TRAIT_SAME(std::reverse_iterator<char*>,
        boost_kahypar::span<char>::reverse_iterator);
    BOOST_TEST_TRAIT_SAME(std::reverse_iterator<int*>,
        boost_kahypar::span<int>::reverse_iterator);
}

void test_const_reverse_iterator()
{
    BOOST_TEST_TRAIT_SAME(std::reverse_iterator<const char*>,
        boost_kahypar::span<char>::const_reverse_iterator);
    BOOST_TEST_TRAIT_SAME(std::reverse_iterator<const int*>,
        boost_kahypar::span<int>::const_reverse_iterator);
}

int main()
{
    test_element_type();
    test_value_type();
    test_size_type();
    test_difference_type();
    test_pointer();
    test_const_pointer();
    test_reference();
    test_const_reference();
    test_iterator();
    test_const_iterator();
    test_reverse_iterator();
    test_const_reverse_iterator();
    return boost_kahypar::report_errors();
}
#else
int main()
{
    return 0;
}
#endif
