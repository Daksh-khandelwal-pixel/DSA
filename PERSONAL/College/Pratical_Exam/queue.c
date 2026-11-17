#include <stdio.h>
#define MAX 100

int front = -1;
int rear = -1;
int queue[MAX];

void enqueue(int value){
    if(rear == MAX -1){
        printf("Queue Overflow");
        return;
    }
    if(front == -1){
        front = 0;
    }
    queue[++rear] = value;
}

void dequeue(){
    if(front == -1 || front > rear){
        printf("Queue Underflow");
        return;
    }
    int value = queue[front++];
    printf("dequeue: %d\n", value);

    if(front> rear){
        front = -1;
        rear = -1;
    }
}


void display(){
    if(front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for(int i = front; i <= rear; i++){ // Display from top down to 0
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();

    display();
    return 0;
}