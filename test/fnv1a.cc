#include <gtest/gtest.h>

#include <stdint.h>

#include "hashing.h"

TEST(FNV1A, test)
{
    uint64_t expectedHash = 0xf9e6e6ef197c2b25;
    for (size_t i = 0; i < SHA256_BLOCK_SIZE; i++)
        ASSERT_EQ(expectedHash, fnv1a_hash_data_64("test", 4));
}

TEST(FNV1A, fowler_noll_vo)
{
    uint64_t expectedHash = 0x5fa5c489307ccdaa;
    for (size_t i = 0; i < SHA256_BLOCK_SIZE; i++)
        ASSERT_EQ(expectedHash, fnv1a_hash_data_64("fowler-noll-vo", 14));
}