// Copyright 2020 Peter Dimov.
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/system/is_error_code_enum.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>

enum error
{
    success = 0,
    e1,
    e2,
    e3
};

namespace boost_kahypar
{
namespace system
{

template<> struct is_error_code_enum< ::error >
{
    static const bool value = true;
};

}
}

boost_kahypar::system::error_code make_error_code( ::error e );

enum not_error
{
};

int main()
{
    BOOST_TEST( boost_kahypar::system::is_error_code_enum< ::error >::value );
    BOOST_TEST( !boost_kahypar::system::is_error_code_enum< ::not_error >::value );

    return boost_kahypar::report_errors();
}
