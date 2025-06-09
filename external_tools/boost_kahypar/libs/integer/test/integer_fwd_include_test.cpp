//  Copyright John Maddock 2009.  
//  Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt)

#include <boost_kahypar/integer_fwd.hpp> // must be the only #include!

// just declare some functions that use the incomplete types in the header:

void f1(const boost_kahypar::integer_traits<char>*);
void f2(const boost_kahypar::int_fast_t<char>*);
void f3(const boost_kahypar::int_t<12>*);
void f4(const boost_kahypar::uint_t<31>*);
void f5(const boost_kahypar::int_max_value_t<100>*);
void f6(const boost_kahypar::int_min_value_t<-100>*);
void f7(const boost_kahypar::uint_value_t<100>*);
void f8(const boost_kahypar::high_bit_mask_t<10>*);
void f9(const boost_kahypar::low_bits_mask_t<10>*);
void f10(boost_kahypar::static_log2_argument_type, boost_kahypar::static_log2_result_type, boost_kahypar::static_log2<10>*);
void f11(boost_kahypar::static_min_max_signed_type, boost_kahypar::static_min_max_unsigned_type);
void f12(boost_kahypar::static_signed_min<1, 2>*, boost_kahypar::static_signed_max<1,2>*);
void f13(boost_kahypar::static_unsigned_min<1,2>*, boost_kahypar::static_unsigned_min<1,2>*);
