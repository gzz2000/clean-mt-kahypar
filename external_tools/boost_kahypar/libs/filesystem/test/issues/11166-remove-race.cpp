#include <boost_kahypar/filesystem.hpp>
#include <boost_kahypar/thread.hpp>
#include <fstream>

boost_kahypar::condition_variable cond;
boost_kahypar::mutex mut;

#define FNAME ("remove-test")
void remover()
{
    while (1)
    {
        boost_kahypar::filesystem::remove(FNAME);
    }
}

void creater()
{
    for (int i = 0; i < 100000; i++)
        std::fstream(FNAME, std::fstream::out);
}

int main()
{
    boost_kahypar::filesystem::remove(FNAME);
    boost_kahypar::filesystem::remove(FNAME);

    std::cout << "If you got this far, it's OK to remove a file that doesn't exist\n"
                 "Now trying with one creator thread and two remover threads.\n"
                 "This is likely to crash after just a few seconds at most."
              << std::endl;

    boost_kahypar::thread c(creater), r1(remover), r2(remover);

    c.join();
    r1.interrupt();
    r1.join();
    r2.interrupt();
    r2.join();
}
