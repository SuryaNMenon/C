#include<stdio.h>
#include<stdlib.h>

int partition(int *arr,int start, int end){
    int i, pIndex, pivot, temp;
    pivot = arr[end];
    pIndex = start;
    for(i=start;i<end;i++){
        if(arr[i]<pivot){
            temp = arr[pIndex];
            arr[pIndex] = arr[i];
            arr[i] = temp;
            pIndex++;
        }
    }
    temp = arr[pIndex];
    arr[pIndex] = arr[end];
    arr[end] = temp;
    return pIndex;
}

void QuickSort(int *arr,int start, int end){
    if(start<end){
        int pIndex = partition(arr,start,end);
        QuickSort(arr,start,pIndex-1);
        QuickSort(arr,pIndex+1,end);
    }
}

void main(){
    int arr[] ={7,2,1,6,8,5,3,4};
    QuickSort(arr,0,7);
    printf("Elements of array are: ");
    int i;
    for(i=0;i<7;i++) printf("%d ",arr[i]);
}