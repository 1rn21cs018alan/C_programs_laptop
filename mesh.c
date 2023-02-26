#include<stdio.h>
#include<stdlib.h>  // for clear screen function
#include<math.h>

typedef
struct array
{
    float b[11][11];
    int size;
    char type;
}M;

void print_mesh_hyper(M m);
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
        scanf("%f",&(m1->b[0][i]));
    }
    for(i=0;i<(m1->size);i++)
    {
        printf("Enter value at (%d,%d):",(m1->size)-1,i);
        scanf("%f",&(m1->b[(m1->size)-1][i]));
    }
    for(i=1;i<(m1->size)-1;i++)
    {
        printf("Enter value at (%d,%d):",i,(m1->size)-1);
        scanf("%f",&(m1->b[i][(m1->size)-1]));
    }
    // print_mesh_hyper(*m1);
}
void calc_Hyperbolic(M *m1)
{
    int i,j;
    for(i=1;i<(m1->size)-1;i++)
    {
        m1->b[i][(m1->size)-2]=((m1->b[i-1][(m1->size)-1])+(m1->b[i+1][(m1->size)-1]))/2.0;
    }
    for(i=(m1->size)-3;i>=0;i--)
    {
        for(j=1;j<(m1->size)-1;j++)
        {
            m1->b[j][i]=(m1->b[j-1][i+1])+(m1->b[j+1][i+1])-(m1->b[j][i+2]);
        }
    }
    // print_mesh_hyper(*m1);
}

void print_mesh_hyper(M m)
{
    printf("\n\n\n");
    for(int i=m.size-1;i>=0;i--)
    {
        for(int j=0;j<m.size;j++)
        {
            if((  m.b[j][j] > -1000.0 ) && ( m.b[j][i] < 1000.0 ))
            {
                printf("%.3f\t\t",m.b[j][i]);
            }
            else
            {
                printf("%.3f\t",m.b[j][i]);
            }
        }
        printf("\n\n");
    }
}

void Hyperbolic()
{
    M m;
    printf("Enter no of steps in the values:");
    scanf("%d",&(m.size));
    init_Hyberbolic(&m);
    calc_Hyperbolic(&m);
    print_mesh_hyper(m);
}

void Eliptical();
void plus(float b[5][5],int i,int j,int offset)
{
    b[i][j]=(float)(b[i-offset][j]+b[i+offset][j]+b[i][j-offset]+b[i][j+offset])/4.0;
}

void cross(float b[5][5],int i,int j,int offset)
{
    b[i][j]=(float)(b[i-offset][j-offset]+b[i+offset][j-offset]+b[i+offset][j+offset]+b[i-offset][j+offset])/4.0;
}
void plus1(float b[4][4],int i,int j,int offset)
{
    b[i][j]=(float)(b[i-offset][j]+b[i+offset][j]+b[i][j-offset]+b[i][j+offset])/4.0;
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

void cross1(float b[4][4],int i,int j,int offset)
{
    b[i][j]=(float)(b[i-offset][j-offset]+b[i+offset][j-offset]+b[i+offset][j+offset]+b[i-offset][j+offset])/4.0;
}



void calculate_mesh_even(float b[5][5])
{
    plus(b,2,2,2);
    cross(b,1,1,1);
    cross(b,1,3,1);
    cross(b,3,1,1);
    cross(b,3,3,1);
    plus(b,1,2,1);
    plus(b,2,1,1);
    plus(b,3,2,1);
    plus(b,2,3,1);
}

void border_input_even(float b[5][5])
{
    int i;
    for(i=0;i<5;i++)
    {
        printf("Enter value at (0,%d):",i);
        scanf("%f",&b[0][i]);
    }
    for(i=0;i<5;i++)
    {
        printf("Enter value at (4,%d):",i);
        scanf("%f",&b[4][i]);
    }
    for(i=1;i<4;i++)
    {
        printf("Enter value at (%d,0):",i);
        scanf("%f",&b[i][0]);
    }
    for(i=1;i<4;i++)
    {
        printf("Enter value at (%d,4):",i);
        scanf("%f",&b[i][4]);
    }
}

void print_mesh_even(float b[5][5])
{
    printf("\n\n\n");
    for(int i=4;i>=0;i--)
    {
        for(int j=0;j<5;j++)
        {
            if((  b[j][j] > -1000.0 ) && ( b[j][i] < 1000.0 ))
            {
                printf("%.3f\t\t",b[j][i]);
            }
            else
            {
                printf("%.3f\t",b[j][i]);
            }
        }
        printf("\n\n");
    }
}

void manual_input_mesh_even()
{
    system("cls"); // to clear screen
    float b[5][5];
    entry_mesh(0);
    border_input_even(b);
    calculate_mesh_even(b);
    print_mesh_even(b);
}

/***************************************************************************************
*/
// void getCofactor(int A[4][4], int temp[4][4], int p, int q,
//                  int n)
// {
//     int i = 0, j = 0;
//     for (int row = 0; row < n; row++) {
//         for (int col = 0; col < n; col++) {
//             if (row != p && col != q) {
//                 temp[i][j++] = A[row][col];
//                 if (j == n - 1) {
//                     j = 0;
//                     i++;
//                 }
//             }
//         }
//     }
// }


// int determinant(int A[4][4], int n)
// {
//     int D = 0;
//     if (n == 1)
//         return A[0][0];
 
//     int temp[4][4]; 
 
//     int sign = 1; 
//     for (int f = 0; f < n; f++) {
//         getCofactor(A, temp, 0, f, n);
//         D += sign * A[0][f] * determinant(temp, n - 1);
//         sign = -sign;
//     }

//     return D;
// }


// void adjoint(int A[4][4], int adj[4][4])
// {
//     int sign = 1, temp[4][4];
 
//     for (int i = 0; i < 4; i++) {
//         for (int j = 0; j < 4; j++) {
            
//             getCofactor(A, temp, i, j, 4);
//             sign = ((i + j) % 2 == 0) ? 1 : -1;
//             adj[j][i] = (sign) * (determinant(temp, 4 - 1));
//         }
//     }
// }


// int inverse(int A[4][4], float inverse[4][4])
// {
//     // Find determinant of A[][]
//     int det = determinant(A, 4);
//     if (det == 0) {
//         printf( "Singular matrix, can't find its inverse");
//         return 0;
//     }
 
//     // Find adjoint
//     int adj[4][4];
//     adjoint(A, adj);
 
//     // Find Inverse using formula "inverse(A) =
//     // adj(A)/det(A)"
//     for (int i = 0; i < 4; i++)
//         for (int j = 0; j < 4; j++)
//             inverse[i][j] = adj[i][j] / ((float)det);
 
//     return 1;
// }


// void display(float A[4][4])
// {
//     for (int i = 0; i < 4; i++) {
//         for (int j = 0; j < 4; j++)
//             printf("%.8f\t\t",A[i][j]);
//         printf("\n");
//     }
// }


// void displayint(int A[4][4])
// {
//     for (int i = 0; i < 4; i++) {
//         for (int j = 0; j < 4; j++)
//             printf("%d \t",A[i][j]);
//         printf("\n");
//     }
// }


// int main2()
// {
//     int A[4][4] = { { 4, -1, -1, 0 },
//                     { -1, 4, 0, -1 },
//                     { -1, 0, 4, -1 },
//                     { 0, -1, -1, 4 } };
 
//     int adj[4][4]; // To store adjoint of A[][]
 
//     float inv[4][4]; // To store inverse of A[][]
 
//     printf( "Input matrix is :\n");
//     displayint(A);
 
//     printf("\nThe Adjoint is :\n");
//     adjoint(A, adj);
//     displayint(adj);
 
//     printf("\nThe Inverse is :\n");
//     if (inverse(A, inv)==1)
//         display(inv);
 
//     return 0;
// }


void calculate_mesh_odd(float b[4][4])
{
    float A,B,C,D;
    A=b[0][2]+b[1][3];//for corner 0,3->1,2
    B=b[2][3]+b[3][2];//for corner 3,3->2,2
    C=b[2][0]+b[3][1];//for corner 3,0->2,1
    D=b[1][0]+b[0][1];//for corner 0,0->1,1

    // found this formula by trial and error with matrix multiplication method of solving linear equation
    b[1][1]=(7*D+2*A+2*C+B)/24.0;
    b[1][2]=(7*A+2*B+2*D+C)/24.0;
    b[2][1]=(7*C+2*D+2*B+A)/24.0;
    b[2][2]=(7*B+2*A+2*C+D)/24.0;
}

void border_input_odd(float b[4][4])
{
    int i;
    for(i=1;i<3;i++)
    {
        printf("Enter value at (0,%d):",i);
        scanf("%f",&b[0][i]);
    }
    for(i=1;i<3;i++)
    {
        printf("Enter value at (3,%d):",i);
        scanf("%f",&b[3][i]);
    }
    for(i=1;i<3;i++)
    {
        printf("Enter value at (%d,0):",i);
        scanf("%f",&b[i][0]);
    }
    for(i=1;i<3;i++)
    {
        printf("Enter value at (%d,3):",i);
        scanf("%f",&b[i][3]);
    }
}

void print_mesh_odd(float b[4][4])
{
    printf("\n\n\n");
    for(int i=3;i>=0;i--)
    {
        for(int j=0;j<4;j++)
        {
            if((i%3==0)&&(j%3==0))
            {
                printf("\t\t");
                continue;
            }
            if((  b[j][j] > -1000.0 ) && ( b[j][i] < 1000.0 ))
            {
                printf("%.3f\t\t",b[j][i]);
            }
            else
            {
                printf("%.3f\t",b[j][i]);
            }
        }
        printf("\n\n");
    }
}

// void entry_mesh(int i)
// {
//     if(i)
//     {
//         printf("\t\t(1,3)\t\t(2,3)\n\n");
//         printf("(0,2)\t\t\t\t\t\t(3,2)\n\n");
//         printf("(0,1)\t\t\t\t\t\t(3,1)\n\n");
//         printf("\t\t(1,0)\t\t(2,0)\n\n");
//     }
//     else
//     {
//         for(int i=4;i>=0;i--)
//         {
//             for(int j=0;j<5;j++)
//             {
//                 if((i%4==0)||(j%4==0))
//                 {
//                     printf("(%d,%d)\t\t",i,j);
//                     continue;
//                 }
//                 printf("\t\t");
//             }
//             printf("\n\n");
//         }
//     }
// }

void manual_input_mesh_odd()
{
    system("cls"); // to clear screen
    float b[4][4];
    entry_mesh(1);
    border_input_odd(b);
    calculate_mesh_odd(b);
    print_mesh_odd(b);
}

int main()
{
    printf("Enter 0 for Elliptical solutions and 1 for Hyperbolic Solutions mesh\n");
    int ch;
    scanf("%d",&ch);
    if(ch==1)
        Hyperbolic();
    else if(ch==0)
        Eliptical();
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