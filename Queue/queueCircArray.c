#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int queuecirc[MAX];
int front = -1;
int rear = -1;
int Empty(){
    if(front==-1 && rear==-1) return 1;
    else return 0;
}

int Full(){
    if((front==0 && rear == MAX-1) || (front = rear+1)) return 1;
    else return 0;
}

void Enqueue(int elem){
    if(Full()){
        printf("Queue Overflow - Too many elements.\n");
        exit(1);
    }   
    if(front == -1) 
        front = 0;
    if(rear == MAX-1) 
        rear = 0;
    else rear = rear+1;
    queuecirc[rear] = elem;
}

int Dequeue(){
    if(Empty()){
        printf("Queue Underflow - Too little elements\n");
        exit(1);
    }
    int item = queuecirc[front];
    if(front == rear) front = rear = -1;
    if(front==MAX-1) front = 0;
    else front = front+1;
    return item;
}

int TopElement(){
    if (Empty()){
        printf("The Queue is empty.\n");
        exit(1);
    }
    return queuecirc[front];
}

void Print(){
    if(Empty()){
        printf("Queue is empty.\n");
        exit(1);
    }
    int i;
    i=front;
    printf("Queue elements are: ");
    if(front<=rear){
        while(i<=rear){
            printf("%d ",queuecirc[i]);
            i++;
        }
    }
    else{
        while(i <= MAX-1){
            printf("%d ",queuecirc[i]);
            i++;
        }
        i=0;
        //i=front;
        while(i<=rear){
            printf("%d ",queuecirc[i]);
            i++;
        }
    }
    printf("\n");
}

void main(){
    int elem, choice;
    while(1){
        printf("Enter your choice\n1)Enqueue element\n2)Dequeue element and return dequeued element\n3)Return element in front\n4)Print elements in queue\n5)Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the element to be Enqueued\n");
                scanf("%d",&elem);
                Enqueue(elem);
                Print();
                break;
            case 2:
                printf("The dequeued element is %d\n",Dequeue());
                Print();
                break;
            case 3:
                printf("The top element is %d\n",TopElement());
                break;
            case 4:
                Print();
                break;
            case 5:
                exit(1);
                break;
            default: printf("Wrong choice");
        }
    }
}