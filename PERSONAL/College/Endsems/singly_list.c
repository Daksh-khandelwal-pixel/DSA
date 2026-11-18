#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Helper to create a new node
struct Node *createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) return NULL;

    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// 1. Insert at Beginning
void insertBeg(int value) {
    struct Node *newNode = createNode(value);
    if (newNode == NULL) return;

    newNode->next = head;
    head = newNode;
}

// 2. Insert at End
void insertEnd(int value) {
    struct Node *newNode = createNode(value);
    if (newNode == NULL) return;

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

// 3. Insert at Position (1-based)
void insertMid(int value, int pos) {
    if (pos == 1) {
        insertBeg(value);
        return;
    }

    struct Node *newNode = createNode(value);
    if (newNode == NULL) return;

    struct Node *temp = head;
    int i = 1;
    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// 4. Delete from Beginning
void delBeg() {
    if (head == NULL) {
        printf("Empty\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
}

// 5. Delete from End
void delEnd() {
    if (head == NULL) {
        printf("Empty\n");
        return;
    }

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

// 6. Delete from Position (1-based)
void delMid(int pos) {
    if (head == NULL) {
        printf("Empty\n");
        return;
    }
    if (pos == 1) {
        delBeg();
        return;
    }

    struct Node *temp = head;
    int i = 1;
    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position\n");
        return;
    }

    struct Node *delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
}

// 7. Display list
void display() {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    insertBeg(10);
    insertEnd(30);
    insertMid(20, 2);
    display(); // 10 -> 20 -> 30 -> NULL

    delMid(2);
    display(); // 10 -> 30 -> NULL
    return 0;
}