#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100
void insertElement(int A[], int n)
{
    int elt = 0, pos = 0;
    printf("Enter the element to be inserted : ");
    scanf("%d", &elt);
    printf("Enter the postion at which the element must be inserted : ");
    scanf("%d", &pos);
    for (int i = n; i >= pos; i--)
        A[i] = A[i - 1];
    A[pos] = elt;
}
void deleteElement(int A[], int n)
{
    int pos = 0;
    printf("Enter the postion at which the element must be deleted : ");
    scanf("%d", &pos);
    for (int i = pos; i < n; i++)
        A[i] = A[i + 1];
}
void displayArray(int A[], int n)
{
    printf("The array element are : ");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}
void searchElement(int A[], int n)
{
    int elt = 0, i = 0;
    printf("Enter the element to be searched for : ");
    scanf("%d", &elt);
    for (i = 0; i < n; i++)
    {
        if (A[i] == elt)
        {
            printf("Element found at index %d \n", i);
            return;
        }
    }
    printf("Element not found in the array \n");
}
int main()
{
    int A[MAX_SIZE];
    int n = 0;
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    printf("Enter the elements of the array : ");
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    int choice = 0;
    while (true)
    {
        printf("\nEnter your choice\n1.Insert\n2.Delete\n3.Display\n4.Search\nPress -1 to exit\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            insertElement(A, n);
            n++;
        }
        else if (choice == 2)
        {
            deleteElement(A, n);
            n--;
        }
        else if (choice == 3)
            displayArray(A, n);

        else if (choice == 4)
        {
            searchElement(A, n);
        }
        else if (choice == -1)
            break;
    }

    return 0;
}
