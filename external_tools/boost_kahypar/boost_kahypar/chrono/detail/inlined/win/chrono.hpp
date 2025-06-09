//  win/chrono.cpp  --------------------------------------------------------------//

//  Copyright Beman Dawes 2008
//  Copyright 2009-2010 Vicente J. Botet Escriba

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

//----------------------------------------------------------------------------//
//                                Windows                                     //
//----------------------------------------------------------------------------//
#ifndef BOOST_CHRONO_DETAIL_INLINED_WIN_CHRONO_HPP
#define BOOST_CHRONO_DETAIL_INLINED_WIN_CHRONO_HPP

#include <boost_kahypar/winapi/time.hpp>
#include <boost_kahypar/winapi/timers.hpp>
#include <boost_kahypar/winapi/get_last_error.hpp>
#include <boost_kahypar/winapi/error_codes.hpp>
#include <boost_kahypar/assert.hpp>

namespace boost_kahypar
{
namespace chrono
{
namespace chrono_detail
{

  BOOST_CHRONO_INLINE double get_nanosecs_per_tic() BOOST_NOEXCEPT
  {
      boost_kahypar::winapi::LARGE_INTEGER_ freq;
      if ( !boost_kahypar::winapi::QueryPerformanceFrequency( &freq ) )
          return 0.0L;
      return double(1000000000.0L / freq.QuadPart);
  }

}

  steady_clock::time_point steady_clock::now() BOOST_NOEXCEPT
  {
    double nanosecs_per_tic = chrono_detail::get_nanosecs_per_tic();

    boost_kahypar::winapi::LARGE_INTEGER_ pcount;
    if ( nanosecs_per_tic <= 0.0L )
    {
      BOOST_ASSERT(0 && "Boost::Chrono - get_nanosecs_per_tic Internal Error");
      return steady_clock::time_point();
    }
    unsigned times=0;
    while ( ! boost_kahypar::winapi::QueryPerformanceCounter( &pcount ) )
    {
      if ( ++times > 3 )
      {
        BOOST_ASSERT(0 && "Boost::Chrono - QueryPerformanceCounter Internal Error");
        return steady_clock::time_point();
      }
    }

    return steady_clock::time_point(steady_clock::duration(
      static_cast<steady_clock::rep>((nanosecs_per_tic) * pcount.QuadPart)));
  }


#if !defined BOOST_CHRONO_DONT_PROVIDE_HYBRID_ERROR_HANDLING
  steady_clock::time_point steady_clock::now( system::error_code & ec )
  {
    double nanosecs_per_tic = chrono_detail::get_nanosecs_per_tic();

    boost_kahypar::winapi::LARGE_INTEGER_ pcount;
    if ( (nanosecs_per_tic <= 0.0L)
            || (!boost_kahypar::winapi::QueryPerformanceCounter( &pcount )) )
    {
        boost_kahypar::winapi::DWORD_ cause =
            ((nanosecs_per_tic <= 0.0L)
                    ? boost_kahypar::winapi::ERROR_NOT_SUPPORTED_
                    : boost_kahypar::winapi::GetLastError());
        if (::boost_kahypar::chrono::is_throws(ec)) {
            boost_kahypar::throw_exception(
                    system::system_error(
                            cause,
                            ::boost_kahypar::system::system_category(),
                            "chrono::steady_clock" ));
        }
        else
        {
            ec.assign( cause, ::boost_kahypar::system::system_category() );
            return steady_clock::time_point(duration(0));
        }
    }

    if (!::boost_kahypar::chrono::is_throws(ec))
    {
        ec.clear();
    }
    return time_point(duration(
      static_cast<steady_clock::rep>(nanosecs_per_tic * pcount.QuadPart)));
  }
#endif

  BOOST_CHRONO_INLINE
  system_clock::time_point system_clock::now() BOOST_NOEXCEPT
  {
    boost_kahypar::winapi::FILETIME_ ft;
    boost_kahypar::winapi::GetSystemTimeAsFileTime( &ft );  // never fails
    return system_clock::time_point(
      system_clock::duration(
        ((static_cast<__int64>( ft.dwHighDateTime ) << 32) | ft.dwLowDateTime)
       - 116444736000000000LL
       //- (134775LL*864000000000LL)
      )
    );
  }

#if !defined BOOST_CHRONO_DONT_PROVIDE_HYBRID_ERROR_HANDLING
  BOOST_CHRONO_INLINE
  system_clock::time_point system_clock::now( system::error_code & ec )
  {
    boost_kahypar::winapi::FILETIME_ ft;
    boost_kahypar::winapi::GetSystemTimeAsFileTime( &ft );  // never fails
    if (!::boost_kahypar::chrono::is_throws(ec))
    {
        ec.clear();
    }
    return system_clock::time_point(
      system_clock::duration(
       ((static_cast<__int64>( ft.dwHighDateTime ) << 32) | ft.dwLowDateTime)
       - 116444736000000000LL
       //- (134775LL*864000000000LL)
       ));
  }
#endif

  BOOST_CHRONO_INLINE
  std::time_t system_clock::to_time_t(const system_clock::time_point& t) BOOST_NOEXCEPT
  {
      __int64 temp = t.time_since_epoch().count();
      temp /= 10000000;
      return static_cast<std::time_t>( temp );
  }

  BOOST_CHRONO_INLINE
  system_clock::time_point system_clock::from_time_t(std::time_t t) BOOST_NOEXCEPT
  {
      __int64 temp = t;
      temp *= 10000000;
      return time_point(duration(temp));
  }

}  // namespace chrono
}  // namespace boost_kahypar

#endif
