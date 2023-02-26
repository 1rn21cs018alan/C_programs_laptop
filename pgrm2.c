#include<stdio.h>
void main()
{
    int l,i;
    char a[100];
    printf("enter\n");
    scanf("%s",a);
    for(i=0;a[i]!='\0';i++)
        l++;
    //printf("%d",l);
    for(i=0;i<=(l/2);i++)
    {
        if(a[i]!=a[l-i-1])
        {
            printf("Not ");
            break;
        }
    }
    printf("Palindrome");
}