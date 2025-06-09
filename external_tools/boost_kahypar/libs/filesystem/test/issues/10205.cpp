// Linux test; before running: export LANG=foo

#include <locale>
#include <iostream>
#include <string>
#include <boost_kahypar/filesystem/path.hpp>

int main()
{
    std::string pathname = "/some/filesystem/path/%%%%";

    boost_kahypar::filesystem::path path(pathname);

    std::wcout << path.wstring() << std::endl;

    return 0;
}
