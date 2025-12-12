#include "myStack.h"

// The stack is a Last In, First Out (LIFO) data structure.
// Can be used for parsing, backtracking and reversing.

void init(myStack *stack){
    stack->top = -1;
}

bool isEmpty(myStack *stack){
    // Time Complexity: O(1)
    if (stack->top == -1){
        return true;
    }
    return false;
}

bool isFull(myStack * stack){
    // Time Complexity: O(1)
    if (stack->top == MAX_SIZE-1){
        return true;
    }
    return false;
}

int push(myStack *stack, int value){
    // Time Complexity: O(1)
    if (isFull(stack)){
        printf("Could not add to the stack, the stack is full\n");
        return -1;
    }
    stack->top++;
    stack->arr[stack->top] = value;
    printf("%d has been pushed onto the stack\n", value);
    return 0;
}

int pop(myStack *stack){
    // Time Complexity: O(1)
    if (isEmpty(stack)){
        printf("Nothing to pop from the stack\n");
        return -1;
    }

    int poppedValue = stack->arr[stack->top];
    stack->top--;
    printf("%d has been popped off the stack\n", poppedValue); 
    return poppedValue;
}

int peek(myStack * stack){
    // Time Complexity: O(1)
    if (isEmpty(stack)){
        printf("The stack is empty!\n");
        return -1;
    }
    printf("%d is at the top of the stack\n", stack->arr[stack->top]);
    return stack->arr[stack->top];
}

int main(){
    myStack stack;
    init(&stack);

    for (int iter = 0; iter <= MAX_SIZE; iter++){
        push(&stack, iter);
    }

    while (!isEmpty(&stack)) {
        pop(&stack);
    }
    pop(&stack);
    return 0;
}