
// Copyright 2019 Peter Dimov.
// Distributed under the Boost Software License, Version 1.0.

#include <boost_kahypar/config.hpp>

#if defined(STD_SINGLE_INSTANCE_DYN_LINK)
# define EXPORT BOOST_SYMBOL_EXPORT
#else
# define EXPORT
#endif

#include <boost_kahypar/system/error_code.hpp>
#include <system_error>

namespace lib1
{

EXPORT std::error_code get_system_code()
{
    return boost_kahypar::system::error_code( 0, boost_kahypar::system::system_category() );
}

EXPORT std::error_code get_generic_code()
{
    return boost_kahypar::system::error_code( 0, boost_kahypar::system::generic_category() );
}

} // namespace lib1
