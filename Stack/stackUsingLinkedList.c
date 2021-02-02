#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* link;
};
struct Node* top = NULL;

void Push(int elem){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = elem;
    temp->link = top;
    top = temp;
}
void Pop(){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if(top==NULL){
        printf("Stack Underflow - Too little elements\n");
        return;
    }
    temp=top;
    top=top->link;
    free(temp);
}

void TopElement(){
    printf("%d\n",top->data);
}

void Empty(){
    if(top==NULL) printf("Stack is empty.");
    else printf("Stack is not empty");
}

void Print(){
    struct Node* temp = top;
    if(temp==NULL){
        printf("Stack is empty");
        return;
    }
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("\n");
}

void main(){
    int choice=6;
    printf("Enter the operation to perform:\n1)Push Element\n2)Pop element at TOP\n3)Return value of TOP element\n4)Return whether Stack is empty or not\n5)Print Elements of Stack\n6)Exit\n");
    scanf("%d",&choice);
    while(choice != 6){
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