#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 5

// Blueprint of structure
typedef struct {
    int *arr; // For storing elements
    int top; // Shows index xof top element
    int capacity; // Overall capacity of the array depends on it
} Stack;

// Creating and initialising structure (Constructor)
Stack *createStack(){
    Stack *stack = (Stack*)malloc(sizeof(Stack)); // Dynamically alloacated the size -->(Garbage values)
    stack->capacity = MAX; // Initialised capacity to MAX
    stack->arr = (int *)malloc(stack->capacity * sizeof(int));
    stack->top = -1;
    return stack;
}

// Function to free stack memory
void freeStack(Stack *stack){
    free(stack->arr);
    free(stack);
}

bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

bool isFull(Stack *stack) {
    return stack->top == stack->capacity-1;
}

/*
// Push operations if want to show overflow
void push(Stack *stack, int x){ // passed in the location of stack and which value
    if(isfull(stack)){
        printf("Stack Overflow");
        return; // "Stop executing this function and go back to whoever called me."
    }else{
        stack->arr[++stack->top] = x; // Preincrement then value  = (-1 > 0(now value at 0)) 
    }
}
*/

// Push
void push(Stack *stack, int value) {
    // Resize when full
    if (isFull(stack)) {
        stack->capacity += 2;   // Increase by 2
        stack->arr = (int *)realloc(stack->arr, stack->capacity * sizeof(int));
        printf("Stack resized. New capacity = %d\n", stack->capacity);
    }
    stack->arr[++stack->top] = value;
}

// pop operations
int pop(Stack *stack){
    if(isEmpty(stack)){
        printf("Stack Underflow");
        return -1; // Function end immediately
    }
return stack->arr[stack->top--];
}

// peek operations
int peek(Stack *stack){
    // Check both conditions whether empty or not
    if (isEmpty(stack)){
        printf("Stack is empty");
        return -1;
    }
    return stack->arr[stack->top];
}


int main(){
    printf("-----------Implementations of stack----------\n");

    Stack *st = createStack();

    push(st, 10);
    push(st, 20);
    push(st, 30);
    push(st, 40);
    push(st, 50);

    // Triggers resize (5 → 7)
    push(st, 60);

    // Triggers resize (7 → 9)
    push(st, 70);
    push(st, 80);

    printf("Top element = %d\n", peek(st));

    printf("Popped = %d\n", pop(st));

    printf("Top element = %d\n", peek(st));

    printf("Current Capacity = %d\n", st->capacity);

    freeStack(st);

    return 0;
}