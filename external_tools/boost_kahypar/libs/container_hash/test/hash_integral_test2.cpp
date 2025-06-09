// Copyright 2005-2009 Daniel James.
// Copyright 2021 Peter Dimov.
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/container_hash/hash.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>
#include <boost_kahypar/core/type_name.hpp>
#include <boost_kahypar/type_traits/is_signed.hpp>
#include <boost_kahypar/type_traits/make_unsigned.hpp>
#include <boost_kahypar/static_assert.hpp>
#include <boost_kahypar/config.hpp>

// This test checks that values representable in a signed
// and the corresponding unsigned type hash to the same value

template<class T>
void signed_unsigned_test()
{
    BOOST_STATIC_ASSERT( boost_kahypar::is_signed<T>::value );

    typedef typename boost_kahypar::make_unsigned<T>::type U;

    T x = std::numeric_limits<T>::max();

    do
    {
        BOOST_TEST_EQ( boost_kahypar::hash<T>()( x ), boost_kahypar::hash<U>()( static_cast<U>( x ) ) );
        x /= 3;
    }
    while( x > 0 );
}

#define TEST(type) std::cerr << "Testing: " #type " (" << boost_kahypar::core::type_name<type>() << ")\n"; signed_unsigned_test<type>();

int main()
{
    TEST(signed char)
    TEST(short)
    TEST(int)
    TEST(long)

#if !defined(BOOST_NO_LONG_LONG)
    TEST(boost_kahypar::long_long_type)
#endif

#if defined(BOOST_HAS_INT128)
    TEST(boost_kahypar::int128_type)
#endif

    return boost_kahypar::report_errors();
}
