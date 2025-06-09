// Copyright 2020 Peter Dimov
// Distributed under the Boost Software License, Version 1.0
// http://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/system/system_category.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>

// Tests whether system_category() is functional when only
// system_category.hpp is included

namespace sys = boost_kahypar::system;

int main()
{
    sys::error_category const & cat = sys::system_category();

    BOOST_TEST_CSTR_EQ( cat.name(), "system" );

    return boost_kahypar::report_errors();
}
