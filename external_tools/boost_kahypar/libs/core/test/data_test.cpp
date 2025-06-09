/*
Copyright 2023 Glen Joseph Fernandes
(glenjofe@gmail.com)

Distributed under the Boost Software License, Version 1.0.
(http://www.boost.org/LICENSE_1_0.txt)
*/
#include <boost_kahypar/config.hpp>
#if !defined(BOOST_NO_CXX11_CONSTEXPR) && !defined(BOOST_NO_CXX11_DECLTYPE)
#include <boost_kahypar/core/data.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>

class range {
public:
    int* data() {
        return &v_[0];
    }

    const int* data() const {
        return &v_[0];
    }

    std::size_t size() const {
        return 4;
    }

private:
    int v_[4];
};

void test_range()
{
    range c;
    BOOST_TEST_EQ(boost_kahypar::data(c), c.data());
}

void test_const_range()
{
    const range c = range();
    BOOST_TEST_EQ(boost_kahypar::data(c), c.data());
}

void test_array()
{
    int a[4];
    BOOST_TEST_EQ(boost_kahypar::data(a), a);
}

void test_initializer_list()
{
    std::initializer_list<int> l{1, 2, 3, 4};
    BOOST_TEST_EQ(boost_kahypar::data(l), l.begin());
}

int main()
{
    test_range();
    test_const_range();
    test_array();
    test_initializer_list();
    return boost_kahypar::report_errors();
}
#else
int main()
{
    return 0;
}
#endif
