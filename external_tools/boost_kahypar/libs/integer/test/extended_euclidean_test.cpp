/*
 *  (C) Copyright Nick Thompson 2018.
 *  Use, modification and distribution are subject to the
 *  Boost Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt)
 */

#include "multiprecision_config.hpp"

#ifndef DISABLE_MP_TESTS
#include <boost_kahypar/integer/extended_euclidean.hpp>
#include <boost_kahypar/cstdint.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>
#include <boost_kahypar/multiprecision/cpp_int.hpp>
#include <boost_kahypar/integer/common_factor.hpp>

using boost_kahypar::multiprecision::int128_t;
using boost_kahypar::multiprecision::int256_t;
using boost_kahypar::integer::extended_euclidean;
using boost_kahypar::integer::gcd;

template<class Z>
void test_extended_euclidean()
{
    // Stress test:
    //Z max_arg = std::numeric_limits<Z>::max();
    Z max_arg = 500;
    for (Z m = max_arg; m > 0; --m)
    {
        for (Z n = max_arg; n > 0; --n)
        {
            boost_kahypar::integer::euclidean_result_t<Z> u = extended_euclidean(m, n);
            int256_t gcdmn = gcd(m, n);
            int256_t x = u.x;
            int256_t y = u.y;
            BOOST_TEST_EQ(u.gcd, gcdmn);
            BOOST_TEST_EQ(m*x + n*y, gcdmn);
        }
    }
}



int main()
{
    test_extended_euclidean<boost_kahypar::int16_t>();
    test_extended_euclidean<boost_kahypar::int32_t>();
    test_extended_euclidean<boost_kahypar::int64_t>();
    test_extended_euclidean<int128_t>();

    return boost_kahypar::report_errors();;
}
#else
int main()
{
    return 0;
}
#endif
