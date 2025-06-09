/* test_geometric.cpp
 *
 * Copyright Steven Watanabe 2011
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * $Id$
 *
 */

#include <boost_kahypar/random/geometric_distribution.hpp>
#include <boost_kahypar/random/uniform_real.hpp>
#include <boost_kahypar/math/distributions/geometric.hpp>
#include <boost_kahypar/numeric/conversion/cast.hpp>

#define BOOST_RANDOM_DISTRIBUTION boost_kahypar::random::geometric_distribution<>
#define BOOST_RANDOM_DISTRIBUTION_NAME geometric
#define BOOST_MATH_DISTRIBUTION boost_kahypar::math::geometric
#define BOOST_RANDOM_ARG1_TYPE double
#define BOOST_RANDOM_ARG1_NAME p
#define BOOST_RANDOM_ARG1_DEFAULT 0.5
#define BOOST_RANDOM_ARG1_DISTRIBUTION(n) boost_kahypar::uniform_real<>(0.0001, 0.9999)
#define BOOST_RANDOM_DISTRIBUTION_MAX boost_kahypar::numeric_cast<int>(-5 / std::log(1-p))

#include "test_real_distribution.ipp"
