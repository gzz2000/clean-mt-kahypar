#include <boost_kahypar/config.hpp>

#include <boost_kahypar/fusion/include/list.hpp>
#include <boost_kahypar/fusion/include/make_list.hpp>
#include <boost_kahypar/fusion/sequence/intrinsic/at_c.hpp>

#define ZI_TUPLE      boost_kahypar::fusion::list
#define ZI_MAKE_TUPLE boost_kahypar::fusion::make_list
#define ZI_TUPLE_GET(n) boost_kahypar::fusion::at_c<n>

#include "detail/zip_iterator_test_original.ipp"
