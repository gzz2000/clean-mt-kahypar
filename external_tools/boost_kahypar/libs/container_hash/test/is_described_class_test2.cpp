// Copyright 2022 Peter Dimov.
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/type_traits/integral_constant.hpp>
#include <boost_kahypar/describe/class.hpp>

struct X
{
};

BOOST_DESCRIBE_STRUCT( X, (), () )

namespace boost_kahypar
{
namespace container_hash
{

template<class T> struct is_described_class;
template<> struct is_described_class<X>: boost_kahypar::false_type {};

} // namespace container_hash
} // namespace boost_kahypar

#include <boost_kahypar/container_hash/is_described_class.hpp>
#include <boost_kahypar/core/lightweight_test_trait.hpp>

int main()
{
    using boost_kahypar::container_hash::is_described_class;

    BOOST_TEST_TRAIT_FALSE((is_described_class<X>));

    return boost_kahypar::report_errors();
}
