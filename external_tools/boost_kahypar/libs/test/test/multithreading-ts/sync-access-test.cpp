//  (C) Copyright Gennadiy Rozental 2008-2015.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/libs/test for the library home page.
//
//  File        : $RCSfile$
//
//  Version     : $Revision$
//
//  Description : tests Unit Test Framework usability in MT environment with
//                Boost.Test calls externally synchronized
// ***************************************************************************

#define BOOST_TEST_MODULE sync_access_test
#include <boost_kahypar/test/unit_test.hpp>

#include <boost_kahypar/thread.hpp>
#include <boost_kahypar/thread/barrier.hpp>
#include <boost_kahypar/bind/bind.hpp>
#include <boost_kahypar/ref.hpp>

using namespace boost_kahypar;
namespace ut = boost_kahypar::unit_test;

static boost_kahypar::mutex m;

/// thread execution function
static void thread_function(boost_kahypar::barrier& b)
{
    b.wait(); /// wait until memory barrier allows the execution
    boost_kahypar::mutex::scoped_lock lock(m); /// lock mutex
    BOOST_TEST(1 ==0 ); /// produce the fault
}

#if BOOST_PP_VARIADICS
/// test function which creates threads
BOOST_AUTO_TEST_CASE( test_multiple_assertion_faults, * ut::expected_failures(100))
#else
BOOST_TEST_DECORATOR(
  * ut::expected_failures(100)
)
BOOST_AUTO_TEST_CASE( test_multiple_assertion_faults)
#endif
{
    boost_kahypar::thread_group tg;      // thread group to manage all threads
    boost_kahypar::barrier      b(100);  // memory barrier, which should block all threads
                                 // until all 100 threads were created

    for(size_t i=0; i<100; ++i)
        tg.create_thread(boost_kahypar::bind(thread_function, ref(b))); /// create a thread and pass it the barrier

    tg.join_all();
}

// EOF
