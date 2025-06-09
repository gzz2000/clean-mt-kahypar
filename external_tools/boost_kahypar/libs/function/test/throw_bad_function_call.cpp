
// Copyright 2018 Peter Dimov.
// Distributed under the Boost Software License, Version 1.0.

#include <boost_kahypar/function.hpp>
#include <boost_kahypar/config.hpp>

#if defined(THROW_BAD_FUNCTION_CALL_DYN_LINK)
# define EXPORT BOOST_SYMBOL_EXPORT
#else
# define EXPORT
#endif

EXPORT void throw_bad_function_call()
{
    throw boost_kahypar::bad_function_call();
}
