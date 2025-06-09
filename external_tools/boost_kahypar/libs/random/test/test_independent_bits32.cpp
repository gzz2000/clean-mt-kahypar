/* test_independent_bits32.cpp
 *
 * Copyright Steven Watanabe 2011
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * $Id$
 *
 */

#include <boost_kahypar/random/independent_bits.hpp>
#include <boost_kahypar/random/mersenne_twister.hpp>

typedef boost_kahypar::random::independent_bits_engine<boost_kahypar::random::mt19937, 32, boost_kahypar::uint32_t> independent_bits32;
#define BOOST_RANDOM_URNG independent_bits32

#define BOOST_RANDOM_SEED_WORDS 624

#define BOOST_RANDOM_VALIDATION_VALUE 4123659995U
#define BOOST_RANDOM_SEED_SEQ_VALIDATION_VALUE 666528879U
#define BOOST_RANDOM_ITERATOR_VALIDATION_VALUE 3408548740U

#define BOOST_RANDOM_GENERATE_VALUES { 0xD091BB5CU, 0x22AE9EF6U, 0xE7E1FAEEU, 0xD5C31F79U }

#include "test_generator.ipp"
