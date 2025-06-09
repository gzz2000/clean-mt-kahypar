/*
 *
 * Copyright (c) 2003
 * John Maddock
 *
 * Use, modification and distribution are subject to the 
 * Boost Software License, Version 1.0. (See accompanying file 
 * LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 *
 */

#include <boost_kahypar/regex.hpp>
#include <boost_kahypar/config.hpp>

#if defined(BOOST_MSVC)
// this lets us compile at warning level 4 without seeing concept-check related warnings
#  pragma warning(disable:4100)
#endif
#ifdef BOOST_BORLANDC
#pragma option -w-8019 -w-8004 -w-8008
#endif
#ifdef BOOST_INTEL
#pragma warning(disable:1418 981 983 595 383)
#endif

#include <boost_kahypar/regex/concepts.hpp>


int main()
{
   boost_kahypar::function_requires<
      boost_kahypar::RegexTraitsConcept<
         boost_kahypar::regex_traits<char>
      >
   >();
#ifndef BOOST_NO_STD_LOCALE
   boost_kahypar::function_requires<
      boost_kahypar::BoostRegexConcept<
         boost_kahypar::basic_regex<char, boost_kahypar::cpp_regex_traits<char> >
      >
   >();
#ifndef BOOST_NO_WREGEX
   boost_kahypar::function_requires<
      boost_kahypar::BoostRegexConcept<
         boost_kahypar::basic_regex<wchar_t, boost_kahypar::cpp_regex_traits<wchar_t> >
      >
   >();
#endif
#endif
   boost_kahypar::function_requires<
      boost_kahypar::BoostRegexConcept<
         boost_kahypar::basic_regex<char, boost_kahypar::c_regex_traits<char> >
      >
   >();
#ifndef BOOST_NO_WREGEX
   boost_kahypar::function_requires<
      boost_kahypar::BoostRegexConcept<
         boost_kahypar::basic_regex<wchar_t, boost_kahypar::c_regex_traits<wchar_t> >
      >
   >();
#endif
#if defined(_WIN32) && !defined(BOOST_REGEX_NO_W32)
   boost_kahypar::function_requires<
      boost_kahypar::BoostRegexConcept<
         boost_kahypar::basic_regex<char, boost_kahypar::w32_regex_traits<char> >
      >
   >();
#ifndef BOOST_NO_WREGEX
   boost_kahypar::function_requires<
      boost_kahypar::BoostRegexConcept<
         boost_kahypar::basic_regex<wchar_t, boost_kahypar::w32_regex_traits<wchar_t> >
      >
   >();
#endif
#endif
   //
   // now test the regex_traits concepts:
   //
   typedef boost_kahypar::basic_regex<char, boost_kahypar::regex_traits_architype<char> > regex_traits_tester_type1;
   boost_kahypar::function_requires<
      boost_kahypar::BoostRegexConcept<
         regex_traits_tester_type1
      >
   >();
   typedef boost_kahypar::basic_regex<boost_kahypar::char_architype, boost_kahypar::regex_traits_architype<boost_kahypar::char_architype> > regex_traits_tester_type2;
   boost_kahypar::function_requires<
      boost_kahypar::BaseRegexConcept<
         regex_traits_tester_type2
      >
   >();
   return 0;
}


