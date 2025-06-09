//
//  placeholder_std_bind_test.cpp - std::bind with Boost's _1
//
//  Copyright 2016 Peter Dimov
//
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//

#include <boost_kahypar/config.hpp>
#include <boost_kahypar/config/pragma_message.hpp>

#if defined(BOOST_NO_CXX11_HDR_FUNCTIONAL)

BOOST_PRAGMA_MESSAGE( "Skipping test because BOOST_NO_CXX11_HDR_FUNCTIONAL is defined" )
int main() {}

#elif defined(BOOST_GCC) && BOOST_GCC < 40600

BOOST_PRAGMA_MESSAGE( "Skipping test because BOOST_GCC is less than 40600" )
int main() {}

#else

#include <boost_kahypar/bind/bind.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>
#include <functional>

using namespace boost_kahypar::placeholders;

//

namespace std
{

template<int N> struct is_placeholder< boost_kahypar::arg<N> >: public integral_constant<int, N> {};

} // namespace std

int foo( int i )
{
    return i;
}

int main()
{
    BOOST_TEST_EQ( std::bind( foo, _1 )( 1 ), 1 );
    BOOST_TEST_EQ( std::bind( foo, _2 )( 1, 2 ), 2 );
    BOOST_TEST_EQ( std::bind( foo, _3 )( 1, 2, 3 ), 3 );

    return boost_kahypar::report_errors();
}

#endif
