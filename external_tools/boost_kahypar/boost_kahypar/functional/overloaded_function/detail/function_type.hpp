
// Copyright (C) 2009-2012 Lorenzo Caminiti
// Distributed under the Boost Software License, Version 1.0
// (see accompanying file LICENSE_1_0.txt or a copy at
// http://www.boost.org/LICENSE_1_0.txt)
// Home at http://www.boost.org/libs/functional/overloaded_function

#ifndef BOOST_FUNCTIONAL_OVERLOADED_FUNCTION_DETAIL_FUNCTION_TYPE_HPP_
#define BOOST_FUNCTIONAL_OVERLOADED_FUNCTION_DETAIL_FUNCTION_TYPE_HPP_

#include <boost_kahypar/function_types/is_function.hpp>
#include <boost_kahypar/function_types/is_function_pointer.hpp>
#include <boost_kahypar/function_types/is_function_reference.hpp>
#include <boost_kahypar/function_types/function_type.hpp>
#include <boost_kahypar/function_types/parameter_types.hpp>
#include <boost_kahypar/function_types/result_type.hpp>
#include <boost_kahypar/type_traits/remove_pointer.hpp>
#include <boost_kahypar/type_traits/remove_reference.hpp>
#include <boost_kahypar/function.hpp>
#include <boost_kahypar/mpl/if.hpp>
#include <boost_kahypar/mpl/identity.hpp>
#include <boost_kahypar/mpl/pop_front.hpp>
#include <boost_kahypar/mpl/push_front.hpp>
#include <boost_kahypar/typeof/typeof.hpp>

// Do not use namespace ::detail because overloaded_function is already a class.
namespace boost_kahypar { namespace overloaded_function_detail {

// Requires: F is a monomorphic functor (i.e., has non-template `operator()`).
// Returns: F's function type `result_type (arg1_type, arg2_type, ...)`.
// It does not assume F typedef result_type, arg1_type, ... but needs typeof.
template<typename F>
class functor_type {
    // NOTE: clang does not accept extra parenthesis `&(...)`.
    typedef BOOST_TYPEOF_TPL(&F::operator()) call_ptr;
public:
    typedef
        typename boost_kahypar::function_types::function_type<
            typename boost_kahypar::mpl::push_front<
                  typename boost_kahypar::mpl::pop_front< // Remove functor type (1st).
                    typename boost_kahypar::function_types::parameter_types<
                            call_ptr>::type
                  >::type
                , typename boost_kahypar::function_types::result_type<call_ptr>::type
            >::type
        >::type
    type;
};

// NOTE: When using boost_kahypar::function in Boost.Typeof emulation mode, the user
// has to register boost_kahypar::functionN instead of boost_kahypar::function in oder to
// do TYPEOF(F::operator()). That is confusing, so boost_kahypar::function is handled
// separately so it does not require any Boost.Typeof registration at all.
template<typename F>
struct functor_type< boost_kahypar::function<F> > {
    typedef F type;
};

// Requires: F is a function type, pointer, reference, or monomorphic functor.
// Returns: F's function type `result_type (arg1_type, arg2_type, ...)`.
template<typename F>
struct function_type {
    typedef
        typename boost_kahypar::mpl::if_<boost_kahypar::function_types::is_function<F>,
            boost_kahypar::mpl::identity<F>
        ,
            typename boost_kahypar::mpl::if_<boost_kahypar::function_types::
                    is_function_pointer<F>,
                boost_kahypar::remove_pointer<F>
            ,
                typename boost_kahypar::mpl::if_<boost_kahypar::function_types::
                        is_function_reference<F>,
                    boost_kahypar::remove_reference<F>
                , // Else, requires that F is a functor.
                    functor_type<F>
                >::type
            >::type
        >::type
    ::type type;
};

} } // namespace

#endif // #include guard

