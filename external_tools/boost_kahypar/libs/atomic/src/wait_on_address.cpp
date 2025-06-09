/*
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * Copyright (c) 2020 Andrey Semashev
 */
/*!
 * \file   wait_on_address.cpp
 *
 * This file contains implementation of runtime detection of \c WaitOnAddress and related APIs on Windows.
 *
 * https://docs.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-waitonaddress
 * https://docs.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-wakebyaddresssingle
 * https://docs.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-wakebyaddressall
 */

// Include boost/winapi/config.hpp first to make sure target Windows version is selected by Boost.WinAPI
#include <boost_kahypar/winapi/config.hpp>

#include <boost_kahypar/winapi/basic_types.hpp>

#include <boost_kahypar/atomic/detail/config.hpp>
#include <boost_kahypar/atomic/detail/link.hpp>
#include <boost_kahypar/atomic/detail/once_flag.hpp>
#include <boost_kahypar/atomic/detail/wait_on_address.hpp>

#if BOOST_WINAPI_PARTITION_DESKTOP || BOOST_WINAPI_PARTITION_SYSTEM

#include <boost_kahypar/memory_order.hpp>
#include <boost_kahypar/winapi/thread.hpp>
#include <boost_kahypar/winapi/get_proc_address.hpp>
#include <boost_kahypar/winapi/dll.hpp>

#include <boost_kahypar/atomic/detail/core_operations.hpp>

#endif // BOOST_WINAPI_PARTITION_DESKTOP || BOOST_WINAPI_PARTITION_SYSTEM

#include <boost_kahypar/atomic/detail/header.hpp>

namespace boost_kahypar {
namespace atomics {
namespace detail {

BOOST_ATOMIC_DECL wait_on_address_t* wait_on_address = NULL;
BOOST_ATOMIC_DECL wake_by_address_t* wake_by_address_single = NULL;
BOOST_ATOMIC_DECL wake_by_address_t* wake_by_address_all = NULL;

#if BOOST_WINAPI_PARTITION_DESKTOP || BOOST_WINAPI_PARTITION_SYSTEM

BOOST_ATOMIC_DECL once_flag wait_functions_once_flag = { 2u };

BOOST_ATOMIC_DECL void initialize_wait_functions() BOOST_NOEXCEPT
{
    static_assert(once_flag_operations::is_always_lock_free, "Boost.Atomic unsupported target platform: native atomic operations not implemented for bytes");

    once_flag_operations::storage_type old_val = once_flag_operations::load(wait_functions_once_flag.m_flag, boost_kahypar::memory_order_acquire);
    while (true)
    {
        if (old_val == 2u)
        {
            if (BOOST_UNLIKELY(!once_flag_operations::compare_exchange_strong(wait_functions_once_flag.m_flag, old_val, 1u, boost_kahypar::memory_order_relaxed, boost_kahypar::memory_order_relaxed)))
                continue;

            boost_kahypar::winapi::HMODULE_ kernel_base = boost_kahypar::winapi::get_module_handle(L"api-ms-win-core-synch-l1-2-0.dll");
            if (BOOST_LIKELY(kernel_base != NULL))
            {
                wait_on_address_t* woa = (wait_on_address_t*)boost_kahypar::winapi::get_proc_address(kernel_base, "WaitOnAddress");
                if (BOOST_LIKELY(woa != NULL))
                {
                    wake_by_address_t* wbas = (wake_by_address_t*)boost_kahypar::winapi::get_proc_address(kernel_base, "WakeByAddressSingle");
                    wake_by_address_t* wbaa = (wake_by_address_t*)boost_kahypar::winapi::get_proc_address(kernel_base, "WakeByAddressAll");

                    if (BOOST_LIKELY(wbas != NULL && wbaa != NULL))
                    {
                        wait_on_address = woa;
                        wake_by_address_single = wbas;
                        wake_by_address_all = wbaa;
                    }
                }
            }

            once_flag_operations::store(wait_functions_once_flag.m_flag, 0u, boost_kahypar::memory_order_release);
            break;
        }
        else if (old_val == 1u)
        {
            boost_kahypar::winapi::SwitchToThread();
            old_val = once_flag_operations::load(wait_functions_once_flag.m_flag, boost_kahypar::memory_order_acquire);
        }
        else
        {
            break;
        }
    }
}

#else // BOOST_WINAPI_PARTITION_DESKTOP || BOOST_WINAPI_PARTITION_SYSTEM

BOOST_ATOMIC_DECL once_flag wait_functions_once_flag = { 0u };

BOOST_ATOMIC_DECL void initialize_wait_functions() BOOST_NOEXCEPT
{
}

#endif // BOOST_WINAPI_PARTITION_DESKTOP || BOOST_WINAPI_PARTITION_SYSTEM

} // namespace detail
} // namespace atomics
} // namespace boost_kahypar

#include <boost_kahypar/atomic/detail/footer.hpp>
