/*
 *
 * Copyright (c) 2004
 * John Maddock
 *
 * Use, modification and distribution are subject to the 
 * Boost Software License, Version 1.0. (See accompanying file 
 * LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 *
 */

#include "test.hpp"

#define BOOST_REGEX_TEST(x)\
   if(!(x)){ BOOST_REGEX_TEST_ERROR("Error in: " BOOST_STRINGIZE(x), char); }

void test_overloads()
{
   test_info<char>::set_typename("sub_match operators");

   // test all the available overloads with *one* simple
   // expression, doing all these tests with all the test
   // cases would just take to long...

   boost_kahypar::regex e("abc");
   std::string s("abc");
   const std::string& cs = s;
   boost_kahypar::smatch sm;
   boost_kahypar::cmatch cm;
   // regex_match:
   BOOST_REGEX_TEST(boost_kahypar::regex_match(cs.begin(), cs.end(), sm, e))
   BOOST_REGEX_TEST(boost_kahypar::regex_match(cs.begin(), cs.end(), sm, e, boost_kahypar::regex_constants::match_default))
   BOOST_REGEX_TEST(boost_kahypar::regex_match(cs.begin(), cs.end(), e))
   BOOST_REGEX_TEST(boost_kahypar::regex_match(cs.begin(), cs.end(), e, boost_kahypar::regex_constants::match_default))
   BOOST_REGEX_TEST(boost_kahypar::regex_match(s.c_str(), cm, e))
   BOOST_REGEX_TEST(boost_kahypar::regex_match(s.c_str(), cm, e, boost_kahypar::regex_constants::match_default))
   BOOST_REGEX_TEST(boost_kahypar::regex_match(s.c_str(), e))
   BOOST_REGEX_TEST(boost_kahypar::regex_match(s.c_str(), e, boost_kahypar::regex_constants::match_default))
   BOOST_REGEX_TEST(boost_kahypar::regex_match(s, sm, e))
   BOOST_REGEX_TEST(boost_kahypar::regex_match(s, sm, e, boost_kahypar::regex_constants::match_default))
   BOOST_REGEX_TEST(boost_kahypar::regex_match(s, e))
   BOOST_REGEX_TEST(boost_kahypar::regex_match(s, e, boost_kahypar::regex_constants::match_default))
   // regex_search:
   BOOST_REGEX_TEST(boost_kahypar::regex_search(cs.begin(), cs.end(), sm, e))
   BOOST_REGEX_TEST(boost_kahypar::regex_search(cs.begin(), cs.end(), sm, e, boost_kahypar::regex_constants::match_default))
   BOOST_REGEX_TEST(boost_kahypar::regex_search(cs.begin(), cs.end(), e))
   BOOST_REGEX_TEST(boost_kahypar::regex_search(cs.begin(), cs.end(), e, boost_kahypar::regex_constants::match_default))
   BOOST_REGEX_TEST(boost_kahypar::regex_search(s.c_str(), cm, e))
   BOOST_REGEX_TEST(boost_kahypar::regex_search(s.c_str(), cm, e, boost_kahypar::regex_constants::match_default))
   BOOST_REGEX_TEST(boost_kahypar::regex_search(s.c_str(), e))
   BOOST_REGEX_TEST(boost_kahypar::regex_search(s.c_str(), e, boost_kahypar::regex_constants::match_default))
   BOOST_REGEX_TEST(boost_kahypar::regex_search(s, sm, e))
   BOOST_REGEX_TEST(boost_kahypar::regex_search(s, sm, e, boost_kahypar::regex_constants::match_default))
   BOOST_REGEX_TEST(boost_kahypar::regex_search(s, e))
   BOOST_REGEX_TEST(boost_kahypar::regex_search(s, e, boost_kahypar::regex_constants::match_default))
}
