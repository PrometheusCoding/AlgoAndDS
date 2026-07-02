#ifndef MYPRIORITYQUEUE_H
#define MYPRIORITYQUEUE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int val;
    int priority;
} queueElement;

typedef struct {
    queueElement arr[MAX_SIZE];
    int count;
} myPriorityQueue;

void init(myPriorityQueue *pqueue);

bool isEmpty(myPriorityQueue *pqueue);
bool isFull(myPriorityQueue *pqueue);

void enqueue(myPriorityQueue *pqueue, queueElement element);
queueElement dequeue(myPriorityQueue *pqueue);
void peek(myPriorityQueue *pqueue); 


#endif