#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int adjmat[MAX][MAX];
int n, graphtype;

void GetNewGraph(){
    int maxedge, origin, destin, i;
    printf("Enter Graph type: 1) Undirected 2) Directed\n");
    scanf("%d",&graphtype);
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    if(graphtype==1) maxedge = n*(n-1)/2;
    else maxedge = n*(n-1);
    for(i=0;i<=n-1;i++){
        printf("Enter the edge in origin destination format. -1 -1 to exit.\n");
        scanf("%d %d",&origin,&destin);
        if(origin == 1 && destin == -1) break;
        if(origin <0 || origin >=n || destin < 0 || destin >=n){
            printf("Invalid Vertex.");
            i--;
        }
        else{
            adjmat[origin][destin] = 1;
            if(graphtype == 1) adjmat[destin][origin] = 1;
        }

    }
}

void InsertEdge(int origin, int destin){
    if(origin <0 || destin <0 || origin >= n || destin >= n){
        printf("Edge out of range.\n");
        return;
    }
    else{
        adjmat[origin][destin] = 1;
    }
    if(graphtype=1) adjmat[destin][origin]=1;
    return;
}

void DeleteEdge(int origin, int destin){
    if(origin <0 || destin <0 || origin >= n || destin >= n){
    printf("Edge out of range.\n");
    return;
    }
    else{
        adjmat[origin][destin] = 0;
    }
    if(graphtype= 1) adjmat[destin][origin]=0;
    return;
}

void Print(){
    int i, j;
    for(i=0;i<=n-1;i++){
        for(j=0;j<=n-1;j++){
            printf("%4d",adjmat[i][j]);
        }
    printf("\n");
    }
}

void main(){
    GetNewGraph();
    int choice, origin,destin;
    while(1){
        printf("Enter your choice:\n1)Insert Edge\n2)Delete Element\n3)Display\n4)Quit");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter edge in origin and destination: ");
            scanf("%d %d",&origin,&destin);
            InsertEdge(origin,destin);
            break;
            case 2:
            printf("Enter edge in origin and destination: ");
            scanf("%d %d",&origin,&destin);
            DeleteEdge(origin,destin);
            break;
            case 3:
            printf("Adjacancy Matrix Elements are: \n");
            Print();
            break;
            case 4:
            exit(1);
            default:("Wrong choice");
        }
    }
}