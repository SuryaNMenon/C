#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int arr[MAX];

void insertionSort(int size){
    int i, value, hole;
    for(i=1;i<size;i++){
        value = arr[i];
        hole = i;
        while(hole>0 && arr[hole-1]>value){
            arr[hole] = arr[hole-1];
            hole--;
        }
        arr[hole] = value;
    }
    printf("The array elements are: ");
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}

void main(){
    int size, i;
    printf("Enter size of array: ");
    scanf("%d",&size);
    for(i=0;i<size;i++){
        printf("Enter an element: ");
        scanf("%d",&arr[i]);
    }
    insertionSort(size);
}