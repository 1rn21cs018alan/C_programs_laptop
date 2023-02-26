#include<stdio.h>

int main()
{
    char ch,bigstring[15];
    int i=0;
    while(i<15)
    {
        scanf("%c",&ch);
        bigstring[i]=ch;
        i++;
    }
    printf("%s",bigstring);
}
