#pragma once

#include <cstdint>

// Unsigned integers
using unsinged64int = uint64_t;
using unsigned32int = uint32_t;
using unsinged16int = uint16_t;
using unsigned8bit = uint8_t;

// Singed integers
using int64 = int64_t;
using int32 = int32_t;
using int16 = int16_t;
using int8 = int8_t;

constexpr unsinged64int outOfBoundsUnsignedInt64 {0xffff'ffff'ffff'ffffull};
constexpr unsigned32int outOfBoundsUnsignedInt32 {0xffff'fffful};
constexpr unsinged16int outOfBoundsUnsignedInt16 {0xffff};
constexpr unsigned8bit outOfBoundsUnsignedInt8 {0xff};

