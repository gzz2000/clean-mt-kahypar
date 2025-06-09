//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Vicente J. Botet Escriba 20010.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or
// copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Based on the unique_threader/unique_joiner design from of Kevlin Henney (n1883)
//
// See http://www.boost.org/libs/chrono for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef BOOST_CHRONO_TYPEOF_RATIO_HPP
#define BOOST_CHRONO_TYPEOF_RATIO_HPP

#include <boost_kahypar/ratio/ratio.hpp>
#include <boost_kahypar/typeof/typeof.hpp>

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TEMPLATE(boost_kahypar::ratio, (boost_kahypar::intmax_t)(boost_kahypar::intmax_t))

#endif
