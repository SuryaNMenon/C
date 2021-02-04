#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
int top=-1;
char stack[MAX];
void Push(char elem){
    if(top==MAX-1){
        printf("Stack Overflow");
        return;
    }
    stack[++top] = elem;
}

char Pop(){
    if(top==-1) printf("Stack Underflow");
    else return stack[top--];
}

main(){
    char str[MAX];
    unsigned int i;
    printf("Enter the string to be reversed: \n");
    gets(str);
    for(i=0;i<strlen(str);i++){
        Push(str[i]);
    }
    for(i=0;i<strlen(str);i++){
        str[i] = Pop();
    }
    printf("The reversed string is: ");
    puts(str);
}