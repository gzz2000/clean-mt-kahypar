/*
 * Copyright 2010 Vicente J. Botet Escriba
 * Copyright 2015 Andrey Semashev
 * Copyright 2017 James E. King, III
 *
 * Distributed under the Boost Software License, Version 1.0.
 * See http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef BOOST_WINAPI_WAIT_HPP_INCLUDED_
#define BOOST_WINAPI_WAIT_HPP_INCLUDED_

#include <boost_kahypar/winapi/basic_types.hpp>
#include <boost_kahypar/winapi/wait_constants.hpp>
#include <boost_kahypar/winapi/detail/header.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#if !defined( BOOST_USE_WINDOWS_H )
extern "C" {

#if BOOST_WINAPI_PARTITION_APP || BOOST_WINAPI_PARTITION_SYSTEM
BOOST_WINAPI_IMPORT boost_kahypar::winapi::DWORD_ BOOST_WINAPI_WINAPI_CC
WaitForSingleObjectEx(
    boost_kahypar::winapi::HANDLE_ hHandle,
    boost_kahypar::winapi::DWORD_ dwMilliseconds,
    boost_kahypar::winapi::BOOL_ bAlertable);
#endif

#if BOOST_WINAPI_PARTITION_DESKTOP || BOOST_WINAPI_PARTITION_SYSTEM
#if BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_NT4
BOOST_WINAPI_IMPORT boost_kahypar::winapi::DWORD_ BOOST_WINAPI_WINAPI_CC
SignalObjectAndWait(
    boost_kahypar::winapi::HANDLE_ hObjectToSignal,
    boost_kahypar::winapi::HANDLE_ hObjectToWaitOn,
    boost_kahypar::winapi::DWORD_ dwMilliseconds,
    boost_kahypar::winapi::BOOL_ bAlertable);
#endif
#endif

#if BOOST_WINAPI_PARTITION_APP_SYSTEM
BOOST_WINAPI_IMPORT_EXCEPT_WM boost_kahypar::winapi::DWORD_ BOOST_WINAPI_WINAPI_CC
WaitForSingleObject(
    boost_kahypar::winapi::HANDLE_ hHandle,
    boost_kahypar::winapi::DWORD_ dwMilliseconds);

BOOST_WINAPI_IMPORT_EXCEPT_WM boost_kahypar::winapi::DWORD_ BOOST_WINAPI_WINAPI_CC
WaitForMultipleObjects(
    boost_kahypar::winapi::DWORD_ nCount,
    boost_kahypar::winapi::HANDLE_ const* lpHandles,
    boost_kahypar::winapi::BOOL_ bWaitAll,
    boost_kahypar::winapi::DWORD_ dwMilliseconds);

BOOST_WINAPI_IMPORT boost_kahypar::winapi::DWORD_ BOOST_WINAPI_WINAPI_CC
WaitForMultipleObjectsEx(
    boost_kahypar::winapi::DWORD_ nCount,
    boost_kahypar::winapi::HANDLE_ const* lpHandles,
    boost_kahypar::winapi::BOOL_ bWaitAll,
    boost_kahypar::winapi::DWORD_ dwMilliseconds,
    boost_kahypar::winapi::BOOL_ bAlertable);
#endif // BOOST_WINAPI_PARTITION_APP_SYSTEM

} // extern "C"
#endif

namespace boost_kahypar {
namespace winapi {

#if BOOST_WINAPI_PARTITION_APP || BOOST_WINAPI_PARTITION_SYSTEM
using ::WaitForSingleObjectEx;
#endif
#if BOOST_WINAPI_PARTITION_DESKTOP || BOOST_WINAPI_PARTITION_SYSTEM
#if BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_NT4
using ::SignalObjectAndWait;
#endif
#endif

#if BOOST_WINAPI_PARTITION_APP_SYSTEM
using ::WaitForMultipleObjects;
using ::WaitForMultipleObjectsEx;
using ::WaitForSingleObject;
#endif

}
}

#include <boost_kahypar/winapi/detail/footer.hpp>

#endif // BOOST_WINAPI_WAIT_HPP_INCLUDED_
