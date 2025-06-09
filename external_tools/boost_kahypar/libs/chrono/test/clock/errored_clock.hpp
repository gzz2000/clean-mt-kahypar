//  errored_clock.hpp  --------------------------------------------------------------//

//  Copyright 2010 Vicente J. Botet Escriba

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef BOOST_CHRONO_ERRORED_CLOCKS_HPP
#define BOOST_CHRONO_ERRORED_CLOCKS_HPP

#include <boost_kahypar/chrono/config.hpp>
#include <boost_kahypar/chrono/duration.hpp>
#include <boost_kahypar/chrono/time_point.hpp>
#include <boost_kahypar/system/error_code.hpp>
#include <boost_kahypar/system/system_error.hpp>
#include <boost_kahypar/throw_exception.hpp>
#include <boost_kahypar/chrono/detail/system.hpp>

  class errored_clock
  {
  public:
      typedef boost_kahypar::chrono::nanoseconds                          duration;
      typedef duration::rep                        rep;
      typedef duration::period                     period;
      typedef boost_kahypar::chrono::time_point<errored_clock>  time_point;
      static const bool is_steady =             true;
      static int errno_;

      static void set_errno(int err) {
          errno_=err;
      }

      // throws on error
      static time_point  now() {
          boost_kahypar::throw_exception(
                  boost_kahypar::system::system_error(
                          errno_,
                          ::boost_kahypar::system::system_category(),
                          "errored_clock"
                  )
          );
          return time_point();
      }
      // never throws and set ec
      static time_point  now(boost_kahypar::system::error_code & ec) {
          if (::boost_kahypar::chrono::is_throws(ec))
          {
              boost_kahypar::throw_exception(
                      boost_kahypar::system::system_error(
                              errno_,
                              ::boost_kahypar::system::system_category(),
                              "errored_clock"
                      )
              );
          }
          ec.assign( errno_, ::boost_kahypar::system::system_category() );
          return time_point();
      };
  };
  int errored_clock::errno_;

#endif
