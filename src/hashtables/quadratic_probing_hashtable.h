#ifndef DATA_STRUCTURES_QUADRATIC_PROBING_HASHTABLE_H
#define DATA_STRUCTURES_QUADRATIC_PROBING_HASHTABLE_H

#include <stdbool.h>
#include <stddef.h>

// Type Definition of an Entry structure in a hashtable (linear probing)
typedef struct
{
    // Key of the entry 🔑
    char const * key;
    void * value;
} quadratic_probing_hashtable_entry_t;

// Type definition of a HashTable structure using linear probing for hash collisions
typedef struct
{
    size_t allocated;
    size_t used;    
    quadratic_probing_hashtable_entry_t ** entries;
    void (*printValue) (void* value);
}  quadratic_probing_hashtable_t;

// Creates a new hashtable
int quadratic_probing_hashtable_init_table(quadratic_probing_hashtable_t * table);

// Frees the memory used by the hashtable
void quadratic_probing_hashtable_free_table(quadratic_probing_hashtable_t * table);

// Prints out the hashtable
void quadratic_probing_hashtable_print_table(quadratic_probing_hashtable_t * table);

// Inserts a new entry into the hashtable
int quadratic_probing_hashtable_insert_entry(quadratic_probing_hashtable_entry_t * entry, quadratic_probing_hashtable_t * table);

// Removes a entry from the hashtable
quadratic_probing_hashtable_entry_t * quadratic_probing_hashtable_remove_entry(quadratic_probing_hashtable_entry_t * entry, quadratic_probing_hashtable_t * table);

// Looks up a entry in the hashtable, based on a key
quadratic_probing_hashtable_entry_t * quadratic_probing_hashtable_look_up_entry(char const * key, quadratic_probing_hashtable_t * table);

void quadratic_probing_hashtable_set_print_function(quadratic_probing_hashtable_t * table, void * printfunction);

#endif