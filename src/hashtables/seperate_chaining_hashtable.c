#include "seperate_chaining_hashtable.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../hashing/fnv1a.h"
#include "common.h"

/// Tombstone
#define TOMBSTONE (seperate_chaining_hashtable_entry_t *)(0xFFFFFFFFFFFFFFFFUL)

static int seperate_chaining_hashtable_grow_table(seperate_chaining_hashtable_t * );
static void seperate_chaining_hashtable_insert_all_entries(seperate_chaining_hashtable_t * , seperate_chaining_hashtable_entry_t * );

void seperate_chaining_hashtable_set_print_function(seperate_chaining_hashtable_t * table, void * printfunction)
{
    if(!table || !printfunction)
        return;
    table->printValue = printfunction;
}

seperate_chaining_hashtable_t * seperate_chaining_hashtable_new()
{
    seperate_chaining_hashtable_t * table = malloc(sizeof(seperate_chaining_hashtable_t));
    if(!table)
        return NULL;
    seperate_chaining_hashtable_init_table(table);
    return table;
}

void seperate_chaining_hashtable_destory(seperate_chaining_hashtable_t ** table)
{
    if(!*table)
        return;
    seperate_chaining_hashtable_free_entries(*table);
    free(*table);
    *table = NULL;
}


void seperate_chaining_hashtable_print_table(seperate_chaining_hashtable_t * table)
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
            seperate_chaining_hashtable_entry_t * currentNode = table->entries[i];
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
                currentNode = (seperate_chaining_hashtable_entry_t *)currentNode->nextNode;
            }
            printf("\n");
        }
    }
    printf("end:\n");
}

int seperate_chaining_hashtable_init_table(seperate_chaining_hashtable_t * table)
{
    if(!table)
        return -1;
    table->used = 0;
    table->allocated = TABLE_INIT_SIZE;
    table->entries = malloc(table->allocated * sizeof(seperate_chaining_hashtable_entry_t *));
    table->printValue = NULL;
    if(!table->entries)
        return -1;
    for (int i = 0; i < table->allocated; i++)
        table->entries[i] = NULL;
    return 0;
}

void seperate_chaining_hashtable_free_entries(seperate_chaining_hashtable_t * table)
{
    if(!table->entries)
        return;
    free(table->entries);
    table->allocated = table->used = 0;
    table->entries = NULL;
}

int seperate_chaining_hashtable_insert_entry(seperate_chaining_hashtable_entry_t * entry, seperate_chaining_hashtable_t * table)
{
    if (!entry || !table)
        return -1;
    if(table->used > ((double)table->allocated) * TABLE_GROWTH_TRIGGER_VALUE)
        if(seperate_chaining_hashtable_grow_table(table))
            return -1;
    uint32_t index = fnv1a_hash_data_32(entry->key, strlen(entry->key))  & (table->allocated - 1);
    entry->nextNode = (struct seperate_chaining_hashtable_entry_t *)table->entries[index];
    table->entries[index] = entry;
    if(entry->nextNode)
        table->used++;
    return 0;
}

seperate_chaining_hashtable_entry_t * seperate_chaining_hashtable_remove_entry(seperate_chaining_hashtable_entry_t * entry, seperate_chaining_hashtable_t * table)
{
    if(!table)
        return NULL;
    uint32_t index = fnv1a_hash_data_32(entry->key, strlen(entry->key))  & (table->allocated - 1);
    seperate_chaining_hashtable_entry_t *tempEntry = table->entries[index];
    seperate_chaining_hashtable_entry_t *previousEntry = NULL;
    while (tempEntry != NULL && strncmp(tempEntry->key, entry->key, MAX_KEY_LENGTH))
    {
        previousEntry = tempEntry;
        tempEntry = (seperate_chaining_hashtable_entry_t *)tempEntry->nextNode;
    }
    if (!tempEntry)
        return NULL;
    if (!previousEntry)
        table->entries[index] = (seperate_chaining_hashtable_entry_t *)tempEntry->nextNode;
    else
        previousEntry->nextNode = tempEntry->nextNode;
    table->used--;
    return tempEntry;
}

seperate_chaining_hashtable_entry_t * seperate_chaining_hashtable_lookup_entry(char * key, seperate_chaining_hashtable_t * table)
{
    if(!table)
        return NULL;
    uint32_t index = fnv1a_hash_data_32(key, strlen(key))  & (table->allocated - 1);
    seperate_chaining_hashtable_entry_t *tempNode = table->entries[index];
    while (strncmp(tempNode->key, key, MAX_KEY_LENGTH) && tempNode->nextNode)
        tempNode = (seperate_chaining_hashtable_entry_t *)tempNode->nextNode;
    if(strncmp(tempNode->key, key, MAX_KEY_LENGTH))
        return NULL;
    return tempNode;
}

static void seperate_chaining_hashtable_insert_all_entries(seperate_chaining_hashtable_t * table, seperate_chaining_hashtable_entry_t * entry)
{
    if(entry->nextNode)
        seperate_chaining_hashtable_insert_all_entries(table, (seperate_chaining_hashtable_entry_t *)entry->nextNode);
    entry->nextNode = NULL;
    seperate_chaining_hashtable_insert_entry(entry, table);     
}

static int seperate_chaining_hashtable_grow_table(seperate_chaining_hashtable_t * table)
{    
    seperate_chaining_hashtable_entry_t ** newEntries = CHECKED_MALLOC_USING_TYPE(table->allocated *  GROWTH_FACTOR, *table->entries);    
    if(!newEntries)
        return - 1;
    for (size_t i = 0; i < table->allocated * GROWTH_FACTOR; i++)
        newEntries[i] = NULL;
    seperate_chaining_hashtable_entry_t ** oldEntries = table->entries;
    table->entries = newEntries;
    table->used = 0;
    table->allocated *= GROWTH_FACTOR;
    for (size_t j = 0; j < table->allocated / GROWTH_FACTOR; j++)
        if(oldEntries[j])
            seperate_chaining_hashtable_insert_all_entries(table, oldEntries[j]);
    free(oldEntries);    
    return 0;
}