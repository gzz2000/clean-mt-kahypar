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
  *   LOCATION:    see http://www.boost.org for most recent version.
  *   FILE         credit_card_example.cpp
  *   VERSION      see <boost_kahypar/version.hpp>
  *   DESCRIPTION: Credit card number formatting code.
  */

#include <boost_kahypar/regex.hpp>
#include <string>

bool validate_card_format(const std::string& s)
{
   static const boost_kahypar::regex e("(\\d{4}[- ]){3}\\d{4}");
   return boost_kahypar::regex_match(s, e);
}

const boost_kahypar::regex e("\\A(\\d{3,4})[- ]?(\\d{4})[- ]?(\\d{4})[- ]?(\\d{4})\\z");
const std::string machine_format("\\1\\2\\3\\4");
const std::string human_format("\\1-\\2-\\3-\\4");

std::string machine_readable_card_number(const std::string& s)
{
   return boost_kahypar::regex_replace(s, e, machine_format, boost_kahypar::match_default | boost_kahypar::format_sed);
}

std::string human_readable_card_number(const std::string& s)
{
   return boost_kahypar::regex_replace(s, e, human_format, boost_kahypar::match_default | boost_kahypar::format_sed);
}

#include <iostream>
using namespace std;

int main()
{
   string s[4] = { "0000111122223333", "0000 1111 2222 3333",
                   "0000-1111-2222-3333", "000-1111-2222-3333", };
   int i;
   for(i = 0; i < 4; ++i)
   {
      cout << "validate_card_format(\"" << s[i] << "\") returned " << validate_card_format(s[i]) << endl;
   }
   for(i = 0; i < 4; ++i)
   {
      cout << "machine_readable_card_number(\"" << s[i] << "\") returned " << machine_readable_card_number(s[i]) << endl;
   }
   for(i = 0; i < 4; ++i)
   {
      cout << "human_readable_card_number(\"" << s[i] << "\") returned " << human_readable_card_number(s[i]) << endl;
   }
   return 0;
}




