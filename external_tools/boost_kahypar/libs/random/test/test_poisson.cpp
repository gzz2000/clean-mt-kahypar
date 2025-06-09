/* test_poisson.cpp
 *
 * Copyright Steven Watanabe 2010
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * $Id$
 *
 */

#include <boost_kahypar/random/poisson_distribution.hpp>
#include <boost_kahypar/random/uniform_real.hpp>
#include <boost_kahypar/math/distributions/poisson.hpp>

#define BOOST_RANDOM_DISTRIBUTION boost_kahypar::random::poisson_distribution<>
#define BOOST_RANDOM_DISTRIBUTION_NAME poisson
#define BOOST_MATH_DISTRIBUTION boost_kahypar::math::poisson
#define BOOST_RANDOM_ARG1_TYPE double
#define BOOST_RANDOM_ARG1_NAME mean
#define BOOST_RANDOM_ARG1_DEFAULT 100000.0
#define BOOST_RANDOM_ARG1_DISTRIBUTION(n) boost_kahypar::uniform_real<>(1e-15, n)
#define BOOST_RANDOM_DISTRIBUTION_MAX static_cast<int>(mean * 4)

#include "test_real_distribution.ipp"
