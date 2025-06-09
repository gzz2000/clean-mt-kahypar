// Copyright 2022 Peter Dimov.
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/system/error_code.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>
#include <sstream>

namespace sys = boost_kahypar::system;

int main()
{
    {
        std::wostringstream os;
        os << sys::error_code();

        BOOST_TEST( os.str() == L"system:0" );
    }

    return boost_kahypar::report_errors();
}
