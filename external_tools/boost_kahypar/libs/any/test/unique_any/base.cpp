// Copyright Antony Polukhin, 2013-2024.
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost_kahypar/any/unique_any.hpp>

#include <boost_kahypar/core/lightweight_test.hpp>

#include <vector>

void test_basic() {
    boost_kahypar::anys::unique_any a;
    BOOST_TEST(!a.has_value());

    auto& i = a.emplace<int>(42);
    BOOST_TEST_EQ(i, 42);
    BOOST_TEST(a.has_value());
    BOOST_TEST_EQ(boost_kahypar::any_cast<int>(a), 42);
    BOOST_TEST_EQ(boost_kahypar::anys::any_cast<int>(a), 42);
    BOOST_TEST_EQ(boost_kahypar::any_cast<int&>(a), 42);
    BOOST_TEST_EQ(boost_kahypar::anys::any_cast<int&>(a), 42);
    BOOST_TEST_EQ(&boost_kahypar::any_cast<int&>(a), &i);
    BOOST_TEST_EQ(&boost_kahypar::anys::any_cast<int&>(a), &i);

    boost_kahypar::anys::unique_any b = std::move(a);
    BOOST_TEST(!a.has_value());
    BOOST_TEST(b.has_value());
    BOOST_TEST_EQ(boost_kahypar::any_cast<int&>(b), 42);

    b.reset();
    BOOST_TEST(!b.has_value());
}

void test_const() {
    const boost_kahypar::anys::unique_any a = 42;
    BOOST_TEST(a.has_value());
    BOOST_TEST_EQ(boost_kahypar::any_cast<int>(a), 42);
    BOOST_TEST_EQ(boost_kahypar::anys::any_cast<int>(a), 42);
    BOOST_TEST_EQ(boost_kahypar::any_cast<const int&>(a), 42);
    BOOST_TEST_EQ(boost_kahypar::anys::any_cast<const int&>(a), 42);
}

void test_bad_any_cast() {
    boost_kahypar::anys::unique_any a;
    a.emplace<int>(42);

    try {
        boost_kahypar::any_cast<char>(a);
        BOOST_TEST(false);
    } catch (const boost_kahypar::bad_any_cast&) {
    }

    try {
        boost_kahypar::any_cast<int*>(a);
        BOOST_TEST(false);
    } catch (const boost_kahypar::bad_any_cast&) {
    }
}

struct counting_destroy {
    static int destructor_called;

    ~counting_destroy() {
      ++destructor_called;
    }
};

int counting_destroy::destructor_called = 0;

void test_destructor() {
    {
        boost_kahypar::anys::unique_any a;
        BOOST_TEST_EQ(counting_destroy::destructor_called, 0);

        a.emplace<counting_destroy>();
        BOOST_TEST_EQ(counting_destroy::destructor_called, 0);

        a.reset();
        BOOST_TEST_EQ(counting_destroy::destructor_called, 1);
    }
    BOOST_TEST_EQ(counting_destroy::destructor_called, 1);

    {
        boost_kahypar::anys::unique_any a = counting_destroy{};
        BOOST_TEST_EQ(counting_destroy::destructor_called, 2);

        a.emplace<counting_destroy>();
        BOOST_TEST_EQ(counting_destroy::destructor_called, 3);

        boost_kahypar::anys::unique_any b;
        b = std::move(a);
        BOOST_TEST_EQ(counting_destroy::destructor_called, 3);

        b.reset();
        BOOST_TEST_EQ(counting_destroy::destructor_called, 4);
    }
    BOOST_TEST_EQ(counting_destroy::destructor_called, 4);

    {
        boost_kahypar::anys::unique_any a = counting_destroy{};
        BOOST_TEST_EQ(counting_destroy::destructor_called, 5);
    }
    BOOST_TEST_EQ(counting_destroy::destructor_called, 6);
}

void test_swap() {
    boost_kahypar::anys::unique_any a;
    boost_kahypar::anys::unique_any b;

    a = 42;
    std::vector<int> ethalon_vec{1, 2, 3, 4, 5};
    b = ethalon_vec;

    auto* vec_data = boost_kahypar::any_cast<std::vector<int>&>(b).data();

    swap(a, b);
    BOOST_TEST(a.has_value());
    BOOST_TEST(b.has_value());

    BOOST_TEST_EQ(boost_kahypar::any_cast<int>(b), 42);
    BOOST_TEST(boost_kahypar::any_cast<std::vector<int>>(a) == ethalon_vec);

    BOOST_TEST_EQ(boost_kahypar::any_cast<std::vector<int>&>(a).data(), vec_data);
}

int main() {
    test_basic();
    test_const();
    test_bad_any_cast();
    test_destructor();
    test_swap();

    return boost_kahypar::report_errors();
}

