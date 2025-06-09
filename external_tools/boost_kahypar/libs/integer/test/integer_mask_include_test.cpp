//  Copyright John Maddock 2009.  
//  Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt)

#include <boost_kahypar/integer/integer_mask.hpp> // must be the only #include!

int main()
{
   boost_kahypar::high_bit_mask_t<20>::least l = boost_kahypar::high_bit_mask_t<20>::high_bit;
   boost_kahypar::high_bit_mask_t<12>::fast f = boost_kahypar::high_bit_mask_t<12>::high_bit_fast;
   l += f + boost_kahypar::high_bit_mask_t<12>::bit_position;
   (void)l;
   boost_kahypar::low_bits_mask_t<20>::least l2 = boost_kahypar::low_bits_mask_t<20>::sig_bits;
   boost_kahypar::low_bits_mask_t<12>::fast f2 = boost_kahypar::low_bits_mask_t<12>::sig_bits_fast;
   l2 += f2 + boost_kahypar::low_bits_mask_t<12>::bit_count;
   (void)l2;
}
