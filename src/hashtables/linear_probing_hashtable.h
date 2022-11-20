#ifndef DATA_STRUCTURES_LINEAR_PROBING_HASHTABLE_H
#define DATA_STRUCTURES_LINEAR_PROBING_HASHTABLE_H

#include <stdbool.h>
#include <stddef.h>

// Type Definition of an Entry structure in a hashtable (linear probing)
typedef struct
{
    // Key of the entry 🔑
    char const * key;
    /// Value that is stored in the entry
    void * value;
} linear_probing_hashtable_entry_t;

// Type definition of a HashTable structure using linear probing for hash collisions
typedef struct
{
    /// The amount or allocated entries
    size_t allocated;
    /// The amount of used entries
    size_t used;    
    /// Pointer to the entries
    linear_probing_hashtable_entry_t ** entries;
    /// Function pointer to a function that prints out the value stored in the hashtable
    void (*printValue) (void * value);
} linear_probing_hashtable_t;

/// @brief Initializes a new hashtable
/// @param table The hashtable that is initialized
/// @return 0 if it could be initialized, -1 if not
int linear_probing_hashtable_init_table(linear_probing_hashtable_t * table);

/// @brief Creates and initializes a new hashtable
/// @return The hashtable that was created
linear_probing_hashtable_t * linear_probing_hashtable_new();

/// @brief Frees the memory occupied by a hashtable (does not free the memory occupied by the entries)
/// @param table The table that is freed
void linear_probing_hashtable_destory(linear_probing_hashtable_t ** table);

/// @brief  Frees the memory used by the hashtable
/// @param table The hashtable where the entries are freed
void linear_probing_hashtable_free_entries(linear_probing_hashtable_t * table);

/// @brief Prints a hashtable
/// @param table The hashtable that is printed
void linear_probing_hashtable_print_table(linear_probing_hashtable_t * table);

/// @brief Inserts a new entry into the hashtable
/// @param entry The entry that is inserted
/// @param table The table where the entry is inserted
/// @return 0 if the entry was added, -1 if the entry couldn't be added
int linear_probing_hashtable_insert_entry(linear_probing_hashtable_entry_t * entry, linear_probing_hashtable_t * table);

/// @brief Removes a entry from the hashtable
/// @param entry The entry that is removed from the hashtable
/// @param table The table where the entry is removed
/// @return The entry that was removed or null if no entry was removed
linear_probing_hashtable_entry_t * linear_probing_hashtable_remove_entry(linear_probing_hashtable_entry_t * entry, linear_probing_hashtable_t * table);

/// @brief Looks up a entry in the hashtable
/// @param key The key that is used to look up the entry
/// @param table The table where the entry is looked up
/// @return The entry that corresponds to the key or NULL if no entry corresponfing to the key was found
linear_probing_hashtable_entry_t * linear_probing_hashtable_look_up_entry(char const * key, linear_probing_hashtable_t * table);

/// @brief Sets the print function of the table to the specified function
/// @param table The table where the print function is set
/// @param printfunction Pointer to the custom print function of the hashtable
void linear_probing_hashtable_set_print_function(linear_probing_hashtable_t * table, void * printfunction);

#endif