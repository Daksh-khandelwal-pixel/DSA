#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int arr[MAX];
int top = -1;

void push(int value){
    // check full or not
    if(top == MAX -1){ printf("Stack Overflow"); return; }
    arr[++top] = value; // Increment index and place value
    printf("Value inserted: %d \n", value);
}

void pop(){
    //check empty or not
    if(top == -1){ printf("Stack underflow"); return; }
    int value = arr[top];
    top--;
    printf("Value deleted: %d\n", value);
    
}

void peek(){
    if(top == -1){
        printf("Stack is empty\n");
        return;
    }
    printf("The peek is: %d\n", arr[top]);
}

void display(){
    if(top == -1){ 
        printf("Stack is empty\n"); 
        return; 
    }
    printf(" ----DISPLAY----\n");
    
    // Start at the top, count down to 0
    for(int i = top; i >= 0; i--){
        printf(" %d ", arr[i]); 
    }
}

int main(){
    push(20);
    push(30);
    push(40);
    push(50);

    pop();
    pop();
    
    peek();

    display();
    return 0;
}