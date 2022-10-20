#include "external_chaining_hashtable.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../hashing/fnv1a.h"
#include "common_macros.h"

/// Tombstone - marks the spot of a deleted entry
#define TOMBSTONE (external_chaining_hashtable_entry_t *)(0xFFFFFFFFFFFFFFFFUL)

static int external_chaining_hashtable_grow_table(external_chaining_hashtable_t * );
static void insert_all_entries(external_chaining_hashtable_t * , external_chaining_hashtable_entry_t * );

void external_chaining_hashtable_set_print_function(external_chaining_hashtable_t * table, void * printfunction)
{
    if(!table || !printfunction)
        return;
    table->printValue = printfunction;
}

void external_chaining_hashtable_print_table(external_chaining_hashtable_t * table)
{
    if(!table)
        return;
    printf("start:\n");
    for (int i = 0; i < table->allocated; i++)
    {
        if (table->entries[i] == NULL)
            printf("%i\t%s\n", i, "------");
        else if (table->entries[i] == TOMBSTONE)
            printf("%i\t%s (%i)\n", i, "--RIP--", 0);
        else
        {
            printf("%i\t", i);
            external_chaining_hashtable_entry_t * currentNode = table->entries[i];
            while (currentNode != NULL)
            {
                printf("%s", currentNode->key);
                if(table->printValue)
                {
                    putc('(', stdout);
                    table->printValue(currentNode->value);
                    putc(')', stdout);
                }
                printf(" - ");
                currentNode = (external_chaining_hashtable_entry_t *)currentNode->nextNode;
            }
            printf("\n");
        }
    }
    printf("end:\n");
}

int external_chaining_hashtable_init_table(external_chaining_hashtable_t * table)
{
    if(!table)
        return -1;
    table->used = 0;
    table->allocated = TABLE_INIT_SIZE;
    table->entries = malloc(table->allocated * sizeof(external_chaining_hashtable_entry_t *));
    table->printValue = NULL;
    if(!table->entries)
        return -1;
    for (int i = 0; i < table->allocated; i++)
        table->entries[i] = NULL;
    return 0;
}

void external_chaining_hashtable_free_table(external_chaining_hashtable_t * table)
{
    if(!table->entries)
        return;
    free(table->entries);
    table->allocated = table->used = 0;
    table->entries = NULL;
}

int external_chaining_hashtable_insert_entry(external_chaining_hashtable_entry_t * entry, external_chaining_hashtable_t * table)
{
    if (!entry || !table)
        return -1;
    if(table->used > ((double)table->allocated) * TABLE_GROWTH_TRIGGER_VALUE)
        if(external_chaining_hashtable_grow_table(table))
            return -1;
    uint32_t index = fnv1a_hash_data_32(entry->key, strlen(entry->key))  & (table->allocated - 1);
    entry->nextNode = (struct external_chaining_hashtable_entry_t *)table->entries[index];
    table->entries[index] = entry;
    if(entry->nextNode)
        table->used++;
    return 0;
}

external_chaining_hashtable_entry_t * external_chaining_hashtable_remove_entry(external_chaining_hashtable_entry_t * entry, external_chaining_hashtable_t * table)
{
    if(!table)
        return NULL;
    uint32_t index = fnv1a_hash_data_32(entry->key, strlen(entry->key))  & (table->allocated - 1);
    external_chaining_hashtable_entry_t *tempEntry = table->entries[index];
    external_chaining_hashtable_entry_t *previousEntry = NULL;
    while (tempEntry != NULL && strncmp(tempEntry->key, entry->key, MAX_KEY_LENGTH))
    {
        previousEntry = tempEntry;
        tempEntry = (external_chaining_hashtable_entry_t *)tempEntry->nextNode;
    }
    if (!tempEntry)
        return NULL;
    if (!previousEntry)
        table->entries[index] = (external_chaining_hashtable_entry_t *)tempEntry->nextNode;
    else
        previousEntry->nextNode = tempEntry->nextNode;
    table->used--;
    return tempEntry;
}

external_chaining_hashtable_entry_t * external_chaining_hashtable_lookup_entry(char * key, external_chaining_hashtable_t * table)
{
    if(!table)
        return NULL;
    uint32_t index = fnv1a_hash_data_32(key, strlen(key))  & (table->allocated - 1);
    external_chaining_hashtable_entry_t *tempNode = table->entries[index];
    while (strncmp(tempNode->key, key, MAX_KEY_LENGTH) && tempNode->nextNode)
        tempNode = (external_chaining_hashtable_entry_t *)tempNode->nextNode;
    if(strncmp(tempNode->key, key, MAX_KEY_LENGTH))
        return NULL;
    return tempNode;
}

static void insert_all_entries(external_chaining_hashtable_t * table, external_chaining_hashtable_entry_t * entry)
{
    if(entry->nextNode)
        insert_all_entries(table, (external_chaining_hashtable_entry_t *)entry->nextNode);
    entry->nextNode = NULL;
    external_chaining_hashtable_insert_entry(entry, table);     
}

static int external_chaining_hashtable_grow_table(external_chaining_hashtable_t * table)
{    
    external_chaining_hashtable_entry_t ** newEntries = CHECKED_MALLOC_USING_TYPE(table->allocated *  GROWTH_FACTOR, *table->entries);    
    if(!newEntries)
        return - 1;
    for (size_t i = 0; i < table->allocated * GROWTH_FACTOR; i++)
        newEntries[i] = NULL;
    external_chaining_hashtable_entry_t ** oldEntries = table->entries;
    table->entries = newEntries;
    table->used = 0;
    table->allocated *= GROWTH_FACTOR;
    for (size_t j = 0; j < table->allocated / GROWTH_FACTOR; j++)
        if(oldEntries[j])
            insert_all_entries(table, oldEntries[j]);
    free(oldEntries);    
    return 0;
}