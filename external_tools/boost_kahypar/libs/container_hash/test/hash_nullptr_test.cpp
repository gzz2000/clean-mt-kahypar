// Copyright 2022 Peter Dimov.
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/container_hash/hash.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>
#include <boost_kahypar/config.hpp>
#include <boost_kahypar/config/pragma_message.hpp>
#include <cstddef>

#if defined(BOOST_NO_CXX11_NULLPTR)

BOOST_PRAGMA_MESSAGE( "Test skipped, BOOST_NO_CXX11_NULLPTR is defined" )
int main() {}

#else

template<class T> std::size_t hv( T const& x )
{
    return boost_kahypar::hash<T>()( x );
}

int main()
{
    {
        BOOST_TEST_EQ( hv((void*)0), hv(nullptr) );
    }

    {
        int x = 0;

        BOOST_TEST_EQ( hv((int*)0), hv(nullptr) );
        BOOST_TEST_NE( hv(&x), hv(nullptr) );

        (void)x;
    }

    return boost_kahypar::report_errors();
}

#endif
