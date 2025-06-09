// Copyright 2021 Peter Dimov
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/core/detail/string_view.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>
#include <cstddef>

int main()
{
    {
        char const* s1 = "12345";
        char const* s2 = "";

        boost_kahypar::core::string_view sv1( s1 );
        boost_kahypar::core::string_view sv2( s2 );

        sv1.swap( sv2 );

        BOOST_TEST_EQ( sv1.data(), s2 );
        BOOST_TEST_EQ( sv1.size(), 0 );

        BOOST_TEST_EQ( sv2.data(), s1 );
        BOOST_TEST_EQ( sv2.size(), 5);
    }

    {
        boost_kahypar::core::string_view sv;

        char const* data = sv.data();
        std::size_t size = sv.size();

        sv.remove_prefix( 0 );

        BOOST_TEST_EQ( sv.data(), data );
        BOOST_TEST_EQ( sv.size(), size );

        sv.remove_suffix( 0 );

        BOOST_TEST_EQ( sv.data(), data );
        BOOST_TEST_EQ( sv.size(), size );
    }

    {
        boost_kahypar::core::string_view sv( "" );

        char const* data = sv.data();
        std::size_t size = sv.size();

        sv.remove_prefix( 0 );

        BOOST_TEST_EQ( sv.data(), data );
        BOOST_TEST_EQ( sv.size(), size );

        sv.remove_suffix( 0 );

        BOOST_TEST_EQ( sv.data(), data );
        BOOST_TEST_EQ( sv.size(), size );
    }

    {
        boost_kahypar::core::string_view sv( "12345" );

        char const* data = sv.data();
        std::size_t size = sv.size();

        sv.remove_prefix( 0 );

        BOOST_TEST_EQ( sv.data(), data );
        BOOST_TEST_EQ( sv.size(), size );

        sv.remove_suffix( 0 );

        BOOST_TEST_EQ( sv.data(), data );
        BOOST_TEST_EQ( sv.size(), size );
    }

    {
        boost_kahypar::core::string_view sv( "12345" );

        char const* data = sv.data();
        std::size_t size = sv.size();

        sv.remove_prefix( 2 );

        BOOST_TEST_EQ( sv.data(), data + 2 );
        BOOST_TEST_EQ( sv.size(), size - 2 );
    }

    {
        boost_kahypar::core::string_view sv( "12345" );

        char const* data = sv.data();
        std::size_t size = sv.size();

        sv.remove_prefix( 5 );

        BOOST_TEST_EQ( sv.data(), data + 5 );
        BOOST_TEST_EQ( sv.size(), size - 5 );
    }

    {
        boost_kahypar::core::string_view sv( "12345" );

        char const* data = sv.data();
        std::size_t size = sv.size();

        sv.remove_suffix( 2 );

        BOOST_TEST_EQ( sv.data(), data );
        BOOST_TEST_EQ( sv.size(), size - 2 );
    }

    {
        boost_kahypar::core::string_view sv( "12345" );

        char const* data = sv.data();
        std::size_t size = sv.size();

        sv.remove_suffix( 5 );

        BOOST_TEST_EQ( sv.data(), data );
        BOOST_TEST_EQ( sv.size(), size - 5 );
    }

    return boost_kahypar::report_errors();
}
