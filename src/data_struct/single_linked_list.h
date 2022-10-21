#ifndef DATA_STRUCTURES_SINGLE_LINKED_LIST_H
#define DATA_STRUCTURES_SINGLE_LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct single_link_t
{
    void * value;
    struct single_link_t * next;
} single_link_t;

single_link_t * new_link(void * val, single_link_t * next);

single_link_t * prepend(single_link_t * list, void * value);

single_link_t * append(single_link_t * list, void * val);

single_link_t * make_list(int n, void ** array);

bool contains(single_link_t * list, void * value);

single_link_t * reverse(single_link_t * list);

single_link_t * delete_value(single_link_t * list, void * value);

#endif
