// Copyright 2022 Peter Dimov
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/core/lightweight_test.hpp>

// Should fail, because boost_kahypar::report_errors() hasn't been called

int main()
{
    boost_kahypar::core::lwt_init();
}
