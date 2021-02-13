#include <stdio.h>
#define MAX 100
void selectionSort(int A[], int n)
{
   int i = 0, j = 0, minIndex = 0;
   for (i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (j = i+1; j < n; j++)
        {
            if (A[j] < A[minIndex])
                minIndex = j;
        }
        int temp = A[minIndex];
        A[minIndex] = A[i];
        A[i] = temp;
    }
    printf("The array in sorted order is : ");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}
int main()
{
    int i=0, n=0, A[MAX];
    printf("Enter the number of elements in the array\n");
    scanf("%d",&n);
    printf("Enter the elements of the array\n");
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);
    selectionSort(A,n);
    return 0;
}
