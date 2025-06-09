
// Copyright 2018 Peter Dimov.
// Distributed under the Boost Software License, Version 1.0.

#include <boost_kahypar/system/error_code.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>
#include <boost_kahypar/core/quick_exit.hpp>
#include <boost_kahypar/config.hpp>
#include <cerrno>

#if defined(BOOST_MSVC)
# pragma warning(disable: 4722) // Z::~Z never returns
#endif

using namespace boost_kahypar::system;

struct Z
{
    ~Z()
    {
        BOOST_TEST_CSTR_EQ( generic_category().name(), "generic" );
        BOOST_TEST_CSTR_EQ( system_category().name(), "system" );

        boost_kahypar::quick_exit( boost_kahypar::report_errors() );
    }
};

static Z z;

static error_code e1( 1, system_category() );
static error_code e2( ENOENT, generic_category() );

int main()
{
    (void)e1;
    (void)e2;
}
