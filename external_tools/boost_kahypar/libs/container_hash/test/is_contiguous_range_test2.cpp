// Copyright 2022 Peter Dimov.
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/type_traits/integral_constant.hpp>
#include <cstddef>

struct X1
{
    char const* begin() const;
    char const* end() const;
    char const* data() const;
    std::size_t size() const;
};

struct X2
{
    char const* begin() const;
    char const* end() const;
    char const* data() const;
    std::size_t size() const;
};

struct X3
{
    char const* begin() const;
    char const* end() const;
    char const* data() const;
    std::size_t size() const;
};

namespace boost_kahypar
{
namespace container_hash
{

template<class T> struct is_contiguous_range;
template<> struct is_contiguous_range<X2>: boost_kahypar::false_type {};

template<class T> struct is_range;
template<> struct is_range<X3>: boost_kahypar::false_type {};

} // namespace container_hash
} // namespace boost_kahypar

#include <boost_kahypar/container_hash/is_contiguous_range.hpp>
#include <boost_kahypar/core/lightweight_test_trait.hpp>

int main()
{
    using boost_kahypar::container_hash::is_contiguous_range;

#if !defined(BOOST_NO_CXX11_DECLTYPE) && !defined(BOOST_NO_SFINAE_EXPR) && !BOOST_WORKAROUND(BOOST_GCC, < 40700) && !BOOST_WORKAROUND(BOOST_MSVC, < 1910)

    BOOST_TEST_TRAIT_TRUE((is_contiguous_range<X1>));

#endif

    BOOST_TEST_TRAIT_FALSE((is_contiguous_range<X2>));
    BOOST_TEST_TRAIT_FALSE((is_contiguous_range<X3>));

    return boost_kahypar::report_errors();
}
