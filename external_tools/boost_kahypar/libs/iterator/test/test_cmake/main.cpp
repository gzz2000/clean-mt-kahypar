//  Copyright (c) 2023 Andrey Semashev
//
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  https://www.boost.org/LICENSE_1_0.txt)

#include <boost_kahypar/generator_iterator.hpp>
#include <boost_kahypar/indirect_reference.hpp>
#include <boost_kahypar/next_prior.hpp>
#include <boost_kahypar/pointee.hpp>
#include <boost_kahypar/shared_container_iterator.hpp>
#include <boost_kahypar/iterator/advance.hpp>
#include <boost_kahypar/iterator/counting_iterator.hpp>
#include <boost_kahypar/iterator/distance.hpp>
#include <boost_kahypar/iterator/filter_iterator.hpp>
#include <boost_kahypar/iterator/function_input_iterator.hpp>
#include <boost_kahypar/iterator/function_output_iterator.hpp>
#include <boost_kahypar/iterator/indirect_iterator.hpp>
#include <boost_kahypar/iterator/interoperable.hpp>
#include <boost_kahypar/iterator/is_iterator.hpp>
#include <boost_kahypar/iterator/is_lvalue_iterator.hpp>
#include <boost_kahypar/iterator/is_readable_iterator.hpp>
#include <boost_kahypar/iterator/iterator_adaptor.hpp>
#include <boost_kahypar/iterator/iterator_archetypes.hpp>
#include <boost_kahypar/iterator/iterator_categories.hpp>
#include <boost_kahypar/iterator/iterator_concepts.hpp>
#include <boost_kahypar/iterator/iterator_facade.hpp>
#include <boost_kahypar/iterator/iterator_traits.hpp>
#include <boost_kahypar/iterator/minimum_category.hpp>
#include <boost_kahypar/iterator/new_iterator_tests.hpp>
#include <boost_kahypar/iterator/permutation_iterator.hpp>
#include <boost_kahypar/iterator/reverse_iterator.hpp>
#include <boost_kahypar/iterator/transform_iterator.hpp>
#include <boost_kahypar/iterator/zip_iterator.hpp>

template< typename Iterator >
class adapted_iterator :
    public boost_kahypar::iterators::iterator_adaptor< adapted_iterator< Iterator >, Iterator >
{
    friend class iterator_core_access;

private:
    typedef boost_kahypar::iterators::iterator_adaptor< adapted_iterator< Iterator >, Iterator > base_type;

public:
    explicit adapted_iterator(Iterator it) : base_type(it) {}
};

int main()
{
    unsigned char buf[8];
    adapted_iterator< unsigned char* > b(buf), e(buf + sizeof(buf));
    return boost_kahypar::iterators::distance(b, e) == static_cast< adapted_iterator< unsigned char* >::difference_type >(sizeof(buf));
}
