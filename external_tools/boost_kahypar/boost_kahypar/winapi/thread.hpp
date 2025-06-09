/*
 * Copyright 2010 Vicente J. Botet Escriba
 * Copyright 2015 Andrey Semashev
 *
 * Distributed under the Boost Software License, Version 1.0.
 * See http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef BOOST_WINAPI_THREAD_HPP_INCLUDED_
#define BOOST_WINAPI_THREAD_HPP_INCLUDED_

#include <boost_kahypar/winapi/basic_types.hpp>
#include <boost_kahypar/winapi/get_current_thread.hpp>
#include <boost_kahypar/winapi/get_current_thread_id.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#if BOOST_WINAPI_PARTITION_APP_SYSTEM

#include <boost_kahypar/winapi/detail/header.hpp>

#if !defined( BOOST_USE_WINDOWS_H )
extern "C" {
BOOST_WINAPI_IMPORT boost_kahypar::winapi::DWORD_ BOOST_WINAPI_WINAPI_CC
SleepEx(
    boost_kahypar::winapi::DWORD_ dwMilliseconds,
    boost_kahypar::winapi::BOOL_ bAlertable);
BOOST_WINAPI_IMPORT_EXCEPT_WM boost_kahypar::winapi::VOID_ BOOST_WINAPI_WINAPI_CC Sleep(boost_kahypar::winapi::DWORD_ dwMilliseconds);
BOOST_WINAPI_IMPORT boost_kahypar::winapi::BOOL_ BOOST_WINAPI_WINAPI_CC SwitchToThread(BOOST_WINAPI_DETAIL_VOID);
} // extern "C"
#endif

namespace boost_kahypar {
namespace winapi {
using ::SleepEx;
using ::Sleep;
using ::SwitchToThread;
}
}

#include <boost_kahypar/winapi/detail/footer.hpp>

#endif // BOOST_WINAPI_PARTITION_APP_SYSTEM
#endif // BOOST_WINAPI_THREAD_HPP_INCLUDED_
