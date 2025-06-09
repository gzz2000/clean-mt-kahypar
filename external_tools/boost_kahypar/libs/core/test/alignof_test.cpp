// Copyright 2023 Peter Dimov
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/core/alignof.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>
#include <boost_kahypar/type_traits.hpp>
#include <boost_kahypar/config.hpp>
#include <cstddef>

template<class T> struct struct_of
{
    T t;
};

template<class T> union union_of
{
    T t;
};

template<class T> void test2()
{
    BOOST_TEST_EQ( BOOST_CORE_ALIGNOF(T), boost_kahypar::alignment_of<T>::value );

#if !defined(BOOST_NO_CXX11_ALIGNOF)

    BOOST_TEST_EQ( BOOST_CORE_ALIGNOF(T), alignof(T) );

#endif
}

template<class T> void test()
{
    test2<T>();
    test2<T[2]>();
    test2< struct_of<T> >();
    test2< union_of<T> >();
}

struct X
{
};

int main()
{
    test<char>();
    test<short>();
    test<int>();
    test<long>();

#if !defined(BOOST_NO_LONG_LONG)
# if !( defined(__GNUC__) && defined(__i386__) )

    // g++ -m32 has alignof(long long) = 8, but boost_kahypar::alignment_of<long long>::value = 4
    test<boost_kahypar::long_long_type>();

# endif
#endif

#if defined(BOOST_HAS_INT128)

    test<boost_kahypar::int128_type>();

#endif

    test<float>();

#if !( defined(__GNUC__) && defined(__i386__) )

    // g++ -m32 has alignof(double) = 8, but boost_kahypar::alignment_of<double>::value = 4
    test<double>();

#endif

    test<long double>();

#if defined(BOOST_HAS_FLOAT128)

    test<__float128>();

#endif

    test<void*>();
    test<void(*)()>();

#if !defined(_MSC_VER)

    // under MSVC, alignof is 8, boost_kahypar::alignment_of is 4
    // under clang-cl, alignof is 4, boost_kahypar::alignment_of is 8 (!)

    test<int X::*>();

#endif

    test<void (X::*)()>();

    return boost_kahypar::report_errors();
}
