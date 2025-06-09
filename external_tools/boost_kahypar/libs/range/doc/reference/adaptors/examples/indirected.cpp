// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//
#include <boost_kahypar/range/adaptor/indirected.hpp>
#include <boost_kahypar/range/algorithm/copy.hpp>
#include <boost_kahypar/shared_ptr.hpp>
#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, const char* argv[])
{
    using namespace boost_kahypar::adaptors;
    
    std::vector<boost_kahypar::shared_ptr<int> > input;
    
    for (int i = 0; i < 10; ++i)
        input.push_back(boost_kahypar::shared_ptr<int>(new int(i)));
        
    boost_kahypar::copy(
        input | indirected,
        std::ostream_iterator<int>(std::cout, ","));
        
    return 0;
}

