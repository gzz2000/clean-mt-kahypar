//  Unit test for boost_kahypar::lexical_cast.
//
//  See http://www.boost.org for most recent version, including documentation.
//
//  Copyright Antony Polukhin, 2011-2024.
//
//  Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt).

#include <boost_kahypar/lexical_cast.hpp>

#include <boost_kahypar/static_assert.hpp>
#include <boost_kahypar/date_time/gregorian/gregorian.hpp>
#include <boost_kahypar/date_time/posix_time/posix_time.hpp>

void parseDate()
{
  std::locale locale;
  boost_kahypar::date_time::format_date_parser<boost_kahypar::gregorian::date, wchar_t> parser(L"", locale);
  boost_kahypar::date_time::special_values_parser<boost_kahypar::gregorian::date, wchar_t> svp;

  boost_kahypar::gregorian::date date = parser.parse_date(L"", L"", svp);
  (void)date;
}


int main()
{
    parseDate();
    return ::boost_kahypar::lexical_cast<int>(L"1000") == 1000;
}


