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
    newNode->next = head;
    head = newNode;
}


void insertEnd(int value) {

    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node *temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}


void insertPos(int value, int pos) {

    if (pos == 1) {
        insertBeg(value);
        return;
    }

    struct Node *temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    if (temp->next == NULL) {
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

    struct Node *temp = head;

    head = head->next;

    free(temp);
}


void deleteEnd() {

    if (head == NULL) return;

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}


void deletePos(int pos) {

    if (head == NULL) return;

    if (pos == 1) {
        deleteBeg();
        return;
    }

    struct Node *temp = head;

    for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Invalid position\n");
        return;
    }

    if (temp->next->next == NULL) {
        deleteEnd();
        return;
    }

    struct Node *nodeToDelete = temp->next;

    temp->next = nodeToDelete->next;

    free(nodeToDelete);
}


// ---------- DISPLAY ----------

void display() {

    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}
