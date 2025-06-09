/*
Copyright 2019 Glen Joseph Fernandes
(glenjofe@gmail.com)

Distributed under the Boost Software License, Version 1.0.
(http://www.boost.org/LICENSE_1_0.txt)
*/
#include <boost_kahypar/functional/factory.hpp>
#include <boost_kahypar/core/default_allocator.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>
#include <boost_kahypar/smart_ptr/shared_ptr.hpp>
#include <boost_kahypar/config.hpp>
#include <exception>

#if defined(BOOST_NO_EXCEPTIONS)
namespace boost_kahypar {

BOOST_NORETURN void throw_exception(const std::exception&)
{
    std::terminate();
}

}
#endif

class sum  {
public:
    sum(int a, int b)
        : value_(a + b) { }

    int get() const {
        return value_;
    }

private:
    int value_;
};

int main()
{
    int a = 1;
    int b = 2;
    {
        boost_kahypar::shared_ptr<sum> s(boost_kahypar::factory<boost_kahypar::shared_ptr<sum>,
            boost_kahypar::default_allocator<void>,
            boost_kahypar::factory_alloc_for_pointee_and_deleter>()(a, b));
        BOOST_TEST(s->get() == 3);
    }
    {
        boost_kahypar::shared_ptr<sum> s(boost_kahypar::factory<boost_kahypar::shared_ptr<sum>,
            boost_kahypar::default_allocator<void>,
            boost_kahypar::factory_passes_alloc_to_smart_pointer>()(a, b));
        BOOST_TEST(s->get() == 3);
    }
    return boost_kahypar::report_errors();
}
