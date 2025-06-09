// Copyright 2021 Peter Dimov.
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/system/errc.hpp>

int main()
{
    make_error_code( boost_kahypar::system::errc::success ).value();
    make_error_code( boost_kahypar::system::errc::success ).category();
    make_error_code( boost_kahypar::system::errc::success ).default_error_condition();
    make_error_code( boost_kahypar::system::errc::success ).message();
    make_error_code( boost_kahypar::system::errc::success ).failed();
    make_error_code( boost_kahypar::system::errc::success ).clear();

    make_error_condition( boost_kahypar::system::errc::success ).value();
    make_error_condition( boost_kahypar::system::errc::success ).category();
    make_error_condition( boost_kahypar::system::errc::success ).message();
    make_error_condition( boost_kahypar::system::errc::success ).failed();
    make_error_condition( boost_kahypar::system::errc::success ).clear();

    make_error_code( boost_kahypar::system::errc::no_such_file_or_directory ).value();
    make_error_code( boost_kahypar::system::errc::no_such_file_or_directory ).category();
    make_error_code( boost_kahypar::system::errc::no_such_file_or_directory ).default_error_condition();
    make_error_code( boost_kahypar::system::errc::no_such_file_or_directory ).message();
    make_error_code( boost_kahypar::system::errc::no_such_file_or_directory ).failed();
    make_error_code( boost_kahypar::system::errc::no_such_file_or_directory ).clear();

    make_error_condition( boost_kahypar::system::errc::no_such_file_or_directory ).value();
    make_error_condition( boost_kahypar::system::errc::no_such_file_or_directory ).category();
    make_error_condition( boost_kahypar::system::errc::no_such_file_or_directory ).message();
    make_error_condition( boost_kahypar::system::errc::no_such_file_or_directory ).failed();
    make_error_condition( boost_kahypar::system::errc::no_such_file_or_directory ).clear();
}
