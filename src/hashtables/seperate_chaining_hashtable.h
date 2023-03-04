#ifndef DATA_STRUCTURES_EXTERNAL_CHAINING_HASHTABLE_H
#define DATA_STRUCTURES_EXTERNAL_CHAINING_HASHTABLE_H

#include <stddef.h>
#include <stdbool.h>

#include "../core/var.h"
typedef struct
{
    /// Key of the entry 🔑
    char const * key;
    /// Pointer to the value stored in the entry
    void * value;
    /// The entry that is chained to the entry 
    struct seperate_chaining_hashtable_entry_t * nextNode;
} seperate_chaining_hashtable_entry_t;

typedef struct
{
    /// The amount or allocated entries
    size_t allocated;
    /// The amount of used entries
    size_t used;    
    /// Pointer to the entries
    seperate_chaining_hashtable_entry_t ** entries;
    /// Function pointer to a function that prints out the value stored in the hashtable
    void (*printValue) (var value);
} seperate_chaining_hashtable_t;

/// @brief Initializes a new hashtable
/// @param table The hashtable that is initialized
/// @return 0 if it could be initialized, -1 if not
int seperate_chaining_hashtable_init_table(seperate_chaining_hashtable_t * table);

/// @brief Creates and initializes a new hashtable
/// @return The hashtable that was created
seperate_chaining_hashtable_t * seperate_chaining_hashtable_new();

/// @brief Frees the memory occupied by a hashtable (does not free the memory occupied by the entries)
/// @param table The table that is freed
void seperate_chaining_hashtable_destory(seperate_chaining_hashtable_t ** table);

/// @brief  Frees the memory used by the hashtable
/// @param table The hashtable where the entries are freed
void seperate_chaining_hashtable_free_entries(seperate_chaining_hashtable_t * table);

/// @brief Prints a hashtable
/// @param table The hashtable that is printed
void seperate_chaining_hashtable_print_table(seperate_chaining_hashtable_t * table);

/// @brief Inserts a new entry into the hashtable
/// @param entry The entry that is inserted
/// @param table The table where the entry is inserted
/// @return 0 if the entry was added, -1 if the entry couldn't be added
int seperate_chaining_hashtable_insert_entry(seperate_chaining_hashtable_entry_t * entry, seperate_chaining_hashtable_t * table);

/// @brief Removes a entry from the hashtable
/// @param entry The entry that is removed from the hashtable
/// @param table The table where the entry is removed
/// @return The entry that was removed or null if no entry was removed
seperate_chaining_hashtable_entry_t * seperate_chaining_hashtable_remove_entry(seperate_chaining_hashtable_entry_t * entry, seperate_chaining_hashtable_t * table);

/// @brief Looks up a entry in the hashtable
/// @param key The key that is used to look up the entry
/// @param table The table where the entry is looked up
/// @return The entry that corresponds to the key or NULL if no entry corresponfing to the key was found
seperate_chaining_hashtable_entry_t * seperate_chaining_hashtable_lookup_entry(char *key, seperate_chaining_hashtable_t * table);

/// @brief Sets the print function of the table to the specified function
/// @param table The table where the print function is set
/// @param printfunction Pointer to the custom print function of the hashtable
void seperate_chaining_hashtable_set_print_function(seperate_chaining_hashtable_t * table, void * printfunction);

#endif