#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

//insertBeg
void insertBeg(int value){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if(newNode == NULL) return;

    newNode->data = value;
    newNode->next = head;
    newNode->prev = NULL;

    if(head != NULL){
        head->prev = newNode;
    }
    head = newNode;
}

//insertEnd
void insertEnd(int value){
    if(head == NULL){
        insertBeg(value);
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if(newNode == NULL) return;

    struct Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = temp;
    temp->next = newNode;
}

//insertMid
void insertMid(int value, int pos){
    if(pos == 1){
        insertBeg(value);
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if(newNode == NULL) return;

    struct Node *temp = head;
    int i = 1;
    while(i < pos - 1 && temp != NULL){
        temp = temp->next;
        i++;
    }
    if(temp == NULL) return;

    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next != NULL){
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

//delBeg
void delBeg(){
    if(head == NULL){
        printf("Empty\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;

    if(head != NULL){
        head->prev = NULL;
    }
    free(temp);
}

//delEnd
void delEnd(){
    if(head == NULL){
        printf("Empty\n");
        return;
    }
    if(head->next == NULL){
        delBeg();
        return;
    }

    struct Node *temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

//delMid
void delMid(int pos){
    if(head == NULL){
        printf("Empty\n");
        return;
    }
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
    if(temp == NULL || temp->next == NULL) return;

    struct Node *delNode = temp->next;
    temp->next = delNode->next;

    if(delNode->next != NULL){
        delNode->next->prev = temp;
    }
    free(delNode);
}

//display
void display(){
    struct Node *temp = head;
    while(temp != NULL){
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    insertBeg(10);
    insertEnd(30);
    insertMid(20, 2);
    display(); // 10 <-> 20 <-> 30 <-> NULL

    delMid(2);
    display(); // 10 <-> 30 <-> NULL
    return 0;
}