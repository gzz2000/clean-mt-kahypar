/* test_triangle.cpp
 *
 * Copyright Steven Watanabe 2011
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * $Id$
 *
 */

#include <boost_kahypar/random/triangle_distribution.hpp>
#include <boost_kahypar/random/uniform_real.hpp>
#include <boost_kahypar/math/distributions/triangular.hpp>

#define BOOST_RANDOM_DISTRIBUTION boost_kahypar::random::triangle_distribution<>
#define BOOST_RANDOM_DISTRIBUTION_NAME lognormal
#define BOOST_MATH_DISTRIBUTION boost_kahypar::math::triangular
#define BOOST_RANDOM_ARG1_TYPE double
#define BOOST_RANDOM_ARG1_NAME b
#define BOOST_RANDOM_ARG1_DEFAULT 0.5
#define BOOST_RANDOM_ARG1_DISTRIBUTION(n) boost_kahypar::uniform_real<>(0.0001, 0.9999)
#define BOOST_RANDOM_DISTRIBUTION_INIT (0.0, b, 1.0)
#define BOOST_MATH_DISTRIBUTION_INIT (0.0, b, 1.0)

#include "test_real_distribution.ipp"
