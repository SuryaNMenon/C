#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* link;
};
struct Node *rear = NULL;
struct Node *front = NULL;

// struct Node* GetNewNode(int elem){
//     struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
//     if (temp == NULL){
//         printf("Memory Unavailable\n");
//         exit(1);
//     }
//     temp->data = elem;
//     temp->link = NULL;
//     return temp;
// }

int Empty(){
    if (front==NULL) return 1;
    else return 0;
}

void Enqueue(int elem){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if(temp==NULL){
        printf("Memory unavailable\n");
        exit(1);
    }
    temp->data = elem;
    temp->link = NULL;
    // if (Empty()){
    //     front = temp;
    // }
    if(front == NULL) front = temp;
    else {
        rear->link = temp;
        rear = rear+1;
    }
}

int Dequeue(){
    if(Empty()){
        printf("Queue Underflow - Too little elements.\n");
        exit(1);
    }
    struct Node* temp = front;
    int item = front->data;
    front = front->link;
    free(temp);
    return item;
}

int FrontElement(){
    if(Empty()){
        printf("Queue Underflow - too little elements\n");
        exit(1);
    }
    struct Node* temp = front;
    return temp->data;
}

void Print(){
    if(Empty()){
        printf("Queue underflow - too little elements\n");
        exit(1);
    }
    struct Node* temp = front;
    printf("Queue elements are: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("\n");
}

void main(){
    int elem, choice=0;
    while(1){
        printf("Enter your choice\n1)Enqueue element\n2)Dequeue element and return dequeued element\n3)Return element in front\n4)Print elements in queue\n5)Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the element to be enqueued\n");
                scanf("%d",&elem);
                Enqueue(elem);
                Print();
                break;
            case 2:
                printf("The dequeued element is: ",Dequeue());
                Print();
                break;
            case 3:
                FrontElement();
                Print();
                break;
            case 4:
                Print();
                break;
            case 5:
                exit(1);
                break;
            default:
                printf("Incorrect choice");
        }
    }
}