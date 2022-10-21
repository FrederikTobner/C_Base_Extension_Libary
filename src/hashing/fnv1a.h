#ifndef HASHIING_FNV1A_H
#define HASHIING_FNV1A_H

#include <stdint.h>
#include <stddef.h>

// Fowler-Noll-Vo hashing function https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function

/// @brief Hashes the data using fowler noll vo (32 bit variant)
/// @param data The data that is hashed
/// @param length The length of the data that is hashed
/// @return an unsigned 32-bit integer 
uint32_t fnv1a_hash_data_32(uint8_t const * data, size_t length);

/// @brief Hashes the data using fowler noll vo (64 bit variant)
/// @param data The data that is hashed
/// @param length The length of the data that is hashed
/// @return an unsigned 64-bit integer 
uint64_t fnv1a_hash_data_64(uint8_t const * data, size_t length);

#endif