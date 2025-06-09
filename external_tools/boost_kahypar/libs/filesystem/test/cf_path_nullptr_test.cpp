// Copyright 2023 Andrey Semashev.
//
// Distributed under the Boost Software License, Version 1.0.
//
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/filesystem/path.hpp>
#include <boost_kahypar/config.hpp>

int main()
{
    boost_kahypar::filesystem::path p(nullptr);
    p = nullptr;
}
