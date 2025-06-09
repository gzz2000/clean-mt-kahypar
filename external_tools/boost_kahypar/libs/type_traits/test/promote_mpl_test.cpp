// Copyright 2005 Alexander Nasonov.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost_kahypar/mpl/at.hpp>
#include <boost_kahypar/mpl/lambda.hpp>
#include <boost_kahypar/mpl/placeholders.hpp>
#include <boost_kahypar/mpl/transform.hpp>
#include <boost_kahypar/mpl/vector.hpp>
#include <boost_kahypar/static_assert.hpp>
#include <boost_kahypar/type_traits/is_same.hpp>
#include <boost_kahypar/type_traits/promote.hpp>

namespace mpl = boost_kahypar::mpl;

int main()
{
    using namespace mpl::placeholders;

    typedef mpl::vector< char
                       , signed char          // 1
                       , unsigned char
                       , short int const      // 3
                       , unsigned short int
                       , int volatile         // 5
                       , unsigned int         // 6
                       , long                 // 7
                       , unsigned long        // 8
                       , float const          // 9
                       > types;

    typedef mpl::transform< types
                          , mpl::lambda< boost_kahypar::promote<_> >::type
                          >::type promoted;

    BOOST_STATIC_ASSERT(( ::boost_kahypar::is_same< mpl::at_c<promoted,1>::type, int           >::value ));
    BOOST_STATIC_ASSERT(( ::boost_kahypar::is_same< mpl::at_c<promoted,3>::type, int const     >::value ));
    BOOST_STATIC_ASSERT(( ::boost_kahypar::is_same< mpl::at_c<promoted,5>::type, int volatile  >::value ));
    BOOST_STATIC_ASSERT(( ::boost_kahypar::is_same< mpl::at_c<promoted,6>::type, unsigned int  >::value ));
    BOOST_STATIC_ASSERT(( ::boost_kahypar::is_same< mpl::at_c<promoted,7>::type, long          >::value ));
    BOOST_STATIC_ASSERT(( ::boost_kahypar::is_same< mpl::at_c<promoted,8>::type, unsigned long >::value ));
    BOOST_STATIC_ASSERT(( ::boost_kahypar::is_same< mpl::at_c<promoted,9>::type, double const  >::value ));

    return 0;
}

