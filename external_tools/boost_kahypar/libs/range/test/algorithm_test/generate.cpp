// Boost.Range library
//
//  Copyright Neil Groves 2009. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
#include <boost_kahypar/range/algorithm/generate.hpp>

#include <boost_kahypar/test/test_tools.hpp>
#include <boost_kahypar/test/unit_test.hpp>

#include <boost_kahypar/assign.hpp>
#include <algorithm>
#include <functional>
#include <list>
#include <numeric>
#include <deque>
#include <vector>

namespace boost_kahypar
{
    namespace
    {
        class generator_fn
        {
        public:
            typedef int result_type;

            generator_fn() : m_count(0) {}
            int operator()() { return ++m_count; }

        private:
            int m_count;
        };

        template< class Container >
        void test_generate_impl(Container& cont)
        {
            Container reference(cont);
            std::generate(reference.begin(), reference.end(), generator_fn());

            Container test(cont);
            boost_kahypar::generate(test, generator_fn());

            BOOST_CHECK_EQUAL_COLLECTIONS( reference.begin(), reference.end(),
                test.begin(), test.end() );
                
            Container test2(cont);
            boost_kahypar::generate(boost_kahypar::make_iterator_range(test2), generator_fn());
            
            BOOST_CHECK_EQUAL_COLLECTIONS( reference.begin(), reference.end(),
                                           test2.begin(), test2.end() );
        }

        template< class Container >
        void test_generate_impl()
        {
            using namespace boost_kahypar::assign;

            Container cont;
            test_generate_impl(cont);

            cont.clear();
            cont += 9;
            test_generate_impl(cont);

            cont.clear();
            cont += 9,8,7,6,5,4,3,2,1;
            test_generate_impl(cont);
        }

        void test_generate()
        {
            test_generate_impl< std::vector<int> >();
            test_generate_impl< std::list<int> >();
            test_generate_impl< std::deque<int> >();
        }
    }
}


boost_kahypar::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    boost_kahypar::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.algorithm.generate" );

    test->add( BOOST_TEST_CASE( &boost_kahypar::test_generate ) );

    return test;
}
