// Copyright 2022 Peter Dimov.
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#if defined(_MSC_VER)
# pragma warning(disable: 4714) // forceinline not inlined
#endif

#if defined(__GNUC__) || defined(__clang__)
# pragma GCC diagnostic ignored "-Wsign-conversion"
#endif

#include <boost_kahypar/filesystem/path.hpp>
#include <boost_kahypar/container_hash/hash.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>

template<class T> std::size_t hv( T const& t )
{
    return boost_kahypar::hash<T>()( t );
}

int main()
{
    boost_kahypar::filesystem::path p1( "/foo/bar" );
    boost_kahypar::filesystem::path p2( "/foo/baz" );

    BOOST_TEST_NE( hv( p1 ), hv( p2 ) );

    return boost_kahypar::report_errors();
}
