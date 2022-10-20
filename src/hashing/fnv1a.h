#ifndef HASHIING_FNV1A_H
#define HASHIING_FNV1A_H

#include <stdint.h>
#include <stddef.h>

// Fowler-Noll-Vo hashing function https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function

uint32_t fnv1a_hash_data_32(char const * data, size_t length);

uint64_t fnv1a_hash_data_64(char const * data, size_t length);

#endif