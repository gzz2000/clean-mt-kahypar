// Copyright David Abrahams and Aleksey Gurtovoy
// 2002-2004. Distributed under the Boost Software License, Version
// 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// compile-time test for "boost_kahypar/core/ref.hpp" header content
// see 'ref_test.cpp' for run-time part

#include <boost_kahypar/core/ref.hpp>
#include <boost_kahypar/static_assert.hpp>
#include <boost_kahypar/config/workaround.hpp>
#include <boost_kahypar/type_traits/is_same.hpp>

namespace {

template< typename T, typename U >
void ref_test(boost_kahypar::reference_wrapper<U>)
{
    typedef typename boost_kahypar::reference_wrapper<U>::type type;
    BOOST_STATIC_ASSERT((boost_kahypar::is_same<U,type>::value));
    BOOST_STATIC_ASSERT((boost_kahypar::is_same<T,type>::value));
}

template< typename T >
void assignable_test_(T x1, T x2)
{
    x1 = x2;
}

template< typename T >
void assignable_test(T x)
{
    assignable_test_( x, x );
}

template< bool R, typename T >
void is_reference_wrapper_test(T)
{
    BOOST_STATIC_ASSERT(boost_kahypar::is_reference_wrapper<T>::value == R);
}

template< typename R, typename Ref >
void cxx_reference_test(Ref)
{
    BOOST_STATIC_ASSERT((boost_kahypar::is_same<R,Ref>::value));
}

template< typename R, typename Ref >
void unwrap_reference_test(Ref)
{
    typedef typename boost_kahypar::unwrap_reference<Ref>::type type;
    BOOST_STATIC_ASSERT((boost_kahypar::is_same<R,type>::value));
}

} // namespace

int main()
{
    int i = 0;
    int& ri = i;

    int const ci = 0;
    int const& rci = ci;

    // 'ref/cref' functions test
    ref_test<int>(boost_kahypar::ref(i));
    ref_test<int>(boost_kahypar::ref(ri));
    ref_test<int const>(boost_kahypar::ref(ci));
    ref_test<int const>(boost_kahypar::ref(rci));

    ref_test<int const>(boost_kahypar::cref(i));
    ref_test<int const>(boost_kahypar::cref(ri));
    ref_test<int const>(boost_kahypar::cref(ci));
    ref_test<int const>(boost_kahypar::cref(rci));

    // test 'assignable' requirement
    assignable_test(boost_kahypar::ref(i));
    assignable_test(boost_kahypar::ref(ri));
    assignable_test(boost_kahypar::cref(i));
    assignable_test(boost_kahypar::cref(ci));
    assignable_test(boost_kahypar::cref(rci));

    // 'is_reference_wrapper' test
    is_reference_wrapper_test<true>(boost_kahypar::ref(i));
    is_reference_wrapper_test<true>(boost_kahypar::ref(ri));
    is_reference_wrapper_test<true>(boost_kahypar::cref(i));
    is_reference_wrapper_test<true>(boost_kahypar::cref(ci));
    is_reference_wrapper_test<true>(boost_kahypar::cref(rci));

    is_reference_wrapper_test<false>(i);
    is_reference_wrapper_test<false, int&>(ri);
    is_reference_wrapper_test<false>(ci);
    is_reference_wrapper_test<false, int const&>(rci);

    // ordinary references/function template arguments deduction test
    cxx_reference_test<int>(i);
    cxx_reference_test<int>(ri);
    cxx_reference_test<int>(ci);
    cxx_reference_test<int>(rci);

    cxx_reference_test<int&, int&>(i);
    cxx_reference_test<int&, int&>(ri);
    cxx_reference_test<int const&, int const&>(i);
    cxx_reference_test<int const&, int const&>(ri);
    cxx_reference_test<int const&, int const&>(ci);
    cxx_reference_test<int const&, int const&>(rci);

    // 'unwrap_reference' test
    unwrap_reference_test<int>(boost_kahypar::ref(i));
    unwrap_reference_test<int>(boost_kahypar::ref(ri));
    unwrap_reference_test<int const>(boost_kahypar::cref(i));
    unwrap_reference_test<int const>(boost_kahypar::cref(ci));
    unwrap_reference_test<int const>(boost_kahypar::cref(rci));

    unwrap_reference_test<int>(i);
    unwrap_reference_test<int>(ri);
    unwrap_reference_test<int>(ci);
    unwrap_reference_test<int>(rci);
    unwrap_reference_test<int&, int&>(i);
    unwrap_reference_test<int&, int&>(ri);
    unwrap_reference_test<int const&, int const&>(i);
    unwrap_reference_test<int const&, int const&>(ri);
    unwrap_reference_test<int const&, int const&>(ci);
    unwrap_reference_test<int const&, int const&>(rci);

    return 0;
}
