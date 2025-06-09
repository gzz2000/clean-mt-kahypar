
// Copyright 2018 Peter Dimov.
// Distributed under the Boost Software License, Version 1.0.

#include <boost_kahypar/core/typeinfo.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>

boost_kahypar::core::typeinfo const & get_typeid_int();

int main()
{
    boost_kahypar::core::typeinfo const & ti = BOOST_CORE_TYPEID( int );
    boost_kahypar::core::typeinfo const & tf = BOOST_CORE_TYPEID( float );

    boost_kahypar::core::typeinfo const & ti2 = get_typeid_int();

    BOOST_TEST( ti2 == ti );
    BOOST_TEST( ti2 != tf );

    BOOST_TEST( !ti2.before( ti ) );
    BOOST_TEST( !ti.before( ti2 ) );

    BOOST_TEST( ti2.before( tf ) != tf.before( ti2 ) );

    return boost_kahypar::report_errors();
}
