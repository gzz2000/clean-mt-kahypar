/* boost random.hpp header file
 *
 * Copyright Jens Maurer 2000-2001
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * See http://www.boost.org/libs/random for documentation.
 *
 * $Id$
 *
 * Revision history
 *  2000-02-18  portability fixes (thanks to Beman Dawes)
 *  2000-02-21  shuffle_output, inversive_congruential_schrage,
 *              generator_iterator, uniform_smallint
 *  2000-02-23  generic modulus arithmetic helper, removed *_schrage classes,
 *              implemented Streamable and EqualityComparable concepts for 
 *              generators, added Bernoulli distribution and Box-Muller
 *              transform
 *  2000-03-01  cauchy, lognormal, triangle distributions; fixed 
 *              uniform_smallint; renamed gaussian to normal distribution
 *  2000-03-05  implemented iterator syntax for distribution functions
 *  2000-04-21  removed some optimizations for better BCC/MSVC compatibility
 *  2000-05-10  adapted to BCC and MSVC
 *  2000-06-13  incorporated review results
 *  2000-07-06  moved basic templates from namespace detail to random
 *  2000-09-23  warning removals and int64 fixes (Ed Brey)
 *  2000-09-24  added lagged_fibonacci generator (Matthias Troyer)
 *  2001-02-18  moved to individual header files
 */

#ifndef BOOST_RANDOM_HPP
#define BOOST_RANDOM_HPP

// generators
#include <boost_kahypar/random/additive_combine.hpp>
#include <boost_kahypar/random/discard_block.hpp>
#include <boost_kahypar/random/independent_bits.hpp>
#include <boost_kahypar/random/inversive_congruential.hpp>
#include <boost_kahypar/random/lagged_fibonacci.hpp>
#include <boost_kahypar/random/linear_congruential.hpp>
#include <boost_kahypar/random/linear_feedback_shift.hpp>
#include <boost_kahypar/random/mersenne_twister.hpp>
#include <boost_kahypar/random/mixmax.hpp>
#include <boost_kahypar/random/ranlux.hpp>
#include <boost_kahypar/random/shuffle_order.hpp>
#include <boost_kahypar/random/shuffle_output.hpp>
#include <boost_kahypar/random/subtract_with_carry.hpp>
#include <boost_kahypar/random/taus88.hpp>
#include <boost_kahypar/random/xor_combine.hpp>
#include <boost_kahypar/random/splitmix64.hpp>

// misc
#include <boost_kahypar/random/generate_canonical.hpp>
#include <boost_kahypar/random/seed_seq.hpp>
#include <boost_kahypar/random/random_number_generator.hpp>
#include <boost_kahypar/random/variate_generator.hpp>

// distributions
#include <boost_kahypar/random/bernoulli_distribution.hpp>
#include <boost_kahypar/random/beta_distribution.hpp>
#include <boost_kahypar/random/binomial_distribution.hpp>
#include <boost_kahypar/random/cauchy_distribution.hpp>
#include <boost_kahypar/random/chi_squared_distribution.hpp>
#include <boost_kahypar/random/discrete_distribution.hpp>
#include <boost_kahypar/random/exponential_distribution.hpp>
#include <boost_kahypar/random/extreme_value_distribution.hpp>
#include <boost_kahypar/random/fisher_f_distribution.hpp>
#include <boost_kahypar/random/gamma_distribution.hpp>
#include <boost_kahypar/random/geometric_distribution.hpp>
#include <boost_kahypar/random/hyperexponential_distribution.hpp>
#include <boost_kahypar/random/laplace_distribution.hpp>
#include <boost_kahypar/random/lognormal_distribution.hpp>
#include <boost_kahypar/random/negative_binomial_distribution.hpp>
#include <boost_kahypar/random/non_central_chi_squared_distribution.hpp>
#include <boost_kahypar/random/normal_distribution.hpp>
#include <boost_kahypar/random/piecewise_constant_distribution.hpp>
#include <boost_kahypar/random/piecewise_linear_distribution.hpp>
#include <boost_kahypar/random/poisson_distribution.hpp>
#include <boost_kahypar/random/student_t_distribution.hpp>
#include <boost_kahypar/random/triangle_distribution.hpp>
#include <boost_kahypar/random/uniform_01.hpp>
#include <boost_kahypar/random/uniform_int.hpp>
#include <boost_kahypar/random/uniform_int_distribution.hpp>
#include <boost_kahypar/random/uniform_on_sphere.hpp>
#include <boost_kahypar/random/uniform_real.hpp>
#include <boost_kahypar/random/uniform_real_distribution.hpp>
#include <boost_kahypar/random/uniform_smallint.hpp>
#include <boost_kahypar/random/weibull_distribution.hpp>

#include <boost_kahypar/random/generate_canonical.hpp>

#endif // BOOST_RANDOM_HPP
