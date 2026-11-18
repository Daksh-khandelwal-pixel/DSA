#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

// 1. Push
void push(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) return;

    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// 2. Pop
void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }

    struct Node *temp = top;
    printf("Popped: %d\n", top->data);
    top = top->next;
    free(temp);
}

// 3. Peek
void peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element: %d\n", top->data);
}

// 4. Display
void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    struct Node *temp = top;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    display(); // 30 -> 20 -> 10 -> NULL

    peek();    // Top element: 30
    pop();     // Popped: 30
    display(); // 20 -> 10 -> NULL

    return 0;
}