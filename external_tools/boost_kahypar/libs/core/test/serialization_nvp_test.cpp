// Copyright 2023 Peter Dimov
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#if defined(__clang__) && defined(__has_warning)
# if __has_warning( "-Wdeprecated-copy" )
#  pragma clang diagnostic ignored "-Wdeprecated-copy"
# endif
#endif

#include <boost_kahypar/core/serialization.hpp>

struct X
{
    int a, b;

    template<class Ar> void serialize( Ar& ar, unsigned /*v*/ )
    {
        ar & boost_kahypar::core::make_nvp( "a", a );
        ar & boost_kahypar::core::make_nvp( "b", b );
    }
};

#include <boost_kahypar/archive/xml_oarchive.hpp>
#include <boost_kahypar/archive/xml_iarchive.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>
#include <sstream>
#include <string>

int main()
{
    std::ostringstream os;

    X x1 = { 7, 11 };

    {
        boost_kahypar::archive::xml_oarchive ar( os );
        ar << boost_kahypar::core::make_nvp( "x1", x1 );
    }

    std::string s = os.str();

    X x2 = { 0, 0 };

    {
        std::istringstream is( s );
        boost_kahypar::archive::xml_iarchive ar( is );
        ar >> boost_kahypar::make_nvp( "x2", x2 );
    }

    BOOST_TEST_EQ( x1.a, x2.a );
    BOOST_TEST_EQ( x1.b, x2.b );

    return boost_kahypar::report_errors();
}
