#include<stdio.h>
int check_last(int arr[20],int n, int x)
{
    while(x--)
    {
        if(arr[x]!=n)
            return 1;
    }
    return 0;
}
void increment(int arr[20],int n, int x);
void print(int arr[20],int x)
{
    while(--x)
    {
        printf("%d ",arr[x]);
    }
    printf("\n");
}
int main()
{
    int i,j,k=1,n,x,arr[20];
    for(i=0;i<20;i++)
        arr[i]=1;
    printf("Enter the values for n and x");
    scanf("%d%d",&n,&x);
    if(n>20||n<1)
        return 0;
    if(x>20||x<1)
        return 0;
    for(i=1;i<x;i++)
    {
        k=k*(n-i+1)/i;
    }
    printf("\n%d\n",k);
    int arr1[20]={1,2,3};
    int arr2[20]={3,3,3};
    printf("%d,%d",check_last(arr1,3,3),check_last(arr2,3,3));
    // while(check_last(arr,n,x))
    // {
    //     increment(arr);
    //     print(arr,int x);
    // }
    return 0;
}