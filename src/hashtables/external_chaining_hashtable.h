#ifndef DATA_STRUCTURES_EXTERNAL_CHAINING_HASHTABLE_H
#define DATA_STRUCTURES_EXTERNAL_CHAINING_HASHTABLE_H

#include <stddef.h>
#include <stdbool.h>
typedef struct
{
    // Key of the entry 🔑
    char const * key;
    // Pointer to the value stored in the entry
    void * value;
    struct external_chaining_hashtable_entry_t * nextNode;
} external_chaining_hashtable_entry_t;

typedef struct
{
    size_t allocated;
    size_t used;
    external_chaining_hashtable_entry_t ** entries;
    void (*printValue) (void* value);
} external_chaining_hashtable_t;

// Creates a new hashtable
int external_chaining_hashtable_init_table(external_chaining_hashtable_t * table);

// Frees the memory used by the hashtable
void external_chaining_hashtable_free_table(external_chaining_hashtable_t * table);

void external_chaining_hashtable_set_print_function(external_chaining_hashtable_t * table, void * printfunction);

// Prints out the hashtable
void external_chaining_hashtable_print_table(external_chaining_hashtable_t * table);

// Inserts a new entry into the hashtable
int external_chaining_hashtable_insert_entry(external_chaining_hashtable_entry_t * entry, external_chaining_hashtable_t * table);

// Removes an entry from the hashtable
external_chaining_hashtable_entry_t * external_chaining_hashtable_remove_entry(external_chaining_hashtable_entry_t * entry, external_chaining_hashtable_t * table);

// Looks up a entry in the hashtable, based on a key
external_chaining_hashtable_entry_t * external_chaining_hashtable_lookup_entry(char *key, external_chaining_hashtable_t * table);

#endif