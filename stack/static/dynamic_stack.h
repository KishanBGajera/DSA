#ifndef dynamic_stack_h
#define dynamic_stack_h

#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    int* array;
    int size;
};

struct Stack* createStack(){
    struct Stack* stack = (struct Stack*)calloc(1, sizeof(struct Stack));
    stack->top = -1;
    stack->size = 0;
    stack->array = (int *)calloc(stack->size, sizeof(int));
    return stack;
}

int isEmpty(struct Stack* stack){
    return stack->top == -1;
}

void push(struct Stack* stack, int data){
    stack->array = (int *)realloc(stack->array, ++stack->size * sizeof(int));
    printf("pushed %d to stack\n", data);
}

void pop(struct Stack* stack){
    stack->array = (int *)realloc(stack->array, --stack->size * sizeof(int));
    printf("%d popped out of stack\n", stack->array[stack->top+1]);
}

void peek(struct Stack* stack){
    printf("%d is on top of stack\n", stack->array[stack->top]);
}

void sizeOfStack(struct Stack* stack){
    printf("Size of stack is %d\n", stack->size);
}

void showStack(struct Stack* stack){
    printf("\nStack : \n");
    for(int i=stack->top; i>=0; i--){
        printf(" ____\n");
        printf("| %d |\n", stack->array[i]);
    }
    printf("\n");
}

#endif // dynamic_stack_h