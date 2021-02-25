#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

struct Node{
    int data;
    struct Node* link;
};

struct Node* top = NULL;

void Push(char data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->link = top;
    top = newNode;
}

char Pop(){
    if(top == NULL){
        printf("Underflow");
        return 'f';
    }
    struct Node* newNode = top;
    top = newNode->link;
    return newNode->data;
}

char Top(){
    if(top==NULL){
        printf("Empty");
        return 'e';
    }
    return top->data;
}

void main(){
    printf("Enter the string: ");
    char str[MAX];
    gets(str);
    int i; for(i=0;i<strlen(str);i++)
        Push(str[i]);
    for(i=0;i<strlen(str);i++)
        str[i] = Pop();
    printf("String in reverse order is: ");
    puts(str);
}