#include<stdlib.h>
#include<stdio.h>
#define MAX 100
int adjmat[MAX][MAX];
int n;
void main(){
    int maxedges,graphtype,origin,destin,i,j;
    printf("Enter graphtype: 1) Undirected 2) Directed\n");
    scanf("%d",&graphtype);
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    if(graphtype == 1) maxedges = n*(n-1)/2;
    else maxedges = n*(n-1);
    for(i=0;i<=n-1;i++){
        printf("Enter the edge in format origin then destination. Enter -1 and -1 to exit.\n");
        printf("Enter Origin: ");
        scanf("%d",&origin);
        printf("Enter Destination: ");
        scanf("%d",&destin);
        if(origin == -1 && destin == -1) break;
        if(origin < 0 || origin >=n || destin < 0 || destin >=n){
            printf("Invalid Vertex\n");
            i--;
        }
        else{
            adjmat[origin][destin] = 1;
            if(graphtype == 1) adjmat[destin][origin] = 1;
        }
    }
    printf("Adjacency matrix is: \n");
    for(i=0;i<=n-1;i++){
        for(j=0;j<=n-1;j++){
            printf("%4d",adjmat[i][j]);
        }
        printf("\n");
    }
}