#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int top = -1;
#define MAX 101
char stack[MAX];
void Push(char elem){
    if(top==MAX-1){
        printf("Stack Overflow");
        exit(1);
    }
    stack[++top] = elem;
}

char Pop(){
    if(top==-1){
        printf("Stack Underflow");
        exit(1);
    }
    return stack[top--];
}

int Matching(char validator, char elem){
    if(validator == '(' && elem == ')') return 1;
    if(validator == '{' && elem == '}') return 1;
    if(validator == '[' && elem == ']') return 1;
    return 0;
}

int Validate(char str[]){
    int i;
    char validator;
    for(i=0;i<strlen(str);i++){
        if(str[i]=='(' || str[i]=='{' || str[i]=='[')
            Push(str[i]);
        else if(str[i]==')'||str[i]=='}'||str[i]==']')
            if(top==-1){
                printf("More closing parantheses than opening parantheses\n");
                return 0;
            }
            else{
                validator = Pop();
                if(Matching(validator,str[i])==0){
                    printf("Mismatched parantheses are %c and %c\n",validator,str[i]);
                    return 0;
                }
            }
    }
    if(top!=-1){
        printf("More opening parantheses than closing parantheses\n");
        return 0;
    }
    else return 1;
}
main(){
    char str[MAX];
    printf("Enter an algebraic expression with parantheses to validate: \n");
    gets(str);
    if (Validate(str)==1) printf("Balanced expression\n");
    else printf("Not balanced Expression\n");
}