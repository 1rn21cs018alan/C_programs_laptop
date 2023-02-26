#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp;
    fp=fopen("file2.txt","w+");
    if(fp==NULL)
    {
        printf("fopen() error");
        return 1;
    }
    int arr[3]={101,203,303};
    fwrite(arr,sizeof(arr),1,fp);
    fclose(fp);
    fp=fopen("file2.txt","r");
    if(fp==NULL)
    {
        printf("fopen() error");
        return 1;
    }
    int arr2[3];
    fread(arr2,sizeof(arr),1,fp);
    fclose(fp);
    printf("%d,%d,%d",arr2[0],arr2[1],arr2[2]);
    
    return 0;
}