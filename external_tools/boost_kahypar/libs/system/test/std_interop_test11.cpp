// Copyright 2021 Peter Dimov.
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/system/error_code.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>
#include <boost_kahypar/config/pragma_message.hpp>
#include <boost_kahypar/config.hpp>
#include <ios>

#if defined(BOOST_LIBSTDCXX_VERSION) && BOOST_LIBSTDCXX_VERSION < 50000

BOOST_PRAGMA_MESSAGE( "Skipping test, BOOST_LIBSTDCXX_VERSION < 50000" )
int main() {}

#else

#include <system_error>

int main()
{
    {
        boost_kahypar::system::error_code ec = std::io_errc::stream;

        BOOST_TEST( ec == std::io_errc::stream );
        BOOST_TEST_NOT( ec != std::io_errc::stream );

        ec.clear();

        BOOST_TEST_NOT( ec == std::io_errc::stream );
        BOOST_TEST( ec != std::io_errc::stream );

        ec = std::io_errc::stream;

        BOOST_TEST( ec == std::io_errc::stream );
        BOOST_TEST_NOT( ec != std::io_errc::stream );
    }

    return boost_kahypar::report_errors();
}

#endif
