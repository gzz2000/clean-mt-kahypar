//  Copyright (c) 2020-2021 Andrey Semashev
//
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#include <boost_kahypar/atomic/ipc_atomic_ref.hpp>
#include <boost_kahypar/memory_order.hpp>

#include <boost_kahypar/config.hpp>
#include <boost_kahypar/cstdint.hpp>

#include "aligned_object.hpp"
#include "atomic_wrapper.hpp"
#include "api_test_helpers.hpp"

int main(int, char *[])
{
    test_lock_free_integral_api< ipc_atomic_ref_wrapper, boost_kahypar::uint8_t >();
    test_lock_free_integral_api< ipc_atomic_ref_wrapper, boost_kahypar::int8_t >();

    test_lock_free_integral_api< ipc_atomic_ref_wrapper, boost_kahypar::uint16_t >();
    test_lock_free_integral_api< ipc_atomic_ref_wrapper, boost_kahypar::int16_t >();

    test_lock_free_integral_api< ipc_atomic_ref_wrapper, boost_kahypar::uint32_t >();
    test_lock_free_integral_api< ipc_atomic_ref_wrapper, boost_kahypar::int32_t >();

    test_lock_free_integral_api< ipc_atomic_ref_wrapper, boost_kahypar::uint64_t >();
    test_lock_free_integral_api< ipc_atomic_ref_wrapper, boost_kahypar::int64_t >();

#if defined(BOOST_HAS_INT128) && !defined(BOOST_ATOMIC_TESTS_NO_INT128)
    test_lock_free_integral_api< ipc_atomic_ref_wrapper, boost_kahypar::int128_type >();
    test_lock_free_integral_api< ipc_atomic_ref_wrapper, boost_kahypar::uint128_type >();
#endif

#if !defined(BOOST_ATOMIC_NO_FLOATING_POINT)
    test_lock_free_floating_point_api< ipc_atomic_ref_wrapper, float >();
    test_lock_free_floating_point_api< ipc_atomic_ref_wrapper, double >();
    test_lock_free_floating_point_api< ipc_atomic_ref_wrapper, long double >();
#if defined(BOOST_HAS_FLOAT128) && !defined(BOOST_ATOMIC_TESTS_NO_FLOAT128)
    test_lock_free_floating_point_api< ipc_atomic_ref_wrapper, boost_kahypar::float128_type >();
#endif
#endif

    test_lock_free_pointer_api< ipc_atomic_ref_wrapper, int >();

    test_lock_free_enum_api< ipc_atomic_ref_wrapper >();

#if !defined(BOOST_NO_CXX17_DEDUCTION_GUIDES)
    if (boost_kahypar::ipc_atomic_ref< int >::is_always_lock_free)
    {
        aligned_object< int, boost_kahypar::ipc_atomic_ref< int >::required_alignment > object(0);
        boost_kahypar::ipc_atomic_ref r(object.get());
        r.store(1, boost_kahypar::memory_order_relaxed);
    }
#endif
    if (boost_kahypar::ipc_atomic_ref< int >::is_always_lock_free)
    {
        aligned_object< int, boost_kahypar::ipc_atomic_ref< int >::required_alignment > object(0);
        boost_kahypar::ipc_atomic_ref< int > r = boost_kahypar::make_ipc_atomic_ref(object.get());
        r.store(1, boost_kahypar::memory_order_relaxed);
    }

    return boost_kahypar::report_errors();
}
