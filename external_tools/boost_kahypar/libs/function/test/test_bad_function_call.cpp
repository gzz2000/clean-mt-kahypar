
// Copyright 2018 Peter Dimov.
// Distributed under the Boost Software License, Version 1.0.

#include <boost_kahypar/function.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>

void throw_bad_function_call();

int main()
{
    BOOST_TEST_THROWS( throw_bad_function_call(), boost_kahypar::bad_function_call );
    return boost_kahypar::report_errors();
}
