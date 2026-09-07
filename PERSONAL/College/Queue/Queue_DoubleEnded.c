#include <stdio.h>
#define MAX 5

int DEqueue[MAX];

int front = -1;
int rear = -1;


void insertFront(int value) {

    if ((rear + 1) % MAX == front) {
        printf("DEqueue Overflow\n");
        return;
    }

    if (front == -1) {
        front = 0;
        rear = 0;
    }
    else if (front == 0) {
        front = MAX - 1;
    }
    else {
        front--;
    }

    DEqueue[front] = value;
}


void insertRear(int value) {

    if ((rear + 1) % MAX == front) {
        printf("DEqueue Overflow\n");
        return;
    }

    if (front == -1) {
        front = 0;
        rear = 0;
    }
    else {
        rear = (rear + 1) % MAX;
    }

    DEqueue[rear] = value;
}


void deleteFront() {

    if (front == -1) {
        printf("DEqueue Underflow\n");
        return;
    }

    printf("Deleted: %d\n", DEqueue[front]);

    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else {
        front = (front + 1) % MAX;
    }
}


void deleteRear() {

    if (front == -1) {
        printf("DEqueue Underflow\n");
        return;
    }

    printf("Deleted: %d\n", DEqueue[rear]);

    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else if (rear == 0) {
        rear = MAX - 1;
    }
    else {
        rear--;
    }
}


void display() {

    if (front == -1) {
        printf("DEqueue is empty\n");
        return;
    }

    int i = front;

    while (i != rear) {
        printf("%d ", DEqueue[i]);
        i = (i + 1) % MAX;
    }

    printf("%d\n", DEqueue[rear]);
}


int main() {

    insertRear(10);
    insertRear(20);
    insertRear(30);

    insertFront(5);

    display();

    deleteFront();

    display();

    deleteRear();

    display();

    return 0;
}

