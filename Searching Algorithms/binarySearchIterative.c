#include<stdio.h>
#define MAX 100

int BinarySearch(int arr[],int n, int x){
    int low = 0, high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == x) return mid;
        else if(x<arr[mid]) high = mid-1;
        else low = mid+1;
    }
    return -1;
}

void main(){
    int arr[MAX] = {1,2,3,4,5,6,7,8,9,10,11,12,13}; int n = 13;
    printf("Enter the element to be searched: ");
    int x; scanf("%d",&x);
    int result = BinarySearch(arr,n, x);
    if(result != -1){
        printf("Element %d found at index %d",x,result);
    }
    else printf("Element %d not found in the array",x);
}