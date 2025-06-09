//
// Copyright (C) 2018 James E. King III
// 
// Permission to copy, use, modify, sell and distribute this software
// is granted provided this copyright notice appears in all copies.
// This software is provided "as is" without express or implied
// warranty, and with no claim as to its suitability for any purpose.
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#include <boost_kahypar/cstdint.hpp>
#include <boost_kahypar/dynamic_bitset/detail/lowest_bit.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>

int main(int, char*[])
{
    for (boost_kahypar::int32_t i = 1; i < 32; ++i) {
	BOOST_TEST_EQ(i, boost_kahypar::detail::lowest_bit(1u << i));
    }

    BOOST_TEST_EQ(2, boost_kahypar::detail::lowest_bit(123456788));
    BOOST_TEST_EQ(30, boost_kahypar::detail::lowest_bit(static_cast<boost_kahypar::int64_t>(1507208177123328)));

    return boost_kahypar::report_errors();
}
