/*
Copyright 2017 Glen Joseph Fernandes
(glenjofe@gmail.com)

Distributed under the Boost Software License, Version 1.0.
(http://www.boost.org/LICENSE_1_0.txt)
*/

#include <boost_kahypar/core/addressof.hpp>

#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES) && \
    !defined(BOOST_NO_CXX11_DELETED_FUNCTIONS)
struct type { };

inline const type function()
{
    return type();
}

int main()
{
    (void)boost_kahypar::addressof(function());
}
#else
#error Requires rvalue references and deleted functions
#endif
