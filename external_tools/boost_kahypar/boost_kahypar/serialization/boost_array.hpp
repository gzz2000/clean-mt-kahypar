#ifndef BOOST_SERIALIZATION_BOOST_ARRAY_HPP
#define BOOST_SERIALIZATION_BOOST_ARRAY_HPP

// (C) Copyright 2005 Matthias Troyer and Dave Abrahams
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost_kahypar/config.hpp> // msvc 6.0 needs this for warning suppression

#if defined(BOOST_NO_STDC_NAMESPACE)
namespace std{
    using ::size_t;
} // namespace std
#endif

#include <boost_kahypar/serialization/nvp.hpp>
#include <boost_kahypar/array.hpp>

namespace boost_kahypar { namespace serialization {
// implement serialization for boost_kahypar::array
template <class Archive, class T, std::size_t N>
void serialize(Archive& ar, boost_kahypar::array<T,N>& a, const unsigned int /* version */)
{
    ar & boost_kahypar::serialization::make_nvp("elems", a.elems);
}

} } // end namespace boost_kahypar::serialization


#endif //BOOST_SERIALIZATION_BOOST_ARRAY_HPP
