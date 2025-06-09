//  atomic.hpp  ------------------------------------------------------------------------//

//  Copyright 2021 Andrey Semashev

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

//  See library home page at http://www.boost.org/libs/filesystem

//--------------------------------------------------------------------------------------//

#ifndef BOOST_FILESYSTEM_SRC_ATOMIC_REF_HPP_
#define BOOST_FILESYSTEM_SRC_ATOMIC_REF_HPP_

#include <boost_kahypar/filesystem/config.hpp>

#if !defined(BOOST_FILESYSTEM_NO_CXX20_ATOMIC_REF)

#include <atomic>

namespace atomic_ns = std;

#else // !defined(BOOST_FILESYSTEM_NO_CXX20_ATOMIC_REF)

#include <boost_kahypar/memory_order.hpp>
#include <boost_kahypar/atomic/atomic_ref.hpp>

namespace atomic_ns = boost_kahypar;

#endif // !defined(BOOST_FILESYSTEM_NO_CXX20_ATOMIC_REF)

#endif // BOOST_FILESYSTEM_SRC_ATOMIC_REF_HPP_
