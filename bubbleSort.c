#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int arr[MAX];

void bubbleSort(int size){
   int i, j, temp, flag = 0;
   for(i=0;i<size;i++){
       for(j=0;j<size-1-i;j++){
           if(arr[j]>arr[j+1]){
               temp = arr[j+1];
               arr[j+1] = arr[j];
               arr[j] = temp;
               flag = 1;
           }
           if(flag == 0) break;
       }
   }
    printf("Array elements are: ");
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}

void main(){
    int size, i;
    printf("Enter size of the array: ");
    scanf("%d",&size);
    for(i=0;i<size;i++){
        printf("Enter an element: ");
        scanf("%d",&arr[i]);
    }
    bubbleSort(size);
}