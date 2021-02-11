#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define initial 1
#define waiting 2
#define visited 3
int n;
int adjmat[MAX][MAX],front = -1,rear = -1;
int state[MAX];
int queue[MAX];

int EmptyQueue(){
    if(front == rear == -1 || front>rear) return 1;
    else return 0;
}

void GetNewGraph(){
    int maxedges, origin, destin, i;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    maxedges = n* (n-1);
    for(i=0;i<=maxedges;i++){
        printf("Enter edge in origin destination format. -1 -1 to exit: ");
        scanf("%d %d",&origin,&destin);
        if(origin==-1 && destin == -1) break;
        if(origin <0 || destin <0 || origin >=n || destin >=n){
            printf("Edge out of range");
            i--;
        }
        else adjmat[origin][destin]=1;
    }
}

void InsertQueue(int v){
    if(rear == MAX-1){
        printf("Queue Overflow");
        exit(1);
    }
    if(front == -1){
        front = 0;
    }
    rear=rear+1;
    queue[rear] = v;
}

int DeleteQueue(){
    if(EmptyQueue() == 1){
        printf("Queue Underflow");
        exit(1);
    }
    int deletedelem = queue[front];
    front = front+1;
    return deletedelem;
}

void BFSearch(int v){
    int i;
    InsertQueue(v);
    state[v] = waiting;
    while(!EmptyQueue()){
        v = DeleteQueue();
        printf("%d",v);
        state[v] = visited;
        for(i = 0; i<n; i++){
            if(adjmat[v][i]==1 && state[i]==initial){
                InsertQueue(i);
                state[i] = waiting;
            }
        }
    }
}

void BFTraversal(){
    int v;
    for(v=0;v<n;v++){
        state[v]=initial;
    }
    printf("Enter the starting vertex for BFS: ");
    scanf("%d",&v);
    BFSearch(v);
}

void main(){
    GetNewGraph();
    BFTraversal();
}