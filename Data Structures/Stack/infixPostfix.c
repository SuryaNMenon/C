#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 100
char stack[MAX];
int top = -1;

void Push(char x){
    if(top == MAX-1){
        printf("Stack Overflow \n");
        exit(1);
    }
    stack[++top] = x;
}

char Pop(){
    if(top == -1){
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int priority(char x){
    if(x == '(') return 0;
    if(x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

void main(){
    char exp[MAX];
    printf("Enter expression: ");
    gets(exp);
    char *e = exp;
    char x;
    while(*e != '\0'){
        if(isalnum(*e))
            printf("%c ", *e);
        else if(*e == '(')
            Push(*e);
        else if(*e == ')'){
            while((x=Pop())!='(')
                printf("%c ",x);
        }
        else{
            while(priority(stack[top])>=priority(*e))
                printf("%c " ,Pop());
            Push(*e);
        e++;
    }
    while(top != -1){
        printf("%c ", Pop());
    }
}