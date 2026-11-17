#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Helper function to locate the last node
struct Node* getLastNode() {
    if (head == NULL) return NULL;
    struct Node *temp = head;
    while (temp->next != head) temp = temp->next;
    return temp;
}

// ---------- INSERT ----------

void insertEnd(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    struct Node *last = getLastNode();
    newNode->next = head;
    last->next = newNode;
}

void insertBeg(int value) {
    insertEnd(value);
    head = getLastNode(); // The new last node becomes the new head
}

void insertPos(int value, int pos) {
    if (pos == 1) { insertBeg(value); return; }
    if (head == NULL) { printf("Invalid position\n"); return; }

    struct Node *temp = head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
        if (temp == head) { printf("Invalid position\n"); return; }
    }

    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

// ---------- DELETE ----------

void deleteBeg() {
    if (head == NULL) return;
    if (head->next == head) { free(head); head = NULL; return; }

    struct Node *last = getLastNode();
    struct Node *toDelete = head;
    head = head->next;
    last->next = head;
    free(toDelete);
}

void deleteEnd() {
    if (head == NULL) return;
    if (head->next == head) { free(head); head = NULL; return; }

    struct Node *temp = head;
    while (temp->next->next != head) temp = temp->next;

    struct Node *toDelete = temp->next;
    temp->next = head;
    free(toDelete);
}

void deletePos(int pos) {
    if (head == NULL) return;
    if (pos == 1) { deleteBeg(); return; }

    struct Node *temp = head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
        if (temp->next == head) { printf("Invalid position\n"); return; }
    }

    struct Node *toDelete = temp->next;
    if (toDelete == head) { printf("Invalid position\n"); return; }

    temp->next = toDelete->next;
    free(toDelete);
}

// ---------- DISPLAY ----------

void display() {
    if (head == NULL) { printf("List is empty\n"); return; }

    struct Node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    insertBeg(10);
    insertEnd(20);
    insertEnd(30);
    insertPos(15, 2);
    display(); // Output: 10 15 20 30

    deleteBeg();
    deleteEnd();
    deletePos(2);
    display(); // Output: 15

    return 0;
}