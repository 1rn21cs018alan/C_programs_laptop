#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp;
    fp=fopen("file3.txt","w+");
    if(fp==NULL)
    {
        printf("fopen() error");
        return 1;
    }
    typedef
    struct student
    {
        char name[20];
        int roll;
        float marks;
    }S;
    S tud1={"chicken broth",420,69.42};
    fwrite(&tud1,sizeof(tud1),1,fp);
    fclose(fp);
    fp=fopen("file3.txt","r");
    if(fp==NULL)
    {
        printf("fopen() error");
        return 1;
    }
    S tud2;
    fread(&tud2,sizeof(tud2),1,fp);
    fclose(fp);
    printf("%s,%d,%lf",tud2.name,tud2.roll,tud2.marks);
    
    return 0;
}