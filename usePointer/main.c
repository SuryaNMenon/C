#include <stdio.h>

int main()
{
    int number1 = 10, number2 = 15;
    int *pointer1 = &number1, *pointer2 = &number2;
    printf("Number 1 located at postion %d holds a value of %d\n",pointer1,*pointer1);
    printf("Number 2 located at postion %d holds a value of %d\n", pointer2, *pointer2);
    return 0;
}