//
// Copyright 2013-2024 Antony Polukhin.
//
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_TYPE_INDEX_CTTI_REGISTER_CLASS_HPP
#define BOOST_TYPE_INDEX_CTTI_REGISTER_CLASS_HPP

/// \file ctti_register_class.hpp
/// \brief Contains BOOST_TYPE_INDEX_REGISTER_CLASS macro implementation that uses boost_kahypar::typeindex::ctti_type_index.
/// Not intended for inclusion from user's code.

#include <boost_kahypar/type_index/ctti_type_index.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
# pragma once
#endif

namespace boost_kahypar { namespace typeindex { namespace detail {

template <class T>
inline const ctti_data& ctti_construct_typeid_ref(const T*) noexcept {
    return boost_kahypar::typeindex::ctti_construct<T>();
}

}}} // namespace boost_kahypar::typeindex::detail

/// @cond
#define BOOST_TYPE_INDEX_REGISTER_CLASS                                                                       \
    virtual const boost_kahypar::typeindex::detail::ctti_data& boost_type_index_type_id_runtime_() const noexcept {   \
        return boost_kahypar::typeindex::detail::ctti_construct_typeid_ref(this);                                     \
    }                                                                                                         \
/**/
/// @endcond

#endif // BOOST_TYPE_INDEX_CTTI_REGISTER_CLASS_HPP

