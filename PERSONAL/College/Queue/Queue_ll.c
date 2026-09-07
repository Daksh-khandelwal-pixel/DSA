#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// We track BOTH ends of the list now
struct Node *front = NULL; 
struct Node *rear = NULL;  

void enqueue(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Queue Overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL; // New node will always be the last node

    // If the queue is entirely empty, both front and rear point to the new node
    if (rear == NULL) {
        front = rear = newNode;
        printf("Enqueued %d\n", value);
        return;
    }

    // Otherwise, attach it to the current rear, then move the rear pointer
    rear->next = newNode;
    rear = newNode;
    
    printf("Enqueued %d\n", value);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    // Delete at the beginning (front)
    struct Node *temp = front;
    int deleted_val = temp->data;

    front = front->next; // Move front forward

    // CRITICAL: If moving front made the queue empty, we must also reset rear
    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
    printf("Dequeued %d\n", deleted_val);
}

void display() {
    if (front == NULL) {
        printf("Queue empty\n");
        return;
    }
    
    struct Node *temp = front; 
    printf("----DISPLAY----\n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    
    display(); // Prints: 10 20 30
    
    dequeue(); // Removes 10
    
    display(); // Prints: 20 30
    
    return 0;
}