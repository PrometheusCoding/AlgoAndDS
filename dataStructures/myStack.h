#ifndef MYSTACK_H
#define MYSTACK_H

#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int top;
} myStack;

void init(myStack *stack);

bool isEmpty(myStack *stack);
bool isFull(myStack * stack);

int push(myStack *stack, int value);
int pop(myStack *stack);
int peek(myStack * stack); 

#endif