#ifndef BOOST_SERIALIZATION_SHARED_PTR_HPP
#define BOOST_SERIALIZATION_SHARED_PTR_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// shared_ptr.hpp: serialization for boost shared pointer

// (C) Copyright 2004 Robert Ramey and Martin Ecker
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for updates, documentation, and revision history.

#include <cstddef> // NULL
#include <memory>

#include <boost_kahypar/config.hpp>
#include <boost_kahypar/mpl/integral_c.hpp>
#include <boost_kahypar/mpl/integral_c_tag.hpp>

#include <boost_kahypar/detail/workaround.hpp>
#include <boost_kahypar/shared_ptr.hpp>

#include <boost_kahypar/serialization/shared_ptr_helper.hpp>
#include <boost_kahypar/serialization/split_free.hpp>
#include <boost_kahypar/serialization/nvp.hpp>
#include <boost_kahypar/serialization/version.hpp>
#include <boost_kahypar/serialization/tracking.hpp>

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// boost_kahypar:: shared_ptr serialization traits
// version 1 to distinguish from boost 1.32 version. Note: we can only do this
// for a template when the compiler supports partial template specialization

#ifndef BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
    namespace boost_kahypar {
    namespace serialization{
        template<class T>
        struct version< ::boost_kahypar::shared_ptr< T > > {
            typedef mpl::integral_c_tag tag;
            #if BOOST_WORKAROUND(__MWERKS__, BOOST_TESTED_AT(0x3206))
            typedef typename mpl::int_<1> type;
            #else
            typedef mpl::int_<1> type;
            #endif
            BOOST_STATIC_CONSTANT(int, value = type::value);
        };
        // don't track shared pointers
        template<class T>
        struct tracking_level< ::boost_kahypar::shared_ptr< T > > {
            typedef mpl::integral_c_tag tag;
            #if BOOST_WORKAROUND(__MWERKS__, BOOST_TESTED_AT(0x3206))
            typedef typename mpl::int_< ::boost_kahypar::serialization::track_never> type;
            #else
            typedef mpl::int_< ::boost_kahypar::serialization::track_never> type;
            #endif
            BOOST_STATIC_CONSTANT(int, value = type::value);
        };
    }}
    #define BOOST_SERIALIZATION_SHARED_PTR(T)
#else
    // define macro to let users of these compilers do this
    #define BOOST_SERIALIZATION_SHARED_PTR(T)                         \
    BOOST_CLASS_VERSION(                                              \
        ::boost_kahypar::shared_ptr< T >,                                     \
        1                                                             \
    )                                                                 \
    BOOST_CLASS_TRACKING(                                             \
        ::boost_kahypar::shared_ptr< T >,                                     \
        ::boost_kahypar::serialization::track_never                           \
    )                                                                 \
    /**/
#endif

namespace boost_kahypar {
namespace serialization{

struct null_deleter {
    void operator()(void const *) const {}
};

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// serialization for boost_kahypar::shared_ptr

// Using a constant means that all shared pointers are held in the same set.
// Thus we detect handle multiple pointers to the same value instances
// in the archive.
void * const shared_ptr_helper_id = 0;

template<class Archive, class T>
inline void save(
    Archive & ar,
    const boost_kahypar::shared_ptr< T > &t,
    const unsigned int /* file_version */
){
    // The most common cause of trapping here would be serializing
    // something like shared_ptr<int>.  This occurs because int
    // is never tracked by default.  Wrap int in a trackable type
    BOOST_STATIC_ASSERT((tracking_level< T >::value != track_never));
    const T * t_ptr = t.get();
    ar << boost_kahypar::serialization::make_nvp("px", t_ptr);
}

#ifdef BOOST_SERIALIZATION_SHARED_PTR_132_HPP
template<class Archive, class T>
inline void load(
    Archive & ar,
    boost_kahypar::shared_ptr< T > &t,
    const unsigned int file_version
){
    // something like shared_ptr<int>.  This occurs because int
    // is never tracked by default.  Wrap int in a trackable type
    BOOST_STATIC_ASSERT((tracking_level< T >::value != track_never));
    T* r;
    if(file_version < 1){
        ar.register_type(static_cast<
            boost_kahypar_132::detail::sp_counted_base_impl<T *, null_deleter > *
        >(NULL));
        boost_kahypar_132::shared_ptr< T > sp;
        ar >> boost_kahypar::serialization::make_nvp("px", sp.px);
        ar >> boost_kahypar::serialization::make_nvp("pn", sp.pn);
        // got to keep the sps around so the sp.pns don't disappear
        boost_kahypar::serialization::shared_ptr_helper<boost_kahypar::shared_ptr> & h =
            ar.template get_helper< shared_ptr_helper<boost_kahypar::shared_ptr> >(
                shared_ptr_helper_id
            );
        h.append(sp);
        r = sp.get();
    }
    else{
        ar >> boost_kahypar::serialization::make_nvp("px", r);
    }
    shared_ptr_helper<boost_kahypar::shared_ptr> & h =
        ar.template get_helper<shared_ptr_helper<boost_kahypar::shared_ptr> >(
            shared_ptr_helper_id
        );
    h.reset(t,r);
}
#else

template<class Archive, class T>
inline void load(
    Archive & ar,
    boost_kahypar::shared_ptr< T > &t,
    const unsigned int /*file_version*/
){
    // The most common cause of trapping here would be serializing
    // something like shared_ptr<int>.  This occurs because int
    // is never tracked by default.  Wrap int in a trackable type
    BOOST_STATIC_ASSERT((tracking_level< T >::value != track_never));
    T* r;
    ar >> boost_kahypar::serialization::make_nvp("px", r);

    boost_kahypar::serialization::shared_ptr_helper<boost_kahypar::shared_ptr> & h =
        ar.template get_helper<shared_ptr_helper<boost_kahypar::shared_ptr> >(
            shared_ptr_helper_id
        );
    h.reset(t,r);
}
#endif

template<class Archive, class T>
inline void serialize(
    Archive & ar,
    boost_kahypar::shared_ptr< T > &t,
    const unsigned int file_version
){
    // correct shared_ptr serialization depends upon object tracking
    // being used.
    BOOST_STATIC_ASSERT(
        boost_kahypar::serialization::tracking_level< T >::value
        != boost_kahypar::serialization::track_never
    );
    boost_kahypar::serialization::split_free(ar, t, file_version);
}

} // namespace serialization
} // namespace boost_kahypar

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// std::shared_ptr serialization traits
// version 1 to distinguish from boost 1.32 version. Note: we can only do this
// for a template when the compiler supports partial template specialization

#ifndef BOOST_NO_CXX11_SMART_PTR
#include <boost_kahypar/static_assert.hpp>

// note: we presume that any compiler/library which supports C++11
// std::pointers also supports template partial specialization
// trap here if such presumption were to turn out to wrong!!!
#ifdef BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
    BOOST_STATIC_ASSERT(false);
#endif

namespace boost_kahypar {
namespace serialization{
    template<class T>
    struct version< ::std::shared_ptr< T > > {
        typedef mpl::integral_c_tag tag;
        typedef mpl::int_<1> type;
        BOOST_STATIC_CONSTANT(int, value = type::value);
    };
    // don't track shared pointers
    template<class T>
    struct tracking_level< ::std::shared_ptr< T > > {
        typedef mpl::integral_c_tag tag;
        typedef mpl::int_< ::boost_kahypar::serialization::track_never> type;
        BOOST_STATIC_CONSTANT(int, value = type::value);
    };
}}
// the following just keeps older programs from breaking
#define BOOST_SERIALIZATION_SHARED_PTR(T)

namespace boost_kahypar {
namespace serialization{

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// serialization for std::shared_ptr

template<class Archive, class T>
inline void save(
    Archive & ar,
    const std::shared_ptr< T > &t,
    const unsigned int /* file_version */
){
    // The most common cause of trapping here would be serializing
    // something like shared_ptr<int>.  This occurs because int
    // is never tracked by default.  Wrap int in a trackable type
    BOOST_STATIC_ASSERT((tracking_level< T >::value != track_never));
    const T * t_ptr = t.get();
    ar << boost_kahypar::serialization::make_nvp("px", t_ptr);
}

template<class Archive, class T>
inline void load(
    Archive & ar,
    std::shared_ptr< T > &t,
    const unsigned int /*file_version*/
){
    // The most common cause of trapping here would be serializing
    // something like shared_ptr<int>.  This occurs because int
    // is never tracked by default.  Wrap int in a trackable type
    BOOST_STATIC_ASSERT((tracking_level< T >::value != track_never));
    T* r;
    ar >> boost_kahypar::serialization::make_nvp("px", r);
    //void (* const id)(Archive &, std::shared_ptr< T > &, const unsigned int) = & load;
    boost_kahypar::serialization::shared_ptr_helper<std::shared_ptr> & h =
        ar.template get_helper<
            shared_ptr_helper<std::shared_ptr>
        >(
            shared_ptr_helper_id
        );
    h.reset(t,r);
}

template<class Archive, class T>
inline void serialize(
    Archive & ar,
    std::shared_ptr< T > &t,
    const unsigned int file_version
){
    // correct shared_ptr serialization depends upon object tracking
    // being used.
    BOOST_STATIC_ASSERT(
        boost_kahypar::serialization::tracking_level< T >::value
        != boost_kahypar::serialization::track_never
    );
    boost_kahypar::serialization::split_free(ar, t, file_version);
}

} // namespace serialization
} // namespace boost_kahypar

#endif // BOOST_NO_CXX11_SMART_PTR

#endif // BOOST_SERIALIZATION_SHARED_PTR_HPP
