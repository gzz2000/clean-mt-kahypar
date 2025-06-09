/*
Copyright 2018 Glen Joseph Fernandes
(glenjofe@gmail.com)

Distributed under the Boost Software License, Version 1.0.
(http://www.boost.org/LICENSE_1_0.txt)
*/
#include <boost_kahypar/core/empty_value.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>

#if !defined(BOOST_NO_CXX11_FINAL)
class type final {
public:
    explicit type(int count)
        : value_(count) { }
    int value() const {
        return value_ + 1;
    }
    int value() {
        return value_ + 2;
    }
private:
    int value_;
};

struct empty final {
    int value() const {
        return 1;
    }
    int value() {
        return 2;
    }
};

void test_type()
{
    const boost_kahypar::empty_value<type> v1(boost_kahypar::empty_init_t(), 3);
    BOOST_TEST(v1.get().value() == 4);
    boost_kahypar::empty_value<type> v2(boost_kahypar::empty_init_t(), 3);
    BOOST_TEST(v2.get().value() == 5);
}

void test_empty()
{
    const boost_kahypar::empty_value<empty> v1 = boost_kahypar::empty_init_t();
    BOOST_TEST(v1.get().value() == 1);
    boost_kahypar::empty_value<empty> v2;
    BOOST_TEST(v2.get().value() == 2);
}

int main()
{
    test_type();
    test_empty();
    return boost_kahypar::report_errors();
}
#else
int main()
{
    return 0;
}
#endif
