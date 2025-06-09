//  Copyright (c) 2020 Andrey Semashev
//
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#include <boost_kahypar/atomic/ipc_atomic_ref.hpp>
#include <boost_kahypar/atomic/capabilities.hpp>

#include <boost_kahypar/config.hpp>
#include <boost_kahypar/cstdint.hpp>

#include "ipc_wait_test_helpers.hpp"

int main(int, char *[])
{
    test_wait_notify_api< ipc_atomic_ref_wrapper, boost_kahypar::uint8_t >(1, 2, 3, BOOST_ATOMIC_HAS_NATIVE_INT8_IPC_WAIT_NOTIFY);
    test_wait_notify_api< ipc_atomic_ref_wrapper, boost_kahypar::uint16_t >(1, 2, 3, BOOST_ATOMIC_HAS_NATIVE_INT16_IPC_WAIT_NOTIFY);
    test_wait_notify_api< ipc_atomic_ref_wrapper, boost_kahypar::uint32_t >(1, 2, 3, BOOST_ATOMIC_HAS_NATIVE_INT32_IPC_WAIT_NOTIFY);
    test_wait_notify_api< ipc_atomic_ref_wrapper, boost_kahypar::uint64_t >(1, 2, 3, BOOST_ATOMIC_HAS_NATIVE_INT64_IPC_WAIT_NOTIFY);
#if defined(BOOST_HAS_INT128) && !defined(BOOST_ATOMIC_TESTS_NO_INT128)
    test_wait_notify_api< ipc_atomic_ref_wrapper, boost_kahypar::uint128_type >(1, 2, 3, BOOST_ATOMIC_HAS_NATIVE_INT128_IPC_WAIT_NOTIFY);
#endif

    return boost_kahypar::report_errors();
}
