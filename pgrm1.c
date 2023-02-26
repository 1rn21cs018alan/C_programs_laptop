#include<stdio.h>
void main()
{
    char n[200];
    scanf("%s",n);
    int len=0, i;
    for(i=0; n[i]!='\0';i++)
    {
        len++;
    }
    printf("%d\n",len);
}
