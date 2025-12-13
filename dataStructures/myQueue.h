#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int front;
    int rear;
    int count;
} myQueue;

void init(myQueue *queue);

bool isEmpty(myQueue *queue);
bool isFull(myQueue * queue);

void enqueue(myQueue *queue, int value);
int dequeue(myQueue *queue);
void peek(myQueue * queue); 


#endif