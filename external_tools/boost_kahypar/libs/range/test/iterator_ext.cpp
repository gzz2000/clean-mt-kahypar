// Boost.Range library
//
//  Copyright Neil Groves 2014. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//

#include <boost_kahypar/range/iterator.hpp>
#include <boost_kahypar/static_assert.hpp>
#include <boost_kahypar/type_traits/is_same.hpp>
#include <boost_kahypar/type_traits/is_base_of.hpp>
#include <boost_kahypar/type_traits/decay.hpp>

#include <boost_kahypar/test/test_tools.hpp>
#include <boost_kahypar/test/unit_test.hpp>

#include <vector>

namespace boost_kahypar_range_test
{

struct point
{
    int x;
    int y;
};

class shape
{
public:
    virtual ~shape()
    {
    }

    const std::vector<point>& points() const
    {
        return m_points;
    }

private:
    std::vector<point> m_points;
};

class rectangle : public shape
{
};

class circle : public shape
{
};

class container
{
    typedef std::vector<point> impl_t;
};

} // namespace boost_kahypar_range_test

namespace boost_kahypar
{
    template<typename T>
    struct range_mutable_iterator<
            T,
            typename boost_kahypar::enable_if<
                boost_kahypar::is_base_of<
                    boost_kahypar_range_test::shape,
                    typename boost_kahypar::remove_reference<
                        typename boost_kahypar::remove_cv<T>::type
                    >::type
                >
            >::type
        >
    {
        typedef std::vector<boost_kahypar_range_test::point>::iterator type;
    };

    template<typename T>
    struct range_const_iterator<
            T,
            typename boost_kahypar::enable_if<
                boost_kahypar::is_base_of<
                    boost_kahypar_range_test::shape,
                    typename boost_kahypar::remove_reference<
                        typename boost_kahypar::remove_cv<T>::type
                    >::type
                >
            >::type
        >
    {
        typedef std::vector<boost_kahypar_range_test::point>::const_iterator type;
    };

    template<>
    struct range_mutable_iterator<boost_kahypar_range_test::container>
    {
        typedef std::vector<boost_kahypar_range_test::point>::iterator type;
    };

    template<>
    struct range_const_iterator<boost_kahypar_range_test::container>
    {
        typedef std::vector<boost_kahypar_range_test::point>::const_iterator type;
    };
}

namespace boost_kahypar_range_test
{
    template<typename Shape>
    void test_iterator_impl()
    {
        BOOST_STATIC_ASSERT((
            boost_kahypar::is_same<
                std::vector<point>::iterator,
                typename boost_kahypar::range_iterator<Shape>::type
            >::value));

        BOOST_STATIC_ASSERT((
            boost_kahypar::is_same<
                std::vector<point>::const_iterator,
                typename boost_kahypar::range_iterator<const Shape>::type
            >::value));

    #ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
        BOOST_STATIC_ASSERT((
            boost_kahypar::is_same<
                std::vector<point>::iterator,
                typename boost_kahypar::range_iterator<Shape&&>::type
            >::value));
    #endif
    }

    void test_iterator()
    {
        test_iterator_impl<shape>();
        test_iterator_impl<rectangle>();
        test_iterator_impl<circle>();

        test_iterator_impl<container>();
    }
} // namespace boost_kahypar_range_test

boost_kahypar::unit_test::test_suite* init_unit_test_suite( int argc, char* argv[] )
{
    boost_kahypar::unit_test::test_suite* test =
        BOOST_TEST_SUITE("Boost.Range range_iterator meta-function");

    test->add(BOOST_TEST_CASE(&boost_kahypar_range_test::test_iterator));

    return test;
}
