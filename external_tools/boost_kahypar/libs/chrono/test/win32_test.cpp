//  boost win32_test.cpp  -----------------------------------------------------//

//  Copyright 2010 Vicente J. Botet Escriba

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

//  See http://www.boost.org/libs/chrono for documentation.
#include <boost_kahypar/chrono/config.hpp>
#include <boost_kahypar/detail/lightweight_test.hpp>
#if defined(BOOST_CHRONO_WINDOWS_API) ||  defined(__CYGWIN__)

#include <boost_kahypar/chrono/detail/static_assert.hpp>
#if !defined(BOOST_NO_CXX11_STATIC_ASSERT)
#define NOTHING ""
#endif

#include <boost_kahypar/type_traits.hpp>
#include <boost_kahypar/typeof/typeof.hpp>
#undef BOOST_USE_WINDOWS_H
#include <boost_kahypar/winapi/basic_types.hpp>
#include <boost_kahypar/winapi/time.hpp>
#include <windows.h>

void test() {
    {
    boost_kahypar::winapi::LARGE_INTEGER_ a;
    LARGE_INTEGER b;
    BOOST_CHRONO_STATIC_ASSERT((
            sizeof(boost_kahypar::winapi::LARGE_INTEGER_)==sizeof(LARGE_INTEGER)
        ), NOTHING, (boost_kahypar::winapi::LARGE_INTEGER_, LARGE_INTEGER));
    BOOST_TEST((
            sizeof(a.QuadPart)==sizeof(b.QuadPart)
            ));
    BOOST_CHRONO_STATIC_ASSERT((
            offsetof(boost_kahypar::winapi::LARGE_INTEGER_, QuadPart)==offsetof(LARGE_INTEGER, QuadPart)
        ), NOTHING, (boost_kahypar::winapi::LARGE_INTEGER_, LARGE_INTEGER));
    BOOST_CHRONO_STATIC_ASSERT((
            boost_kahypar::is_same<
                    BOOST_TYPEOF(a.QuadPart),
                    BOOST_TYPEOF(b.QuadPart)
                >::value
        ), NOTHING, (boost_kahypar::winapi::LARGE_INTEGER_, LARGE_INTEGER));
    }

    BOOST_CHRONO_STATIC_ASSERT((
            sizeof(boost_kahypar::winapi::BOOL_)==sizeof(BOOL)
        ), NOTHING, (boost_kahypar::winapi::BOOL_, BOOL));
    BOOST_CHRONO_STATIC_ASSERT((
            boost_kahypar::is_same<boost_kahypar::winapi::BOOL_,BOOL>::value
        ), NOTHING, (boost_kahypar::winapi::BOOL_, BOOL));

    BOOST_CHRONO_STATIC_ASSERT((
            sizeof(boost_kahypar::winapi::DWORD_)==sizeof(DWORD)
        ), NOTHING, (boost_kahypar::winapi::DWORD_, DWORD));
    BOOST_CHRONO_STATIC_ASSERT((
            boost_kahypar::is_same<boost_kahypar::winapi::DWORD_,DWORD>::value
        ), NOTHING, (boost_kahypar::winapi::DWORD_, DWORD));

    BOOST_CHRONO_STATIC_ASSERT((
            sizeof(boost_kahypar::winapi::HANDLE_)==sizeof(HANDLE)
        ), NOTHING, (boost_kahypar::winapi::HANDLE_, HANDLE));
    BOOST_CHRONO_STATIC_ASSERT((
            boost_kahypar::is_same<boost_kahypar::winapi::HANDLE_,HANDLE>::value
        ), NOTHING, (boost_kahypar::winapi::HANDLE_, HANDLE));

    BOOST_CHRONO_STATIC_ASSERT((
            sizeof(boost_kahypar::winapi::LONG_)==sizeof(LONG)
        ), NOTHING, (boost_kahypar::winapi::LONG_, LONG));
    BOOST_CHRONO_STATIC_ASSERT((
            boost_kahypar::is_same<boost_kahypar::winapi::LONG_,LONG>::value
        ), NOTHING, (boost_kahypar::winapi::LONG_, LONG));

    BOOST_CHRONO_STATIC_ASSERT((
            sizeof(boost_kahypar::winapi::LONGLONG_)==sizeof(LONGLONG)
        ), NOTHING, (boost_kahypar::winapi::LONGLONG_, LONGLONG));
    BOOST_CHRONO_STATIC_ASSERT((
            boost_kahypar::is_same<boost_kahypar::winapi::LONGLONG_,LONGLONG>::value
        ), NOTHING, (boost_kahypar::winapi::LONGLONG_, LONGLONG));

    BOOST_CHRONO_STATIC_ASSERT((
            sizeof(boost_kahypar::winapi::ULONG_PTR_)==sizeof(ULONG_PTR)
        ), NOTHING, (boost_kahypar::winapi::ULONG_PTR_, ULONG_PTR));
    BOOST_CHRONO_STATIC_ASSERT((
            boost_kahypar::is_same<boost_kahypar::winapi::ULONG_PTR_,ULONG_PTR>::value
        ), NOTHING, (boost_kahypar::winapi::ULONG_PTR_, ULONG_PTR));
        
    BOOST_CHRONO_STATIC_ASSERT((
            sizeof(boost_kahypar::winapi::PLARGE_INTEGER_)==sizeof(PLARGE_INTEGER)
        ), NOTHING, (boost_kahypar::winapi::PLARGE_INTEGER_, PLARGE_INTEGER));
    //~ BOOST_CHRONO_STATIC_ASSERT((
            //~ boost_kahypar::is_same<boost_kahypar::winapi::PLARGE_INTEGER_,PLARGE_INTEGER>::value
        //~ ), NOTHING, (boost_kahypar::winapi::PLARGE_INTEGER_, PLARGE_INTEGER));
        
    {
        BOOST_CHRONO_STATIC_ASSERT((
                sizeof(boost_kahypar::winapi::FILETIME_)==sizeof(FILETIME)
            ), NOTHING, (boost_kahypar::winapi::FILETIME_, FILETIME));
        
        BOOST_CHRONO_STATIC_ASSERT((
                sizeof(boost_kahypar::winapi::PFILETIME_)==sizeof(PFILETIME)
            ), NOTHING, (boost_kahypar::winapi::PFILETIME_, PFILETIME));
        

        boost_kahypar::winapi::FILETIME_ a;
        FILETIME b;
        BOOST_TEST((
                sizeof(a.dwLowDateTime)==sizeof(b.dwLowDateTime)
                ));
        BOOST_TEST((
                sizeof(a.dwHighDateTime)==sizeof(b.dwHighDateTime)
                ));
        BOOST_CHRONO_STATIC_ASSERT((
                offsetof(boost_kahypar::winapi::FILETIME_, dwLowDateTime)==offsetof(FILETIME, dwLowDateTime)
            ), NOTHING, (boost_kahypar::winapi::FILETIME_, FILETIME));
        BOOST_CHRONO_STATIC_ASSERT((
                offsetof(boost_kahypar::winapi::FILETIME_, dwHighDateTime)==offsetof(FILETIME, dwHighDateTime)
            ), NOTHING, (boost_kahypar::winapi::FILETIME_, FILETIME));
        BOOST_CHRONO_STATIC_ASSERT((
            boost_kahypar::is_same<
                    BOOST_TYPEOF(a.dwLowDateTime),
                    BOOST_TYPEOF(b.dwLowDateTime)
                >::value
        ), NOTHING, (boost_kahypar::winapi::FILETIME_, FILETIME));
        BOOST_CHRONO_STATIC_ASSERT((
            boost_kahypar::is_same<
                    BOOST_TYPEOF(a.dwHighDateTime),
                    BOOST_TYPEOF(b.dwHighDateTime)
                >::value
        ), NOTHING, (boost_kahypar::winapi::FILETIME_, FILETIME));

    }

//    BOOST_CHRONO_STATIC_ASSERT((
//            GetLastError==boost_kahypar::winapi::::GetLastError
//        ), NOTHING, ());

}
#else
void test() {
}
#endif
int main(  )
{
    test();

  return boost_kahypar::report_errors();
}

