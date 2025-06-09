// Copyright 2022 Peter Dimov
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/core/detail/string_view.hpp>
#include <boost_kahypar/config.hpp>

#if defined(BOOST_NO_CXX11_NULLPTR)

#error BOOST_NO_CXX11_NULLPTR is defined, test will be skipped.

#else

int main()
{
    return boost_kahypar::core::string_view( nullptr ).size() == 0;
}

#endif
