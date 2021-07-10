#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    int priority;
    struct Node* link;
} *front = NULL;

void insert(int data, int priority){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if(temp == NULL){
        printf("Memory unavailable.\n");
        return;
    }
    temp->data = data;
    temp->priority = priority;
    temp->link = NULL;
    if(front == NULL || temp->priority < front->priority){ // Queue is empty or item to be added has a priority higher than first node's element.
        temp->link = front;
        front = temp;
        return;
    }
    struct Node* ptr = front;
    while(ptr->link != NULL && ptr->link->priority <= temp->priority){
        ptr = ptr->link;
    }
    temp->link = ptr->link;
    ptr->link = temp;
}

void delete(){
    if(front == NULL){
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = front;
    front = temp->link;
    printf("Deleted element is %d of priority %d\n", temp->data, temp->priority);
    free(temp);
}

void display(){
    if(front == NULL){
        printf("Queue is empty.\n");
        return;
    }
    struct Node* ptr = front;
    printf("Queue Elements are:\n");
    printf("Priority\t\tElement\n");
    while(ptr!=NULL){
        printf("%5d\t\t%5d\n", ptr->priority, ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

void main(){
    int choice, item, priority;
    while(1){
        printf("\tMenu\n");
        printf("1. Insert item\n2. Delete item\n3. Display Queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the item: ");
                scanf("%d", &item);
                printf("Enter its priority: ");
                scanf("%d", &priority);
                insert(item, priority);
                display();
                break;
            case 2:
                delete();
                display();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
                break;
            default: printf("Invalid choice\n");
        }
    }
}