#include<stdio.h>
#include<stdbool.h>
#define MAX 101
int A[100];
int top = -1;

void Empty(){
    if(top==-1) printf("Stack is Empty\n");
    else printf("Stack is not empty\n");
}

void Push(int elem){
    if(top == MAX-1){
        printf("Stack Overflow - Too many elements.\n");
        return;
    }
    A[++top] = elem;
}

void Pop(){
    if(top==-1){
        printf("Stack Underflow - Too little elements\n");
        return;
    }
    top--;
}

void TopElement(){
    if(top==-1){
        printf("The Stack is currently empty.\n");
        return;
    }
    printf("%d\n",A[top]);
}

void Print(){
    int i;
    if(top==-1){
        printf("The Stack is currently empty.\n");
        return;
    }
    for(i=0;i<=top;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

void main(){
    int choice = 6;
    printf("Enter the operation to perform:\n1)Push Element\n2)Pop element at TOP\n3)Return value of TOP element\n4)Return whether Stack is empty or not\n5)Print Elements of Stack\n6)Exit\n");
    scanf("%d",&choice);
    while(choice!=6){
        if (choice == 1){
            int elem;
            printf("Enter the element to be pushed to the Stack: \n");
            scanf("%d",&elem);
            Push(elem);
            Print();
        }
        else if(choice == 2){
            Pop();
            Print();
        }
        else if(choice == 3){
            TopElement();
        }
        else if(choice == 4){
            Empty();
        }
        else if(choice == 5){
            Print();
        }
        printf("Enter the operation to perform:\n1)Push Element\n2)Pop element at TOP\n3)Return value of TOP element\n4)Return whether Stack is empty or not\n5)Print Elements of Stack\n6)Exit");
        scanf("%d",&choice);
    }
}