#include <stdio.h>

int main()
{
    int num1 = 1, num2 = 2;
    int *pointer1 = &num1, *pointer2 = &num2;
    printf("Number 1 located at postion %d has a value of %d\n",pointer1,*pointer1);
    printf("Number 2 located at postion %d has a value of %d\n", pointer2, *pointer2);
    return 0;
}
