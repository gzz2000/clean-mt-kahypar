// Copyright 2023 Peter Dimov
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/function.hpp>
#include <boost_kahypar/bind/bind.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>

using namespace boost_kahypar::placeholders;

int f1() { return 1; }
int f2() { return 2; }

int main()
{
    {
        boost_kahypar::function<int()> fn( boost_kahypar::bind( f1 ) );

        BOOST_TEST( fn == boost_kahypar::bind( f1 ) );
        BOOST_TEST( fn != boost_kahypar::bind( f2 ) );
    }

    {
        boost_kahypar::function<int(int)> fn( boost_kahypar::bind( f1 ) );

        BOOST_TEST( fn == boost_kahypar::bind( f1 ) );
        BOOST_TEST( fn != boost_kahypar::bind( f2 ) );
    }

    {
        boost_kahypar::function<int(int, int)> fn( boost_kahypar::bind( f1 ) );

        BOOST_TEST( fn == boost_kahypar::bind( f1 ) );
        BOOST_TEST( fn != boost_kahypar::bind( f2 ) );
    }

    {
        boost_kahypar::function<int(int, int, int)> fn( boost_kahypar::bind( f1 ) );

        BOOST_TEST( fn == boost_kahypar::bind( f1 ) );
        BOOST_TEST( fn != boost_kahypar::bind( f2 ) );
    }

    {
        boost_kahypar::function<int(int, int, int, int)> fn( boost_kahypar::bind( f1 ) );

        BOOST_TEST( fn == boost_kahypar::bind( f1 ) );
        BOOST_TEST( fn != boost_kahypar::bind( f2 ) );
    }

    {
        boost_kahypar::function<int(int, int, int, int, int)> fn( boost_kahypar::bind( f1 ) );

        BOOST_TEST( fn == boost_kahypar::bind( f1 ) );
        BOOST_TEST( fn != boost_kahypar::bind( f2 ) );
    }

    {
        boost_kahypar::function<int(int, int, int, int, int, int)> fn( boost_kahypar::bind( f1 ) );

        BOOST_TEST( fn == boost_kahypar::bind( f1 ) );
        BOOST_TEST( fn != boost_kahypar::bind( f2 ) );
    }

    {
        boost_kahypar::function<int(int, int, int, int, int, int, int)> fn( boost_kahypar::bind( f1 ) );

        BOOST_TEST( fn == boost_kahypar::bind( f1 ) );
        BOOST_TEST( fn != boost_kahypar::bind( f2 ) );
    }

    {
        boost_kahypar::function<int(int, int, int, int, int, int, int, int)> fn( boost_kahypar::bind( f1 ) );

        BOOST_TEST( fn == boost_kahypar::bind( f1 ) );
        BOOST_TEST( fn != boost_kahypar::bind( f2 ) );
    }

    {
        boost_kahypar::function<int(int, int, int, int, int, int, int, int, int)> fn( boost_kahypar::bind( f1 ) );

        BOOST_TEST( fn == boost_kahypar::bind( f1 ) );
        BOOST_TEST( fn != boost_kahypar::bind( f2 ) );
    }

    return boost_kahypar::report_errors();
}
