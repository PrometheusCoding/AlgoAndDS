#include "myQueue.h"

// The circular queue is a First In, First Out (FIFO) data structure.
// Can be used for managing requests

void init(myQueue *queue){
    queue->front = 0;
    queue->rear = -1;
    queue->count = 0;
}

bool isEmpty(myQueue *queue){
    // Time Complexity: O(1)
    return queue->count == 0;
}

bool isFull(myQueue *queue){
    // Time Complexity: O(1)
    if (queue->count == MAX_SIZE){
        return true;
    }
    return false;
}

int enqueue(myQueue *queue, int value){
    // Time Complexity: O(1)
    if (isFull(queue)){
        printf("%d could not be queued. The queue is full!\n", value);
        return -1;
    }
    
    if (queue->rear + 1 > MAX_SIZE - 1){
        queue->rear = 0;
    } else{
        queue->rear++;
    }
    queue->arr[queue->rear] = value;
    queue->count++;

    return 0;
}

int dequeue(myQueue *queue){
    // Time Complexity: O(1)
    if (isEmpty(queue)){
        return -1;
    }

    int dequeued = queue->arr[queue->front];  
    if (queue->front + 1 > MAX_SIZE - 1){
        queue->front = 0;
    } else{
        queue->front++;
    }
    queue->count--;

    return dequeued;
}

void peek(myQueue *queue){
    // Time Complexity: O(1)
    if (isEmpty(queue)){
        printf("The queue is empty. Nothing to see here!\n");
        return;
    }

    printf("%d is at the front of the queue\n", queue->arr[queue->front]);
    return;
} 

#ifdef MYQUEUE_TEST
int main(){
    myQueue queue;
    init(&queue);

    for (int iter = 0; iter <= MAX_SIZE; iter++){
        enqueue(&queue, iter);
    }
    peek(&queue);

    while (!isEmpty(&queue)) {
        dequeue(&queue);
    }
    dequeue(&queue);
    peek(&queue);
    return 0;
}
#endif