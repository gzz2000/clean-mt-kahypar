// Copyright David Abrahams 2006. Distributed under the Boost
// Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#ifndef BOOST_CONCEPT_DETAIL_BORLAND_DWA2006429_HPP
# define BOOST_CONCEPT_DETAIL_BORLAND_DWA2006429_HPP

# include <boost_kahypar/preprocessor/cat.hpp>
# include <boost_kahypar/concept/detail/backward_compatibility.hpp>

namespace boost_kahypar { namespace concepts {

template <class ModelFnPtr>
struct require;

template <class Model>
struct require<void(*)(Model)>
{
    enum { instantiate = sizeof((((Model*)0)->~Model()), 3) };
};

#  define BOOST_CONCEPT_ASSERT_FN( ModelFnPtr )         \
  enum                                                  \
  {                                                     \
      BOOST_PP_CAT(boost_concept_check,__LINE__) =      \
      boost_kahypar::concepts::require<ModelFnPtr>::instantiate  \
  }

}} // namespace boost_kahypar::concept

#endif // BOOST_CONCEPT_DETAIL_BORLAND_DWA2006429_HPP
