/* test_non_central_chi_squared.cpp
 *
 * Copyright Steven Watanabe 2011
 * Copyright Thijs van den Berg 2014
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * $Id$
 *
 */
 
#include <boost_kahypar/random/non_central_chi_squared_distribution.hpp>
#include <boost_kahypar/random/uniform_real.hpp>
#include <boost_kahypar/math/distributions/non_central_chi_squared.hpp>

#define BOOST_RANDOM_DISTRIBUTION boost_kahypar::random::non_central_chi_squared_distribution<>
#define BOOST_RANDOM_DISTRIBUTION_NAME non_central_chi_squared
#define BOOST_MATH_DISTRIBUTION boost_kahypar::math::non_central_chi_squared
#define BOOST_RANDOM_ARG1_TYPE double
#define BOOST_RANDOM_ARG1_NAME k
#define BOOST_RANDOM_ARG1_DEFAULT 1000.0
#define BOOST_RANDOM_ARG1_DISTRIBUTION(k) boost_kahypar::uniform_real<>(0.00001, k)
#define BOOST_RANDOM_ARG2_TYPE double
#define BOOST_RANDOM_ARG2_NAME lambda
#define BOOST_RANDOM_ARG2_DEFAULT 1000.0
#define BOOST_RANDOM_ARG2_DISTRIBUTION(lambda) boost_kahypar::uniform_real<>(0.00001, lambda)

#include "test_real_distribution.ipp"
