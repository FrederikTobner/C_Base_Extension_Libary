#ifndef DATA_STRUCTURES_LINEAR_PROBING_HASHTABLE_H
#define DATA_STRUCTURES_LINEAR_PROBING_HASHTABLE_H

#include <stdbool.h>
#include <stddef.h>

// Type Definition of an Entry structure in a hashtable (linear probing)
typedef struct
{
    // Key of the entry 🔑
    char const * key;
    void * value;
} linear_probing_hashtable_entry_t;

// Type definition of a HashTable structure using linear probing for hash collisions
typedef struct
{
    size_t allocated;
    size_t used;    
    linear_probing_hashtable_entry_t ** entries;
    void (*printValue) (void* value);
} linear_probing_hashtable_t;

// Creates a new hashtable
int linear_probing_hashtable_init_table(linear_probing_hashtable_t * table);

// Frees the memory used by the hashtable
void linear_probing_hashtable_free_table(linear_probing_hashtable_t * table);

// Prints out the hashtable
void linear_probing_hashtable_print_table(linear_probing_hashtable_t * table);

// Inserts a new entry into the hashtable
int linear_probing_hashtable_insert_entry(linear_probing_hashtable_entry_t * entry, linear_probing_hashtable_t * table);

// Removes a entry from the hashtable
linear_probing_hashtable_entry_t * linear_probing_hashtable_remove_entry(linear_probing_hashtable_entry_t * entry, linear_probing_hashtable_t * table);

// Looks up a entry in the hashtable, based on a key
linear_probing_hashtable_entry_t * linear_probing_hashtable_look_up_entry(char const * key, linear_probing_hashtable_t * table);

void linear_probing_hashtable_set_print_function(linear_probing_hashtable_t * table, void * printfunction);

#endif