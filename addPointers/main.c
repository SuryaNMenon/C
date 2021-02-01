#include <stdio.h>

int main()
{
    int num1, num2;
    printf("Enter the first number\n");
    scanf("%d",&num1);
    printf("Enter the second number\n");
    scanf("%d",&num2);
    int *pointer1 = &num1, *pointer2 = &num2;
    printf("Sum of the two number is %d", *pointer1+*pointer2);
    return 0;
}
