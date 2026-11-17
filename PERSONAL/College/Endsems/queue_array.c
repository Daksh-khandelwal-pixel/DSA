#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// enqueue
void enqueue(int value){
    if(rear == MAX -1){
        printf("Queue Overflow");
        return;
    }
    if(front == -1){
        front = 0;
    }
    queue[++rear] = value;
    printf("Value inserted %d\n",queue[rear]);
}

// dequeue
void dequeue(){
    if(front == -1 || front>rear){
        printf("Queue Underflow");
        return;
    }
    int value = queue[front++];
    printf("Value inserted %d\n",value);

    if(front> rear){
        front = -1, rear = -1;
    }
}

// display
void display(){
    if(front == -1 || front>rear){
        printf("Queue Underflow");
        return;
    }
    for(int i = front; i<=rear;i++){
        printf(" %d ",queue[i]);
    }
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(60);
    enqueue(89);

    dequeue();

    display();
    return 0;
}