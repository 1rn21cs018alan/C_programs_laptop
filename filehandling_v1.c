#include<stdio.h>
#include<stdlib.h>
void add(FILE * fp)
{
    fprintf(fp,"%s","hshsh");
}
int main()
{
    FILE *fp;
    fp=fopen("file.txt","w+");
    fprintf(fp,"%s %s %s %d","we","are","in",2021);
    add(fp);
    fclose(fp);
    return 0;
}