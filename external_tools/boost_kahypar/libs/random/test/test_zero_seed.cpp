/*
	Test case for ticket #7951
	tests whether or not xxx() == xxx(0) for various engines
	Thanks to Stephen T. Lavavej for his close reading of 26.5.3.3 [rand.eng.sub]/7 
*/

#include <boost_kahypar/random/ranlux.hpp>
#include <boost_kahypar/random/linear_congruential.hpp>
#include <boost_kahypar/random/mersenne_twister.hpp>

#define BOOST_TEST_MAIN
#include <boost_kahypar/test/unit_test.hpp>

#ifdef BOOST_MSVC
#pragma warning(push)
#pragma warning(disable:4244)
#endif

BOOST_AUTO_TEST_CASE(test_zero_seed)
{
    BOOST_CHECK(boost_kahypar::random::ranlux24_base(0) == boost_kahypar::random::ranlux24_base()); 
    BOOST_CHECK(boost_kahypar::random::minstd_rand0(0)  == boost_kahypar::random::minstd_rand0()); 
    BOOST_CHECK(boost_kahypar::random::mt19937(0)       != boost_kahypar::random::mt19937()); 

    BOOST_CHECK(boost_kahypar::random::ranlux48_base(0) == boost_kahypar::random::ranlux48_base ()); 

    BOOST_CHECK(boost_kahypar::random::ranlux_base_01(0) == boost_kahypar::random::ranlux_base_01 ()); 
    BOOST_CHECK(boost_kahypar::random::ranlux64_base_01(0) == boost_kahypar::random::ranlux64_base_01 ()); 
}
