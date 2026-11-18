#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

// Helper to create a new node
struct Node *createNode(int value){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// 1. insertBeg
void insertBeg(int value){
    struct Node *newNode = createNode(value);
    if(head == NULL){
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// 2. insertEnd
void insertEnd(int value){
    struct Node *newNode = createNode(value);
    if(head == NULL){
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// 3. insertMid
void insertMid(int value, int pos){
    if(pos == 1){
        insertBeg(value);
        return;
    }

    struct Node *newNode = createNode(value);
    struct Node *temp = head;
    int i = 1;
    while(i < pos - 1 && temp != NULL){
        temp = temp->next;
        i++;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if(temp->next != NULL){
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

// 4. delBeg
void delBeg(){
    if(head == NULL) return;

    struct Node *delNode = head;
    head = head->next;
    if(head != NULL){
        head->prev = NULL;
    }
    free(delNode);
}

// 5. delEnd
void delEnd(){
    if(head == NULL) return;
    if(head->next == NULL){
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
}

// 6. delMid
void delMid(int pos){
    if(head == NULL) return;
    if(pos == 1){
        delBeg();
        return;
    }

    struct Node *temp = head;
    int i = 1;
    while(i < pos - 1 && temp != NULL){
        temp = temp->next;
        i++;
    }

    struct Node *delNode = temp->next;
    temp->next = delNode->next;
    if(delNode->next != NULL){
        delNode->next->prev = temp;
    }
    free(delNode);
}

// 7. display
void display(){
    struct Node *temp = head;
    while(temp != NULL){
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    insertBeg(20);
    insertBeg(10);
    insertEnd(40);
    insertMid(30, 3);
    display(); // 10 <-> 20 <-> 30 <-> 40 <-> NULL

    delMid(2);
    delBeg();
    delEnd();
    display(); // 30 <-> NULL

    return 0;
}