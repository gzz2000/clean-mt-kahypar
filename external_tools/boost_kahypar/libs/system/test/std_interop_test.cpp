
// Copyright 2017 Peter Dimov.
//
// Distributed under the Boost Software License, Version 1.0.
//
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt

// See library home page at http://www.boost.org/libs/system

#include <boost_kahypar/system/error_code.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>
#include <boost_kahypar/core/snprintf.hpp>
#include <system_error>
#include <cerrno>
#include <string>
#include <cstdio>

static void test_generic_category()
{
    boost_kahypar::system::error_category const & bt = boost_kahypar::system::generic_category();
    std::error_category const & st = bt;

    BOOST_TEST_CSTR_EQ( bt.name(), st.name() );

    int ev = ENOENT;

    // Under MSVC, it's "no such file or directory" instead of "No such file or directory"
    BOOST_TEST_EQ( bt.message( ev ).substr( 1 ), st.message( ev ).substr( 1 ) );

    {
        boost_kahypar::system::error_code bc( ev, bt );

        BOOST_TEST_EQ( bc.value(), ev );
        BOOST_TEST_EQ( &bc.category(), &bt );

        std::error_code sc( bc );

        BOOST_TEST_EQ( sc.value(), ev );
        BOOST_TEST_EQ( &sc.category(), &st );
    }

    {
        boost_kahypar::system::error_condition bn = bt.default_error_condition( ev );

        BOOST_TEST_EQ( bn.value(), ev );
        BOOST_TEST_EQ( &bn.category(), &bt );

        BOOST_TEST( bt.equivalent( ev, bn ) );

        std::error_condition sn( bn );

        BOOST_TEST_EQ( sn.value(), ev );
        BOOST_TEST_EQ( &sn.category(), &st );

        BOOST_TEST( st.equivalent( ev, sn ) );
    }
}

static void test_system_category()
{
    boost_kahypar::system::error_category const & bt = boost_kahypar::system::system_category();
    std::error_category const & st = bt;

    BOOST_TEST_CSTR_EQ( bt.name(), st.name() );

    for( int ev = 1; ev < 6; ++ev )
    {
        std::string bm = bt.message( ev );
        std::string sm = st.message( ev );

        // We strip whitespace and the trailing dot, MSVC not so much
        BOOST_TEST_EQ( bm, sm.substr( 0, bm.size() ) );

        {
            boost_kahypar::system::error_code bc( ev, bt );

            BOOST_TEST_EQ( bc.value(), ev );
            BOOST_TEST_EQ( &bc.category(), &bt );

            std::error_code sc( bc );

            BOOST_TEST_EQ( sc.value(), ev );
            BOOST_TEST_EQ( &sc.category(), &st );
        }

        {
            boost_kahypar::system::error_condition bn = bt.default_error_condition( ev );
            BOOST_TEST( bt.equivalent( ev, bn ) );

            std::error_condition sn( bn );
            BOOST_TEST( st.equivalent( ev, sn ) );
        }
    }
}

// test_user_category

class user_category_impl: public boost_kahypar::system::error_category
{
public:

    virtual const char * name() const noexcept
    {
        return "user";
    }

    virtual std::string message( int ev ) const
    {
        char buffer[ 256 ];
        boost_kahypar::core::snprintf( buffer, sizeof( buffer ), "user message %d", ev );

        return buffer;
    }

    virtual boost_kahypar::system::error_condition default_error_condition( int ev ) const noexcept
    {
        if( ev == 4 )
        {
            return boost_kahypar::system::error_condition( EMFILE, boost_kahypar::system::generic_category() );
        }
        else if( ev == 5 )
        {
            return boost_kahypar::system::error_condition( EACCES, boost_kahypar::system::generic_category() );
        }
        else
        {
            return boost_kahypar::system::error_condition( ev, *this );
        }
    }

    virtual bool equivalent( int code, const boost_kahypar::system::error_condition & condition ) const noexcept
    {
        if( code == 4 && condition == make_error_condition( boost_kahypar::system::errc::too_many_files_open_in_system ) )
        {
            return true;
        }

        if( code == 4 && condition == make_error_condition( boost_kahypar::system::errc::too_many_files_open ) )
        {
            return true;
        }

        return default_error_condition( code ) == condition;
    }

    // virtual bool equivalent( const error_code & code, int condition ) const noexcept;
};

boost_kahypar::system::error_category const & user_category()
{
    static user_category_impl cat_;
    return cat_;
}

static void test_user_category()
{
    boost_kahypar::system::error_category const & bt = user_category();
    std::error_category const & st = bt;

    BOOST_TEST_CSTR_EQ( bt.name(), st.name() );

    {
        int ev = 5;
        BOOST_TEST_EQ( bt.message( ev ), st.message( ev ) );

        {
            boost_kahypar::system::error_code bc( ev, bt );

            BOOST_TEST_EQ( bc.value(), ev );
            BOOST_TEST_EQ( &bc.category(), &bt );

            std::error_code sc( bc );

            BOOST_TEST_EQ( sc.value(), ev );
            BOOST_TEST_EQ( &sc.category(), &st );
        }

        {
            boost_kahypar::system::error_condition bn = bt.default_error_condition( ev );
            BOOST_TEST( bt.equivalent( ev, bn ) );

            std::error_condition sn( bn );
            BOOST_TEST( st.equivalent( ev, sn ) );
        }
    }

    {
        int ev = 4;
        BOOST_TEST_EQ( bt.message( ev ), st.message( ev ) );

        {
            boost_kahypar::system::error_code bc( ev, bt );

            BOOST_TEST_EQ( bc.value(), ev );
            BOOST_TEST_EQ( &bc.category(), &bt );

            std::error_code sc( bc );

            BOOST_TEST_EQ( sc.value(), ev );
            BOOST_TEST_EQ( &sc.category(), &st );
        }

        {
            boost_kahypar::system::error_condition bn = bt.default_error_condition( ev );
            BOOST_TEST( bt.equivalent( ev, bn ) );

            std::error_condition sn( bn );
            BOOST_TEST( st.equivalent( ev, sn ) );
        }

        {
            boost_kahypar::system::error_condition bn = make_error_condition( boost_kahypar::system::errc::too_many_files_open_in_system );
            BOOST_TEST( bt.equivalent( ev, bn ) );

            std::error_condition sn( bn );
            BOOST_TEST( st.equivalent( ev, sn ) );
        }

        {
            boost_kahypar::system::error_condition bn = make_error_condition( boost_kahypar::system::errc::too_many_files_open );
            BOOST_TEST( bt.equivalent( ev, bn ) );

            std::error_condition sn( bn );
            BOOST_TEST( st.equivalent( ev, sn ) );
        }
    }
}

// test_user2_category

enum user2_errc
{
    my_enoent = 1,
    my_einval,
    my_other
};

class user2_category_impl: public boost_kahypar::system::error_category
{
public:

    virtual const char * name() const noexcept
    {
        return "user2";
    }

    virtual std::string message( int ev ) const
    {
        char buffer[ 256 ];
        boost_kahypar::core::snprintf( buffer, sizeof( buffer ), "user2 message %d", ev );

        return buffer;
    }

    virtual boost_kahypar::system::error_condition default_error_condition( int ev ) const noexcept
    {
        return boost_kahypar::system::error_condition( ev, *this );
    }

    virtual bool equivalent( int code, const boost_kahypar::system::error_condition & condition ) const noexcept
    {
        return default_error_condition( code ) == condition;
    }

    virtual bool equivalent( const boost_kahypar::system::error_code & code, int condition ) const noexcept
    {
        if( code.category() == *this )
        {
            return condition == code.value();
        }
        else if( condition == my_enoent )
        {
            return code == boost_kahypar::system::errc::no_such_file_or_directory;
        }
        else if( condition == my_einval )
        {
            return code == boost_kahypar::system::errc::invalid_argument;
        }
        else
        {
            return false;
        }
    }
};

boost_kahypar::system::error_category const & user2_category()
{
    static user2_category_impl cat_;
    return cat_;
}

static void test_user2_category()
{
    boost_kahypar::system::error_category const & bt = user2_category();
    std::error_category const & st = bt;

    int ev = my_enoent;

    boost_kahypar::system::error_condition bn( ev, bt );

    BOOST_TEST_EQ( bn.value(), ev );
    BOOST_TEST_EQ( &bn.category(), &bt );

    boost_kahypar::system::error_code bc = make_error_code( boost_kahypar::system::errc::no_such_file_or_directory );

    BOOST_TEST( bc == bn );

    std::error_condition sn( bn );

    BOOST_TEST_EQ( sn.value(), ev );
    BOOST_TEST_EQ( &sn.category(), &st );

    std::error_code sc( bc );

    BOOST_TEST( sc == sn );
}

//

int main()
{
    test_generic_category();
    test_system_category();
    test_user_category();
    test_user2_category();

    return boost_kahypar::report_errors();
}
