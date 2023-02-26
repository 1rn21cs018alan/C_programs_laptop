#include<stdio.h>
#include<stdlib.h>  // for clear screen function
#include<math.h>

typedef
struct array
{
    double b[11][11];
    int size;
}M;

void print_mesh(M m);
void entry_mesh_hyper(int size);
void init_Hyberbolic(M *m1);
void calc_Hyperbolic(M *m1);
void Hyperbolic();
void Eliptical();
void plus(M *m,int i,int j,int offset);
void cross(M *m,int i,int j,int offset);
void entry_mesh(int i);
void calculate_mesh_even(M *m);
void border_input_even(M *m);
void manual_input_mesh_even();
void calculate_mesh_odd(M *m);
void border_input_odd(M *m);
void print_mesh_odd(M m);
void manual_input_mesh_odd();
void Parabolic();
void init_Parabolic(M *m);
void calc_Parabolic_Crank(M *m);
void small_print(double val);
void big_print(double val);

void small_print(double val)
{
    double temp=val;
    int expo=1;
    while(fabs(temp)<1.0)
    {
        expo++;
        temp*=10;
    }
    printf("%.3lfx10^-%d\t",temp,expo);
}

void big_print(double val)
{
    double temp=val;
    int expo=1;
    while(fabs(temp)>10.0)
    {
        expo++;
        temp/=10;
    }
    printf("%.3lfx10^%d\t",temp,expo);
}

void init_Parabolic(M *m)
{
    init_Hyberbolic(m);
}


void calc_Parabolic_Crank(M *m)
{
    if(m->size==3)
    {
        for(int i=(m->size)-2;i>=0;i--)
        {
            m->b[1][i]=((m->b[0][i])+(m->b[2][i])+(m->b[0][i+1])+(m->b[2][i+1]))/4.0;
        }
        print_mesh(*m);
    }
    if(m->size==4)
    {
        double d1,d2;
        for(int i=(m->size)-2;i>=0;i--)
        {
            d1=(m->b[0][i]+m->b[0][i+1]+m->b[2][i+1]);
            d2=(m->b[3][i]+m->b[3][i+1]+m->b[1][i+1]);
            m->b[1][i]=(d1+4*d2)/15.0;
            m->b[2][i]=(d2+4*d1)/15.0;
        }
    }
    if(m->size==5)
    {
        double d1,d2,d3;
        for(int i=(m->size)-2;i>=0;i--)
        {
            d1=(m->b[0][i]+m->b[0][i+1]+m->b[2][i+1]);
            d2=(m->b[3][i+1]+m->b[1][i+1]);
            d3=(m->b[2][i+1]+m->b[4][i]+m->b[4][i+1]);
            m->b[1][i]=(15*d1+4*d2+d3)/56.0;
            m->b[2][i]=(4*d1+16*d2+4*d3)/56.0;
            m->b[3][i]=(d1+4*d2+15*d3)/56.0;
        }
    }
    if(m->size==6)
    {
        double d1,d2,d3,d4;
        for(int i=(m->size)-2;i>=0;i--)
        {
            d1=(m->b[0][i]+m->b[0][i+1]+m->b[2][i+1]);
            d2=(m->b[3][i+1]+m->b[1][i+1]);
            d3=(m->b[4][i+1]+m->b[2][i+1]);
            d4=(m->b[3][i+1]+m->b[5][i]+m->b[5][i+1]);
            m->b[1][i]=(56*d1+15*d2+4*d3+d4)/209.0;
            m->b[2][i]=(15*d1+60*d2+16*d3+4*d4)/209.0;
            m->b[3][i]=(15*d4+60*d3+16*d2+4*d1)/209.0;
            m->b[4][i]=(56*d4+15*d3+4*d2+d1)/209.0;
        }
    }
}


void Parabolic()
{
    system("cls");
    M m;
    printf("Enter no of steps in x:");
    scanf("%d",&(m.size));
    init_Parabolic(&m);
    calc_Parabolic_Crank(&m);
    print_mesh(m);
}

void entry_mesh_hyper(int size)
{
    printf("Enter the values for coordinates as shown below");
    for(int i=size-1;i>-1;i--)
    {
        printf("\n");
        for(int j=0;j<size;j++)
        {
            if(i==size-1  || j==0 ||j==size-1)
                printf("(%d,%d)\t\t",j,i);
            else
                printf("\t\t");
        }
        printf("\n");
    }
}

void init_Hyberbolic(M *m1)
{
    entry_mesh_hyper(m1->size);
    int i;
    for(i=0;i<m1->size;i++)
    {
        printf("Enter value at (0,%d):",i);
        scanf("%lf",&(m1->b[0][i]));
    }
    for(i=0;i<(m1->size);i++)
    {
        printf("Enter value at (%d,%d):",(m1->size)-1,i);
        scanf("%lf",&(m1->b[(m1->size)-1][i]));
    }
    for(i=1;i<(m1->size)-1;i++)
    {
        printf("Enter value at (%d,%d):",i,(m1->size)-1);
        scanf("%lf",&(m1->b[i][(m1->size)-1]));
    }
    // print_mesh_hyper(*m1);
}
void calc_Hyperbolic(M *m1)
{
    int i,j;
    for(i=1;i<(m1->size)-1;i++)//2nd row calculations(using V method)
    {
        m1->b[i][(m1->size)-2]=((m1->b[i-1][(m1->size)-1])+(m1->b[i+1][(m1->size)-1]))/2.0;
    }
    for(i=(m1->size)-3;i>=0;i--)//from 3rd to last row(using diamond method)
    {
        for(j=1;j<(m1->size)-1;j++)
        {
            m1->b[j][i]=(m1->b[j-1][i+1])+(m1->b[j+1][i+1])-(m1->b[j][i+2]);
        }
    }
    // print_mesh_hyper(*m1);
}

void print_mesh(M m)
{
    printf("\n\n\n");
    double val;
    for(int i=m.size-1;i>=0;i--)
    {
        for(int j=0;j<m.size;j++)
        {
            val=m.b[j][i];
            if(val==0)
            {
                printf("%.3lf\t\t",val);
            }
            else if(fabs(val)<0.01)
            {
                small_print(val);
            }
            else if((val > -100.0 ) && ( val< 1000.0 ))
            {
                printf("%.3lf\t\t",val);
            }
            else
            {
                big_print(val);
            }
        }
        printf("\n\n");
    }
}

void Hyperbolic()
{
    system("cls");
    M m;
    printf("Enter no of steps in the values:");
    scanf("%d",&(m.size));
    init_Hyberbolic(&m);
    calc_Hyperbolic(&m);
    print_mesh(m);
}

void plus(M *m,int i,int j,int offset)
{
    m->b[i][j]=(double)((m->b[i-offset][j])+(m->b[i+offset][j])+(m->b[i][j-offset])+(m->b[i][j+offset]))/4.0;
}

void cross(M *m,int i,int j,int offset)
{
    m->b[i][j]=(double)((m->b[i-offset][j-offset])+(m->b[i+offset][j-offset])+(m->b[i+offset][j+offset])+(m->b[i-offset][j+offset]))/4.0;
}

void entry_mesh(int i)
{
    if(i)
    {
        printf("\t\t(1,3)\t\t(2,3)\n\n");
        printf("(0,2)\t\t\t\t\t\t(3,2)\n\n");
        printf("(0,1)\t\t\t\t\t\t(3,1)\n\n");
        printf("\t\t(1,0)\t\t(2,0)\n\n");
    }
    else
    {
        for(int i=4;i>=0;i--)
        {
            for(int j=0;j<5;j++)
            {
                if((i%4==0)||(j%4==0))
                {
                    printf("(%d,%d)\t\t",i,j);
                    continue;
                }
                printf("\t\t");
            }
            printf("\n\n");
        }
    }
}

void calculate_mesh_even(M *m)
{
    plus(m,2,2,2);
    cross(m,1,1,1);
    cross(m,1,3,1);
    cross(m,3,1,1);
    cross(m,3,3,1);
    plus(m,1,2,1);
    plus(m,2,1,1);
    plus(m,3,2,1);
    plus(m,2,3,1);
}

void border_input_even(M *m)
{
    int i;
    m->size=5;
    for(i=0;i<5;i++)
    {
        printf("Enter value at (0,%d):",i);
        scanf("%lf",&(m->b[0][i]));
    }
    for(i=0;i<5;i++)
    {
        printf("Enter value at (4,%d):",i);
        scanf("%lf",&(m->b[4][i]));
    }
    for(i=1;i<4;i++)
    {
        printf("Enter value at (%d,0):",i);
        scanf("%lf",&(m->b[i][0]));
    }
    for(i=1;i<4;i++)
    {
        printf("Enter value at (%d,4):",i);
        scanf("%lf",&(m->b[i][4]));
    }
}


void manual_input_mesh_even()
{
    system("cls"); // to clear screen
    M m;
    entry_mesh(0);
    border_input_even(&m);
    calculate_mesh_even(&m);
    print_mesh(m);
}


void calculate_mesh_odd(M *m)
{
    double A,B,C,D;
    A=(m->b[0][2])+m->b[1][3];//for corner 0,3->1,2
    B=(m->b[2][3])+m->b[3][2];//for corner 3,3->2,2
    C=(m->b[2][0])+m->b[3][1];//for corner 3,0->2,1
    D=(m->b[1][0])+m->b[0][1];//for corner 0,0->1,1

    // found this formula by trial and error with matrix multiplication method of solving linear equation
    m->b[1][1]=(7*D+2*A+2*C+B)/24.0;
    m->b[1][2]=(7*A+2*B+2*D+C)/24.0;
    m->b[2][1]=(7*C+2*D+2*B+A)/24.0;
    m->b[2][2]=(7*B+2*A+2*C+D)/24.0;
}

void border_input_odd(M *m)
{
    int i;
    for(i=1;i<3;i++)
    {
        printf("Enter value at (0,%d):",i);
        scanf("%lf",&(m->b[0][i]));
    }
    for(i=1;i<3;i++)
    {
        printf("Enter value at (3,%d):",i);
        scanf("%lf",&(m->b[3][i]));
    }
    for(i=1;i<3;i++)
    {
        printf("Enter value at (%d,0):",i);
        scanf("%lf",&(m->b[i][0]));
    }
    for(i=1;i<3;i++)
    {
        printf("Enter value at (%d,3):",i);
        scanf("%lf",&(m->b[i][3]));
    }
}

void print_mesh_odd(M m)
{
    printf("\n\n\n");
    double val;
    for(int i=3;i>=0;i--)
    {
        for(int j=0;j<4;j++)
        {
            if((i%3==0)&&(j%3==0))
            {
                printf("\t\t");
                continue;
            }
            val=m.b[j][i];
            if(val==0)
            {
                printf("%.3lf\t\t",val);
            }
            else if(fabs(val)<0.01)
            {
                small_print(val);
            }
            else if((val > -100.0 ) && ( val< 1000.0 ))
            {
                printf("%.3lf\t\t",val);
            }
            else
            {
                big_print(val);
            }
        }
        printf("\n\n");
    }
}

void manual_input_mesh_odd()
{
    system("cls"); // to clear screen
    M m;
    entry_mesh(1);
    border_input_odd(&m);
    calculate_mesh_odd(&m);
    print_mesh_odd(m);
}

int main()
{
    printf("Enter 0 for Elliptical solutions or 1 for Hyperbolic Solutions mesh or 2 for Parabolic Solutions\n");
    int ch;
    scanf("%d",&ch);
    if(ch==1)
        Hyperbolic();
    else if(ch==0)
        Eliptical();
    else if(ch==2)
        Parabolic();
    else    
        printf("WRONG CHOICE!\n");

    return 0;
}

void Eliptical()
{
    printf("Enter 0 for even mesh and 1 for odd mesh\n");
    int ch;
    scanf("%d",&ch);
    if(ch==1)
        manual_input_mesh_odd();
    else if(ch==0)
        manual_input_mesh_even();   
}