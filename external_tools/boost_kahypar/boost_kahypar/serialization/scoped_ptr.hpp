#ifndef BOOST_SERIALIZATION_SCOPED_PTR_HPP_VP_2003_10_30
#define BOOST_SERIALIZATION_SCOPED_PTR_HPP_VP_2003_10_30

#if defined(_MSC_VER)
# pragma once
#endif

//  Copyright (c) 2003 Vladimir Prus.
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// Provides non-intrusive serialization for boost_kahypar::scoped_ptr
// Does not allow to serialize scoped_ptr's to builtin types.

#include <boost_kahypar/config.hpp>

#include <boost_kahypar/scoped_ptr.hpp>
#include <boost_kahypar/serialization/nvp.hpp>
#include <boost_kahypar/serialization/split_free.hpp>

namespace boost_kahypar {
namespace serialization {

    template<class Archive, class T>
    void save(
        Archive & ar,
        const boost_kahypar::scoped_ptr< T > & t,
        const unsigned int /* version */
    ){
        T* r = t.get();
        ar << boost_kahypar::serialization::make_nvp("scoped_ptr", r);
    }

    template<class Archive, class T>
    void load(
        Archive & ar,
        boost_kahypar::scoped_ptr< T > & t,
        const unsigned int /* version */
    ){
        T* r;
        ar >> boost_kahypar::serialization::make_nvp("scoped_ptr", r);
        t.reset(r);
    }

    template<class Archive, class T>
    void serialize(
        Archive& ar,
        boost_kahypar::scoped_ptr< T >& t,
        const unsigned int version
    ){
        boost_kahypar::serialization::split_free(ar, t, version);
    }

} // namespace serialization
} // namespace boost_kahypar

#endif // BOOST_SERIALIZATION_SCOPED_PTR_HPP_VP_2003_10_30
