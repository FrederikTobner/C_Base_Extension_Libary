#include "single_linked_list.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../core/memory.h"

single_link_t * new_single_link_t(void * value, single_link_t * next)
{
    single_link_t *single_link_t = new(single_link_t);
    if (!single_link_t)
        return 0;
    single_link_t->value = value;
    single_link_t->next = next;
    return single_link_t;
}

single_link_t * prepend(single_link_t * list, void * value)
{
    return new_single_link_t(value, list);
}

void free_list(single_link_t *list)
{
    while (list)
    {
        single_link_t *next = list->next;
        delete(list);
        list = next;
    }
}

bool contains(single_link_t * singleLinkedList, void * value)
{
    while (singleLinkedList)
    {
        if (singleLinkedList->value == value)
            return true;
        singleLinkedList = singleLinkedList->next;
    }
    return false;
}

single_link_t * make_list(int n, void ** array)
{
    single_link_t * singleLinkedList = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        single_link_t * single_link_t = new_single_link_t(array[i], singleLinkedList);
        if (!single_link_t)
        {
            free_list(singleLinkedList);
            return 0;
        }
        singleLinkedList = single_link_t;
    }
    return singleLinkedList;
}

single_link_t * append(single_link_t * list, void * value)
{
    if (!list)
        return new_single_link_t(value, 0);
    single_link_t *last = list;
    while (last->next)
        last = last->next;
    last->next = new_single_link_t(value, 0);
    if (!last->next)
        return 0;
    else
        return list;
}

single_link_t * reverse(single_link_t * list) 
{ 
    if (!list) 
        return 0; 
        single_link_t * next = list->next; 
        single_link_t * reversed = list; 
        reversed->next = 0; 
        while (next) 
        { 
            single_link_t * next_next = next->next; 
            next->next = reversed; 
            reversed = next; 
            next = next_next; 
        } 
        return reversed; 
}

single_link_t * delete_value(single_link_t * list, void * value) 
{ 
    if (!list) 
        return 0; 
    if (list->value == value) 
    {  
        single_link_t * next = list->next; 
        delete(list); 
        return delete_value(next, value); 
    } 
    else 
    { 
        list->next = delete_value(list->next, value); 
        return list; 
    } 
}