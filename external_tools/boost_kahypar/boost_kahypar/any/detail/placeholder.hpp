// Copyright Antony Polukhin, 2021-2024.
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_ANY_ANYS_DETAIL_PLACEHOLDER_HPP
#define BOOST_ANY_ANYS_DETAIL_PLACEHOLDER_HPP

#include <boost_kahypar/config.hpp>
#ifdef BOOST_HAS_PRAGMA_ONCE
# pragma once
#endif

#include <boost_kahypar/type_index.hpp>

/// @cond
namespace boost_kahypar {
namespace anys {
namespace detail {

class BOOST_SYMBOL_VISIBLE placeholder {
public:
    virtual ~placeholder() {}
    virtual const boost_kahypar::typeindex::type_info& type() const noexcept = 0;
};

} // namespace detail
} // namespace anys
} // namespace boost_kahypar
/// @endcond

#endif  // #ifndef BOOST_ANY_ANYS_DETAIL_PLACEHOLDER_HPP
