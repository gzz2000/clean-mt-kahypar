
// Copyright 2018, 2021 Peter Dimov.
// Distributed under the Boost Software License, Version 1.0.

#include <boost_kahypar/core/typeinfo.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>

boost_kahypar::core::typeinfo const & get_typeid_X();

struct BOOST_SYMBOL_VISIBLE X
{
};

struct Y
{
};

int main()
{
    boost_kahypar::core::typeinfo const & tx = BOOST_CORE_TYPEID( X );
    boost_kahypar::core::typeinfo const & ty = BOOST_CORE_TYPEID( Y );

    boost_kahypar::core::typeinfo const & tx2 = get_typeid_X();

    BOOST_TEST( tx2 == tx );
    BOOST_TEST( tx2 != ty );

    BOOST_TEST( !tx2.before( tx ) );
    BOOST_TEST( !tx.before( tx2 ) );

    BOOST_TEST( tx2.before( ty ) != ty.before( tx2 ) );

    return boost_kahypar::report_errors();
}
