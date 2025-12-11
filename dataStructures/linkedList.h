#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>


typedef struct linkedList{
    int val;
    struct linkedList* next;
} linkedList;

linkedList* list_insert(linkedList* head, int value);
linkedList* list_remove(linkedList* head, int value);
linkedList* list_search(linkedList* head, int value);

#endif