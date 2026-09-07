#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void push(int value){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if(newNode == NULL){
        printf("Stack Overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    
    printf("Pushed %d to stack\n", value);
}

void pop(){
    if(head == NULL){
        printf("Stack underflow\n");
        return;
    }
    
    struct Node *temp = head; 
    
    int poppedValue = temp->data;
    head = head->next;
    free(temp); // Now we free the actual old head
    printf("Popped %d from stack\n", poppedValue);
}

void peek() {
    if (head == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element is: %d\n", head->data);
}

void display(){
    if(head == NULL){
        printf("Stack is empty\n");
        return;
    }
    
    struct Node *temp = head; 
    
    printf("----DISPLAY----\n");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next; // Move to next node
    }
    printf("\n");
}

int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    
    display();
    
    peek();
    
    pop();
    pop();
    
    display();
    
    return 0;
}