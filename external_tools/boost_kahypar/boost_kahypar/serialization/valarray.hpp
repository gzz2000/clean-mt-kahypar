#ifndef BOOST_SERIALIZATION_VALARAY_HPP
#define BOOST_SERIALIZATION_VALARAY_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// valarray.hpp: serialization for stl vector templates

// (C) Copyright 2005 Matthias Troyer .
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for updates, documentation, and revision history.

#include <valarray>
#include <boost_kahypar/config.hpp>
#include <boost_kahypar/core/addressof.hpp>

#include <boost_kahypar/serialization/collections_save_imp.hpp>
#include <boost_kahypar/serialization/collections_load_imp.hpp>
#include <boost_kahypar/serialization/split_free.hpp>
#include <boost_kahypar/serialization/collection_size_type.hpp>
#include <boost_kahypar/serialization/array_wrapper.hpp>

// function specializations must be defined in the appropriate
// namespace - boost_kahypar::serialization
#if defined(__SGI_STL_PORT) || defined(_STLPORT_VERSION)
#define STD _STLP_STD
#else
#define STD std
#endif

namespace boost_kahypar {
namespace serialization {

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// valarray< T >

template<class Archive, class U>
void save( Archive & ar, const STD::valarray<U> &t, const unsigned int /*file_version*/ )
{
    const collection_size_type count(t.size());
    ar << BOOST_SERIALIZATION_NVP(count);
    if (t.size()){
        // explicit template arguments to pass intel C++ compiler
        ar << serialization::make_array<const U, collection_size_type>(
            static_cast<const U *>( boost_kahypar::addressof(t[0]) ),
            count
        );
    }
}

template<class Archive, class U>
void load( Archive & ar, STD::valarray<U> &t,  const unsigned int /*file_version*/ )
{
    collection_size_type count;
    ar >> BOOST_SERIALIZATION_NVP(count);
    t.resize(count);
    if (t.size()){
        // explicit template arguments to pass intel C++ compiler
        ar >> serialization::make_array<U, collection_size_type>(
            static_cast<U *>( boost_kahypar::addressof(t[0]) ),
            count
        );
    }
}

// split non-intrusive serialization function member into separate
// non intrusive save/load member functions
template<class Archive, class U>
inline void serialize( Archive & ar, STD::valarray<U> & t, const unsigned int file_version)
{
    boost_kahypar::serialization::split_free(ar, t, file_version);
}

} } // end namespace boost_kahypar::serialization

#include <boost_kahypar/serialization/collection_traits.hpp>

BOOST_SERIALIZATION_COLLECTION_TRAITS(STD::valarray)
#undef STD

#endif // BOOST_SERIALIZATION_VALARAY_HPP
