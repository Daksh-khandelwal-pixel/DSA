#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int priority[MAX];
int rear = -1;

void enqueue(int value, int p){
    if(rear == MAX -1){
        printf("Queue Overflow");
        return;
    }
    rear++;
    queue[rear] = value;
    priority[rear] = p;
    printf("Inserted %d with priority %d\n", value, p);
}

void dequeue(){
    if(rear == -1){
        printf("Queue Underflow");
        return;
    }

    int highestpriority = 0;
    for(int i = 0; i<rear;i++){
        if(priority[i] < priority[highestpriority]){
            highestpriority = i;
        }
    }
    printf("Dequeued value: %d ",queue[highestpriority]);

    for(int i = highestpriority; i<=rear;i++){
        queue[i] = queue[i+1];
        priority[i] = priority[i+1];
    }
    rear--;
}


void display() { 
    if (rear == -1){ 
        printf("Priority Queue is empty\n"); 
        return; 
    } 
    printf("\nValue\tPriority\n"); 
    for (int i = 0; i <= rear; i++){
        printf("%d\t%d\n", queue[i], priority[i]);
    } 
}

int main(){
    enqueue(10, 2); 
    enqueue(20, 1); 
    enqueue(30, 3); 

    display(); 
    dequeue(); 

    display(); 

    return 0;
}