// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//


#include <boost_kahypar/detail/workaround.hpp>

#if BOOST_WORKAROUND(BOOST_BORLANDC, BOOST_TESTED_AT(0x564))
#  pragma warn -8091 // suppress warning in Boost.Test
#  pragma warn -8057 // unused argument argc/argv in Boost.Test
#endif

#include <boost_kahypar/range.hpp>
#include <boost_kahypar/test/test_tools.hpp>
#include <boost_kahypar/test/unit_test.hpp>
#include <boost_kahypar/static_assert.hpp>
#include <boost_kahypar/cstdint.hpp>
#include <list>
#include <vector>

namespace boost_kahypar_range_extension_size_test
{
    class FooWithoutSize
    {
        typedef std::list<int> impl_t;
        
        BOOST_STATIC_ASSERT((
            boost_kahypar::is_same<
                boost_kahypar::range_size<std::list<int> >::type,
                std::list<int>::size_type
            >::value));
        
        typedef impl_t::const_iterator const_iterator;
        typedef impl_t::iterator iterator;

    public:
        friend inline const_iterator range_begin(const FooWithoutSize& obj) { return obj.m_impl.begin(); }
        friend inline iterator range_begin(FooWithoutSize& obj) { return obj.m_impl.begin(); }
        friend inline const_iterator range_end(const FooWithoutSize& obj) { return obj.m_impl.end(); }
        friend inline iterator range_end(FooWithoutSize& obj){ return obj.m_impl.end(); }

    private:
        impl_t m_impl;
    };
    
    template<typename SizeType>
    class FooWithSize
    {
    public:
        typedef SizeType size_type;
        typedef boost_kahypar::uint8_t* iterator;
        typedef const boost_kahypar::uint8_t* const_iterator;
        
        const_iterator begin() const;
        iterator begin();
        const_iterator end() const;
        iterator end();
    };
    
    BOOST_STATIC_ASSERT((
        boost_kahypar::is_same<
            boost_kahypar::uint8_t,
            boost_kahypar::range_size<FooWithSize<boost_kahypar::uint8_t> >::type
        >::value
    ));
    
    BOOST_STATIC_ASSERT((
        boost_kahypar::is_same<
            boost_kahypar::uint16_t,
            boost_kahypar::range_size<FooWithSize<boost_kahypar::uint16_t> >::type
        >::value
    ));
    
    BOOST_STATIC_ASSERT((
        boost_kahypar::is_same<
            boost_kahypar::uint32_t,
            boost_kahypar::range_size<FooWithSize<boost_kahypar::uint32_t> >::type
        >::value
    ));
    
    BOOST_STATIC_ASSERT((
        boost_kahypar::is_same<
            boost_kahypar::uint64_t,
            boost_kahypar::range_size<FooWithSize<boost_kahypar::uint64_t> >::type
        >::value
    ));
    
    class UdtSizeType
    {
    public:
        typedef boost_kahypar::uint16_t value_type;
        
        UdtSizeType() : value_(0) { }
        UdtSizeType(value_type value) : value_(value) { }
        
        operator value_type() const { return value_; }
        
    private:
        value_type value_;
    };
    
    BOOST_STATIC_ASSERT((
        boost_kahypar::is_same<
            UdtSizeType,
            boost_kahypar::range_size<FooWithSize<UdtSizeType> >::type
        >::value
    ));
    
    class Foo2WithoutSize
    {
    public:
        struct const_iterator
        {
            typedef std::forward_iterator_tag iterator_category;
            typedef boost_kahypar::int8_t difference_type;
            typedef boost_kahypar::int16_t value_type;
            typedef value_type* pointer;
            typedef value_type& reference;
            
            reference operator*() const;
            pointer operator->() const;
            const_iterator& operator++();
            const_iterator operator++(int);
            bool operator==(const const_iterator&) const;
            bool operator!=(const const_iterator&) const;
        };
        
        struct iterator : const_iterator
        {
            typedef const value_type* pointer;
            typedef const value_type& reference;
            
            reference operator*() const;
            pointer operator->() const;
            
            iterator& operator++();
            iterator operator++(int);
            
            bool operator==(const iterator&) const;
            bool operator!=(const iterator&) const;
        };
        
        const_iterator begin() const;
        iterator begin();
        const_iterator end() const;
        iterator end();
    };
    
    BOOST_STATIC_ASSERT((
        boost_kahypar::is_same<
            boost_kahypar::uint8_t,
            boost_kahypar::range_size<
                ::boost_kahypar_range_extension_size_test::Foo2WithoutSize>::type
        >::value
    ));
}

namespace boost_kahypar
{
    template<> struct range_iterator<const ::boost_kahypar_range_extension_size_test::FooWithoutSize>
    {
        typedef std::list<int>::const_iterator type;
    };

    template<> struct range_iterator< ::boost_kahypar_range_extension_size_test::FooWithoutSize>
    {
        typedef std::list<int>::iterator type;
    };
}

namespace boost_kahypar_range_extension_size_test
{
    inline boost_kahypar::range_size<FooWithoutSize>::type
    range_calculate_size(const FooWithoutSize& rng)
    {
        return 2u;
    }
}

BOOST_STATIC_ASSERT((
    boost_kahypar::is_same<
        boost_kahypar::make_unsigned<std::ptrdiff_t>::type,
        boost_kahypar::range_size<
                    boost_kahypar_range_extension_size_test::FooWithoutSize>::type
    >::value
));

typedef boost_kahypar::make_unsigned<std::ptrdiff_t>::type t1;
typedef boost_kahypar::range_size<boost_kahypar_range_extension_size_test::FooWithoutSize>::type t1;

namespace
{

void check_size_works_with_random_access()
{
    std::vector<int> container;
    container.push_back(1);
    BOOST_CHECK_EQUAL( boost_kahypar::size(container), 1u );
}

void check_extension_size()
{
    BOOST_CHECK_EQUAL( boost_kahypar::size(boost_kahypar_range_extension_size_test::FooWithoutSize()), 2u );
}

} // anonymous namespace

using boost_kahypar::unit_test::test_suite;

test_suite* init_unit_test_suite( int argc, char* argv[] )
{
    test_suite* test = BOOST_TEST_SUITE( "Range Test Suite" );

    test->add( BOOST_TEST_CASE( &check_size_works_with_random_access ));
    test->add( BOOST_TEST_CASE( &check_extension_size ) );

    return test;
}
