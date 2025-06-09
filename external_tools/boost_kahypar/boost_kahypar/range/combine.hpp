//  Copyright Neil Groves 2010. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
#ifndef BOOST_RANGE_COMBINE_HPP
#define BOOST_RANGE_COMBINE_HPP

#include <boost_kahypar/config.hpp>
#include <boost_kahypar/range/iterator_range_core.hpp>
#include <boost_kahypar/iterator/zip_iterator.hpp>

namespace boost_kahypar
{
    namespace range
    {

template<typename IterTuple>
class combined_range
        : public iterator_range<zip_iterator<IterTuple> >
{
    typedef iterator_range<zip_iterator<IterTuple> > base;
public:
    combined_range(IterTuple first, IterTuple last)
        : base(first, last)
    {
    }
};

    } // namespace range
} // namespace boost_kahypar

#if defined(BOOST_NO_CXX11_AUTO_DECLARATIONS) || \
    defined(BOOST_NO_CXX11_DECLTYPE) || \
    defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES) || \
    defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
#   include <boost_kahypar/range/detail/combine_cxx03.hpp>
#else
#   include <boost_kahypar/range/detail/combine_cxx11.hpp>
#endif

#endif
