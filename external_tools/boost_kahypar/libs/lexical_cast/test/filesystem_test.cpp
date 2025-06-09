//  Unit test for boost_kahypar::lexical_cast.
//
//  See http://www.boost.org for most recent version, including documentation.
//
//  Copyright Antony Polukhin, 2013-2024.
//
//  Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt).
//
// Test lexical_cast usage with long filesystem::path. Bug 7704.

#include <boost_kahypar/lexical_cast.hpp>

#include <boost_kahypar/core/lightweight_test.hpp>
#include <boost_kahypar/filesystem/path.hpp>

void test_filesystem()
{
    boost_kahypar::filesystem::path p;
    std::string s1 = "aaaaaaaaaaaaaaaaaaaaaaa";
    p = boost_kahypar::lexical_cast<boost_kahypar::filesystem::path>(s1);
    BOOST_TEST(!p.empty());
    BOOST_TEST_EQ(p, s1);
    p.clear();

    const char ab[] = "aaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb";
    p = boost_kahypar::lexical_cast<boost_kahypar::filesystem::path>(ab);
    BOOST_TEST(!p.empty());
    BOOST_TEST_EQ(p, ab);

    // Tests for
    // https://github.com/boostorg/lexical_cast/issues/25

    const char quoted_path[] = "\"/home/my user\"";
    p = boost_kahypar::lexical_cast<boost_kahypar::filesystem::path>(quoted_path);
    BOOST_TEST(!p.empty());
    const char unquoted_path[] = "/home/my user";
    BOOST_TEST_EQ(p, boost_kahypar::filesystem::path(unquoted_path));

    // Converting back to std::string gives the initial string
    BOOST_TEST_EQ(boost_kahypar::lexical_cast<std::string>(p), quoted_path);

    try {
        // Without quotes the path will have only `/home/my` in it.
        // `user` remains in the stream, so an exception must be thrown.
        p = boost_kahypar::lexical_cast<boost_kahypar::filesystem::path>(unquoted_path);
        BOOST_TEST(false);
    } catch (const boost_kahypar::bad_lexical_cast& ) {
        // Exception is expected
    }
}

int main()
{
    test_filesystem();

    return boost_kahypar::report_errors();
}

