// Copyright (c) 2021-2024 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost_kahypar/any.hpp>
#include <boost_kahypar/any/basic_any.hpp>

int main()
{
    boost_kahypar::anys::basic_any<256, 16> bany = 10;
    boost_kahypar::any value;
    value = bany;
}

