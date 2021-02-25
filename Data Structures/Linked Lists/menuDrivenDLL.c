#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
} *head;

int linkedListLength = 0;

struct Node* GetNewNode(int elem){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = elem;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

void insertHead(int elem){
    struct Node* newNode = GetNewNode(elem);
    if(head == NULL){
        head = newNode;
        linkedListLength++;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    linkedListLength++;
}

void insertTail(int elem){
    struct Node* newNode = GetNewNode(elem);
    if(head == NULL){
        head = newNode;
        linkedListLength++;
        return;
    }
    struct Node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    linkedListLength++;
}

void insertN(int elem, int pos){
    struct Node* newNode = GetNewNode(elem);
    if(head == NULL){
        head = newNode;
        linkedListLength++;
        return;
    }
    if(pos>linkedListLength+1){
        printf("Incompatible Position. Choose again.\n");
        return;
    }
    if(pos == 1){
        insertHead(elem);
        return;
    }
    struct Node* temp = head;
    int i;
    for(i=0;i<pos-2;i++){
        temp = temp->next;
    }
    newNode ->next = temp->next;
    temp->next->prev = newNode;
    newNode->prev = temp;
    temp->next = newNode;
    linkedListLength++;
}

void Delete(int pos){
    if(head == NULL){
        printf("Linked list is empty. Choose again.\n");
        return;
    }
    if(pos == 1){
        struct Node* del = head;
        head = del->next;
        free(del);
        linkedListLength--;
        return;
    }
    if(pos > linkedListLength){
        printf("Incompatible position. Choose again.\n");
        return;
    }
    struct Node* del = head;
    int i; for(i=0;i<pos-1;i++){
        del = del->next;
    }
    del->prev->next = del->next;
    del->next->prev = del->prev;
    free(del);
    linkedListLength--;
    // struct Node* delnode = temp->next;
    // struct Node* fillnode = delnode->next;
    // temp->next = delnode->next;
    // fillnode->prev = temp;
    // free(delnode);
    // linkedListLength--;
}

void printForward(){
    if(head == NULL){
        printf("Linked List is empty. Choose again\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List elements in forward order are: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void printReverse(){
    if(head == NULL){
        printf("Linked List is empty. Choose again.\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List elements in reverse order are: ");
    while(temp->next!=NULL){
        temp = temp->next;
    }
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

void main(){
    head = NULL;
    int i, elem, pos, choice;
    while(1){
        printf("\tMenu\n1)Insert element at head\n2)Insert element at tail\n3)Insert element at input position\n4)Delete element\n5)Display in forward order\n6)Display in reverse order\n7)Exit\n\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("Enter element: ");
            scanf("%d",&elem);
            insertHead(elem);
            printForward();
            break;
            case 2: printf("Enter element: ");
            scanf("%d",&elem);
            insertTail(elem);
            printForward();
            break;
            case 3: printf("Enter element and position: ");
            scanf("%d%d", &elem, &pos);
            insertN(elem, pos);
            printForward();
            break; 
            case 4: printf("Enter position: ");
            scanf("%d", &pos);
            Delete(pos);
            printForward();
            break;
            case 5: printForward();
            break;
            case 6: printReverse();
            break;
            case 7: exit(1);
            break;
            default: printf("Wrong choice\n");
        }
    }
}