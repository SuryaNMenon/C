#include <stdio.h>
#define MAX_SIZE 100
void bubbleSort(int A[], int n)
{
    int i = 0, j = 0, temp = 0;
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
    printf("The array in sorted order is : ");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}
int main()
{
    int n = 0;
    int A[MAX_SIZE];
    printf("Enter the number of the elements of the array : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    bubbleSort(A, n);
    return 0;
}
