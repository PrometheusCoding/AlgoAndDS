#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"


// A simple linked list implementation. Only stores integers (COULD BE CHANGED FOR A DIFFERENT TYPE DEPENDING ON USE CASE)
// Has the following functions:
// 1. Insert
// 2. Delete
// 3. Find

linkedList* list_insert(linkedList* head, int value){
    // Create the new node
    // First node could be NULL, replace that with our new node.
    // Iterate through the linkedList until we reach the next node that is null, link the current node with our new node. GENERAL CASE
    // Time Complexity: Best case (When list is empty) - O(1), Average/Worst case - O(n)
    linkedList* newNode = malloc(sizeof(linkedList));

    if (newNode == NULL){
        return head;
    }

    newNode->val = value;
    newNode->next = NULL;

    if (head == NULL){
        printf("%d was inserted as the head!\n", value);
        return newNode;
    }

    linkedList* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }

    tail->next = newNode;
    printf("%d was inserted!\n", value);
    return head;
}

linkedList* list_remove(linkedList* head, int value){

    // Check if the list is empty
    // Check if the head of the list is the value we want to remove
    //      --> YES: We create a new head that points to the node that the current head is linked to. Free the current head and return new head
    // Go through the linked list, managing the previous and current node (to be able to connect the list back together)
    // Check if the current node is the value we want to remove
    //      --> YES: We replace the previous nodes next with the current nodes next and free the current node, then return head
    //      --> NO: Go to next node
    // When we reach the end and the value hasn't been found, return head.
    // Time Complexity: Best case (when head is value to remove) - O(1), Average/Worst case - O(n)

    if (head == NULL){
        return NULL;
    }

    if (head->val == value){
        linkedList* newHead = head->next;
        free(head);
        printf("%d was removed!\n", value);
        return newHead; 
    }

    linkedList* previousNode = head;
    linkedList* currentNode = head->next;
    while (currentNode != NULL){
        if (currentNode->val == value){

            previousNode->next = currentNode->next;
            free(currentNode);
            printf("%d was removed!\n", value);
            return head;
        }

        previousNode = currentNode;
        currentNode = currentNode->next;

    }
    printf("%d was not in the linked list. Could not be removed!\n", value);
    return head;
}

linkedList* list_search(linkedList* head, int value){
    // Time Complexity: Best case (when value to find is at the head) - O(1), Average/Worst case - O

    linkedList* currentNode = head;
    while (currentNode != NULL){
        if (currentNode->val == value){
            printf("%d was found!\n", value);
            return currentNode;
        }

        currentNode = currentNode->next;
    }
    printf("%d was not found!\n", value);
    return NULL;
}


int main(){
    printf("Hello\n");
    linkedList *newLinkedList = NULL;
    newLinkedList = list_insert(newLinkedList, 32);
    newLinkedList = list_search(newLinkedList, 32);
    newLinkedList = list_remove(newLinkedList, 40);
    newLinkedList = list_remove(newLinkedList, 32);
    return 0;
}