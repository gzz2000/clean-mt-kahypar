// Copyright David Abrahams 2006. Distributed under the Boost
// Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#ifndef BOOST_CONCEPT_DETAIL_GENERAL_DWA2006429_HPP
# define BOOST_CONCEPT_DETAIL_GENERAL_DWA2006429_HPP

# include <boost_kahypar/config.hpp>
# include <boost_kahypar/preprocessor/cat.hpp>
# include <boost_kahypar/concept/detail/backward_compatibility.hpp>

# ifdef BOOST_OLD_CONCEPT_SUPPORT
#  include <boost_kahypar/concept/detail/has_constraints.hpp>
#  include <boost_kahypar/type_traits/conditional.hpp>
# endif

// This implementation works on Comeau and GCC, all the way back to
// 2.95
namespace boost_kahypar { namespace concepts {

template <class ModelFn>
struct requirement_;

namespace detail
{
  template <void(*)()> struct instantiate {};
}

template <class Model>
struct requirement
{
#   if defined(BOOST_GCC) && (BOOST_GCC >= 110000)
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wnonnull"
#   endif
    static void failed() { ((Model*)0)->~Model(); }
#   if defined(BOOST_GCC) && (BOOST_GCC >= 110000)
#   pragma GCC diagnostic pop
#   endif
};

struct failed {};

template <class Model>
struct requirement<failed ************ Model::************>
{
#   if defined(BOOST_GCC) && (BOOST_GCC >= 110000)
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wnonnull"
#   endif
    static void failed() { ((Model*)0)->~Model(); }
#   if defined(BOOST_GCC) && (BOOST_GCC >= 110000)
#   pragma GCC diagnostic pop
#   endif
};

# ifdef BOOST_OLD_CONCEPT_SUPPORT

template <class Model>
struct constraint
{
#   if defined(BOOST_GCC) && (BOOST_GCC >= 110000)
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wnonnull"
#   endif
    static void failed() { ((Model*)0)->constraints(); }
#   if defined(BOOST_GCC) && (BOOST_GCC >= 110000)
#   pragma GCC diagnostic pop
#   endif
};
  
template <class Model>
struct requirement_<void(*)(Model)>
  : boost_kahypar::conditional<
        concepts::not_satisfied<Model>::value
      , constraint<Model>
      , requirement<failed ************ Model::************>
    >::type
{};
  
# else

// For GCC-2.x, these can't have exactly the same name
template <class Model>
struct requirement_<void(*)(Model)>
    : requirement<failed ************ Model::************>
{};
  
# endif

#  define BOOST_CONCEPT_ASSERT_FN( ModelFnPtr )             \
    typedef ::boost_kahypar::concepts::detail::instantiate<          \
    &::boost_kahypar::concepts::requirement_<ModelFnPtr>::failed>    \
      BOOST_PP_CAT(boost_concept_check,__LINE__)             \
      BOOST_ATTRIBUTE_UNUSED

}}

#endif // BOOST_CONCEPT_DETAIL_GENERAL_DWA2006429_HPP
