// Copyright 2021, 2022 Peter Dimov.
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#if defined(__GNUC__) && __GNUC__ == 8
# pragma GCC diagnostic ignored "-Wsign-conversion"
#endif

#include <boost_kahypar/container_hash/hash.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>
#include <boost_kahypar/core/detail/splitmix64.hpp>
#include <boost_kahypar/config.hpp>
#include <boost_kahypar/config/pragma_message.hpp>

#if defined(BOOST_NO_CXX11_HDR_UNORDERED_SET)

BOOST_PRAGMA_MESSAGE( "Test skipped, BOOST_NO_CXX11_HDR_UNORDERED_SET is defined" )
int main() {}

#elif defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES) && defined(_CPPLIB_VER) && _CPPLIB_VER >= 520

BOOST_PRAGMA_MESSAGE( "Test skipped, _CPPLIB_VER >= 520 and BOOST_NO_CXX11_VARIADIC_TEMPLATES is defined" )
int main() {}

#else

#include <unordered_set>

template<class T> std::size_t hv( T const& x )
{
    return boost_kahypar::hash<T>()( x );
}

template<class T> void test()
{
    typedef std::unordered_set<T> set;

    int const N = 256;

    set v;

    boost_kahypar::detail::splitmix64 rng;

    for( int i = 0; i < N; ++i )
    {
        BOOST_TEST_EQ( hv( v ), boost_kahypar::hash_unordered_range( v.begin(), v.end() ) );
        v.insert( static_cast<T>( rng() ) );
    }
}

int main()
{
    test<unsigned>();
    test<boost_kahypar::uint64_t>();
    test<float>();
    test<double>();

    return boost_kahypar::report_errors();
}

#endif
