// Copyright Kevlin Henney, 2000-2005.
// Copyright Alexander Nasonov, 2006-2010.
// Copyright Antony Polukhin, 2011-2024.
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// what:  lexical_cast custom keyword cast
// who:   contributed by Kevlin Henney,
//        enhanced with contributions from Terje Slettebo,
//        with additional fixes and suggestions from Gennaro Prota,
//        Beman Dawes, Dave Abrahams, Daryle Walker, Peter Dimov,
//        Alexander Nasonov, Antony Polukhin, Justin Viiret, Michael Hofmann,
//        Cheng Yang, Matthew Bradbury, David W. Birdsall, Pavel Korzh and other Boosters
// when:  November 2000, March 2003, June 2005, June 2006, March 2011 - 2014

#ifndef BOOST_LEXICAL_CAST_TRY_LEXICAL_CONVERT_HPP
#define BOOST_LEXICAL_CAST_TRY_LEXICAL_CONVERT_HPP

#include <boost_kahypar/config.hpp>
#ifdef BOOST_HAS_PRAGMA_ONCE
#   pragma once
#endif

#include <boost_kahypar/type_traits/conditional.hpp>
#include <boost_kahypar/type_traits/is_arithmetic.hpp>

#include <boost_kahypar/lexical_cast/detail/buffer_view.hpp>
#include <boost_kahypar/lexical_cast/detail/is_character.hpp>
#include <boost_kahypar/lexical_cast/detail/converter_numeric.hpp>
#include <boost_kahypar/lexical_cast/detail/converter_lexical.hpp>

namespace boost_kahypar {
    namespace detail
    {
        template<typename Target, typename Source>
        using is_arithmetic_and_not_xchars = boost_kahypar::integral_constant<
            bool,
            !(boost_kahypar::detail::is_character<Target>::value) &&
                !(boost_kahypar::detail::is_character<Source>::value) &&
                boost_kahypar::is_arithmetic<Source>::value &&
                boost_kahypar::is_arithmetic<Target>::value
        >;
    }

    namespace conversion { namespace detail {

        template <typename Target, typename Source>
        inline bool try_lexical_convert(const Source& arg, Target& result)
        {
            static_assert(
                !boost_kahypar::is_volatile<Source>::value,
                "Boost.LexicalCast does not support volatile input");

            typedef typename boost_kahypar::detail::array_to_pointer_decay<Source>::type src;

            typedef boost_kahypar::detail::is_arithmetic_and_not_xchars<Target, src >
                shall_we_copy_with_dynamic_check_t;

            typedef typename boost_kahypar::conditional<
                 shall_we_copy_with_dynamic_check_t::value,
                 boost_kahypar::detail::dynamic_num_converter_impl<Target, src >,
                 boost_kahypar::detail::lexical_converter_impl<Target, src >
            >::type caster_type;

            return caster_type::try_convert(arg, result);
        }

        template <typename Target, typename CharacterT>
        inline bool try_lexical_convert(const CharacterT* chars, std::size_t count, Target& result)
        {
            static_assert(
                boost_kahypar::detail::is_character<CharacterT>::value,
                "This overload of try_lexical_convert is meant to be used only with arrays of characters."
            );
            return ::boost_kahypar::conversion::detail::try_lexical_convert(
                ::boost_kahypar::conversion::detail::make_buffer_view(chars, chars + count),
                result
            );
        }

    }} // namespace conversion::detail

    namespace conversion {
        // ADL barrier
        using ::boost_kahypar::conversion::detail::try_lexical_convert;
    }

} // namespace boost_kahypar

#endif // BOOST_LEXICAL_CAST_TRY_LEXICAL_CONVERT_HPP

