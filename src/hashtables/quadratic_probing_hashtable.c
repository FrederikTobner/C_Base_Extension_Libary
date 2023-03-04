#include "quadratic_probing_hashtable.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../hashing/fnv1a.h"

#include "common.h"
#include "../core/memory.h"

/// Tombstone
#define TOMBSTONE (quadratic_probing_hashtable_entry_t *)(0xFFFFFFFFFFFFFFFFUL)

static int quadratic_probing_hashtable_grow_table(quadratic_probing_hashtable_t *);

void quadratic_probing_hashtable_set_print_function(quadratic_probing_hashtable_t * table, void * printfunction)
{
    if(!table || !printfunction)
        return;
    table->printValue = printfunction;
}

quadratic_probing_hashtable_t * quadratic_probing_hashtable_new()
{
    quadratic_probing_hashtable_t * table =new(quadratic_probing_hashtable_t);
    if(!table)
        return NULL;
    quadratic_probing_hashtable_init_table(table);
    return table;
}

void quadratic_probing_hashtable_destory(quadratic_probing_hashtable_t ** table)
{
    if(!*table)
        return;
    quadratic_probing_hashtable_free_entries(*table);
    delete(*table);
    *table = NULL;
}

void quadratic_probing_hashtable_print_table(quadratic_probing_hashtable_t * table)
{
    if(!table)
        return;
    printf("start:\n");
    for (uint32_t i = 0; i < table->allocated; i++)
    {
        if (!table->entries[i])
            printf("%i\t%s (%i)\n", i, "----", 0);
        else if (table->entries[i] == TOMBSTONE)
            printf("%i\t%s (%i)\n", i, "-RIP-", 0);
        else
        {
            printf("%i\t%s ", i, table->entries[i]->key);
            if(table->printValue)
            {
                    putc('(', stdout);
                    table->printValue(table->entries[i]->value);
                    putc(')', stdout);
            }
            putc('\n', stdout);
        }
            
    }
    printf("end:\n");
}

int quadratic_probing_hashtable_init_table(quadratic_probing_hashtable_t * table)
{
    if(!table)
        return -1;
    table->used = 0;
    table->allocated = TABLE_INIT_SIZE;
    table->entries = malloc(table->allocated * sizeof(quadratic_probing_hashtable_entry_t *));
    table->printValue = NULL;
    if(!table->entries)
        return -1;
    for (int i = 0; i < table->allocated; i++)
        table->entries[i] = NULL;
    return 0;
}

void quadratic_probing_hashtable_free_entries(quadratic_probing_hashtable_t * table)
{
    if(!table->entries)
        return;
    delete(table->entries);
    table->allocated = table->used = 0;
    table->entries = NULL;
}

int quadratic_probing_hashtable_insert_entry(quadratic_probing_hashtable_entry_t * node, quadratic_probing_hashtable_t * table)
{
    if (!node || !table)
        return -1;
    if(table->used >= ((double)table->allocated) * TABLE_GROWTH_TRIGGER_VALUE)
        if(quadratic_probing_hashtable_grow_table(table))
            return -1;
    uint32_t index = fnv1a_hash_data_32(node->key, strlen(node->key));
    for (int i = 0; i < table->allocated; i++)
    {
        // When we reach the end of the hashTable we continue from the beginning
        uint32_t try = (i + index * index)  & (table->allocated - 1);
        if (!table->entries[try] || table->entries[try] == TOMBSTONE)
        {
            table->entries[try] = node;
            table->used++;
            return 0;
        }
    }
    return -1;
}

quadratic_probing_hashtable_entry_t * quadratic_probing_hashtable_remove_entry(quadratic_probing_hashtable_entry_t * node, quadratic_probing_hashtable_t * table)
{
    if(!table)
        return NULL;
    uint32_t index = fnv1a_hash_data_32(node->key, strlen(node->key));
    for (uint32_t i = 0; i < table->allocated; i++)
    {
        // When we reach the end of the hashTable we continue from the beginning
        uint32_t try = (i + index * index) & (table->allocated - 1);
        if (!table->entries[try])
            return false;
        if (!strncmp(table->entries[try]->key, node->key, MAX_KEY_LENGTH))
        {
            quadratic_probing_hashtable_entry_t *tempNode = table->entries[try];
            table->entries[try] = TOMBSTONE;
            table->used--;
            return tempNode;
        }
    }
    return NULL;
}

quadratic_probing_hashtable_entry_t * quadratic_probing_hashtable_look_up_entry(char const * key, quadratic_probing_hashtable_t * table)
{
    if(!table)
        return NULL;
    uint32_t index = fnv1a_hash_data_32(key, strlen(key));
    for (uint32_t i = 0; i < table->allocated; i++)
    {
        uint32_t try = (i + index * index) & (table->allocated - 1);
        if (!table->entries[try])
            return NULL;
        if (!strncmp(table->entries[try]->key, key, MAX_KEY_LENGTH))            
            return table->entries[try]; // Entry found
    }
    return NULL;
}

static int quadratic_probing_hashtable_grow_table(quadratic_probing_hashtable_t * table)
{
    quadratic_probing_hashtable_entry_t ** newEntries = CHECKED_MALLOC_USING_TYPE(table->allocated *  GROWTH_FACTOR, *table->entries);       
    if(!newEntries)
        return - 1;
    for (size_t i = 0; i < table->allocated * GROWTH_FACTOR; i++)
        newEntries[i] = NULL;
    quadratic_probing_hashtable_entry_t ** oldEntries = table->entries;
    table->entries = newEntries;
    table->used = 0;
    table->allocated *= GROWTH_FACTOR;
    for (size_t j = 0; j < table->allocated / GROWTH_FACTOR; j++)
        quadratic_probing_hashtable_insert_entry(oldEntries[j], table);
    delete(oldEntries);    
    return 0;
}