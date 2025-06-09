// Copyright 2021 Peter Dimov.
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/system/error_code.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>
#include <boost_kahypar/config.hpp>
#include <cerrno>
#include <system_error>

enum my_errc
{
    my_enoent = ENOENT
};

#if defined(BOOST_GCC) && BOOST_GCC < 70000

// g++ 6 and earlier do not allow specializations outside the namespace

namespace boost_kahypar
{
namespace system
{

template<> struct is_error_condition_enum<my_errc>: std::true_type {};

} // namespace system
} // namespace boost_kahypar

namespace std
{

template<> struct is_error_condition_enum<my_errc>: std::true_type {};

} // namespace std

#else

template<> struct boost_kahypar::system::is_error_condition_enum<my_errc>: std::true_type {};
template<> struct std::is_error_condition_enum<my_errc>: std::true_type {};

#endif

boost_kahypar::system::error_condition make_error_condition( my_errc e )
{
    return boost_kahypar::system::error_condition( e, boost_kahypar::system::generic_category() );
}

boost_kahypar::system::error_code make_error_code( my_errc e )
{
    return boost_kahypar::system::error_code( e, boost_kahypar::system::generic_category() );
}

int main()
{
    {
        boost_kahypar::system::error_code e1 = make_error_code( my_enoent );

        BOOST_TEST( e1 == my_enoent );
        BOOST_TEST_NOT( e1 != my_enoent );
    }

    {
        std::error_code e1 = make_error_code( my_enoent );

        BOOST_TEST( e1 == my_enoent );
        BOOST_TEST_NOT( e1 != my_enoent );
    }

    return boost_kahypar::report_errors();
}
