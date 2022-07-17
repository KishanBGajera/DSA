#ifndef stack_h
#define stack_h

#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int top;
    unsigned capacity;
    int* array;
} Stack;

struct Stack* createStack(unsigned capacity){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    printf("Stake created with capacity : %d\n", stack->capacity);
    return stack;
}

int isFull(struct Stack* stack){
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack){
    return stack->top == -1;
}

void push(struct Stack* stack, int data){
    if(isFull(stack)){
        printf("StackOverFlow : Cannot push %d, stack is full\n", data);
    }
    else{
        stack->array[++stack->top] = data;
        printf("%d pushed to stack\n", data);
    }
}

void peek(struct Stack* stack){
    if(isEmpty(stack)){
        printf("Stack is Empty\n");
    }
    else{
        printf("%d is on the top of the stack\n", stack->array[stack->top]);
    }
}

void pop(struct Stack* stack){
    if(isEmpty(stack)){
        printf("StackUnderFlow : cannot pop, stack has no element\n");
    }
    else{
        stack->top--;
        printf("%d popped out of the stack\n", stack->array[stack->top+1]);
    }
}

void showStack(struct Stack* stack){
    if(isEmpty(stack)){
        printf("Stack is Empty\n");
    }
    else{
        printf("\nStack : \n");
        for(int i=stack->top; i>=0; i--){
            printf(" ____\n");
            printf("| %d |\n", stack->array[i]);
        }
        printf("\n");
    }
}

#endif /* stack_h */
