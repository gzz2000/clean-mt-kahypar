// Copyright 2009 (C) Dean Michael Berris <me@deanberris.com>
// Copyright 2012 (C) Google, Inc.
// Copyright 2012 (C) Jeffrey Lee Hellrung, Jr.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_FUNCTION_INPUT_ITERATOR
#define BOOST_FUNCTION_INPUT_ITERATOR

#include <boost_kahypar/config.hpp>
#include <boost_kahypar/assert.hpp>
#include <boost_kahypar/core/addressof.hpp>
#include <boost_kahypar/type_traits/conditional.hpp>
#include <boost_kahypar/function_types/is_function_pointer.hpp>
#include <boost_kahypar/function_types/result_type.hpp>
#include <boost_kahypar/iterator/iterator_facade.hpp>
#include <boost_kahypar/none.hpp>
#include <boost_kahypar/optional/optional.hpp>
#include <boost_kahypar/utility/result_of.hpp>

#ifdef BOOST_RESULT_OF_USE_TR1
#include <boost_kahypar/type_traits/is_function.hpp>
#endif

namespace boost_kahypar {

namespace iterators {

    template <class Function, class Input>
    class function_input_iterator;

    namespace impl {

        // Computes the return type of an lvalue-call with an empty argument,
        // i.e. decltype(declval<F&>()()). F should be a nullary lvalue-callable
        // or function.
        template <class F>
        struct result_of_nullary_lvalue_call
        {
            typedef typename result_of<
#ifdef BOOST_RESULT_OF_USE_TR1
                typename boost_kahypar::conditional<is_function<F>::value, F&, F>::type()
#else
                F&()
#endif
            >::type type;
        };

        template <class Function, class Input>
        class function_object_input_iterator :
            public iterator_facade<
                iterators::function_input_iterator<Function, Input>,
                typename result_of_nullary_lvalue_call<Function>::type,
                single_pass_traversal_tag,
                typename result_of_nullary_lvalue_call<Function>::type const &
            >
        {
        public:
            function_object_input_iterator() {}
            function_object_input_iterator(Function & f_, Input state_ = Input())
                : f(boost_kahypar::addressof(f_)), state(state_) {}

            void increment() {
                if (value)
                    value = none;
                else
                    (*f)();
                ++state;
            }

            typename result_of_nullary_lvalue_call<Function>::type const &
                dereference() const {
                if (!value)
                    value = (*f)();
                return value.get();
            }

            bool equal(function_object_input_iterator const & other) const {
                return f == other.f && state == other.state;
            }

        private:
            Function * f;
            Input state;
            mutable optional<typename result_of_nullary_lvalue_call<Function>::type> value;
        };

        template <class Function, class Input>
        class function_pointer_input_iterator :
            public iterator_facade<
                iterators::function_input_iterator<Function, Input>,
                typename function_types::result_type<Function>::type,
                single_pass_traversal_tag,
                typename function_types::result_type<Function>::type const &
            >
        {
        public:
            function_pointer_input_iterator() {}
            function_pointer_input_iterator(Function &f_, Input state_ = Input())
                : f(f_), state(state_) {}

            void increment() {
                if (value)
                    value = none;
                else
                    (*f)();
                ++state;
            }

            typename function_types::result_type<Function>::type const &
                dereference() const {
                if (!value)
                    value = (*f)();
                return value.get();
            }

            bool equal(function_pointer_input_iterator const & other) const {
                return f == other.f && state == other.state;
            }

        private:
            Function f;
            Input state;
            mutable optional<typename function_types::result_type<Function>::type> value;
        };

    } // namespace impl

    template <class Function, class Input>
    class function_input_iterator :
        public boost_kahypar::conditional<
            function_types::is_function_pointer<Function>::value,
            impl::function_pointer_input_iterator<Function,Input>,
            impl::function_object_input_iterator<Function,Input>
        >::type
    {
        typedef typename boost_kahypar::conditional<
            function_types::is_function_pointer<Function>::value,
            impl::function_pointer_input_iterator<Function,Input>,
            impl::function_object_input_iterator<Function,Input>
        >::type base_type;
    public:
        function_input_iterator(Function & f, Input i)
            : base_type(f, i) {}
    };

    template <class Function, class Input>
    inline function_input_iterator<Function, Input>
        make_function_input_iterator(Function & f, Input state) {
            typedef function_input_iterator<Function, Input> result_t;
            return result_t(f, state);
    }

    template <class Function, class Input>
    inline function_input_iterator<Function*, Input>
        make_function_input_iterator(Function * f, Input state) {
            typedef function_input_iterator<Function*, Input> result_t;
            return result_t(f, state);
    }

    struct infinite
    {
        infinite & operator++() { return *this; }
        infinite & operator++(int) { return *this; }
        bool operator==(infinite &) const { return false; };
        bool operator==(infinite const &) const { return false; };
    };

} // namespace iterators

using iterators::function_input_iterator;
using iterators::make_function_input_iterator;
using iterators::infinite;

} // namespace boost_kahypar

#endif

