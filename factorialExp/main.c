#include <stdio.h>
void solve(int n)
{
    int r = 0,i=0,fact=1;
    for (i = 1; i <= n; i++)
    {
        fact *= i;
        r += (fact / i);
    }
    printf("The value of the expression until %d is %d\n", n, r);
}
int main()
{
    int n = 0;
    printf("Enter n : ");
    scanf("%d", &n);
    solve(n);
    return 0;
}
