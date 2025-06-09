/*
 *
 * Copyright (c) 1998-2002
 * John Maddock
 *
 * Use, modification and distribution are subject to the 
 * Boost Software License, Version 1.0. (See accompanying file 
 * LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 *
 */

 /*
  *   LOCATION:    see http://www.boost.org/libs/regex for documentation.
  *   FILE         regex.cpp
  *   VERSION      see <boost_kahypar/version.hpp>
  *   DESCRIPTION: Declares boost_kahypar::basic_regex<> and associated
  *                functions and classes. This header is the main
  *                entry point for the template regex code.
  */


/* start with C compatibility API */

#ifndef BOOST_RE_REGEX_HPP
#define BOOST_RE_REGEX_HPP

#ifndef BOOST_REGEX_CONFIG_HPP
#include <boost_kahypar/regex/config.hpp>
#endif

#ifdef BOOST_REGEX_CXX03
#include <boost_kahypar/regex/v4/regex.hpp>
#else
#include <boost_kahypar/regex/v5/regex.hpp>
#endif

#endif  // include




