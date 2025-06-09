// Test that yield primitives aren't cancelation points
//
// Copyright 2023 Peter Dimov
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/core/yield_primitives.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>
#include <boost_kahypar/config.hpp>
#include <boost_kahypar/config/pragma_message.hpp>

#if !defined(BOOST_HAS_PTHREADS)

BOOST_PRAGMA_MESSAGE( "Skipping test because BOOST_HAS_PTHREADS is not defined" )
int main() {}

#else

#include <pthread.h>

pthread_mutex_t s_mx = PTHREAD_MUTEX_INITIALIZER;

void* threadfunc( void* )
{
    pthread_mutex_lock( &s_mx );
    pthread_mutex_unlock( &s_mx );

    boost_kahypar::core::sp_thread_pause();
    boost_kahypar::core::sp_thread_yield();
    boost_kahypar::core::sp_thread_sleep();

    return 0;
}

int main()
{
    pthread_mutex_lock( &s_mx );

    pthread_t th;
    pthread_create( &th, 0, threadfunc, 0 );

    pthread_cancel( th );

    pthread_mutex_unlock( &s_mx );

    void* r;
    pthread_join( th, &r );

    BOOST_TEST_EQ( r, (void*)0 );

    return boost_kahypar::report_errors();
}

#endif
