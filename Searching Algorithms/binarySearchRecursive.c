#include<stdio.h>
#define MAX 100

int BinarySearch(int arr[], int start, int end, int x){
    if(start>end) return -1;
    int mid = start + (end - start)/2;
    if(x == arr[mid]) return mid;
    else if (x<arr[mid]) return BinarySearch(arr,start,mid-1,x);
    else return BinarySearch(arr,mid+1,end,x);
}

void main(){
    int arr[MAX] = {1,2,3,4,5,6,7,8,9,10,11,12,13}; int n = 13;
    printf("Enter element to be searched: ");
    int x; scanf("%d",&x);
    int result = BinarySearch(arr, 0, n-1,x);
    if(result != -1) printf("Element %d found at index %d",x,result);
    else printf("Element %d not found");
}