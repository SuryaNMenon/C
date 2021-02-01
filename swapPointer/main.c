#include <stdio.h>
int main()
{
    int num1, num2;
    printf("Enter the first number");
    scanf("%d",&num1);
    printf("Enter the second number");
    scanf("%d",&num2);
    printf("The numbers before swapping are:\n Number 1 - %d \n Number 2 - %d\n",num1, num2);
    int *pointer1=&num1, *pointer2=&num2;
    int temp = 0;
    temp = *pointer2;
    *pointer2 = *pointer1;
    *pointer1 = temp;
    printf("The numbers after swapping are: \n Number 1 - %d \n Number 2 - %d\n",num1,num2);
    return 0;
}

