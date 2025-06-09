// Copyright 2022 Peter Dimov.
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#if defined(__clang__)
# pragma clang diagnostic ignored "-Wmismatched-tags"
#endif

#include <boost_kahypar/container_hash/hash.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>
#include <boost_kahypar/type_traits/integral_constant.hpp>
#include <boost_kahypar/describe/class.hpp>
#include <boost_kahypar/config.hpp>
#include <boost_kahypar/config/pragma_message.hpp>
#include <utility>

#if defined(BOOST_NO_CXX11_HDR_TUPLE)

BOOST_PRAGMA_MESSAGE( "Skipping test because BOOST_NO_CXX11_HDR_TUPLE is defined" )
int main() {}

#elif !defined(BOOST_DESCRIBE_CXX14)

BOOST_PRAGMA_MESSAGE( "Skipping test because BOOST_DESCRIBE_CXX14 is not defined" )
int main() {}

#else

namespace user
{

struct Y3
{
    int a;
    int b;
};

BOOST_DESCRIBE_STRUCT(Y3, (), (a, b))

} // namespace user

namespace std
{

template<> struct tuple_size<user::Y3>: std::integral_constant<std::size_t, 2>
{
};

} // namespace std

namespace boost_kahypar
{
namespace container_hash
{

    template<> struct is_tuple_like<user::Y3>: boost_kahypar::false_type {};

} // namespace container_hash
} // namespace boost_kahypar

template<class T> std::size_t hv( T const& t )
{
    return boost_kahypar::hash<T>()( t );
}

int main()
{
    {
        user::Y3 tp = { 1, 2 };
        int const a[] = { 1, 2 };

        BOOST_TEST_EQ( hv(tp), hv(a) );
    }

    return boost_kahypar::report_errors();
}

#endif
