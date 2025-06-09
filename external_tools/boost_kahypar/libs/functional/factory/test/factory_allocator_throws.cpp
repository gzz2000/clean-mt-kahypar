/*
Copyright 2019 Glen Joseph Fernandes
(glenjofe@gmail.com)

Distributed under the Boost Software License, Version 1.0.
(http://www.boost.org/LICENSE_1_0.txt)
*/
#include <boost_kahypar/functional/factory.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>
#include <boost_kahypar/smart_ptr/shared_ptr.hpp>

struct type {
    explicit type(bool b) {
        if (b) {
            throw true;
        }
    }
};

template<class T>
class creator {
public:
    static int count;

    typedef T value_type;
    typedef T* pointer;

    template<class U>
    struct rebind {
        typedef creator<U> other;
    };

    creator() { }

    template<class U>
    creator(const creator<U>&) { }

    T* allocate(std::size_t size) {
        ++count;
        return static_cast<T*>(::operator new(sizeof(T) * size));
    }

    void deallocate(T* ptr, std::size_t) {
        --count;
        ::operator delete(ptr);
    }
};

template<class T>
int creator<T>::count = 0;

template<class T, class U>
inline bool
operator==(const creator<T>&, const creator<U>&)
{
    return true;
}

template<class T, class U>
inline bool
operator!=(const creator<T>&, const creator<U>&)
{
    return false;
}

int main()
{
    bool b = true;
    try {
        boost_kahypar::shared_ptr<type> s(boost_kahypar::factory<boost_kahypar::shared_ptr<type>,
            creator<void>,
            boost_kahypar::factory_alloc_for_pointee_and_deleter>()(b));
    } catch (...) {
        BOOST_TEST(creator<type>::count == 0);
    }
    try {
        boost_kahypar::shared_ptr<type> s(boost_kahypar::factory<boost_kahypar::shared_ptr<type>,
            creator<void>,
            boost_kahypar::factory_passes_alloc_to_smart_pointer>()(b));
    } catch (...) {
        BOOST_TEST(creator<type>::count == 0);
    }
    return boost_kahypar::report_errors();
}

