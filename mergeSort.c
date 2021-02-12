#include<stdio.h>
#include<stdlib.h>

void Merge(int *arr, int *L, int *R, int leftcount, int  rightcount){
	int i=0;int j = 0; int k = 0;
	while(i<leftcount && j<rightcount){
		if(L[i]<R[j]) arr[k++] = L[i++];
		else arr[k++] = R[j++];
	}
	while(i<leftcount) arr[k++] = L[i++];
	while(j<rightcount) arr[k++] = R[j++];
}
void MergeSort(int *arr, int n){
	int mid, i;

	if(n<2) return;
	mid = n/2;

	int *L = (int)malloc(mid*sizeof(int));
	int *R = (int)malloc((n-mid)*sizeof(int));

	for(i=0;i<mid;i++) L[i] = arr[i];
	for(i=mid;i<n;i++) R[i-mid] = arr[i];

	MergeSort(L, mid);
	MergeSort(R, n-mid);
	Merge(arr,L,R,mid, n-mid);

		free(L);
		free(R);
}
void main(){
	int i, numberOfElements;
	int arr[] = {6,2,3,1,9,10,15,13,12,17};
	numberOfElements = sizeof(arr)/sizeof(arr[0]);
	MergeSort(arr,numberOfElements);
	for(i=0;i<numberOfElements;i++) printf("%d ",arr[i]);
}