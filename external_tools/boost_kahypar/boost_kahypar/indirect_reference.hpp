#ifndef INDIRECT_REFERENCE_DWA200415_HPP
# define INDIRECT_REFERENCE_DWA200415_HPP

//
// Copyright David Abrahams 2004. Use, modification and distribution is
// subject to the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// typename indirect_reference<P>::type provides the type of *p.
//
// http://www.boost.org/libs/iterator/doc/pointee.html
//

# include <boost_kahypar/detail/is_incrementable.hpp>
# include <boost_kahypar/iterator/iterator_traits.hpp>
# include <boost_kahypar/type_traits/remove_cv.hpp>
# include <boost_kahypar/mpl/eval_if.hpp>
# include <boost_kahypar/pointee.hpp>

namespace boost_kahypar {

namespace detail
{
  template <class P>
  struct smart_ptr_reference
  {
      typedef typename boost_kahypar::pointee<P>::type& type;
  };
}

template <class P>
struct indirect_reference
  : mpl::eval_if<
        detail::is_incrementable<P>
      , iterator_reference<P>
      , detail::smart_ptr_reference<P>
    >
{
};

} // namespace boost_kahypar

#endif // INDIRECT_REFERENCE_DWA200415_HPP
