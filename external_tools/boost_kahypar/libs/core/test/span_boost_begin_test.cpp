/*
Copyright 2022 Glen Joseph Fernandes
(glenjofe@gmail.com)

Distributed under the Boost Software License, Version 1.0.
(http://www.boost.org/LICENSE_1_0.txt)
*/
#include <boost_kahypar/config.hpp>
#if !defined(BOOST_NO_CXX11_CONSTEXPR) && !defined(BOOST_NO_CXX11_DECLTYPE)
#include <boost_kahypar/core/span.hpp>
#include <vector>

namespace boost_kahypar {
namespace begin_ {

template<class T>
void begin(T&) { }

} // begin_

using namespace begin_;

} // boost

template class boost_kahypar::span<float>;

void function()
{
    std::vector<int> y;
    boost_kahypar::begin(y);
}
#endif
