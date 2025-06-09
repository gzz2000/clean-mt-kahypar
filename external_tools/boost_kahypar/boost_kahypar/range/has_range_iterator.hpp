// Boost.Range library
//
//  Copyright Neil Groves 2010. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//
// Acknowledgments:
// Ticket #8341: Arno Schoedl - improved handling of has_range_iterator upon
// use-cases where T was const.
#ifndef BOOST_RANGE_HAS_ITERATOR_HPP_INCLUDED
#define BOOST_RANGE_HAS_ITERATOR_HPP_INCLUDED

#include <boost_kahypar/mpl/bool.hpp>
#include <boost_kahypar/mpl/eval_if.hpp>
#include <boost_kahypar/mpl/has_xxx.hpp>
#include <boost_kahypar/range/iterator.hpp>
#include <boost_kahypar/type_traits/remove_reference.hpp>
#include <boost_kahypar/utility/enable_if.hpp>

namespace boost_kahypar
{
    namespace range_detail
    {
        BOOST_MPL_HAS_XXX_TRAIT_DEF(type)

        template<class T, class Enabler = void>
        struct has_range_iterator_impl
            : boost_kahypar::mpl::false_
        {
        };

        template<class T>
        struct has_range_iterator_impl<
            T,
            BOOST_DEDUCED_TYPENAME ::boost_kahypar::enable_if<
                BOOST_DEDUCED_TYPENAME mpl::eval_if<is_const<T>,
                    has_type<boost_kahypar::range_const_iterator<
                                BOOST_DEDUCED_TYPENAME remove_const<T>::type> >,
                    has_type<boost_kahypar::range_mutable_iterator<T> >
                >::type
            >::type
        >
            : boost_kahypar::mpl::true_
        {
        };

        template<class T, class Enabler = void>
        struct has_range_const_iterator_impl
            : boost_kahypar::mpl::false_
        {
        };

        template<class T>
        struct has_range_const_iterator_impl<
            T,
            BOOST_DEDUCED_TYPENAME ::boost_kahypar::enable_if<
                has_type<boost_kahypar::range_const_iterator<T> >
            >::type
        >
            : boost_kahypar::mpl::true_
        {
        };

    } // namespace range_detail

    template<class T>
    struct has_range_iterator
        : range_detail::has_range_iterator_impl<
            BOOST_DEDUCED_TYPENAME remove_reference<T>::type>
    {};

    template<class T>
    struct has_range_const_iterator
        : range_detail::has_range_const_iterator_impl<
            BOOST_DEDUCED_TYPENAME remove_reference<T>::type>
    {};
} // namespace boost_kahypar

#endif // include guard

