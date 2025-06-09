//  boost/chrono/timer.hpp  ------------------------------------------------------------//

//  Copyright Beman Dawes 2008
//  Copyright 2009 Vicente J. Botet Escriba

//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/libs/system for documentation.

#ifndef BOOSTEX_CHRONO_TIMER_HPP
#define BOOSTEX_CHRONO_TIMER_HPP

#include <boost_kahypar/chrono/chrono.hpp>
#include <boost_kahypar/system/error_code.hpp>

namespace boost_kahypar_ex
{
  namespace chrono
  {

//--------------------------------------------------------------------------------------//
//                                    timer                                             //
//--------------------------------------------------------------------------------------//

    template <class Clock=boost_kahypar::chrono::high_resolution_clock>
    class timer
    {
    public:
      typedef Clock                       clock;
      typedef typename Clock::duration    duration;
      typedef typename Clock::time_point  time_point;

      explicit timer( boost_kahypar::system::error_code & ec = ::boost_kahypar::throws() )
        {
          start(ec);
          }

     ~timer() {}  // never throws

      void start( boost_kahypar::system::error_code & ec = ::boost_kahypar::throws() )
        {
          m_start = clock::now( ec );
          }

      duration elapsed( boost_kahypar::system::error_code & ec = ::boost_kahypar::throws() )
        { return clock::now( ec ) - m_start; }

    private:
      time_point m_start;
    };

    typedef chrono::timer< boost_kahypar::chrono::system_clock > system_timer;
#ifdef BOOST_CHRONO_HAS_CLOCK_STEADY
    typedef chrono::timer< boost_kahypar::chrono::steady_clock > steady_timer;
#endif
    typedef chrono::timer< boost_kahypar::chrono::high_resolution_clock > high_resolution_timer;

  } // namespace chrono
} // namespace boost_kahypar_ex

#endif
