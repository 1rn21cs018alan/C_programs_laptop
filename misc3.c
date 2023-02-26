#include<stdio.h>
int main()
{
    for(int i=0;i<512;i++)
        printf("\n%d-%c",i,i);
    char a="⁴";
    printf("-%c-",a);
    return 0;
}