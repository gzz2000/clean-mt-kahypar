// Copyright 2017 Peter Dimov.
//
// Distributed under the Boost Software License, Version 1.0.
//
// Check that using Chrono and Timer in the same program does
//   not cause link errors.


#include <boost_kahypar/chrono.hpp>
#include <boost_kahypar/timer/timer.hpp>

int main()
{
    boost_kahypar::chrono::steady_clock::now();
    boost_kahypar::timer::cpu_timer cpt;
}
