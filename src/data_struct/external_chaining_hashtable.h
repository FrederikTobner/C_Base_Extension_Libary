#ifndef DATA_STRUCTURES_EXTERNAL_CHAINING_HASHTABLE_H
#define DATA_STRUCTURES_EXTERNAL_CHAINING_HASHTABLE_H

#include <stddef.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 256

#define TABLE_INIT_SIZE 8

typedef struct
{
    const char key[MAX_NAME_LENGTH];
    int value;
    struct external_chaining_hashtable_entry_t *nextNode;
} external_chaining_hashtable_entry_t;

typedef struct
{
    size_t allocated;
    size_t used;
    external_chaining_hashtable_entry_t ** entries;
} external_chaining_hashtable_t;

// Creates a new hashtable
int external_chaining_hashtable_init_table(external_chaining_hashtable_t * table);

// Frees the memory used by the hashtable
void external_chaining_hashtable_free_table(external_chaining_hashtable_t * table);

// Prints out the hashtable
void external_chaining_hashtable_print_table(external_chaining_hashtable_t * table);

// Inserts a new entry into the hashtable
bool external_chaining_hashtable_insert_entry(external_chaining_hashtable_entry_t * entry, external_chaining_hashtable_t * table);

// Removes an entry from the hashtable
external_chaining_hashtable_entry_t * external_chaining_hashtable_remove_entry(external_chaining_hashtable_entry_t * entry, external_chaining_hashtable_t * table);

/* Looks up a entry in the hashtable, based on a key
WARNING: returns null if the entry couldn't be found*/
external_chaining_hashtable_entry_t * external_chaining_hashtable_lookup_entry(char *key, external_chaining_hashtable_t * table);

#endif