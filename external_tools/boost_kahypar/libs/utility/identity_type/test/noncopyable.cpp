
// Copyright (C) 2009-2012 Lorenzo Caminiti
// Distributed under the Boost Software License, Version 1.0
// (see accompanying file LICENSE_1_0.txt or a copy at
// http://www.boost.org/LICENSE_1_0.txt)
// Home at http://www.boost.org/libs/utility/identity_type

#include <boost_kahypar/utility/identity_type.hpp>
#include <boost_kahypar/static_assert.hpp>
#include <boost_kahypar/noncopyable.hpp>

//[noncopyable
#define TMP_ASSERT(metafunction) \
    BOOST_STATIC_ASSERT(metafunction::value)

template<typename T, T init>
struct noncopyable : boost_kahypar::noncopyable {
    static const T value = init;
};

TMP_ASSERT(BOOST_IDENTITY_TYPE((noncopyable<bool, true>)));
//]

int main() { return 0; }

