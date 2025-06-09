#include <boost_kahypar/filesystem.hpp>
#include <boost_kahypar/range.hpp>
#include <boost_kahypar/range/algorithm.hpp>
#include <boost_kahypar/range/adaptors.hpp>
#include <vector>
#include <iostream>

namespace fs = boost_kahypar::filesystem;
using namespace boost_kahypar::adaptors;

int main()
{
    fs::recursive_directory_iterator beg("."), end;

    auto fileFilter = [](fs::path const& path) {
        return is_regular_file(path);
    };

    std::vector< fs::path > paths;
    copy(boost_kahypar::make_iterator_range(beg, end) | filtered(fileFilter), std::back_inserter(paths));

    for (auto& p : paths)
        std::cout << p << "\n";
}