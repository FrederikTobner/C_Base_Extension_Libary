#include "fnv1a.h"

#define OFFSET_BASIS32 0x811c9dc5u
#define PRIME32 0x01000193u

#define OFFSET_BASIS64 0xcbf29ce484222325 
#define PRIME64 0x00000100000001B3

uint32_t fnv1a_hash_data_32(uint8_t const * data, size_t length)
{
    uint32_t hash = OFFSET_BASIS32;
    for (size_t i = 0; i < length; i++)
    {
        hash ^= data[i];
        hash *= PRIME32;
    }
    return hash;
}

uint64_t fnv1a_hash_data_64(uint8_t const * data, size_t length)
{
    uint64_t hash = OFFSET_BASIS64;
    for (size_t i = 0; i < length; i++)
    {
        hash ^= data[i];
        hash *= PRIME64;
    }
    return hash;
}