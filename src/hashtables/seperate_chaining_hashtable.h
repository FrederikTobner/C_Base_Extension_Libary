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
    struct seperate_chaining_hashtable_entry_t * nextNode;
} seperate_chaining_hashtable_entry_t;

typedef struct
{
    size_t allocated;
    size_t used;
    seperate_chaining_hashtable_entry_t ** entries;
    void (*printValue) (void* value);
} seperate_chaining_hashtable_t;

// Initializes a new hashtable
int seperate_chaining_hashtable_init_table(seperate_chaining_hashtable_t * table);

// Creates and initializes a new hashtable
seperate_chaining_hashtable_t * seperate_chaining_hashtable_new();

// Frees the memory occupied by a hashtable (does not free the memory occupied by the entries)
void seperate_chaining_hashtable_destory(seperate_chaining_hashtable_t ** table);

// Frees the memory used by the hashtable
void seperate_chaining_hashtable_free_entries(seperate_chaining_hashtable_t * table);

void seperate_chaining_hashtable_set_print_function(seperate_chaining_hashtable_t * table, void * printfunction);

// Prints out the hashtable
void seperate_chaining_hashtable_print_table(seperate_chaining_hashtable_t * table);

// Inserts a new entry into the hashtable
int seperate_chaining_hashtable_insert_entry(seperate_chaining_hashtable_entry_t * entry, seperate_chaining_hashtable_t * table);

// Removes an entry from the hashtable
seperate_chaining_hashtable_entry_t * seperate_chaining_hashtable_remove_entry(seperate_chaining_hashtable_entry_t * entry, seperate_chaining_hashtable_t * table);

// Looks up a entry in the hashtable, based on a key
seperate_chaining_hashtable_entry_t * seperate_chaining_hashtable_lookup_entry(char *key, seperate_chaining_hashtable_t * table);

#endif