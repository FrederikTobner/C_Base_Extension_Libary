#ifndef HASHIING_FNV1A_H
#define HASHIING_FNV1A_H

#include <stdint.h>

uint32_t hash_data_32(char const * key, uint32_t length);

uint64_t hash_data_64(char const * key, uint64_t length);

#endif