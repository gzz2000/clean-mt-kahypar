// Before running this test: export LANG=foo

#include <boost_kahypar/filesystem.hpp>
int main()
{
    boost_kahypar::filesystem::path("/abc").root_directory();
}
