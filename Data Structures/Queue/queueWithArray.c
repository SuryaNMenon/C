#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int queue[MAX];
int front = -1;
int rear = -1;

int isEmpty(){
    if (front == -1 && rear == -1) return 1;
    else return 0;
}

int isFull(){
    if (rear == MAX-1) return 1;
    else return 0;
}

void Enqueue(int elem){
    if (isFull()){
        printf("Queue Overflow - Too many elements\n");
        exit(1);
    }
    else if (front == -1){
        front = 0;
    }
    rear = rear+1;
    queue[rear] = elem;
}

int Dequeue(){
    if(isEmpty()){
        printf("Stack Underflow - Too little elements\n");
        exit(1);
    }
    return queue[front++];
}

int Peek(){
    if(isEmpty()){
        printf("Queue is Empty\n");
        exit(1);
    }
    return queue[front];
}

void Print(){
    if(isEmpty()){
        printf("Queue is empty\n");
        exit(1);
    }
    int i;
    for(i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}

void main(){
    int choice,item;
    while(1){
        printf("Enter your choice:\n1)Enqueue element\n2)Dequeue element\n3)Return element in front\n4)Print elements of the Queue\n5)Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the element to be Enqueued\n");
                scanf("%d",&item);
                Enqueue(item);
                Print();
                break;
            case 2:
                printf("The Dequeued element is %d\n",Dequeue());
                break;
            case 3:
                printf("The element in the front of the Queue is %d\n",Peek());
                break;
            case 4:
                printf("The elements of the Queue are:\n");
                Print();
                break;
            case 5:
                exit(1);
                break;
            default: printf("Wrong Choice\n");
        }
    }
   

}
