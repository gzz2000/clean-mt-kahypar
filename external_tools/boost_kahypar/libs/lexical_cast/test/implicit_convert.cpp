//  Copyright Antony Polukhin, 2023-2024.
//
//  Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt).

#include <boost_kahypar/lexical_cast.hpp>

#include <boost_kahypar/core/lightweight_test.hpp>

#include <boost_kahypar/lexical_cast.hpp>

struct oops {
    operator int () const {
        return 41;
    }
};

inline std::ostream& operator<<(std::ostream& os, const oops&) {
    return os << 42;
}

int main () {
    auto val = boost_kahypar::lexical_cast<int>(oops{});
    BOOST_TEST_EQ(val, 42);

    return boost_kahypar::report_errors();
}
