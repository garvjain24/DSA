#include <stdio.h>
int fact(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
        return n * fact(n - 1);
}
int main()
{
    int n,res;
    printf("Enter the number :");
    scanf("%d",&n);
    res=fact(n);
    printf("\nFactorial of %d is =%d\n",n,res);
    return 0;
}