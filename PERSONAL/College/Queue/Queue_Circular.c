#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int value){
    if((rear+1)%MAX== front){
        printf("Queue Overflow");
        return;
    }
    // First Element
    if(front == -1){
        front = 0;
    }

    rear = (rear+1)%MAX;
    queue[rear] = value;
    printf("Enqueud value: %d\n", queue[rear]);
}

void dequeue(){
    if(front == -1){
        printf("Queue Underflow");
        return;
    }
    int value = queue[front];
    printf("Dequeud value: %d\n", queue[front]);

    if(rear == front){
        rear = -1;
        front = -1;
    }else{
        front = (front+1)%MAX;
    }
}

void display(){
    printf("----------- DISPLAY -----------\n");
    if(front == -1){
        printf("Queue Underflow");
        return;
    }
    int i = front;
    while(i != rear){
        printf(" %d ", queue[i]);
        i = (i+1)%MAX;
    }
    printf("%d\n", queue[rear]);
    printf("\n");
}

int main(){
    enqueue(5);
    enqueue(6);
    enqueue(9);
    enqueue(13);
    enqueue(91);

    display();

    dequeue();
    dequeue();

    display();

    return 0;
}