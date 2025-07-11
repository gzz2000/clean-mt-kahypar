/*
 * Copyright 2010 Vicente J. Botet Escriba
 * Copyright 2015 Andrey Semashev
 *
 * Distributed under the Boost Software License, Version 1.0.
 * See http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef BOOST_WINAPI_GET_CURRENT_THREAD_ID_HPP_INCLUDED_
#define BOOST_WINAPI_GET_CURRENT_THREAD_ID_HPP_INCLUDED_

#include <boost_kahypar/winapi/basic_types.hpp>
#include <boost_kahypar/winapi/detail/header.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

// Windows CE define GetCurrentThreadId as an inline function in kfuncs.h
#if !defined( BOOST_USE_WINDOWS_H ) && !defined( UNDER_CE )
extern "C" {
BOOST_WINAPI_IMPORT boost_kahypar::winapi::DWORD_ BOOST_WINAPI_WINAPI_CC GetCurrentThreadId(BOOST_WINAPI_DETAIL_VOID);
}
#endif

namespace boost_kahypar {
namespace winapi {
using ::GetCurrentThreadId;
}
}

#include <boost_kahypar/winapi/detail/footer.hpp>

#endif // BOOST_WINAPI_GET_CURRENT_THREAD_ID_HPP_INCLUDED_
