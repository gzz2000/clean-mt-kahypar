#include <boost_kahypar/config.hpp>

//
//  bind_nested_rv_test.cpp
//
//  Copyright (c) 2016 Peter Dimov
//
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//

#include <boost_kahypar/bind/bind.hpp>
#include <boost_kahypar/make_shared.hpp>
#include <boost_kahypar/function.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>

using namespace boost_kahypar::placeholders;

//

bool f1( boost_kahypar::shared_ptr<int> p1 )
{
    BOOST_TEST( p1 != 0 && *p1 == 1 );
    return true;
}

bool f2( boost_kahypar::shared_ptr<int> p1, boost_kahypar::shared_ptr<int> p2 )
{
    BOOST_TEST( p1 != 0 && *p1 == 1 );
    BOOST_TEST( p2 != 0 && *p2 == 2 );
    return true;
}

bool f3( boost_kahypar::shared_ptr<int> p1, boost_kahypar::shared_ptr<int> p2, boost_kahypar::shared_ptr<int> p3 )
{
    BOOST_TEST( p1 != 0 && *p1 == 1 );
    BOOST_TEST( p2 != 0 && *p2 == 2 );
    BOOST_TEST( p3 != 0 && *p3 == 3 );
    return true;
}

bool f4( boost_kahypar::shared_ptr<int> p1, boost_kahypar::shared_ptr<int> p2, boost_kahypar::shared_ptr<int> p3, boost_kahypar::shared_ptr<int> p4 )
{
    BOOST_TEST( p1 != 0 && *p1 == 1 );
    BOOST_TEST( p2 != 0 && *p2 == 2 );
    BOOST_TEST( p3 != 0 && *p3 == 3 );
    BOOST_TEST( p4 != 0 && *p4 == 4 );
    return true;
}

bool f5( boost_kahypar::shared_ptr<int> p1, boost_kahypar::shared_ptr<int> p2, boost_kahypar::shared_ptr<int> p3, boost_kahypar::shared_ptr<int> p4, boost_kahypar::shared_ptr<int> p5 )
{
    BOOST_TEST( p1 != 0 && *p1 == 1 );
    BOOST_TEST( p2 != 0 && *p2 == 2 );
    BOOST_TEST( p3 != 0 && *p3 == 3 );
    BOOST_TEST( p4 != 0 && *p4 == 4 );
    BOOST_TEST( p5 != 0 && *p5 == 5 );
    return true;
}

bool f6( boost_kahypar::shared_ptr<int> p1, boost_kahypar::shared_ptr<int> p2, boost_kahypar::shared_ptr<int> p3, boost_kahypar::shared_ptr<int> p4, boost_kahypar::shared_ptr<int> p5, boost_kahypar::shared_ptr<int> p6 )
{
    BOOST_TEST( p1 != 0 && *p1 == 1 );
    BOOST_TEST( p2 != 0 && *p2 == 2 );
    BOOST_TEST( p3 != 0 && *p3 == 3 );
    BOOST_TEST( p4 != 0 && *p4 == 4 );
    BOOST_TEST( p5 != 0 && *p5 == 5 );
    BOOST_TEST( p6 != 0 && *p6 == 6 );
    return true;
}

bool f7( boost_kahypar::shared_ptr<int> p1, boost_kahypar::shared_ptr<int> p2, boost_kahypar::shared_ptr<int> p3, boost_kahypar::shared_ptr<int> p4, boost_kahypar::shared_ptr<int> p5, boost_kahypar::shared_ptr<int> p6, boost_kahypar::shared_ptr<int> p7 )
{
    BOOST_TEST( p1 != 0 && *p1 == 1 );
    BOOST_TEST( p2 != 0 && *p2 == 2 );
    BOOST_TEST( p3 != 0 && *p3 == 3 );
    BOOST_TEST( p4 != 0 && *p4 == 4 );
    BOOST_TEST( p5 != 0 && *p5 == 5 );
    BOOST_TEST( p6 != 0 && *p6 == 6 );
    BOOST_TEST( p7 != 0 && *p7 == 7 );
    return true;
}

bool f8( boost_kahypar::shared_ptr<int> p1, boost_kahypar::shared_ptr<int> p2, boost_kahypar::shared_ptr<int> p3, boost_kahypar::shared_ptr<int> p4, boost_kahypar::shared_ptr<int> p5, boost_kahypar::shared_ptr<int> p6, boost_kahypar::shared_ptr<int> p7, boost_kahypar::shared_ptr<int> p8 )
{
    BOOST_TEST( p1 != 0 && *p1 == 1 );
    BOOST_TEST( p2 != 0 && *p2 == 2 );
    BOOST_TEST( p3 != 0 && *p3 == 3 );
    BOOST_TEST( p4 != 0 && *p4 == 4 );
    BOOST_TEST( p5 != 0 && *p5 == 5 );
    BOOST_TEST( p6 != 0 && *p6 == 6 );
    BOOST_TEST( p7 != 0 && *p7 == 7 );
    BOOST_TEST( p8 != 0 && *p8 == 8 );
    return true;
}

bool f9( boost_kahypar::shared_ptr<int> p1, boost_kahypar::shared_ptr<int> p2, boost_kahypar::shared_ptr<int> p3, boost_kahypar::shared_ptr<int> p4, boost_kahypar::shared_ptr<int> p5, boost_kahypar::shared_ptr<int> p6, boost_kahypar::shared_ptr<int> p7, boost_kahypar::shared_ptr<int> p8, boost_kahypar::shared_ptr<int> p9 )
{
    BOOST_TEST( p1 != 0 && *p1 == 1 );
    BOOST_TEST( p2 != 0 && *p2 == 2 );
    BOOST_TEST( p3 != 0 && *p3 == 3 );
    BOOST_TEST( p4 != 0 && *p4 == 4 );
    BOOST_TEST( p5 != 0 && *p5 == 5 );
    BOOST_TEST( p6 != 0 && *p6 == 6 );
    BOOST_TEST( p7 != 0 && *p7 == 7 );
    BOOST_TEST( p8 != 0 && *p8 == 8 );
    BOOST_TEST( p9 != 0 && *p9 == 9 );
    return true;
}

void test()
{
    {
        boost_kahypar::function<bool(boost_kahypar::shared_ptr<int>)> f( f1 );

        ( boost_kahypar::bind( f, _1 ) && boost_kahypar::bind( f1, _1 ) )( boost_kahypar::make_shared<int>( 1 ) );
    }

    {
        boost_kahypar::function<bool(boost_kahypar::shared_ptr<int>, boost_kahypar::shared_ptr<int>)> f( f2 );

        ( boost_kahypar::bind( f, _1, _2 ) && boost_kahypar::bind( f2, _1, _2 ) )( boost_kahypar::make_shared<int>( 1 ), boost_kahypar::make_shared<int>( 2 ) );
    }

    {
        boost_kahypar::function<bool(boost_kahypar::shared_ptr<int>, boost_kahypar::shared_ptr<int>, boost_kahypar::shared_ptr<int>)> f( f3 );

        ( boost_kahypar::bind( f, _1, _2, _3 ) && boost_kahypar::bind( f3, _1, _2, _3 ) )( boost_kahypar::make_shared<int>( 1 ), boost_kahypar::make_shared<int>( 2 ), boost_kahypar::make_shared<int>( 3 ) );
    }

    {
        boost_kahypar::function<bool(boost_kahypar::shared_ptr<int>, boost_kahypar::shared_ptr<int>, boost_kahypar::shared_ptr<int>)> f( f3 );

        ( boost_kahypar::bind( f, _1, _2, _3 ) && boost_kahypar::bind( f3, _1, _2, _3 ) )( boost_kahypar::make_shared<int>( 1 ), boost_kahypar::make_shared<int>( 2 ), boost_kahypar::make_shared<int>( 3 ) );
    }

    {
        boost_kahypar::function<bool(boost_kahypar::shared_ptr<int>, boost_kahypar::shared_ptr<int>, boost_kahypar::shared_ptr<int>, boost_kahypar::shared_ptr<int>)> f( f4 );

        ( boost_kahypar::bind( f, _1, _2, _3, _4 ) && boost_kahypar::bind( f4, _1, _2, _3, _4 ) )( boost_kahypar::make_shared<int>( 1 ), boost_kahypar::make_shared<int>( 2 ), boost_kahypar::make_shared<int>( 3 ), boost_kahypar::make_shared<int>( 4 ) );
    }

    {
        boost_kahypar::function<bool(boost_kahypar::shared_ptr<int>, boost_kahypar::shared_ptr<int>, boost_kahypar::shared_ptr<int>, boost_kahypar::shared_ptr<int>, boost_kahypar::shared_ptr<int>)> f( f5 );

        ( boost_kahypar::bind( f, _1, _2, _3, _4, _5 ) && boost_kahypar::bind( f5, _1, _2, _3, _4, _5 ) )( boost_kahypar::make_shared<int>( 1 ), boost_kahypar::make_shared<int>( 2 ), boost_kahypar::make_shared<int>( 3 ), boost_kahypar::make_shared<int>( 4 ), boost_kahypar::make_shared<int>( 5 ) );
    }

    {
        boost_kahypar::function<bool(boost_kahypar::shared_ptr<int>, boost_kahypar::shared_ptr<int>, boost_kahypar::shared_ptr<int>, boost_kahypar::shared_ptr<int>, boost_kahypar::shared_ptr<int>, boost_kahypar::shared_ptr<int>)> f( f6 );

        ( boost_kahypar::bind( f, _1, _2, _3, _4, _5, _6 ) && boost_kahypar::bind( f6, _1, _2, _3, _4, _5, _6 ) )( boost_kahypar::make_shared<int>( 1 ), boost_kahypar::make_shared<int>( 2 ), boost_kahypar::make_shared<int>( 3 ), boost_kahypar::make_shared<int>( 4 ), boost_kahypar::make_shared<int>( 5 ), boost_kahypar::make_shared<int>( 6 ) );
    }

    {
        boost_kahypar::function<bool(boost_kahypar::shared_ptr<int>, boost_kahypar::shared_ptr<int>, boost_kahypar::shared_ptr<int>, boost_kahypar::shared_ptr<int>, boost_kahypar::shared_ptr<int>, boost_kahypar::shared_ptr<int>, boost_kahypar::shared_ptr<int>)> f( f7 );

        ( boost_kahypar::bind( f, _1, _2, _3, _4, _5, _6, _7 ) && boost_kahypar::bind( f7, _1, _2, _3, _4, _5, _6, _7 ) )( boost_kahypar::make_shared<int>( 1 ), boost_kahypar::make_shared<int>( 2 ), boost_kahypar::make_shared<int>( 3 ), boost_kahypar::make_shared<int>( 4 ), boost_kahypar::make_shared<int>( 5 ), boost_kahypar::make_shared<int>( 6 ), boost_kahypar::make_shared<int>( 7 ) );
    }

    {
        boost_kahypar::function<bool(boost_kahypar::shared_ptr<int>, boost_kahypar::shared_ptr<int>, boost_kahypar::shared_ptr<int>, boost_kahypar::shared_ptr<int>, boost_kahypar::shared_ptr<int>, boost_kahypar::shared_ptr<int>, boost_kahypar::shared_ptr<int>, boost_kahypar::shared_ptr<int>)> f( f8 );

        ( boost_kahypar::bind( f, _1, _2, _3, _4, _5, _6, _7, _8 ) && boost_kahypar::bind( f8, _1, _2, _3, _4, _5, _6, _7, _8 ) )( boost_kahypar::make_shared<int>( 1 ), boost_kahypar::make_shared<int>( 2 ), boost_kahypar::make_shared<int>( 3 ), boost_kahypar::make_shared<int>( 4 ), boost_kahypar::make_shared<int>( 5 ), boost_kahypar::make_shared<int>( 6 ), boost_kahypar::make_shared<int>( 7 ), boost_kahypar::make_shared<int>( 8 ) );
    }

    {
        boost_kahypar::function<bool(boost_kahypar::shared_ptr<int>, boost_kahypar::shared_ptr<int>, boost_kahypar::shared_ptr<int>, boost_kahypar::shared_ptr<int>, boost_kahypar::shared_ptr<int>, boost_kahypar::shared_ptr<int>, boost_kahypar::shared_ptr<int>, boost_kahypar::shared_ptr<int>, boost_kahypar::shared_ptr<int>)> f( f9 );

        ( boost_kahypar::bind( f, _1, _2, _3, _4, _5, _6, _7, _8, _9 ) && boost_kahypar::bind( f9, _1, _2, _3, _4, _5, _6, _7, _8, _9 ) )( boost_kahypar::make_shared<int>( 1 ), boost_kahypar::make_shared<int>( 2 ), boost_kahypar::make_shared<int>( 3 ), boost_kahypar::make_shared<int>( 4 ), boost_kahypar::make_shared<int>( 5 ), boost_kahypar::make_shared<int>( 6 ), boost_kahypar::make_shared<int>( 7 ), boost_kahypar::make_shared<int>( 8 ), boost_kahypar::make_shared<int>( 9 ) );
    }
}

int main()
{
    test();
    return boost_kahypar::report_errors();
}
