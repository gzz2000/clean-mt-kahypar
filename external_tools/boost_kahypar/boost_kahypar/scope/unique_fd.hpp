/*
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * https://www.boost.org/LICENSE_1_0.txt)
 *
 * Copyright (c) 2023 Andrey Semashev
 */
/*!
 * \file scope/unique_fd.hpp
 *
 * This header contains definition of \c unique_fd type.
 */

#ifndef BOOST_SCOPE_UNIQUE_FD_HPP_INCLUDED_
#define BOOST_SCOPE_UNIQUE_FD_HPP_INCLUDED_

#include <boost_kahypar/scope/detail/config.hpp>
#include <boost_kahypar/scope/unique_resource.hpp>
#include <boost_kahypar/scope/fd_deleter.hpp>
#include <boost_kahypar/scope/fd_resource_traits.hpp>
#include <boost_kahypar/scope/detail/header.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

namespace boost_kahypar {
namespace scope {

//! Unique POSIX-like file descriptor resource
using unique_fd = unique_resource< int, fd_deleter, fd_resource_traits >;

} // namespace scope
} // namespace boost_kahypar

#include <boost_kahypar/scope/detail/footer.hpp>

#endif // BOOST_SCOPE_UNIQUE_FD_HPP_INCLUDED_
