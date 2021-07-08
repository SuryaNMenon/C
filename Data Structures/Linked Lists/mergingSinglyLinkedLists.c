#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* link;
};

struct Node* insert(struct Node* head, int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    if(head == NULL){
        temp->link = head;
        head = temp;
        return head;
    }
    struct Node* p = head;
    while(p->link != NULL){
        p = p->link;
    }
    temp->link = p->link;
    p->link = temp;
    return head;
}

struct Node* sortedInsert(struct Node* head, int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    if(head == NULL || data < head->data){
        temp->link = head;
        head = temp;
        return head;
    }
    struct Node* temp2 = head;
    while(temp2->link != NULL && data > temp2->link->data){
        temp2 = temp2->link;
    }
    temp->link = temp2->link;
    temp2->link = temp;
    return head;
}

void display(struct Node* head){
    struct Node* p = head;
    printf("Linked list elements are:");
    while(p!=NULL){
        printf(" %d", p->data);
        p=p->link;
    }
    printf(" ");
}

void merge(struct Node* p1, struct Node* p2){
    struct Node* head3 = NULL;
    while(p1 != NULL && p2 != NULL)
    {
        if(p1->data < p2->data){
            head3 = insert(head3, p1->data);
            p1 = p1->link;
        }
        else if(p2->data < p1->data){
            head3 = insert(head3, p2->data);
            p2 = p2->link;
        }
        else if(p1->data == p2->data){
            head3 = insert(head3, p1->data);
            p1 = p1->link;
            p2 = p2->link;
        }
    }
    while(p1!=NULL){
        head3 = insert(head3, p1->data);
        p1 = p1->link;
    }
    while(p2!=NULL){
        head3 = insert(head3, p2->data);
        p2 = p2->link;
    }
    printf("Linked Lists after merging:");
    display(head3);
}

struct Node* createLL(struct Node* head){
    printf("Enter number of nodes");
    int n; scanf("%d", &n);
    int i; for(i=0;i<n;i++){
        printf("Enter the data to insert: ");
        int data; scanf("%d", &data);
        head = sortedInsert(head, data);
    }
    return head;
}

void main(){
    struct Node *head1=NULL, *head2=NULL;
    head1 = createLL(head1);
    head2 = createLL(head2);
    printf("The linked lists are:\n");
    display(head1);
    display(head2);
    merge(head1, head2);
}