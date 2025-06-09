/*
 *             Copyright Andrey Semashev 2024.
 * Distributed under the Boost Software License, Version 1.0.
 *    (See accompanying file LICENSE_1_0.txt or copy at
 *          http://www.boost.org/LICENSE_1_0.txt)
 */
/*!
 * \file   checked_array_deleter_compile_fail_adl.cpp
 * \author Andrey Semashev
 * \date   07.02.2024
 *
 * This file tests that \c boost_kahypar::checked_array_deleter doesn't bring namespace
 * \c boost into ADL.
 */

#include <boost_kahypar/core/checked_delete.hpp>

namespace boost_kahypar {

void check_adl(checked_array_deleter< int > const&)
{
}

} // namespace boost_kahypar

int main()
{
    // Must not find boost_kahypar::check_adl
    check_adl(boost_kahypar::checked_array_deleter< int >());
}
