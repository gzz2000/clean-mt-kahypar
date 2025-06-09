/*
Copyright 2018 Glen Joseph Fernandes
(glenjofe@gmail.com)

Distributed under the Boost Software License, Version 1.0.
(http://www.boost.org/LICENSE_1_0.txt)
*/
#include <boost_kahypar/config.hpp>
#if !defined(BOOST_NO_CXX11_FINAL)
#include <boost_kahypar/compressed_pair.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>

struct type1 {
    operator bool() const {
        return false;
    }
};

struct type2 final {
    operator bool() const {
        return false;
    }
};

#if !defined(BOOST_IS_FINAL)
namespace boost_kahypar {

template<>
struct is_final<type2>
    : true_type { };

} /* boost*/
#endif

template<class T1, class T2>
void test()
{
    boost_kahypar::compressed_pair<T1, T2> p;
    BOOST_TEST(!p.first());
    BOOST_TEST(!p.second());
}

int main()
{
    test<type1, type2>();
    test<type2, type1>();
    test<type2, type2>();
    return boost_kahypar::report_errors();
}
#else
int main()
{
    return 0;
}
#endif
