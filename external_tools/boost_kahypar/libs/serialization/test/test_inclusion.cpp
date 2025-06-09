/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// test_const.cpp

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com .
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost_kahypar/serialization/access.hpp>
#include <boost_kahypar/serialization/base_object.hpp>
#include <boost_kahypar/serialization/export.hpp>
#include <boost_kahypar/serialization/level.hpp>
#include <boost_kahypar/serialization/level_enum.hpp>
#include <boost_kahypar/serialization/nvp.hpp>
#include <boost_kahypar/serialization/split_free.hpp>
#include <boost_kahypar/serialization/split_member.hpp>
#include <boost_kahypar/serialization/tracking.hpp>
#include <boost_kahypar/serialization/tracking_enum.hpp>
#include <boost_kahypar/serialization/traits.hpp>
#include <boost_kahypar/serialization/type_info_implementation.hpp>
#include <boost_kahypar/serialization/singleton.hpp>

struct foo
{
    int x;
private:
    friend class boost_kahypar::serialization::access;

    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        // In compilers implementing 2-phase lookup, the call to
        // make_nvp is resolved even if foo::serialize() is never
        // instantiated.
        ar & boost_kahypar::serialization::make_nvp("x",x);
    }
};

int
main(int /*argc*/, char * /*argv*/[]){
    return 0;
}
