#include "fnv1a.h"

#define OFFSET_BASIS32 0x811c9dc5u
#define PRIME32 0x01000193u

#define OFFSET_BASIS64 0xcbf29ce484222325 
#define PRIME64 0x00000100000001B3

uint32_t hash_data_32(char const * key, uint32_t length)
{
    uint32_t hash = OFFSET_BASIS32;
    for (uint32_t i = 0; i < length; i++)
    {
        hash ^= (uint8_t)key[i];
        hash *= PRIME32;
    }
    return hash;
}

uint64_t hash_data_64(char const * key, uint64_t length)
{
    uint64_t hash = OFFSET_BASIS64;
    for (uint64_t i = 0; i < length; i++)
    {
        hash ^= (uint8_t)key[i];
        hash *= PRIME64;
    }
    return hash;
}