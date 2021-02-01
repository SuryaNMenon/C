#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head;

struct Node* GetNewNode(int elem){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = elem;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void InsertAtHead(int elem){
    struct Node* newNode = GetNewNode(elem);
    if(head == NULL){
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void InsertAtTail(int elem){
    struct Node* newNode = GetNewNode(elem);
    struct Node* temp = head;
    if(head == NULL){
        head = newNode;
        return;
    }
    while(temp->next != NULL) temp=temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void Print(){
    struct Node* temp = head;
    while(temp!=NULL){
        printf(" %d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void ReversePrint(){
    struct Node* temp = head;
    if (head==NULL) return;
    while(temp->next != NULL){
        temp=temp->next;
    }
    while(temp!=NULL){
        printf(" %d",temp->data);
        temp=temp->prev;
    }
    printf("\n");
}

int main(){
    head=NULL;
    InsertAtHead(3);
    InsertAtHead(4);
    InsertAtTail(5);
    InsertAtTail(6);
    Print();
    ReversePrint();
}