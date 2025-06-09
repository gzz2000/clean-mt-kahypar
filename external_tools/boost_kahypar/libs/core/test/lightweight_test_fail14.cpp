/*
Copyright 2020 Glen Joseph Fernandes
(glenjofe@gmail.com)

Distributed under the Boost Software License, Version 1.0.
(http://www.boost.org/LICENSE_1_0.txt)
*/
#include <boost_kahypar/core/lightweight_test.hpp>

struct error
    : std::exception {
    const char* what() const BOOST_NOEXCEPT_OR_NOTHROW BOOST_OVERRIDE {
        return "message";
    }
};

void f()
{
    throw error();
}

int main()
{
    BOOST_TEST_NO_THROW(f());
    return boost_kahypar::report_errors();
}
