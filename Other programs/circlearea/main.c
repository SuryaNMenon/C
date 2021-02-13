#include <stdio.h>
#define PI 3.14159
int main()
{
    double area=0.0,radius=0.0;
    printf("Please enter the value of radius of the circle");
    scanf("%lf",&radius);
    area = PI * radius * radius;
    printf("The area of the circle having radius %lf is %lf",radius,area);
    printf("Thank you!");
    return 0;
}


