#include <iostream>
#include <boost_kahypar/filesystem.hpp>
using boost_kahypar::filesystem::path;

int main()
{
    std::cout << path("a").stem() << std::endl;
    std::cout << path("a/").stem() << std::endl;
    std::cout << path("a/b").stem() << std::endl;
    std::cout << path("a/b/").stem() << std::endl;
    std::cout << path("a/b/c").stem() << std::endl;
    std::cout << path("a/b/c/").stem() << std::endl;
    std::cout << path("a/b/c/d").stem() << std::endl;
    std::cout << path("a/b/c/d/").stem() << std::endl;
    std::cout << path("a/b/c/d/e").stem() << std::endl;
    std::cout << path("a/b/c/d/e/").stem() << std::endl;
    return 0;
}
