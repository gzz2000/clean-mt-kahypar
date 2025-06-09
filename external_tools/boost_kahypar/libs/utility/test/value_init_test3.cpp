// Copyright 2020 Peter Dimov
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt)

#include <boost_kahypar/utility/value_init.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>
#include <boost_kahypar/config.hpp>
#include <boost_kahypar/config/pragma_message.hpp>

#if __cplusplus >= 201103L || ( defined(BOOST_MSVC) && BOOST_MSVC >= 1900 )

struct X
{
    int a;
    char b;
};

struct Y: boost_kahypar::value_initialized<X>
{
    char c = 42;
};

int main()
{
    Y y;

    BOOST_TEST_EQ( y.data().a, 0 );
    BOOST_TEST_EQ( y.data().b, 0 );
    BOOST_TEST_EQ( y.c, 42 );

    return boost_kahypar::report_errors();
}

#else

BOOST_PRAGMA_MESSAGE( "Skipping test because compiler doesn't support in-class member initializers" )

int main() {}

#endif
