#ifndef HASHING_JENKINS_H_
#define HASHING_JENKINS_H_

#include <stdint.h>
#include <stddef.h>

/// @brief 
/// @param data The data that is hashed 
/// @param length The length of the data that is hashed
/// @return an unsigned 32-bit integer 
uint32_t jenkins_one_at_a_time_hash(uint8_t const * data, size_t length);

#endif