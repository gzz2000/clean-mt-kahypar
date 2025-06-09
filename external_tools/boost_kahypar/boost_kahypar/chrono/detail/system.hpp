//  Copyright 2009-2010 Vicente J. Botet Escriba

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef BOOST_CHRONO_DETAIL_SYSTEM_HPP
#define BOOST_CHRONO_DETAIL_SYSTEM_HPP

#if !defined BOOST_CHRONO_DONT_PROVIDE_HYBRID_ERROR_HANDLING

#include <boost_kahypar/system/error_code.hpp>

namespace boost_kahypar {
namespace chrono {
    inline bool is_throws(system::error_code  & ec) { return (&ec==&boost_kahypar::throws()); }
}
}

#endif
#endif
