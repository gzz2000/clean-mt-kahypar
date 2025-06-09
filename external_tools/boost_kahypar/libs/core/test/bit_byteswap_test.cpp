// Test for boost/core/bit.hpp (byteswap)
//
// Copyright 2023 Peter Dimov
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#include <boost_kahypar/core/bit.hpp>
#include <boost_kahypar/core/lightweight_test.hpp>
#include <boost_kahypar/cstdint.hpp>

int main()
{
    BOOST_TEST_EQ( boost_kahypar::core::byteswap( (boost_kahypar::int8_t)0x01 ), 0x01 );
    BOOST_TEST_EQ( boost_kahypar::core::byteswap( (boost_kahypar::uint8_t)0xF1 ), 0xF1 );

    BOOST_TEST_EQ( boost_kahypar::core::byteswap( (boost_kahypar::int16_t)0x0102 ), 0x0201 );
    BOOST_TEST_EQ( boost_kahypar::core::byteswap( (boost_kahypar::uint16_t)0xF1E2 ), 0xE2F1 );

    BOOST_TEST_EQ( boost_kahypar::core::byteswap( (boost_kahypar::int32_t)0x01020304 ), 0x04030201 );
    BOOST_TEST_EQ( boost_kahypar::core::byteswap( (boost_kahypar::uint32_t)0xF1E2D3C4u ), 0xC4D3E2F1u );

    BOOST_TEST_EQ( boost_kahypar::core::byteswap( (boost_kahypar::int64_t)0x01020304 << 32 | 0x05060708 ), (boost_kahypar::int64_t)0x08070605 << 32 | 0x04030201 );
    BOOST_TEST_EQ( boost_kahypar::core::byteswap( (boost_kahypar::uint64_t)0xF1E2D3C4u << 32 | 0xB5A69788u ), (boost_kahypar::uint64_t)0x8897A6B5u << 32 | 0xC4D3E2F1u );

    return boost_kahypar::report_errors();
}
