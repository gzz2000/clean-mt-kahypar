/*
Copyright 2023 Glen Joseph Fernandes
(glenjofe@gmail.com)

Distributed under the Boost Software License, Version 1.0.
(http://www.boost.org/LICENSE_1_0.txt)
*/
#include <boost_kahypar/config.hpp>
#if !defined(BOOST_NO_CXX11_CONSTEXPR) && !defined(BOOST_NO_CXX11_DECLTYPE)
#include <boost_kahypar/core/make_span.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>

template<class T>
class range {
public:
    T* data() {
        return &v_[0];
    }

    std::size_t size() const {
        return 4;
    }

private:
    T v_[4];
};

void test_data_size()
{
    int a[4];
    boost_kahypar::span<int> s = boost_kahypar::make_span(&a[0], 4);
    BOOST_TEST_EQ(s.data(), &a[0]);
    BOOST_TEST_EQ(s.size(), 4);
}

void test_first_last()
{
    int a[4];
    boost_kahypar::span<int> s = boost_kahypar::make_span(&a[0], &a[4]);
    BOOST_TEST_EQ(s.data(), &a[0]);
    BOOST_TEST_EQ(s.size(), 4);
}

void test_array()
{
    int a[4];
    boost_kahypar::span<int, 4> s = boost_kahypar::make_span(a);
    BOOST_TEST_EQ(s.data(), &a[0]);
    BOOST_TEST_EQ(s.size(), 4);
}

void test_std_array()
{
    std::array<int, 4> a;
    boost_kahypar::span<int, 4> s = boost_kahypar::make_span(a);
    BOOST_TEST_EQ(s.data(), a.data());
    BOOST_TEST_EQ(s.size(), a.size());
}

void test_const_std_array()
{
    const std::array<int, 4> a = std::array<int, 4>();
    boost_kahypar::span<const int> s = boost_kahypar::make_span(a);
    BOOST_TEST_EQ(s.data(), a.data());
    BOOST_TEST_EQ(s.size(), a.size());
}

void test_range()
{
    range<int> c;
    boost_kahypar::span<int> s = boost_kahypar::make_span(c);
    BOOST_TEST_EQ(s.data(), c.data());
    BOOST_TEST_EQ(s.size(), c.size());
}

void test_initializer_list()
{
    std::initializer_list<int> l{1, 2};
    boost_kahypar::span<const int> s = boost_kahypar::make_span(l);
    BOOST_TEST_EQ(s.data(), l.begin());
    BOOST_TEST_EQ(s.size(), l.size());
}

int main()
{
    test_data_size();
    test_first_last();
    test_array();
    test_std_array();
    test_const_std_array();
    test_range();
    test_initializer_list();
    return boost_kahypar::report_errors();
}
#else
int main()
{
    return 0;
}
#endif
