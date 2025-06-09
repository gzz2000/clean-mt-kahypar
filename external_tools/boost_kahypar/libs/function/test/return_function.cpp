
// Copyright 2018 Peter Dimov.
// Distributed under the Boost Software License, Version 1.0.

#include <boost_kahypar/function.hpp>
#include <boost_kahypar/config.hpp>

#if defined(RETURN_FUNCTION_DYN_LINK)
# define EXPORT BOOST_SYMBOL_EXPORT
#else
# define EXPORT
#endif

int f( int x, int y )
{
    return x + y;
}

EXPORT boost_kahypar::function<int(int, int)> get_fn_1()
{
    return f;
}

EXPORT boost_kahypar::function2<int, int, int> get_fn_2()
{
    return f;
}
