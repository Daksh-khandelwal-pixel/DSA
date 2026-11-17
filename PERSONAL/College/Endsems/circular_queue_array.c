#include <stdio.h>
#define MAX 4

int queue[MAX];
int front = -1, rear = -1;

// enqueue
void enqueue(int value) {
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = value;
    printf("Value inserted %d\n", queue[rear]);
}

// dequeue
void dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }
    int value = queue[front];
    printf("Value deleted %d\n", value);

    // If this was the last element, reset the queue
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// display
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", queue[rear]);
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(60);
    enqueue(89);

    dequeue();
    dequeue();
    dequeue();
    dequeue();

    enqueue(1007);
    dequeue();

    display();
    return 0;
}