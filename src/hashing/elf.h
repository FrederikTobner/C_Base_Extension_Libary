#ifndef HASHING_ELF_H_
#define HASHING_ELF_H_

#include <stdint.h>
#include <stddef.h>

/// @brief ELF Hashing funtion
/// @param data The data that is hashed
/// @param length The length of the data that is hashed
/// @return an unsigned 64-bit integer 
uint64_t ElfHash(uint8_t const * data, size_t length);

#endif