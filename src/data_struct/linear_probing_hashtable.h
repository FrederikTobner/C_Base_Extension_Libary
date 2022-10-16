#ifndef DATA_STRUCTURES_LINEAR_PROBING_HASHTABLE_H
#define DATA_STRUCTURES_LINEAR_PROBING_HASHTABLE_H

#include <stdbool.h>

#define MAX_NAME_LENGTH 256

#define TABLE_SIZE 10

// Type Definition of an Entry structure
typedef struct
{
    char const key[MAX_NAME_LENGTH];
    int value;
} linear_probing_hashtable_entry_t;

// Type definition of a HashTable structure
typedef struct
{
    int size;
    int count;
    linear_probing_hashtable_entry_t * entries[TABLE_SIZE];
} linear_probing_hashtable_t;

// Creates a new hashtable
linear_probing_hashtable_t * linear_probing_hashtable_init_table();

// Frees the memory used by the hashtable
void linear_probing_hashtable_free_table(linear_probing_hashtable_t * table);

// Prints out the hashtable
void linear_probing_hashtable_print_table(linear_probing_hashtable_t * table);

// Inserts a new entry into the hashtable
bool linear_probing_hashtable_insert_entry(linear_probing_hashtable_entry_t * entry, linear_probing_hashtable_t * table);

// Removes a entry from the hashtable
linear_probing_hashtable_entry_t * linear_probing_hashtable_remove_entry(linear_probing_hashtable_entry_t * entry, linear_probing_hashtable_t * table);

/* Looks up a entry in the hashtable, based on a key
WARNING: returns null if the entry couldn't be found*/
linear_probing_hashtable_entry_t * linear_probing_hashtable_look_up_entry(char const * key, linear_probing_hashtable_t * table);

#endif