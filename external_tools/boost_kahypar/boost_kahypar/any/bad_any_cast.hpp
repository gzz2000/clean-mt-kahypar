// Copyright Antony Polukhin, 2020-2024.
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// See http://www.boost.org/libs/any for Documentation.

#ifndef BOOST_ANYS_BAD_ANY_CAST_HPP_INCLUDED
#define BOOST_ANYS_BAD_ANY_CAST_HPP_INCLUDED

#include <boost_kahypar/config.hpp>
#ifdef BOOST_HAS_PRAGMA_ONCE
#   pragma once
#endif

#ifndef BOOST_NO_RTTI
#include <typeinfo>
#endif

#include <stdexcept>

namespace boost_kahypar {

/// The exception thrown in the event of a failed boost_kahypar::any_cast of
/// an boost_kahypar::any, boost_kahypar::anys::basic_any or boost_kahypar::anys::unique_any value.
class BOOST_SYMBOL_VISIBLE bad_any_cast :
#ifndef BOOST_NO_RTTI
    public std::bad_cast
#else
    public std::exception
#endif
{
public:
    const char * what() const BOOST_NOEXCEPT_OR_NOTHROW override
    {
        return "boost_kahypar::bad_any_cast: "
               "failed conversion using boost_kahypar::any_cast";
    }
};

} // namespace boost_kahypar


#endif // #ifndef BOOST_ANYS_BAD_ANY_CAST_HPP_INCLUDED
