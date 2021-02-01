#include <stdio.h>
#define MAX 100
int insertionSort(int A[],int n)
{
    int i=0,j=0,key=0;
    for(i=1;i<n;i++)
    {
        key=A[i];
        j=i-1;
        while(j>=0 && A[j]>key)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1]=key;
    }
    printf("The sorted array elements are: ");
    for(i=0;i<n;i++)
        printf("%d ",A[i]);
    printf("\n");

}
int main()
{
    int A[MAX];
    int n=0,i;
    printf("Enter the number of elements of the array\n");
    scanf("%d",&n);
    printf("Enter the elements of the array\n");
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);
    insertionSort(A,n);
    return 0;
}
