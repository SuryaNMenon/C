#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int dequearray[10];
int front = -1;
int rear = -1;
int Full(){
    if((front==0 && rear == MAX-1) || (front == rear+1)) return 1;
    else return 0;
}

int Empty(){
    if(front==-1) return 1;
    else return 0;
}

void insertAtFront(int elem){
    if(Full()){
        printf("Queue overflow\n");
        exit(1);
    }
    if(front == -1){
        front = 0;
        rear = 0;
    }
    else if(front == 0) front = MAX-1;
    else front = front -1;
    dequearray[front] = elem;
}

void insertAtRear(int elem){
    if(Full()){
        printf("Queue Overflow\n");
        exit(1);
    }
    if(front == -1){
        front = 0;
        rear = 0;
    }
    else if(rear == MAX-1) rear = 0;
    else rear = rear+1;
    dequearray[rear] = elem;
}

int dequeueAtFront(){
    if(Empty()){
        printf("Queue underflow\n");
        exit(1);
    }
    int item = dequearray[front];
    if(front == rear) front = rear = -1;
    else if(front == MAX-1) front = 0;
    else front = front + 1;
    return item;
}

int dequeueAtRear(){
    if(Empty()){
        printf("Queue Underflow\n");
        exit(1);
    }
    int item = dequearray[rear];
    if(front==rear) front = rear = -1;
    else if(rear == 0) rear = MAX-1;
    else rear = rear-1;
    return item;
}

void Print(){
    if(Empty()){
        printf("Queue empty");
        exit(1);
    }
    int i=front;
    printf("Queue elements are: ");
    if(front<=rear){
        while(i<=rear){
            printf("%d ",dequearray[i]);
            i++;
        }
    }
    else{
        while(i<=MAX-1){
            printf("%d ", dequearray[i]);
            i++;
        }
        i = 0;
        while(i<=rear){
            printf("%d ",dequearray[i]);
            i++;
        }
    }
    printf("\n");
}

void main(){
    int elem, choice = 0;
    while(1){
        printf("Enter your choice\n1)Enqueue element in front\n2)Enqueue element in rear\n3)Dequeue element in front\n4)Dequeue element in rear\n5)Print elements of the Queue\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter element to enqueue\n");
                scanf("%d",&elem);
                insertAtFront(elem);
                Print();
                break;
            case 2:
                printf("Enter element to enqueue\n");
                scanf("%d",&elem);
                insertAtRear(elem);
                Print();
                break;
            case 3:
                printf("The dequeued element is %d\n",dequeueAtFront());
                Print();
                break;
            case 4:
                printf("The dequeued element is: %d\n",dequeueAtRear());
                Print();
                break;
            case 5:
                Print();
                break;
            default: printf("Incorrect choice");
        }   
    }
}