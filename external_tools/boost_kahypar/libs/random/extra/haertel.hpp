/* haertel.hpp file
 *
 * Copyright Jens Maurer 2000, 2002
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * $Id$
 *
 * Revision history
 */

/*
 * NOTE: This is not part of the official boost submission.  It exists
 * only as a collection of ideas.
 */

#ifndef BOOST_RANDOM_HAERTEL_HPP
#define BOOST_RANDOM_HAERTEL_HPP

#include <boost_kahypar/cstdint.hpp>
#include <boost_kahypar/random/linear_congruential.hpp>
#include <boost_kahypar/random/inversive_congruential.hpp>

namespace boost_kahypar {
namespace random {

// Wikramaratna 1989  ACORN
template<class IntType, int k, IntType m, IntType val>
class additive_congruential
{
public:
  typedef IntType result_type;
#ifndef BOOST_NO_INCLASS_MEMBER_INITIALIZATION
  static const bool has_fixed_range = true;
  static const result_type min_value = 0;
  static const result_type max_value = m-1;
#else
  enum {
    has_fixed_range = true,
    min_value = 0,
    max_value = m-1
  };
#endif
  template<class InputIterator>
  explicit additive_congruential(InputIterator start) { seed(start); }
  template<class InputIterator>
  void seed(InputIterator start)
  {
    for(int i = 0; i <= k; ++i, ++start)
      values[i] = *start;
  }
  
  result_type operator()()
  {
    for(int i = 1; i <= k; ++i) {
      IntType tmp = values[i-1] + values[i];
      if(tmp >= m)
        tmp -= m;
      values[i] = tmp;
    }
    return values[k];
  }
  result_type validation() const { return val; }
private:
  IntType values[k+1];
};


template<class IntType, int r, int s, IntType m, IntType val>
class lagged_fibonacci_int
{
public:
  typedef IntType result_type;
#ifndef BOOST_NO_INCLASS_MEMBER_INITIALIZATION
  static const bool has_fixed_range = true;
  static const result_type min_value = 0;
  static const result_type max_value = m-1;
#else
  enum {
    has_fixed_range = true,
    min_value = 0,
    max_value = m-1
  };
#endif
  explicit lagged_fibonacci_int(IntType start) { seed(start); }
  template<class Generator>
  explicit lagged_fibonacci_int(Generator & gen) { seed(gen); }
  void seed(IntType start)
  {
    linear_congruential<uint32_t, 299375077, 0, 0, 0> init;
    seed(init);
  }
  template<class Generator>
  void seed(Generator & gen)
  {
    assert(r > s);
    for(int i = 0; i < 607; ++i)
      values[i] = gen();
    current = 0;
    lag = r-s;
  }
  
  result_type operator()()
  {
    result_type tmp = values[current] + values[lag];
    if(tmp >= m)
      tmp -= m;
    values[current] = tmp;
    ++current;
    if(current >= r)
      current = 0;
    ++lag;
    if(lag >= r)
      lag = 0;
    return tmp;
  }
  result_type validation() const { return val; }
private:
  result_type values[r];
  int current, lag;
};

} // namespace random
} // namespace boost_kahypar

// distributions from Haertel's dissertation
// (additional parameterizations of the basic templates)
namespace Haertel {
  typedef boost_kahypar::random::linear_congruential<boost_kahypar::uint64_t, 45965, 453816691,
    (boost_kahypar::uint64_t(1)<<31), 0> LCG_Af2;
  typedef boost_kahypar::random::linear_congruential<boost_kahypar::uint64_t, 211936855, 0,
    (boost_kahypar::uint64_t(1)<<29)-3, 0> LCG_Die1;
  typedef boost_kahypar::random::linear_congruential<boost_kahypar::uint32_t, 2824527309u, 0,
    0, 0> LCG_Fis;
  typedef boost_kahypar::random::linear_congruential<boost_kahypar::uint64_t, 950706376u, 0,
    (boost_kahypar::uint64_t(1)<<31)-1, 0> LCG_FM;
  typedef boost_kahypar::random::linear_congruential<boost_kahypar::int32_t, 51081, 0,
    2147483647, 0> LCG_Hae;
  typedef boost_kahypar::random::linear_congruential<boost_kahypar::uint32_t, 69069, 1,
    0, 0> LCG_VAX;
  typedef boost_kahypar::random::inversive_congruential<boost_kahypar::int64_t, 240318, 197, 
    1000081, 0> NLG_Inv1;
  typedef boost_kahypar::random::inversive_congruential<boost_kahypar::int64_t, 15707262,
    13262967, (1<<24)-17, 0> NLG_Inv2;
  typedef boost_kahypar::random::inversive_congruential<boost_kahypar::int32_t, 1, 1,
    2147483647, 0> NLG_Inv4;
  typedef boost_kahypar::random::inversive_congruential<boost_kahypar::int32_t, 1, 2,
    1<<30, 0> NLG_Inv5;
  typedef boost_kahypar::random::additive_congruential<boost_kahypar::int32_t, 6,
    (1<<30)-35, 0> MRG_Acorn7;
  typedef boost_kahypar::random::lagged_fibonacci_int<boost_kahypar::uint32_t, 607, 273,
    0, 0> MRG_Fib2;
} // namespace Haertel

#endif
