#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp;
    fp=fopen("file4.txt","w+");
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
    S tud1[3]={{"chicken broth",420,69.42},{"Alan",18,85.54},{"kev",44,91.32}};
    fwrite(tud1,sizeof(tud1),1,fp);
    fclose(fp);
    fp=fopen("file4.txt","r");
    if(fp==NULL)
    {
        printf("fopen() error");
        return 1;
    }
    S tud2[3];
    fread(tud2,sizeof(tud2),1,fp);
    fclose(fp);
    printf("%s,%d,%lf\n",tud2[0].name,tud2[0].roll,tud2[0].marks);
    printf("%s,%d,%lf\n",tud2[1].name,tud2[1].roll,tud2[1].marks);
    printf("%s,%d,%lf",tud2[2].name,tud2[2].roll,tud2[2].marks);
    return 0;
}