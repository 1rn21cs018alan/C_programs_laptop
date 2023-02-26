#include<stdio.h>
int main()
{
    int m=10;
    printf("\n--[%d %d %d %d %d %d %d %d %d %d--",m--,m--,m--,m--,m--,m--,m,m--,m--,m--);
    m=10;
    printf("\n--[%d %d %d %d %d %d %d %d %d %d--",m--,m--,m--,m--,m--,m--,m,m--,m--,m--);
    m=10;
    printf("\n--[%d %d %d %d %d %d %d %d %d %d--",--m,--m,++m,m,--m,--m,--m,--m,--m,--m);
    m=10;
    printf("\n--[ %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d--",--m,--m,--m,--m,--m,--m,m--,m--,m--,m--,m--,m--,m,m,m,m,m,m,m++,m++,m++,m++,m++,m++,++m,++m,++m,++m,++m,++m);
    
   return 0;
}