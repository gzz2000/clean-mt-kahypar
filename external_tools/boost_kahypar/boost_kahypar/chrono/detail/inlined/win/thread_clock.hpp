//  boost thread_clock.cpp  -----------------------------------------------------------//

//  Copyright 2010 Vicente J. Botet Escriba

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

//  See http://www.boost.org/libs/chrono for documentation.

//--------------------------------------------------------------------------------------//
#ifndef BOOST_CHRONO_DETAIL_INLINED_WIN_THREAD_CLOCK_HPP
#define BOOST_CHRONO_DETAIL_INLINED_WIN_THREAD_CLOCK_HPP

#include <boost_kahypar/chrono/config.hpp>
#include <boost_kahypar/chrono/thread_clock.hpp>
#include <cassert>
#include <boost_kahypar/assert.hpp>

#include <boost_kahypar/winapi/get_last_error.hpp>
#include <boost_kahypar/winapi/get_current_thread.hpp>
#include <boost_kahypar/winapi/get_thread_times.hpp>

namespace boost_kahypar
{
namespace chrono
{

#if !defined BOOST_CHRONO_DONT_PROVIDE_HYBRID_ERROR_HANDLING
thread_clock::time_point thread_clock::now( system::error_code & ec )
{
    //  note that Windows uses 100 nanosecond ticks for FILETIME
    boost_kahypar::winapi::FILETIME_ creation, exit, user_time, system_time;

    if ( boost_kahypar::winapi::GetThreadTimes(
            boost_kahypar::winapi::GetCurrentThread (), &creation, &exit,
            &system_time, &user_time ) )
    {
        duration user = duration(
                ((static_cast<duration::rep>(user_time.dwHighDateTime) << 32)
                        | user_time.dwLowDateTime) * 100 );

        duration system = duration(
                ((static_cast<duration::rep>(system_time.dwHighDateTime) << 32)
                        | system_time.dwLowDateTime) * 100 );

        if (!::boost_kahypar::chrono::is_throws(ec))
        {
            ec.clear();
        }
        return time_point(system+user);

    }
    else
    {
        if (::boost_kahypar::chrono::is_throws(ec))
        {
            boost_kahypar::throw_exception(
                    system::system_error(
                            boost_kahypar::winapi::GetLastError(),
                            ::boost_kahypar::system::system_category(),
                            "chrono::thread_clock" ));
        }
        else
        {
            ec.assign( boost_kahypar::winapi::GetLastError(), ::boost_kahypar::system::system_category() );
            return thread_clock::time_point(duration(0));
        }
    }
}
#endif

thread_clock::time_point thread_clock::now() BOOST_NOEXCEPT
{

    //  note that Windows uses 100 nanosecond ticks for FILETIME
    boost_kahypar::winapi::FILETIME_ creation, exit, user_time, system_time;

    if ( boost_kahypar::winapi::GetThreadTimes(
            boost_kahypar::winapi::GetCurrentThread (), &creation, &exit,
            &system_time, &user_time ) )
    {
        duration user   = duration(
                ((static_cast<duration::rep>(user_time.dwHighDateTime) << 32)
                        | user_time.dwLowDateTime) * 100 );

        duration system = duration(
                ((static_cast<duration::rep>(system_time.dwHighDateTime) << 32)
                        | system_time.dwLowDateTime) * 100 );

        return time_point(system+user);
    }
    else
    {
      BOOST_ASSERT(0 && "Boost::Chrono - Internal Error");
      return time_point();
    }

}

} // namespace chrono
} // namespace boost_kahypar

#endif
