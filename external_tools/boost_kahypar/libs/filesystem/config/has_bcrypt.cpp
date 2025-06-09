//  Copyright 2020 Andrey Semashev

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

//  See library home page at http://www.boost.org/libs/filesystem

// Include platform_config.hpp first so that windows.h is guaranteed to be not included
#include "platform_config.hpp"

#include <boost_kahypar/predef/os/windows.h>
#include <boost_kahypar/predef/os/cygwin.h>
#if !BOOST_OS_WINDOWS && !BOOST_OS_CYGWIN
#error "This config test is for Windows only"
#endif

#include <boost_kahypar/winapi/config.hpp>
#include <boost_kahypar/predef/platform.h>
#if !(BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_WIN6 && BOOST_WINAPI_PARTITION_APP_SYSTEM)
#error "No BCrypt API"
#endif

#include <cstddef>
#include <boost_kahypar/winapi/basic_types.hpp>
#include <boost_kahypar/winapi/bcrypt.hpp>

int main()
{
    unsigned char buf[16] = {};
    boost_kahypar::winapi::BCRYPT_ALG_HANDLE_ handle;
    boost_kahypar::winapi::NTSTATUS_ status = boost_kahypar::winapi::BCryptOpenAlgorithmProvider(&handle, boost_kahypar::winapi::BCRYPT_RNG_ALGORITHM_, NULL, 0);
    status = boost_kahypar::winapi::BCryptGenRandom(handle, reinterpret_cast< boost_kahypar::winapi::PUCHAR_ >(static_cast< unsigned char* >(buf)), static_cast< boost_kahypar::winapi::ULONG_ >(sizeof(buf)), 0);
    boost_kahypar::winapi::BCryptCloseAlgorithmProvider(handle, 0);
}
