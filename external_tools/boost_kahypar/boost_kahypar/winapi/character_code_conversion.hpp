/*
 * Copyright 2016 Andrey Semashev
 *
 * Distributed under the Boost Software License, Version 1.0.
 * See http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef BOOST_WINAPI_CHARACTER_CODE_CONVERSION_HPP_INCLUDED_
#define BOOST_WINAPI_CHARACTER_CODE_CONVERSION_HPP_INCLUDED_

#include <boost_kahypar/winapi/basic_types.hpp>
#include <boost_kahypar/winapi/detail/header.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#if !defined( BOOST_USE_WINDOWS_H )
extern "C" {

BOOST_WINAPI_IMPORT_EXCEPT_WM int BOOST_WINAPI_WINAPI_CC
MultiByteToWideChar(
    boost_kahypar::winapi::UINT_ CodePage,
    boost_kahypar::winapi::DWORD_ dwFlags,
    boost_kahypar::winapi::LPCSTR_ lpMultiByteStr,
    int cbMultiByte,
    boost_kahypar::winapi::LPWSTR_ lpWideCharStr,
    int cchWideChar);

BOOST_WINAPI_IMPORT_EXCEPT_WM int BOOST_WINAPI_WINAPI_CC
WideCharToMultiByte(
    boost_kahypar::winapi::UINT_ CodePage,
    boost_kahypar::winapi::DWORD_ dwFlags,
    boost_kahypar::winapi::LPCWSTR_ lpWideCharStr,
    int cchWideChar,
    boost_kahypar::winapi::LPSTR_ lpMultiByteStr,
    int cbMultiByte,
    boost_kahypar::winapi::LPCSTR_ lpDefaultChar,
    boost_kahypar::winapi::LPBOOL_ lpUsedDefaultChar);

} // extern "C"
#endif // #if !defined( BOOST_USE_WINDOWS_H )

namespace boost_kahypar {
namespace winapi {

#if defined( BOOST_USE_WINDOWS_H )

BOOST_CONSTEXPR_OR_CONST UINT_ CP_ACP_ = CP_ACP;
BOOST_CONSTEXPR_OR_CONST UINT_ CP_OEMCP_ = CP_OEMCP;
BOOST_CONSTEXPR_OR_CONST UINT_ CP_MACCP_ = CP_MACCP;
BOOST_CONSTEXPR_OR_CONST UINT_ CP_THREAD_ACP_ = CP_THREAD_ACP;
BOOST_CONSTEXPR_OR_CONST UINT_ CP_SYMBOL_ = CP_SYMBOL;
BOOST_CONSTEXPR_OR_CONST UINT_ CP_UTF7_ = CP_UTF7;
BOOST_CONSTEXPR_OR_CONST UINT_ CP_UTF8_ = CP_UTF8;

BOOST_CONSTEXPR_OR_CONST DWORD_ MB_PRECOMPOSED_ = MB_PRECOMPOSED;
BOOST_CONSTEXPR_OR_CONST DWORD_ MB_COMPOSITE_ = MB_COMPOSITE;
BOOST_CONSTEXPR_OR_CONST DWORD_ MB_USEGLYPHCHARS_ = MB_USEGLYPHCHARS;
BOOST_CONSTEXPR_OR_CONST DWORD_ MB_ERR_INVALID_CHARS_ = MB_ERR_INVALID_CHARS;

BOOST_CONSTEXPR_OR_CONST DWORD_ WC_COMPOSITECHECK_ = WC_COMPOSITECHECK;
BOOST_CONSTEXPR_OR_CONST DWORD_ WC_DISCARDNS_ = WC_DISCARDNS;
BOOST_CONSTEXPR_OR_CONST DWORD_ WC_SEPCHARS_ = WC_SEPCHARS;
BOOST_CONSTEXPR_OR_CONST DWORD_ WC_DEFAULTCHAR_ = WC_DEFAULTCHAR;
#if BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_WIN2K
BOOST_CONSTEXPR_OR_CONST DWORD_ WC_NO_BEST_FIT_CHARS_ = WC_NO_BEST_FIT_CHARS;
#endif

#else // defined( BOOST_USE_WINDOWS_H )

BOOST_CONSTEXPR_OR_CONST UINT_ CP_ACP_ = 0u;
BOOST_CONSTEXPR_OR_CONST UINT_ CP_OEMCP_ = 1u;
BOOST_CONSTEXPR_OR_CONST UINT_ CP_MACCP_ = 2u;
BOOST_CONSTEXPR_OR_CONST UINT_ CP_THREAD_ACP_ = 3u;
BOOST_CONSTEXPR_OR_CONST UINT_ CP_SYMBOL_ = 42u;
BOOST_CONSTEXPR_OR_CONST UINT_ CP_UTF7_ = 65000u;
BOOST_CONSTEXPR_OR_CONST UINT_ CP_UTF8_ = 65001u;

BOOST_CONSTEXPR_OR_CONST DWORD_ MB_PRECOMPOSED_ = 0x00000001;
BOOST_CONSTEXPR_OR_CONST DWORD_ MB_COMPOSITE_ = 0x00000002;
BOOST_CONSTEXPR_OR_CONST DWORD_ MB_USEGLYPHCHARS_ = 0x00000004;
BOOST_CONSTEXPR_OR_CONST DWORD_ MB_ERR_INVALID_CHARS_ = 0x00000008;

BOOST_CONSTEXPR_OR_CONST DWORD_ WC_COMPOSITECHECK_ = 0x00000200;
BOOST_CONSTEXPR_OR_CONST DWORD_ WC_DISCARDNS_ = 0x00000010;
BOOST_CONSTEXPR_OR_CONST DWORD_ WC_SEPCHARS_ = 0x00000020;
BOOST_CONSTEXPR_OR_CONST DWORD_ WC_DEFAULTCHAR_ = 0x00000040;
#if BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_WIN2K
BOOST_CONSTEXPR_OR_CONST DWORD_ WC_NO_BEST_FIT_CHARS_ = 0x00000400;
#endif

#endif // defined( BOOST_USE_WINDOWS_H )

#if BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_WIN6
// This constant is not present in MinGW
BOOST_CONSTEXPR_OR_CONST DWORD_ WC_ERR_INVALID_CHARS_ = 0x00000080;
#endif

using ::MultiByteToWideChar;
using ::WideCharToMultiByte;

} // namespace winapi
} // namespace boost_kahypar

#include <boost_kahypar/winapi/detail/footer.hpp>

#endif // BOOST_WINAPI_CHARACTER_CODE_CONVERSION_HPP_INCLUDED_
