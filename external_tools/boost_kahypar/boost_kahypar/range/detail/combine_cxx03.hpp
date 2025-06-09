// Boost.Range library
//
//  Copyright Neil Groves 2014. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//
#ifndef BOOST_RANGE_DETAIL_COMBINE_CXX03_HPP
#define BOOST_RANGE_DETAIL_COMBINE_CXX03_HPP

#ifndef BOOST_RANGE_MIN_COMBINE_ARGS
#define BOOST_RANGE_MIN_COMBINE_ARGS 2
#endif

#ifndef BOOST_RANGE_MAX_COMBINE_ARGS
#define BOOST_RANGE_MAX_COMBINE_ARGS 5
#endif

#include <boost_kahypar/config.hpp>
#include <boost_kahypar/iterator/zip_iterator.hpp>
#include <boost_kahypar/preprocessor/arithmetic/dec.hpp>
#include <boost_kahypar/preprocessor/arithmetic/div.hpp>
#include <boost_kahypar/preprocessor/arithmetic/mul.hpp>
#include <boost_kahypar/preprocessor/control/if.hpp>
#include <boost_kahypar/preprocessor/control/while.hpp>
#include <boost_kahypar/preprocessor/facilities/empty.hpp>
#include <boost_kahypar/preprocessor/facilities/identity.hpp>
#include <boost_kahypar/preprocessor/iteration/local.hpp>
#include <boost_kahypar/preprocessor/repetition/enum.hpp>
#include <boost_kahypar/preprocessor/repetition/enum_params.hpp>
#include <boost_kahypar/preprocessor/repetition/repeat.hpp>
#include <boost_kahypar/preprocessor/tuple/elem.hpp>
#include <boost_kahypar/range/iterator_range_core.hpp>
#include <boost_kahypar/type_traits/remove_reference.hpp>

namespace boost_kahypar
{

namespace range
{

#define BOOST_RANGE_combined_seq(z, n, data) boost_kahypar::data(BOOST_PP_CAT(r,n))

#ifdef BOOST_NO_CXX11_RVALUE_REFERENCES

#include <boost_kahypar/range/detail/combine_no_rvalue.hpp>

#else // by using rvalue references we avoid requiring 2^n overloads.

#include <boost_kahypar/range/detail/combine_rvalue.hpp>

#endif

#define BOOST_PP_LOCAL_MACRO(n) BOOST_RANGE_combine(~,n,~)
#define BOOST_PP_LOCAL_LIMITS (BOOST_RANGE_MIN_COMBINE_ARGS, \
                               BOOST_RANGE_MAX_COMBINE_ARGS)
#include BOOST_PP_LOCAL_ITERATE()

    } // namespace range

    using boost_kahypar::range::combine;

} // namespace boost_kahypar

#endif // include guard

#undef BOOST_RANGE_combined_seq
#undef BOOST_RANGE_combined_exp_pred
#undef BOOST_RANGE_combined_exp_op
#undef BOOST_RANGE_combined_exp
#undef BOOST_RANGE_combined_bitset_pred
#undef BOOST_RANGE_combined_bitset_op
#undef BOOST_RANGE_combined_bitset
#undef BOOST_RANGE_combined_range_iterator
#undef BOOST_RANGE_combined_args
#undef BOOST_RANGE_combine_impl
#undef BOOST_RANGE_combine
