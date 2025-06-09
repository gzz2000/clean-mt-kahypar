// Copyright Antony Polukhin, 2013-2024.
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost_kahypar/any.hpp>
#include <boost_kahypar/any/unique_any.hpp>

#include <boost_kahypar/core/lightweight_test.hpp>

#include <vector>

void test_basic() {
    boost_kahypar::any from = 42;

    boost_kahypar::anys::unique_any a(std::move(from));
    BOOST_TEST(from.empty());
    BOOST_TEST(a.has_value());

    BOOST_TEST_EQ(boost_kahypar::any_cast<int>(a), 42);
    BOOST_TEST_EQ(boost_kahypar::anys::any_cast<int>(a), 42);
    BOOST_TEST_EQ(boost_kahypar::any_cast<int&>(a), 42);
    BOOST_TEST_EQ(boost_kahypar::anys::any_cast<int&>(a), 42);

    boost_kahypar::anys::unique_any b = std::move(a);
    BOOST_TEST(!a.has_value());
    BOOST_TEST(b.has_value());
    BOOST_TEST_EQ(boost_kahypar::any_cast<int&>(b), 42);

    b.reset();
    BOOST_TEST(!b.has_value());
}

void test_const() {
    boost_kahypar::any from = 42;

    const boost_kahypar::anys::unique_any a = std::move(from);
    BOOST_TEST(a.has_value());
    BOOST_TEST_EQ(boost_kahypar::any_cast<int>(a), 42);
    BOOST_TEST_EQ(boost_kahypar::anys::any_cast<int>(a), 42);
    BOOST_TEST_EQ(boost_kahypar::any_cast<const int&>(a), 42);
    BOOST_TEST_EQ(boost_kahypar::anys::any_cast<const int&>(a), 42);
}

void test_bad_any_cast() {
    boost_kahypar::any from = 42;

    const boost_kahypar::anys::unique_any a = std::move(from);
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
    boost_kahypar::any from = counting_destroy{};
    BOOST_TEST_EQ(counting_destroy::destructor_called, 1);
    boost_kahypar::anys::unique_any a = std::move(from);
    BOOST_TEST_EQ(counting_destroy::destructor_called, 1);

    a.reset();
    BOOST_TEST_EQ(counting_destroy::destructor_called, 2);
}

int main() {
    test_basic();
    test_const();
    test_bad_any_cast();
    test_destructor();

    return boost_kahypar::report_errors();
}

