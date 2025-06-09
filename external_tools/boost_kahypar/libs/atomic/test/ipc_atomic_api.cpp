//  Copyright (c) 2020 Andrey Semashev
//
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#include <boost_kahypar/atomic/ipc_atomic.hpp>
#include <boost_kahypar/atomic/ipc_atomic_flag.hpp>
#include <boost_kahypar/atomic/capabilities.hpp>

#include <boost_kahypar/config.hpp>
#include <boost_kahypar/cstdint.hpp>

#include "atomic_wrapper.hpp"
#include "api_test_helpers.hpp"

int main(int, char *[])
{
#if BOOST_ATOMIC_FLAG_LOCK_FREE == 2
    test_flag_api< boost_kahypar::ipc_atomic_flag >();
#endif

    test_lock_free_integral_api< ipc_atomic_wrapper, boost_kahypar::uint8_t >();
    test_lock_free_integral_api< ipc_atomic_wrapper, boost_kahypar::int8_t >();

    test_lock_free_integral_api< ipc_atomic_wrapper, boost_kahypar::uint16_t >();
    test_lock_free_integral_api< ipc_atomic_wrapper, boost_kahypar::int16_t >();

    test_lock_free_integral_api< ipc_atomic_wrapper, boost_kahypar::uint32_t >();
    test_lock_free_integral_api< ipc_atomic_wrapper, boost_kahypar::int32_t >();

    test_lock_free_integral_api< ipc_atomic_wrapper, boost_kahypar::uint64_t >();
    test_lock_free_integral_api< ipc_atomic_wrapper, boost_kahypar::int64_t >();

#if defined(BOOST_HAS_INT128) && !defined(BOOST_ATOMIC_TESTS_NO_INT128)
    test_lock_free_integral_api< ipc_atomic_wrapper, boost_kahypar::int128_type >();
    test_lock_free_integral_api< ipc_atomic_wrapper, boost_kahypar::uint128_type >();
#endif

#if !defined(BOOST_ATOMIC_NO_FLOATING_POINT)
    test_lock_free_floating_point_api< ipc_atomic_wrapper, float >();
    test_lock_free_floating_point_api< ipc_atomic_wrapper, double >();
    test_lock_free_floating_point_api< ipc_atomic_wrapper, long double >();
#if defined(BOOST_HAS_FLOAT128) && !defined(BOOST_ATOMIC_TESTS_NO_FLOAT128)
    test_lock_free_floating_point_api< ipc_atomic_wrapper, boost_kahypar::float128_type >();
#endif
#endif

    test_lock_free_pointer_api< ipc_atomic_wrapper, int >();

    test_lock_free_enum_api< ipc_atomic_wrapper >();

    return boost_kahypar::report_errors();
}
