/*=============================================================================
    Copyright (c) 2007 Tobias Schwinger
  
    Use modification and distribution are subject to the Boost Software 
    License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
    http://www.boost.org/LICENSE_1_0.txt).
==============================================================================*/

#include <boost_kahypar/config.hpp>

#ifdef BOOST_MSVC
#   pragma warning(disable: 4244) // no conversion warnings, please
#endif

#include <boost_kahypar/core/lightweight_test.hpp>
#include <boost_kahypar/functional/lightweight_forward_adapter.hpp>

#include <boost_kahypar/type_traits/is_same.hpp>

#include <boost_kahypar/blank.hpp>
#include <boost_kahypar/noncopyable.hpp>

#include <memory>

template <class Base = boost_kahypar::blank>
class test_func : public Base 
{
    int val;
public:
    test_func(int v) : val(v) { }

    template<class B>
    test_func(test_func<B> const & that)
      : val(that.val)
    { }

    template<class B> friend class test_func;

    int operator()(int & l, int const & r) const
    {
        return l=r+val;
    }
    long operator()(int & l, int const & r) 
    {
        return -(l=r+val);
    }
    char operator()(int & l, int & r)
    {
        return l=r+val;
    }

    template <typename Sig>
    struct result
    {
        typedef void type;
    };

    // ensure result_of argument types are what's expected
    // note: this is *not* how client code should look like 
    template <class Self>
    struct result< Self const(int&,int const&) > { typedef int type; };

    template <class Self>
    struct result< Self(int&,int const&) > { typedef long type; };

    template <class Self>
    struct result< Self(int&,int&) > { typedef char type; };
};

enum { int_, long_, char_ };

int type_of(int)  { return int_; }
int type_of(long) { return long_; }
int type_of(char) { return char_; }

int main()
{
    {
        using boost_kahypar::is_same;
        using boost_kahypar::result_of;
        typedef boost_kahypar::lightweight_forward_adapter< test_func<> > f;
        typedef boost_kahypar::reference_wrapper<int> ref;
        typedef boost_kahypar::reference_wrapper<int const> cref;

        // lvalue,rvalue
        BOOST_TEST(( is_same<
            result_of< f(ref, int) >::type, long >::value ));
        BOOST_TEST(( is_same<
            result_of< f const (ref, int) >::type, int >::value ));
        // lvalue,const lvalue
        BOOST_TEST(( is_same<
            result_of< f(ref, cref) >::type, long >::value ));
        BOOST_TEST(( is_same<
            result_of< f const (ref, cref) >::type, int >::value ));
        // lvalue,lvalue
        BOOST_TEST(( is_same<
            result_of< f(ref, ref) >::type, char >::value ));
        // result_of works differently for C++11 here, so compare
        // with using it against test_func.
        BOOST_TEST(( is_same<
            result_of< f const (ref, ref) >::type,
            result_of< test_func<> const (int&, int&) >::type >::value ));
    }
    {
        using boost_kahypar::noncopyable;
        using boost_kahypar::lightweight_forward_adapter;

        int v = 0; boost_kahypar::reference_wrapper<int> x(v);
        test_func<noncopyable> f(7);
        lightweight_forward_adapter< test_func<> > func(f);
        lightweight_forward_adapter< test_func<noncopyable> & > func_ref(f);
        lightweight_forward_adapter< test_func<noncopyable> & > const func_ref_c(f);
        lightweight_forward_adapter< test_func<> const > func_c(f);
        lightweight_forward_adapter< test_func<> > const func_c2(f);
        lightweight_forward_adapter< test_func<noncopyable> const & > func_c_ref(f);

        BOOST_TEST( type_of( func(x,1) ) == long_ );
        BOOST_TEST( type_of( func_ref(x,1) ) == long_ );
        BOOST_TEST( type_of( func_ref_c(x,1) ) == long_ );
        BOOST_TEST( type_of( func_c(x,1) ) == int_ );
        BOOST_TEST( type_of( func_c2(x,1) ) == int_ );
        BOOST_TEST( type_of( func_c_ref(x,1) ) == int_ );
        BOOST_TEST( type_of( func(x,x) ) == char_ );

        BOOST_TEST( func(x,1) == -8 );
        BOOST_TEST( func_ref(x,1) == -8 );
        BOOST_TEST( func_ref_c(x,1) == -8 );
        BOOST_TEST( func_c(x,1) == 8 );
        BOOST_TEST( func_c2(x,1) == 8 );
        BOOST_TEST( func_c_ref(x,1) == 8 );
    }

    return boost_kahypar::report_errors();
}

