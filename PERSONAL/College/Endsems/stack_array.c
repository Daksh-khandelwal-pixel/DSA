#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

// push
void push(int value){
    if(top == MAX -1){
        printf("Stack Overflow");
        return;
    }
    stack[++top] = value;
    printf("Value inserted %d\n",stack[top]);
}

// pop
void pop(){
    if(top == -1){
        printf("Stack Underflow");
        return;
    }
    int value = stack[top];
    top--;
    printf("Value deleted %d\n",value);
}

// peek
void peek(){
    if(top == -1){
        printf("Stack is Empty");
        return;
    }
    printf("Value top %d\n",stack[top]);
}

// display
void display(){
    if(top == -1){
        printf("Stack is Empty");
        return;
    }
    for(int i = 0; i <= top;i++){
        printf(" %d ",stack[i]);
    }
}

int main(){
    push(20);
    push(10);
    push(40);

    pop();

    peek();

    display();
    return 0;
}