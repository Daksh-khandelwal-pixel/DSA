#include <stdio.h>
#define MAX 100

int top = -1;
int stack[MAX];

void push(int value){
    if(top == MAX -1){
        printf("Stack Overflow");
        return;
    }
    stack[++top] = value;
}

void pop(){
    if(top == -1){
        printf("Stack Underflow");
        return;
    }
    int value = stack[top];
    printf("poped: %d\n", value);
    stack[top--];
}

void peek(){
    if(top == -1){
        printf("Stack is empty\n");
        return;
    }
    printf("The peek is: %d\n", stack[top]);
}

// CORRECT:
void display(){
    if(top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for(int i = top; i >= 0; i--){ // Display from top down to 0
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main(){
    push(10);
    push(20);
    push(30);
    display();

    pop();

    peek();

    display();
    return 0;
}