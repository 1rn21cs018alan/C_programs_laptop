#include<stdio.h>
#define MAX 100
void push(char S[MAX],int *top,char elem)
{
    if((*top)==MAX-1)
    {
        printf("Overflow\n");
        return;
    }
    (*top)++;
    S[*top]=elem;
    return;
}
void pop(char S[MAX],int *top)
{
    if((*top)==-1)
    {
        printf("Underflow");
        return ;
    }
    char temp=S[*top];
    (*top)--;
    return ;

}
void display(char S[MAX],int top)
{
    for(int i=0;i<top;i++)
        printf("%c\n",S[i]);
    return;
}
int main()
{
    char S[MAX];
    int top=-1;
    //just type what every you need here
    push(S,&top,'A');
    push(S,&top,'B');
    push(S,&top,'T');
    //printf("%c",pop(S,&top));
    display(S,top);

    return 0;

}