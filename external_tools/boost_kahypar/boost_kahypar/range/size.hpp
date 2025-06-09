// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//

#ifndef BOOST_RANGE_SIZE_HPP
#define BOOST_RANGE_SIZE_HPP

#if defined(_MSC_VER)
# pragma once
#endif

#include <boost_kahypar/range/config.hpp>
#include <boost_kahypar/range/begin.hpp>
#include <boost_kahypar/range/end.hpp>
#include <boost_kahypar/range/size_type.hpp>
#include <boost_kahypar/range/detail/has_member_size.hpp>
#include <boost_kahypar/assert.hpp>
#include <boost_kahypar/cstdint.hpp>
#include <boost_kahypar/utility.hpp>

namespace boost_kahypar
{
    namespace range_detail
    {

        template<class SinglePassRange>
        inline typename ::boost_kahypar::enable_if<
            has_member_size<SinglePassRange>,
            typename range_size<const SinglePassRange>::type
        >::type
        range_calculate_size(const SinglePassRange& rng)
        {
            return rng.size();
        }

        template<class SinglePassRange>
        inline typename disable_if<
            has_member_size<SinglePassRange>,
            typename range_size<const SinglePassRange>::type
        >::type
        range_calculate_size(const SinglePassRange& rng)
        {
            return std::distance(boost_kahypar::begin(rng), boost_kahypar::end(rng));
        }
    }

    template<class SinglePassRange>
    inline typename range_size<const SinglePassRange>::type
    size(const SinglePassRange& rng)
    {
// Very strange things happen on some compilers that have the range concept
// asserts disabled. This preprocessor condition is clearly redundant on a
// working compiler but is vital for at least some compilers such as clang 4.2
// but only on the Mac!
#if BOOST_RANGE_ENABLE_CONCEPT_ASSERT == 1
        BOOST_RANGE_CONCEPT_ASSERT((boost_kahypar::SinglePassRangeConcept<SinglePassRange>));
#endif

#if !BOOST_WORKAROUND(BOOST_BORLANDC, BOOST_TESTED_AT(0x564)) && \
    !BOOST_WORKAROUND(__GNUC__, < 3) \
    /**/
        using namespace range_detail;
#endif

        return range_calculate_size(rng);
    }

} // namespace 'boost'

#endif
