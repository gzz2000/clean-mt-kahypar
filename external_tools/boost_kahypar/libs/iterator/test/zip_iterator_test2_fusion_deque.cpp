#include <boost_kahypar/fusion/include/deque.hpp>
#include <boost_kahypar/fusion/include/make_deque.hpp>
#include <boost_kahypar/fusion/sequence/intrinsic/at_c.hpp>

#define ZI_TUPLE      boost_kahypar::fusion::deque
#define ZI_MAKE_TUPLE boost_kahypar::fusion::make_deque
#define ZI_TUPLE_GET(n) boost_kahypar::fusion::at_c<n>

#include "detail/zip_iterator_test_original.ipp"
