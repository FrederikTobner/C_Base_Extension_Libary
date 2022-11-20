#include "elf.h"

uint64_t ElfHash(uint8_t const * data, size_t length)
{
    uint64_t   h = 0, high;
    for (size_t i = 0; i < length; i++)
    {
         h = (h << 4) + *data++;
        if (high = h & 0xF0000000)
            h ^= high >> 24;
        h &= ~high;
    }
    return h;
}