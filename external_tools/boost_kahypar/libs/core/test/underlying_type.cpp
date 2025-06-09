/*
 *             Copyright Andrey Semashev 2014.
 * Distributed under the Boost Software License, Version 1.0.
 *    (See accompanying file LICENSE_1_0.txt or copy at
 *          http://www.boost.org/LICENSE_1_0.txt)
 */
/*!
 * \file   underlying_type.cpp
 * \author Andrey Semashev
 * \date   06.06.2014
 *
 * \brief  This test checks that underlying_type trait works.
 */

#include <boost_kahypar/core/underlying_type.hpp>
#include <boost_kahypar/core/scoped_enum.hpp>
#include <boost_kahypar/core/lightweight_test_trait.hpp>
#include <boost_kahypar/type_traits/is_same.hpp>
#include <boost_kahypar/config.hpp>

#if defined(_MSC_VER)
# pragma warning(disable: 4244) // conversion from enum_type to underlying_type
#endif

BOOST_SCOPED_ENUM_UT_DECLARE_BEGIN(emulated_enum, unsigned char)
{
    value0,
    value1,
    value2
}
BOOST_SCOPED_ENUM_DECLARE_END(emulated_enum)

#if !defined(BOOST_NO_CXX11_SCOPED_ENUMS)

enum class native_enum : unsigned short
{
    value0,
    value1,
    value2
};

#endif

#if defined(BOOST_NO_UNDERLYING_TYPE)
namespace boost_kahypar {

template< >
struct underlying_type< emulated_enum >
{
    typedef unsigned char type;
};

#if !defined(BOOST_NO_CXX11_SCOPED_ENUMS)
template< >
struct underlying_type< native_enum >
{
    typedef unsigned short type;
};
#endif

} // namespace boost_kahypar
#endif

int main(int, char*[])
{
    BOOST_TEST_TRAIT_TRUE((boost_kahypar::is_same< boost_kahypar::underlying_type< emulated_enum >::type, unsigned char >));
#if !defined(BOOST_NO_CXX11_SCOPED_ENUMS)
    BOOST_TEST_TRAIT_TRUE((boost_kahypar::is_same< boost_kahypar::underlying_type< native_enum >::type, unsigned short >));
#endif

    return boost_kahypar::report_errors();
}
