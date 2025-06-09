// Copyright 2017, 2021 Peter Dimov.
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

// See library home page at http://www.boost.org/libs/system

#include <boost_kahypar/system.hpp>
#include <cassert>
#include <cerrno>

#define BOOST_TEST(expr) assert(expr)
#define BOOST_TEST_EQ(x1, x2) assert((x1)==(x2))

int main()
{
    boost_kahypar::system::error_category const & bt = boost_kahypar::system::generic_category();

    int ev = ENOENT;

    boost_kahypar::system::error_code bc( ev, bt );

    BOOST_TEST_EQ( bc.value(), ev );
    BOOST_TEST_EQ( &bc.category(), &bt );

    boost_kahypar::system::error_condition bn = bt.default_error_condition( ev );

    BOOST_TEST_EQ( bn.value(), ev );
    BOOST_TEST_EQ( &bn.category(), &bt );

    BOOST_TEST( bt.equivalent( ev, bn ) );

    BOOST_TEST( bc == bn );

    boost_kahypar::system::error_code bc2 = make_error_code( boost_kahypar::system::errc::no_such_file_or_directory );

    BOOST_TEST_EQ( bc2, bc );
    BOOST_TEST_EQ( bc2.value(), ev );
    BOOST_TEST_EQ( &bc.category(), &bt );

    boost_kahypar::system::system_error x( bc, "prefix" );

    BOOST_TEST_EQ( x.code(), bc );
    BOOST_TEST_EQ( std::string( x.what() ), "prefix: " + bc.what() );
}
