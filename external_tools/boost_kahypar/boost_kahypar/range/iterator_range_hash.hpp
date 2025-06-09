// Boost.Range library
//
//  Copyright Neil Groves 2014
//  Use, modification and distribution is subject to the Boost Software
//  License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//
#include <boost_kahypar/range/iterator_range_core.hpp>
#include <boost_kahypar/functional/hash.hpp>

namespace boost_kahypar
{

template<class T>
std::size_t hash_value(const iterator_range<T>& rng)
{
    return boost_kahypar::hash_range(rng.begin(), rng.end());
}

} // namespace boost_kahypar
