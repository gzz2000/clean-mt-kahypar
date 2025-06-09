/*
Copyright 2019 Glen Joseph Fernandes
(glenjofe@gmail.com)

Distributed under the Boost Software License, Version 1.0.
(http://www.boost.org/LICENSE_1_0.txt)
*/
#include <boost_kahypar/config.hpp>
#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES) && \
    !defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
#include <boost_kahypar/functional/value_factory.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>

class arg {
public:
    explicit arg(int n)
        : value_(n) { }

    arg(arg&& a)
        : value_(a.value_) { }

    int get() const {
        return value_;
    }

private:
    int value_;
};

class sum {
public:
    explicit sum(arg&& a1, arg&& a2)
        : value_(a1.get() + a2.get()) { }

    int get() const {
        return value_;
    }

private:
    int value_;
};

int main()
{
    sum s(boost_kahypar::value_factory<sum>()(arg(1), arg(2)));
    BOOST_TEST(s.get() == 3);
    return boost_kahypar::report_errors();
}
#else
int main()
{
    return 0;
}
#endif
