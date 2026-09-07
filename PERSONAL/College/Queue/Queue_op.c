#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int Queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int value){
    if(rear == MAX -1){
        printf("Queue Overflow");
        return;
    }
    // Only set front to 0 if this is the very first element
    if(front == -1){ 
        front = 0; 
    }
    Queue[++rear] = value;
    printf("Value Enqueue: %d\n", value);

}

void dequeue(){
    // Check if empty (front is -1, OR front has passed rear)
    if(front == -1 || front > rear){
        printf("Queue Underflow\n");
        return;
    }
    
    int dequeue_val = Queue[front++];
    printf("Value Dequeue: %d\n", dequeue_val);
    
    // RESET logic: If the queue is now empty, reset pointers
    if(front > rear){
        front = -1;
        rear = -1;
    }
}

void display(){
    if(front == -1 || front > rear){
        printf("Queue is empty\n");
        return;
    }
    printf("----DISPLAY----\n");
    for(int i = front; i <= rear; i++){
        printf(" %d ", Queue[i]);
    }
    printf("\n");
}

int main(){
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);

    dequeue();
    dequeue();

    display();

    return 0;
}