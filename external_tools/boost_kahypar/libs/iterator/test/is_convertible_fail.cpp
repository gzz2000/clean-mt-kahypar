//
// Copyright (c) Thomas Witt 2002.
//
// Use, modification and distribution is subject to the
// Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include <boost_kahypar/iterator/reverse_iterator.hpp>
#include <boost_kahypar/cstdlib.hpp>

int main()
{
    typedef boost_kahypar::reverse_iterator<int*>  rev_iter1;
    typedef boost_kahypar::reverse_iterator<char*> rev_iter2;

    return boost_kahypar::is_convertible<rev_iter1, rev_iter2>::value
        ? boost_kahypar::exit_failure : boost_kahypar::exit_success;
}
