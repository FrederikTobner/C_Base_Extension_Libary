#include "external_chaining_hashtable.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/// Tombstone - marks the spot of a deleted entry
#define TOMBSTONE (external_chaining_hashtable_entry_t *)(0xFFFFFFFFFFFFFFFFUL)

#define GROWTH_FACTOR (2)

#define TABLE_GROWTH_TRIGGER_VALUE (0.75)

// Calculates the hash based on a string
static unsigned int calculateHash(char const * name, external_chaining_hashtable_t * table)
{
    int length = strlen(name);
    unsigned int hashValue = 0;
    for (int i = 0; i < length; i++)
    {
        hashValue += name[i];
        hashValue *= name[i];
    }
    return hashValue % table->allocated;
}

static int external_chaining_hashtable_grow_table(external_chaining_hashtable_t * table){
    
    external_chaining_hashtable_entry_t ** newEntries = malloc(table->allocated * sizeof(external_chaining_hashtable_entry_t *) * GROWTH_FACTOR);    
    if(!newEntries)
        return - 1;
    for (size_t i = 0; i < table->allocated * GROWTH_FACTOR; i++)
    {
        newEntries[i] = NULL;
    }
    for (size_t j = 0; j < table->allocated; j++)
    {
        newEntries[j] = table->entries[j];
    }
    free(table->entries);
    table->entries = newEntries;    
    table->allocated *= GROWTH_FACTOR;
    return 0;
}

void external_chaining_hashtable_print_table(external_chaining_hashtable_t * table)
{
    printf("start:\n");
    for (int i = 0; i < table->allocated; i++)
    {
        if (table->entries[i] == NULL)
        {
            printf("%i\t%s (%i)\n", i, "------", 0);
        }
        else if (table->entries[i] == TOMBSTONE)
        {
            // Rest in piece brother
            printf("%i\t%s (%i)\n", i, "--RIP--", 0);
        }
        else
        {
            printf("%i\t", i);
            external_chaining_hashtable_entry_t * currentNode = table->entries[i];
            while (currentNode != NULL)
            {
                printf("%s(%i)--", currentNode->key, currentNode->value);
                currentNode = (external_chaining_hashtable_entry_t *)currentNode->nextNode;
            }
            printf("\n");
        }
    }
    printf("end:\n");
}

int external_chaining_hashtable_init_table(external_chaining_hashtable_t * table)
{
    table->used = 0;
    table->allocated = TABLE_INIT_SIZE;
    table->entries = malloc(table->allocated * sizeof(external_chaining_hashtable_entry_t *));
    if(!table->entries)
        return -1;
    for (int i = 0; i < table->allocated; i++)
    {
        table->entries[i] = NULL;
    }
    return 0;
}

void external_chaining_hashtable_free_table(external_chaining_hashtable_t * table)
{
    free(table->entries);
}

bool external_chaining_hashtable_insert_entry(external_chaining_hashtable_entry_t * entry, external_chaining_hashtable_t * table)
{
    if (entry == NULL)
        return false;
    int index = calculateHash(entry->key, table);
    entry->nextNode = (struct external_chaining_hashtable_entry_t *)table->entries[index];
    table->entries[index] = entry;
    if(entry->nextNode != NULL)
        table->used++;
    if(table->used > ((double)table->allocated) * TABLE_GROWTH_TRIGGER_VALUE)
        if(external_chaining_hashtable_grow_table(table))
            return false;
    return true;
}

external_chaining_hashtable_entry_t * external_chaining_hashtable_remove_entry(external_chaining_hashtable_entry_t * entry, external_chaining_hashtable_t * table)
{
    int index = calculateHash(entry->key, table);
    external_chaining_hashtable_entry_t *tempEntry = table->entries[index];
    external_chaining_hashtable_entry_t *previousEntry = NULL;
    while (tempEntry != NULL && strncmp(tempEntry->key, entry->key, MAX_NAME_LENGTH) != 0)
    {
        previousEntry = tempEntry;
        tempEntry = (external_chaining_hashtable_entry_t *)tempEntry->nextNode;
    }
    if (tempEntry == NULL)
        //
        return NULL;
    if (previousEntry == NULL)
    {
        // Deleting the head
        table->entries[index] = (external_chaining_hashtable_entry_t *)tempEntry->nextNode;
    }
    else
    {
        // Deleting something in the middle or at the end
        previousEntry->nextNode = tempEntry->nextNode;
    }
    table->used--;
    return tempEntry;
}

external_chaining_hashtable_entry_t * external_chaining_hashtable_lookup_entry(char * key, external_chaining_hashtable_t * table)
{
    int index = calculateHash(key, table);
    external_chaining_hashtable_entry_t *tempNode = table->entries[index];
    while (tempNode != NULL && strncmp(table->entries[index]->key, key, MAX_NAME_LENGTH) != 0)
    {
        tempNode = (external_chaining_hashtable_entry_t *)tempNode->nextNode;
    }
    return tempNode;
}