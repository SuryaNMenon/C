#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* link;
};
struct Node* head;
void Insert(int elem){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = elem;
    temp->link = NULL;
    if (head == NULL) head = temp;
    else{
        struct Node* temp1 = head;
        while(temp1->link != NULL){
            temp1 = temp1->link;
        }
        temp1->link = temp;
    }
    return;
}
void Print(){
    struct Node* temp = head;
    while(temp!=NULL){
        printf(" %d",temp->data);
        temp=temp->link;
    }
    printf("\n");
}
void ReverseRecursive(struct Node* p){
    if(p->link == NULL){
        head= p;
        return;
    }
    ReverseRecursive(p->link);
    struct Node *q = p->link;
    q->link = p;
    p->link = NULL;
}
int main(){
    Insert(3);
    Insert(4);
    Insert(5);
    Insert(6);
    Print();
    ReverseRecursive(head);
    Print();
}
