#include<stdio.h>

long fact(long n)
{
    if(n<2)
        return 1;
    return n*fact(n-1);
}

int main()
{
    long n;
    printf("Enter a number:");
    scanf("%ld",&n);
    printf("%ld",fact(n));
}