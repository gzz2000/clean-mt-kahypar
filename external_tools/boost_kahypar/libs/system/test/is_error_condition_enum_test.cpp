// Copyright 2020 Peter Dimov.
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/system/is_error_condition_enum.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>

enum condition
{
    c1 = 1,
    c2,
    c3
};

namespace boost_kahypar
{
namespace system
{

template<> struct is_error_condition_enum< ::condition >
{
    static const bool value = true;
};

}
}

boost_kahypar::system::error_condition make_error_condition( ::condition e );

enum not_condition
{
};

int main()
{
    BOOST_TEST( boost_kahypar::system::is_error_condition_enum< ::condition >::value );
    BOOST_TEST( !boost_kahypar::system::is_error_condition_enum< ::not_condition >::value );

    return boost_kahypar::report_errors();
}
