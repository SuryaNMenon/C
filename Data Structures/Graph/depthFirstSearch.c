#include<stdio.h>
#include<stdlib.h>
#define initial 1
#define visited 2
#define MAX 100
int adjmat[MAX][MAX];
int n;
int state[MAX];
int stack[MAX], top = -1;

void GetNewGraph(){
    int maxedges, origin, destin, i;
    printf("Enter vertex count: ");
    scanf("%d",&n);
    maxedges = n*(n-1);
    for(i=0;i<=n-1;i++){
        printf("Enter edges in origin destination format. -1 -1 to exit:\n");
        scanf("%d %d",&origin,&destin);
        if(origin==-1||destin==-1) break;
        if(origin < 0 || destin < 0 || origin >=n || destin >= n){
            printf("Invalid edge range\n");
            i--;
        }
        else adjmat[origin][destin] = 1;
    }
}

int EmptyStack(){
    if(stack[top]==-1) return 1;
    else return 0;
}

void Push(int elem){
    if(top == MAX-1){
        printf("Stack Overflow");
        exit(1);
    }
    top = top + 1;
    stack[top] = elem;
}

int Pop(){
    if(EmptyStack()){
        printf("Stack Underflow");
        exit(1);
    }
    int elem = stack[top];
    top = top -1;
}

void DFSearch(int v){
    int i;
    Push(v);
    while(!EmptyStack()){
        v = Pop();
        if(state[v]== initial){
            printf("%d ",v);
            state[v] = visited;
        }
        for(i=n-1;i>=0;i--){
            if(adjmat[v][i] == 1 && adjmat[v][i]==initial){
                Push(i);
            }
        }
    }
}

void DFTraversal(){
    int i;
    for(i=0;i<n;i++){
        state[i] = initial;
    }
    printf("Enter initial vertex for Depth First Searching: ");
    scanf("%d",&i);
    DFSearch(i);
}

void main(){
    GetNewGraph();
    DFTraversal();
}