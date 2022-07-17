// example of stack implementation with "stack.h"

#include<stdio.h>
#include "stack.h"

int main(){
    // intializing or creating stack with size = 9
    struct Stack* stack = createStack(9);
    
    // pushing values into the stack
    for(int i = 1; i<10; i++)
        push(stack, i*10);
    
    // now stack is completely full (can be confirmed using isFull(stack_name))
    // adding any more elements to the stack will result into StackOverFlow
    
    peek(stack); // 90
    pop(stack); // removes 90
    peek(stack); // 80
    
    showStack(stack); // shows stack as it is implemented (implementation view)
    
    for(int i = 0; i<8; i++)
        pop(stack);
    
    // now stack is completely empty (can be confirmed using isEmpty(stack_name))
    // popping the stack will result into StackUnderFlow
    return 0;
}
