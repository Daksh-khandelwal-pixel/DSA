#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// Queue structure
typedef struct Queue_Using_Array{
    int *array;     // Dynamic array to store queue elements
    int front;      // Index of the front element
    int rear;       // Index of the rear element
    int size;       // Maximum capacity of the queue
} Queue;

// Allocate and initialize a new queue
Queue *createQueue(){
    Queue *queue = (Queue*)malloc(sizeof(Queue));

    queue->size = MAX;
    queue->front = -1;      // Queue starts empty
    queue->rear = -1;

    // Allocate memory for queue elements
    queue->array = (int*)malloc(queue->size * sizeof(int));

    return queue;
}

// Insert an element at the rear
int enqueue(Queue *queue, int value){

    // Check if the queue is full
    if(queue->rear == MAX - 1){
        printf("Queue Overflow\n");
        return -1;
    }

    // Initialize front on first insertion
    if(queue->front == -1)
        queue->front = 0;

    // Insert the new element
    queue->rear++;
    queue->array[queue->rear] = value;

    return 1;
}

// Remove and return the front element
int dequeue(Queue *queue){

    // Check if the queue is empty
    if(queue->front == -1){
        printf("Queue Underflow\n");
        return -1;
    }

    int value = queue->array[queue->front];

    // Reset indices if the last element is removed
    if(queue->front == queue->rear){
        queue->front = queue->rear = -1;
    }
    else{
        // Move front to the next element
        queue->front++;
    }

    return value;
}

// Display all elements in the queue
void display(Queue *queue){

    if(queue->front == -1){
        printf("Queue is empty\n");
        return;
    }

    for(int i = queue->front; i <= queue->rear; i++)
        printf("%d ", queue->array[i]);

    printf("\n");
}

// Return the front element without removing it
int peek(Queue *queue){

    if(queue->front == -1)
        return -1;

    return queue->array[queue->front];
}

int main(){

    printf("----------- Queue Using Array -----------\n");

    Queue *qu = createQueue();

    enqueue(qu, 40);
    enqueue(qu, 51);
    enqueue(qu, 60);
    enqueue(qu, 20);
    enqueue(qu, 20);

    printf("Front element = %d\n", peek(qu));

    printf("Removed = %d\n", dequeue(qu));

    printf("Front element = %d\n", peek(qu));

    printf("Queue Capacity = %d\n", qu->size);

    display(qu);

    return 0;
}