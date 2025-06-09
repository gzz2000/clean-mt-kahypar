// Boost.Range library
//
//  Copyright Neil Groves 2010. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
#include <boost_kahypar/range/istream_range.hpp>
#include <boost_kahypar/range/algorithm_ext.hpp>
#include <boost_kahypar/range/begin.hpp>
#include <boost_kahypar/range/end.hpp>
#include <boost_kahypar/test/test_tools.hpp>
#include <boost_kahypar/test/unit_test.hpp>
#include <sstream>
#include <vector>

namespace
{
    template <typename CharT>
    void test_istream_range_impl()
    {
        std::basic_stringstream<CharT> s;
        std::vector<int> reference;
        for (int i = 0; i < 10; ++i)
        {
            reference.push_back(i);
            s << i << CharT(' ');
        }

        std::vector<int> target;
        boost_kahypar::push_back(target, boost_kahypar::range::istream_range<int>(s));

        BOOST_CHECK_EQUAL_COLLECTIONS( reference.begin(), reference.end(),
            target.begin(), target.end() );
    }
    
    // Test an istream range.
    void test_istream_range()
    {
        test_istream_range_impl<char>();
        test_istream_range_impl<wchar_t>();
    }

} // namespace anonymous namespace

boost_kahypar::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    boost_kahypar::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.istream_range" );

    test->add(BOOST_TEST_CASE( &test_istream_range ));

    return test;
}
