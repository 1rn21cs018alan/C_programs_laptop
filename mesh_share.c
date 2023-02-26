#include<stdio.h>
#include<stdlib.h>  // for clear screen function
#include<math.h>
void plus(float b[5][5],int i,int j,int offset)
{
    b[i][j]=(float)(b[i-offset][j]+b[i+offset][j]+b[i][j-offset]+b[i][j+offset])/4.0;
}

void cross(float b[5][5],int i,int j,int offset)
{
    b[i][j]=(float)(b[i-offset][j-offset]+b[i+offset][j-offset]+b[i+offset][j+offset]+b[i-offset][j+offset])/4.0;
}

void even()
{
    printf("for even\n");
    int i,j;
    float b[5][5];
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(i>0 && i<4 && j>0 && j<4)
                continue;
            printf("Enter value at (%d,%d):",i,j);
            scanf("%f",&b[j][i]);
        }
    }
    plus(b,2,2,2);
    cross(b,1,1,1);
    cross(b,1,3,1);
    cross(b,3,1,1);
    cross(b,3,3,1);
    plus(b,1,2,1);
    plus(b,2,1,1);
    plus(b,3,2,1);
    plus(b,2,3,1);
    for(int i=4;i>=0;i--)
    {
        for(int j=0;j<5;j++)
        {
            printf("%.0f\t",b[j][i]);
        }
        printf("\n");
    }
}


void odd()
{
    printf("for odd\n");
    float b[4][4];
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(i>0 && i<3 && j>0 && j<3)
                continue;
            printf("Enter value at (%d,%d):",j,i);
            scanf("%f",&b[j][i]);
        }
    }
    float A,B,C,D;
    A=b[0][2]+b[1][3];
    B=b[2][3]+b[3][2];
    C=b[2][0]+b[3][1];
    D=b[1][0]+b[0][1];
    b[1][1]=(7*D+2*A+2*C+B)/24.0;
    b[1][2]=(7*A+2*B+2*D+C)/24.0;
    b[2][1]=(7*C+2*D+2*B+A)/24.0;
    b[2][2]=(7*B+2*A+2*C+D)/24.0;
    for(i=3;i>=0;i--)
    {
        for(int j=0;j<4;j++)
        {
            printf("%.0f\t",b[j][i]);
        }
        printf("\n");
    }
}


int main()
{
    printf("Enter as per X-Y graph coordinates\n");
    odd();
    even();
    return 0;
}