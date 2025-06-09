// Copyright 2021 Peter Dimov
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/core/detail/string_view.hpp>
#include <boost_kahypar/utility/string_view.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>
#include <string>

boost_kahypar::core::string_view f( boost_kahypar::core::string_view const& str )
{
    return str;
}

int main()
{
    {
        std::string s1( "123" );
        std::string s2 = f( s1 );

        BOOST_TEST_EQ( s1, s2 );
    }

    {
        boost_kahypar::string_view s1( "123" );
        boost_kahypar::string_view s2 = f( s1 );

        BOOST_TEST_EQ( s1, s2 );
    }

    return boost_kahypar::report_errors();
}
