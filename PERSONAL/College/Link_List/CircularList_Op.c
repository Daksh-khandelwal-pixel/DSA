#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;


// ---------- INSERT ----------

void insertBeg(int value) {

    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = value;

    // Empty list
    if (head == NULL) {

        head = newNode;
        newNode->next = head;

        return;
    }

    struct Node *temp = head;

    // Find last node
    while (temp->next != head) {
        temp = temp->next;
    }

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}


void insertEnd(int value) {

    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = value;

    // Empty list
    if (head == NULL) {

        head = newNode;
        newNode->next = head;

        return;
    }

    struct Node *temp = head;

    // Find last node
    while (temp->next != head) {
        temp = temp->next;
    }

    newNode->next = head;
    temp->next = newNode;
}


void insertPos(int value, int pos) {

    if (pos == 1) {
        insertBeg(value);
        return;
    }

    if (head == NULL) {
        printf("Invalid position\n");
        return;
    }

    struct Node *temp = head;

    for (int i = 1; i < pos - 1; i++) {

        temp = temp->next;

        // Completed full circle
        if (temp == head) {
            printf("Invalid position\n");
            return;
        }
    }

    // Insert at end
    if (temp->next == head) {
        insertEnd(value);
        return;
    }

    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = value;

    newNode->next = temp->next;
    temp->next = newNode;
}


// ---------- DELETE ----------

void deleteBeg() {

    if (head == NULL) return;

    // Only one node
    if (head->next == head) {

        free(head);
        head = NULL;

        return;
    }

    struct Node *temp = head;

    // Find last node
    while (temp->next != head) {
        temp = temp->next;
    }

    struct Node *nodeToDelete = head;

    head = head->next;

    temp->next = head;

    free(nodeToDelete);
}


void deleteEnd() {

    if (head == NULL) return;

    // Only one node
    if (head->next == head) {

        free(head);
        head = NULL;

        return;
    }

    struct Node *temp = head;

    // Find second-last node
    while (temp->next->next != head) {
        temp = temp->next;
    }

    struct Node *nodeToDelete = temp->next;

    temp->next = head;

    free(nodeToDelete);
}


void deletePos(int pos) {

    if (head == NULL) return;

    if (pos == 1) {
        deleteBeg();
        return;
    }

    struct Node *temp = head;

    for (int i = 1; i < pos - 1; i++) {

        temp = temp->next;

        if (temp == head) {
            printf("Invalid position\n");
            return;
        }
    }

    struct Node *nodeToDelete = temp->next;

    // Invalid position
    if (nodeToDelete == head) {
        printf("Invalid position\n");
        return;
    }

    // Delete last node
    if (nodeToDelete->next == head) {
        deleteEnd();
        return;
    }

    temp->next = nodeToDelete->next;

    free(nodeToDelete);
}


// ---------- DISPLAY ----------

void display() {

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;

    do {

        printf("%d ", temp->data);

        temp = temp->next;

    } while (temp != head);

    printf("\n");
}