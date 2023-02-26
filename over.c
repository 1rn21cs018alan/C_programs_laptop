#include<stdio.h>
#include<string.h>
int el1=0,el2=0;
void elem(char a[20])
{
    if(strcmp("Pyro",a)==0)
        el1=1;
    else if(strcmp("Electro",a)==0)
        el2=1;
    if(el1*el2)
        printf("Overloaded");
}