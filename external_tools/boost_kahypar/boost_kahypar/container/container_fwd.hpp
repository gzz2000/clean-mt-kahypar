//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2005-2014. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/container for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef BOOST_CONTAINER_CONTAINER_FWD_HPP
#define BOOST_CONTAINER_CONTAINER_FWD_HPP

#ifndef BOOST_CONFIG_HPP
#  include <boost_kahypar/config.hpp>
#endif

#include <boost_kahypar/container/detail/workaround.hpp>

#if defined(BOOST_HAS_PRAGMA_ONCE)
#  pragma once
#endif

//! \file
//! This header file forward declares the following containers:
//!   - boost_kahypar::container::vector
//!   - boost_kahypar::container::stable_vector
//!   - boost_kahypar::container::static_vector
//!   - boost_kahypar::container::small_vector_base
//!   - boost_kahypar::container::small_vector
//!   - boost_kahypar::container::devector
//!   - boost_kahypar::container::slist
//!   - boost_kahypar::container::list
//!   - boost_kahypar::container::set
//!   - boost_kahypar::container::multiset
//!   - boost_kahypar::container::map
//!   - boost_kahypar::container::multimap
//!   - boost_kahypar::container::flat_set
//!   - boost_kahypar::container::flat_multiset
//!   - boost_kahypar::container::flat_map
//!   - boost_kahypar::container::flat_multimap
//!   - boost_kahypar::container::basic_string
//!   - boost_kahypar::container::string
//!   - boost_kahypar::container::wstring
//!
//! Forward declares the following allocators:
//!   - boost_kahypar::container::allocator
//!   - boost_kahypar::container::node_allocator
//!   - boost_kahypar::container::adaptive_pool
//!
//! Forward declares the following polymorphic resource classes:
//!   - boost_kahypar::container::pmr::memory_resource
//!   - boost_kahypar::container::pmr::polymorphic_allocator
//!   - boost_kahypar::container::pmr::monotonic_buffer_resource
//!   - boost_kahypar::container::pmr::pool_options
//!   - boost_kahypar::container::pmr::unsynchronized_pool_resource
//!   - boost_kahypar::container::pmr::synchronized_pool_resource
//!
//! And finally it defines the following types

#ifndef BOOST_CONTAINER_DOXYGEN_INVOKED

//Std forward declarations
#ifndef BOOST_CONTAINER_DETAIL_STD_FWD_HPP
   #include <boost_kahypar/container/detail/std_fwd.hpp>
#endif

namespace boost_kahypar{
namespace intrusive{
namespace detail{
   //Create namespace to avoid compilation errors
}}}

namespace boost_kahypar{ namespace container{ namespace dtl{
   namespace bi = boost_kahypar::intrusive;
   namespace bid = boost_kahypar::intrusive::detail;
}}}

namespace boost_kahypar{ namespace container{ namespace pmr{
   namespace bi = boost_kahypar::intrusive;
   namespace bid = boost_kahypar::intrusive::detail;
}}}

#include <cstddef>

#endif   //#ifndef BOOST_CONTAINER_DOXYGEN_INVOKED

//////////////////////////////////////////////////////////////////////////////
//                             Containers
//////////////////////////////////////////////////////////////////////////////

namespace boost_kahypar {
namespace container {

#ifndef BOOST_CONTAINER_DOXYGEN_INVOKED

template<class T>
class new_allocator;

template <class T
         ,class Allocator = void
         ,class Options   = void>
class vector;

template <class T
         ,class Allocator = void >
class stable_vector;

template < class T
         , std::size_t Capacity
         , class Options = void>
class static_vector;

template < class T
         , class Allocator = void
         , class Options   = void >
class small_vector_base;

template < class T
         , std::size_t N
         , class Allocator = void
         , class Options   = void  >
class small_vector;

template <class T
         ,class Allocator = void
         ,class Options   = void>
class devector;

template <class T
         ,class Allocator = void
         ,class Options   = void>
class deque;

template <class T
         ,class Allocator = void >
class list;

template <class T
         ,class Allocator = void >
class slist;

template <class Key
         ,class Compare  = std::less<Key>
         ,class Allocator = void
         ,class Options = void>
class set;

template <class Key
         ,class Compare  = std::less<Key>
         ,class Allocator = void
         ,class Options = void >
class multiset;

template <class Key
         ,class T
         ,class Compare  = std::less<Key>
         ,class Allocator = void
         ,class Options = void >
class map;

template <class Key
         ,class T
         ,class Compare  = std::less<Key>
         ,class Allocator = void
         ,class Options = void >
class multimap;

template <class Key
         ,class Compare  = std::less<Key>
         ,class Allocator = void >
class flat_set;

template <class Key
         ,class Compare  = std::less<Key>
         ,class Allocator = void >
class flat_multiset;

template <class Key
         ,class T
         ,class Compare  = std::less<Key>
         ,class Allocator = void >
class flat_map;

template <class Key
         ,class T
         ,class Compare  = std::less<Key>
         ,class Allocator = void >
class flat_multimap;

#ifndef BOOST_NO_CXX11_TEMPLATE_ALIASES

//! Alias templates for small_flat_[multi]{set|map} using small_vector as container

template < class Key
         , std::size_t N
         , class Compare  = std::less<Key>
         , class SmallVectorAllocator = void
         , class SmallVectorOptions   = void  >
using small_flat_set = flat_set<Key, Compare, small_vector<Key, N, SmallVectorAllocator, SmallVectorOptions>>;

template < class Key
         , std::size_t N
         , class Compare  = std::less<Key>
         , class SmallVectorAllocator = void
         , class SmallVectorOptions   = void  >
using small_flat_multiset = flat_multiset<Key, Compare, small_vector<Key, N, SmallVectorAllocator, SmallVectorOptions>>;

template < class Key
         , class T
         , std::size_t N
         , class Compare  = std::less<Key>
         , class SmallVectorAllocator = void
         , class SmallVectorOptions   = void  >
using small_flat_map = flat_map<Key, T, Compare, small_vector<std::pair<Key, T>, N, SmallVectorAllocator, SmallVectorOptions>>;

template < class Key
         , class T
         , std::size_t N
         , class Compare  = std::less<Key>
         , class SmallVectorAllocator = void
         , class SmallVectorOptions   = void  >
using small_flat_multimap = flat_multimap<Key, T, Compare, small_vector<std::pair<Key, T>, N, SmallVectorAllocator, SmallVectorOptions>>;

#endif // #ifndef BOOST_NO_CXX11_TEMPLATE_ALIASES


//! A portable metafunction to obtain a small_flat_set
template < class Key
         , std::size_t N
         , class Compare  = std::less<Key>
         , class SmallVectorAllocator = void
         , class SmallVectorOptions   = void  >
struct small_flat_set_of
{
   typedef flat_set<Key, Compare, small_vector<Key, N, SmallVectorAllocator, SmallVectorOptions> > type;
};

//! A portable metafunction to obtain a small_flat_multiset
template < class Key
         , std::size_t N
         , class Compare  = std::less<Key>
         , class SmallVectorAllocator = void
         , class SmallVectorOptions   = void  >
struct small_flat_multiset_of
{
   typedef flat_multiset<Key, Compare, small_vector<Key, N, SmallVectorAllocator, SmallVectorOptions> > type;
};

//! A portable metafunction to obtain a small_flat_map
template < class Key
         , class T
         , std::size_t N
         , class Compare  = std::less<Key>
         , class SmallVectorAllocator = void
         , class SmallVectorOptions   = void  >
struct small_flat_map_of
{
   typedef flat_map<Key, T, Compare, small_vector<std::pair<Key, T>, N, SmallVectorAllocator, SmallVectorOptions> > type;
};

//! A portable metafunction to obtain a small_flat_multimap
template < class Key
         , class T
         , std::size_t N
         , class Compare  = std::less<Key>
         , class SmallVectorAllocator = void
         , class SmallVectorOptions   = void  >
struct small_flat_multimap_of
{
   typedef flat_multimap<Key, T, Compare, small_vector<std::pair<Key, T>, N, SmallVectorAllocator, SmallVectorOptions> > type;
};

template <class CharT
         ,class Traits = std::char_traits<CharT>
         ,class Allocator  = void >
class basic_string;

typedef basic_string <char>   string;
typedef basic_string<wchar_t> wstring;

BOOST_STATIC_CONSTEXPR std::size_t ADP_nodes_per_block    = 256u;
BOOST_STATIC_CONSTEXPR std::size_t ADP_max_free_blocks    = 2u;
BOOST_STATIC_CONSTEXPR std::size_t ADP_overhead_percent   = 1u;
BOOST_STATIC_CONSTEXPR std::size_t ADP_only_alignment     = 0u;

template < class T
         , std::size_t NodesPerBlock   = ADP_nodes_per_block
         , std::size_t MaxFreeBlocks   = ADP_max_free_blocks
         , std::size_t OverheadPercent = ADP_overhead_percent
         , unsigned Version = 2
         >
class adaptive_pool;

template < class T
         , unsigned Version = 2
         , unsigned int AllocationDisableMask = 0>
class allocator;

BOOST_STATIC_CONSTEXPR std::size_t NodeAlloc_nodes_per_block = 256u;

template
   < class T
   , std::size_t NodesPerBlock = NodeAlloc_nodes_per_block
   , std::size_t Version = 2>
class node_allocator;

namespace pmr {

class memory_resource;

template<class T>
class polymorphic_allocator;

class monotonic_buffer_resource;

struct pool_options;

template <class Allocator>
class resource_adaptor_imp;

class unsynchronized_pool_resource;

class synchronized_pool_resource;

}  //namespace pmr {

#endif   //#ifndef BOOST_CONTAINER_DOXYGEN_INVOKED

//! Type used to tag that the input range is
//! guaranteed to be ordered
struct ordered_range_t
{};

//! Value used to tag that the input range is
//! guaranteed to be ordered
BOOST_CONTAINER_CONSTANT_VAR ordered_range_t ordered_range = ordered_range_t();

//! Type used to tag that the input range is
//! guaranteed to be ordered and unique
struct ordered_unique_range_t
   : public ordered_range_t
{};

//! Value used to tag that the input range is
//! guaranteed to be ordered and unique
BOOST_CONTAINER_CONSTANT_VAR ordered_unique_range_t ordered_unique_range = ordered_unique_range_t();

//! Type used to tag that the inserted values
//! should be default initialized
struct default_init_t
{};

//! Value used to tag that the inserted values
//! should be default initialized
BOOST_CONTAINER_CONSTANT_VAR default_init_t default_init = default_init_t();
#ifndef BOOST_CONTAINER_DOXYGEN_INVOKED

//! Type used to tag that the inserted values
//! should be value initialized
struct value_init_t
{};

//! Value used to tag that the inserted values
//! should be value initialized
BOOST_CONTAINER_CONSTANT_VAR value_init_t value_init = value_init_t();

namespace container_detail_really_deep_namespace {

//Otherwise, gcc issues a warning of previously defined
//anonymous_instance and unique_instance
struct dummy
{
   dummy()
   {
      (void)ordered_range;
      (void)ordered_unique_range;
      (void)default_init;
   }
};

}  //detail_really_deep_namespace {

typedef const std::piecewise_construct_t & piecewise_construct_t;

#endif   //#ifndef BOOST_CONTAINER_DOXYGEN_INVOKED

}}  //namespace boost_kahypar { namespace container {

#endif //#ifndef BOOST_CONTAINER_CONTAINER_FWD_HPP
