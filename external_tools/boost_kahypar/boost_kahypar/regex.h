/*
 *
 * Copyright (c) 1998-2000
 * Dr John Maddock
 *
 * Use, modification and distribution are subject to the 
 * Boost Software License, Version 1.0. (See accompanying file 
 * LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 *
 */
 
 /*
  *   LOCATION:    see http://www.boost.org/libs/regex for documentation.
  *   FILE         regex.h
  *   VERSION      3.12
  *   DESCRIPTION: Declares POSIX API functions
  */

#ifndef BOOST_RE_REGEX_H
#define BOOST_RE_REGEX_H

#include <boost_kahypar/cregex.hpp>

/*
*  add using declarations to bring POSIX API functions into
* global scope, only if this is C++ (and not C).
*/
#ifdef __cplusplus

using boost_kahypar::regoff_t;
using boost_kahypar::regex_tA;
using boost_kahypar::regmatch_t;
using boost_kahypar::REG_BASIC;
using boost_kahypar::REG_EXTENDED;
using boost_kahypar::REG_ICASE;
using boost_kahypar::REG_NOSUB;
using boost_kahypar::REG_NEWLINE;
using boost_kahypar::REG_NOSPEC;
using boost_kahypar::REG_PEND;
using boost_kahypar::REG_DUMP;
using boost_kahypar::REG_NOCOLLATE;
using boost_kahypar::REG_ESCAPE_IN_LISTS;
using boost_kahypar::REG_NEWLINE_ALT;
using boost_kahypar::REG_PERL;
using boost_kahypar::REG_AWK;
using boost_kahypar::REG_GREP;
using boost_kahypar::REG_EGREP;
using boost_kahypar::REG_ASSERT;
using boost_kahypar::REG_INVARG;
using boost_kahypar::REG_ATOI;
using boost_kahypar::REG_ITOA;

using boost_kahypar::REG_NOTBOL;
using boost_kahypar::REG_NOTEOL;
using boost_kahypar::REG_STARTEND;

using boost_kahypar::reg_comp_flags;
using boost_kahypar::reg_exec_flags;
using boost_kahypar::regcompA;
using boost_kahypar::regerrorA;
using boost_kahypar::regexecA;
using boost_kahypar::regfreeA;

#ifndef BOOST_NO_WREGEX
using boost_kahypar::regcompW;
using boost_kahypar::regerrorW;
using boost_kahypar::regexecW;
using boost_kahypar::regfreeW;
using boost_kahypar::regex_tW;
#endif

using boost_kahypar::REG_NOERROR;
using boost_kahypar::REG_NOMATCH;
using boost_kahypar::REG_BADPAT;
using boost_kahypar::REG_ECOLLATE;
using boost_kahypar::REG_ECTYPE;
using boost_kahypar::REG_EESCAPE;
using boost_kahypar::REG_ESUBREG;
using boost_kahypar::REG_EBRACK;
using boost_kahypar::REG_EPAREN;
using boost_kahypar::REG_EBRACE;
using boost_kahypar::REG_BADBR;
using boost_kahypar::REG_ERANGE;
using boost_kahypar::REG_ESPACE;
using boost_kahypar::REG_BADRPT;
using boost_kahypar::REG_EEND;
using boost_kahypar::REG_ESIZE;
using boost_kahypar::REG_ERPAREN;
using boost_kahypar::REG_EMPTY;
using boost_kahypar::REG_E_MEMORY;
using boost_kahypar::REG_E_UNKNOWN;
using boost_kahypar::reg_errcode_t;

#endif /* __cplusplus */

#endif /* BOOST_RE_REGEX_H */




