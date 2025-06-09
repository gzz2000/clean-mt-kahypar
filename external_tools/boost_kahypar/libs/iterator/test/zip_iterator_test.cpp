#include <boost_kahypar/tuple/tuple.hpp>

#define ZI_TUPLE      boost_kahypar::tuples::tuple
#define ZI_MAKE_TUPLE boost_kahypar::make_tuple
#define ZI_TUPLE_GET(n) boost_kahypar::tuples::get<n>
#define ZI_USE_BOOST_TUPLE

#include "detail/zip_iterator_test_original.ipp"
