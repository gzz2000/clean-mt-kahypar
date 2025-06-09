//
// sp_typeinfo_test.cpp
//
// Copyright (c) 2009 Peter Dimov
//
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
//

#define BOOST_ALLOW_DEPRECATED_HEADERS

#include <boost_kahypar/detail/sp_typeinfo.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>
#include <iostream>

int main()
{
    BOOST_TEST( BOOST_SP_TYPEID( int ) == BOOST_SP_TYPEID( int ) );
    BOOST_TEST( BOOST_SP_TYPEID( int ) != BOOST_SP_TYPEID( long ) );
    BOOST_TEST( BOOST_SP_TYPEID( int ) != BOOST_SP_TYPEID( void ) );

    boost_kahypar::detail::sp_typeinfo const & ti = BOOST_SP_TYPEID( int );

    boost_kahypar::detail::sp_typeinfo const * pti = &BOOST_SP_TYPEID( int );
    BOOST_TEST( *pti == ti );

    BOOST_TEST( ti == ti );
    BOOST_TEST( !( ti != ti ) );
    BOOST_TEST( !ti.before( ti ) );

    char const * nti = ti.name();
    std::cout << nti << std::endl;

    boost_kahypar::detail::sp_typeinfo const & tv = BOOST_SP_TYPEID( void );

    boost_kahypar::detail::sp_typeinfo const * ptv = &BOOST_SP_TYPEID( void );
    BOOST_TEST( *ptv == tv );

    BOOST_TEST( tv == tv );
    BOOST_TEST( !( tv != tv ) );
    BOOST_TEST( !tv.before( tv ) );

    char const * ntv = tv.name();
    std::cout << ntv << std::endl;

    BOOST_TEST( ti != tv );
    BOOST_TEST( !( ti == tv ) );

    BOOST_TEST( ti.before( tv ) != tv.before( ti ) );

    return boost_kahypar::report_errors();
}
