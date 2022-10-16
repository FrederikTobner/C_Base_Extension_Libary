#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linear_probing_hashtable.h"

/// Tombstone
#define TOMBSTONE (linear_probing_hashtable_entry_t *)(0xFFFFFFFFFFFFFFFFUL)

static unsigned int calculateHash(const char *name)
{
    int length = strlen(name);
    unsigned int hashValue = 0;
    for (int i = 0; i < length; i++)
    {
        hashValue += name[i];
        hashValue *= name[i];
    }
    return hashValue % TABLE_SIZE;
}

void linear_probing_hashtable_print_table(linear_probing_hashtable_t * table)
{
    printf("start:\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table->entries[i] == NULL)
        {
            printf("%i\t%s (%i)\n", i, "----", 0);
        }
        else if (table->entries[i] == TOMBSTONE)
        {
            printf("%i\t%s (%i)\n", i, "-RIP-", 0);
        }
        else
        {
            printf("%i\t%s (%i)\n", i, table->entries[i]->key, table->entries[i]->value);
        }
    }
    printf("end:\n");
}

linear_probing_hashtable_t * linear_probing_hashtable_init_table()
{
    linear_probing_hashtable_t * table = malloc(sizeof(linear_probing_hashtable_t));
    table->count = 0;
    for (int i = 0; i < TABLE_SIZE; i++)
        table->entries[i] = NULL;
    return table;
}

void linear_probing_hashtable_free_table(linear_probing_hashtable_t * table)
{
    free(table);
}

bool linear_probing_hashtable_insert_entry(linear_probing_hashtable_entry_t * node, linear_probing_hashtable_t * table)
{
    if (node == NULL)
        return false;
    int index = calculateHash(node->key);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        // When we reach the end of the hashTable we continue from the beginning
        int try = (i + index) % TABLE_SIZE;
        if (table->entries[try] == NULL || table->entries[try] == TOMBSTONE)
        {
            table->entries[try] = node;
            table->count++;
            return true;
        }
    }
    return false;
}

linear_probing_hashtable_entry_t * linear_probing_hashtable_remove_entry(linear_probing_hashtable_entry_t * node, linear_probing_hashtable_t * table)
{
    int index = calculateHash(node->key);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        // When we reach the end of the hashTable we continue from the beginning
        int try = (i + index) % TABLE_SIZE;
        if (table->entries[try] == NULL)
        {
            return false;
        }
        if (strncmp(table->entries[index]->key, node->key, MAX_NAME_LENGTH) == 0)
        {
            linear_probing_hashtable_entry_t *tempNode = table->entries[index];
            table->entries[index] = TOMBSTONE;
            table->count--;
            return tempNode;
        }
    }
    return NULL;
}

linear_probing_hashtable_entry_t * linear_probing_hashtable_look_up_entry(char const * key, linear_probing_hashtable_t * table)
{
    int index = calculateHash(key);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        // When we reach the end of the hashTable we continue from the beginning
        int try = (i + index) % TABLE_SIZE;
        if (table->entries[try] == NULL)
        {
            return false;
        }
        if (strncmp(table->entries[index]->key, key, MAX_NAME_LENGTH) == 0)
        {
            // Entry found
            return table->entries[index];
        }
    }
    return NULL;
}