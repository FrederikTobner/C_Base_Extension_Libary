#include <gtest/gtest.h>

#include <stdint.h>

#include "hashing.h"

TEST(FNV1A, test)
{
    uint64_t expectedHash = 0xf9e6e6ef197c2b25;
    ASSERT_EQ(expectedHash, fnv1a_hash_data_64((uint8_t const *)"test", 4));
}

TEST(FNV1A, fowler_noll_vo)
{
    uint64_t expectedHash = 0x5fa5c489307ccdaa;
    ASSERT_EQ(expectedHash, fnv1a_hash_data_64((uint8_t const *)"fowler-noll-vo", 14));
}