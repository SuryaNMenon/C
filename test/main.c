//Program to perform bubble sort on an array
#include <stdio.h>
#define MAX 100
void bubblesort(int A[],int n)
{
    int i=0, j=0, temp=0;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(A[j]>A[j+1])
            {
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;

            }
        }
    }
    printf("The sorted array elements are: \n");
    for(i=0;i<n;i++)
    printf("%d ",A[i]);
}
int main()
{
    int n=0,i;
    int A[MAX];
    printf("Enter the size/number of elements in the array\n");
    scanf("%d",&n);
    printf("Enter the elements of the array\n");
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);
    bubblesort(A,n);
    return 0;
}
