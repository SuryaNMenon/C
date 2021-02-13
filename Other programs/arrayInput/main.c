#include <stdio.h>
#define MAX 100
int main()
{
    int arr[MAX];
    int n = 0, i = 0;
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    printf("Enter the elements of the array : ");
    for (i = 0; i < n; i++)
        scanf("%d", arr + i);
    printf("The elements of the array are : ");
    for (int i = 0; i < n; i++)
        printf("%d ", *(arr + i));
    printf("\n");

}
