#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Helper to create a new node
struct Node *createNode(int value){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL) return NULL;

    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// 1. insertBeg
void insertBeg(int value){
    struct Node *newNode = createNode(value);
    if(newNode == NULL){ return; }

    // Edge case: empty list
    if(head == NULL){
        head = newNode;
        newNode->next = head;
        return;
    }

    struct Node *temp = head;
    while(temp->next != head){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
    head = newNode;
}

// 2. insertEnd
void insertEnd(int value){
    struct Node *newNode = createNode(value);
    if(newNode == NULL){ return; }

    // Edge case: empty list
    if(head == NULL){
        free(newNode);
        insertBeg(value);
        return;
    }

    struct Node *temp = head;
    while(temp->next != head){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

// 3. insertMid
void insertMid(int value, int pos){
    struct Node *newNode = createNode(value);
    if(newNode == NULL){ return; }

    if(pos <= 1 || head == NULL){
        free(newNode);
        insertBeg(value);
        return;
    }

    struct Node *temp = head;
    int i = 1;
    while(i < pos - 1 && temp->next != head){
        temp = temp->next;
        i++;
    }

    if(temp->next == head){
        free(newNode);
        insertEnd(value);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// 4. delBeg
void delBeg(){
    if(head == NULL){
        printf("Empty\n");
        return;
    }

    // Edge case: only 1 node
    if(head->next == head){
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;
    while(temp->next != head){
        temp = temp->next;
    }

    struct Node *delNode = head;
    head = head->next;
    temp->next = head;
    free(delNode);
}

// 5. delEnd
void delEnd(){
    if(head == NULL){
        printf("Empty\n");
        return;
    }

    // Edge case: only 1 node
    if(head->next == head){
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;
    while(temp->next->next != head){
        temp = temp->next;
    }

    struct Node *delNode = temp->next;
    temp->next = head;
    free(delNode);
}

// 6. delMid
void delMid(int pos){
    if(head == NULL){
        printf("Empty\n");
        return;
    }
    if(pos <= 1){
        delBeg();
        return;
    }

    struct Node *temp = head;
    int i = 1;
    while(i < pos - 1 && temp->next != head){
        temp = temp->next;
        i++;
    }

    if(temp->next == head){
        printf("Invalid position\n");
        return;
    }

    struct Node *delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
}

// 7. display
void display(){
    if(head == NULL){
        printf("Empty\n");
        return;
    }

    struct Node *temp = head;
    while(temp->next != head){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("%d -> (head)\n", temp->data);
}

int main(){
    insertBeg(20);
    insertBeg(10);
    insertEnd(40);
    insertMid(30, 3);
    display(); // 10 -> 20 -> 30 -> 40 -> (head)

    delMid(2);
    delBeg();
    delEnd();
    display(); // 30 -> (head)

    return 0;
}