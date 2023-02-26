#include<stdio.h>
#include<stdlib.h>  // for clear screen function
#include<math.h>
#include<string.h>
#define MAX 20
typedef
struct array
{
    double b[MAX][MAX];
    double h,c,k;
    int size,mode,timesteps;
}M;


struct poly
{
    double px,pt,cf;
    struct poly * link;
};

typedef struct poly * P;


void print_mesh(M m);
void entry_mesh_hyper(int size);
void init_Hyberbolic(M *m1);
void calc_Hyperbolic(M *m1);
void Hyperbolic();
void Eliptical();
void plus(M *m,int i,int j,int offset);
void cross(M *m,int i,int j,int offset);
void V_shape(M *m,int i,int j,int offset);
void arrow_shape(M *m,int i,int j,int offset);
void entry_mesh(int i);
void calculate_mesh_even(M *m);
void border_input_even(M *m);
void manual_input_mesh_even();
void calculate_mesh_odd(M *m);
void border_input_odd(M *m);
void print_mesh_odd(M m);
void manual_input_mesh_odd();
void Parabolic();
void entry_mesh_para(int sizex,int sizey);
void init_Parabolic(M *m);
void calc_Parabolic_Crank(M *m);
void calc_Parabolic_Brende(M *m);
void print_mesh_para(M m);
void small_print(double val,FILE * fp);
void big_print(double val,FILE * fp);
double evaluate(P p1,double x,double t);
void read_Poly(P p1);
void displayPoly(P head);
void display(P head);
P getPoly();
void step_input(M *m);
void step_input_mesh_even();
void step_input_mesh_odd();
void step_input_hyper(M *m);
void step_input_para(M *m);
void prank(double a)
{
    if((a==420)||(a==69)||(a==69420)||(a==42069))
        printf("Hmmm, a person of culture as well huh?\n\n");
}

P getPoly()
{
    P x;
    x= (P)malloc(sizeof(struct poly));
    if(x==NULL)
    {
        printf("NO Space");
        exit(0);
    }
    return x;
}


void read_Poly(P p1)
{
    P temp,next;
    int i,n;
    printf("Enter the no of terms for polynomial\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        temp=getPoly();
        printf("\nEnter coefficient and powers of x and t\n");
        scanf("%lf%lf%lf",&(temp->cf),&(temp->px),&(temp->pt));
        next=p1->link;
        p1->link=temp;
        temp->link=next;
    }
}


void display(P head)
{
    P cur=head->link;
    if(cur==head)
    {
        printf("\nNo elements\n");
        return;
    }
    printf("\nElements of Polynomial are:\n");
    while(cur!=head)
    {
        if(cur->cf>=0)
            printf("+");
        printf("%f( X^%d t^%d)",cur->cf,cur->px,cur->pt);
        
        cur=cur->link;
        
    }
    printf("\n");
}

void displayPoly(P head)
{
    P cur=head->link;
    if(cur==head)
    {
        printf("\nNo elements\n");
        return;
    }
    printf("\nElements of Polynomial are:\n");
    while(cur!=head)
    {
        if(cur->cf>0)
        {
            printf("+%f( ",cur->cf);
            if(cur->px==0){}
            else if(cur->px==1)
            {
                printf("X ");
            }
            else
            {
                printf("X^%d ",(int)cur->px);
            }
            if(cur->pt==0){}
            else if(cur->pt==1)
            {
                printf("t ");
            }
            else
            {
                printf("t^%d ",(int)cur->pt);
            }
            
            printf(")");
        }   
        else if(cur->cf<0)
        {
            printf("%f( ",cur->cf);
            if(cur->px==0){}
            else if(cur->px==1)
            {
                printf("X )");
            }
            else
            {
                printf("X^%d )",cur->px);
            }
            
        }
        cur=cur->link;
    }
    printf("\n");
}


double evaluate(P p1,double x,double t)
{
    double sum=0;
    P cur=p1->link;
    // printf("Enter the values of x\n");
    // scanf("%d",&x);
    while(cur!=p1)
    {
        if((cur->cf)!=0)
            sum=sum+cur->cf*pow(x,cur->px)*pow(t,cur->pt);
        cur=cur->link;
    }
    return sum;
}

void small_print(double val,FILE *fp)
{
    double temp=val;
    int expo=1;
    while(fabs(temp)<1.0)
    {
        expo++;
        temp*=10;
    }
    fprintf(fp,"%.3lfx10^-%d\t",temp,expo);
}

void big_print(double val,FILE * fp)
{
    double temp=val;
    int expo=1;
    while(fabs(temp)>10.0)
    {
        expo++;
        temp/=10;
    }
    fprintf(fp,"%.3lfx10^%d\t",temp,expo);
}

void init_Parabolic(M *m)
{
    // entry_mesh_hyper(m->size);
    entry_mesh_para(m->size,m->timesteps);
    m->mode=0;
    int i;
    for(i=0;i<m->timesteps;i++)
    {
        printf("Enter value at (0,%d):",i);
        scanf("%lf",&(m->b[0][i]));
        prank(m->b[0][i]);
    }
    for(i=0;i<(m->timesteps);i++)
    {
        printf("Enter value at (%d,%d):",(m->size)-1,i);
        scanf("%lf",&(m->b[(m->timesteps)-1][i]));
        prank(m->b[(m->timesteps)-1][i]);
    }
    for(i=1;i<(m->size)-1;i++)
    {
        printf("Enter value at (%d,%d):",i,(m->size)-1);
        scanf("%lf",&(m->b[i][(m->timesteps)-1]));
        prank(m->b[i][(m->timesteps)-1]);
    }
}


void calc_Parabolic_Crank(M *m)
{
    if(m->size==3)
    {
        for(int i=(m->timesteps)-2;i>=0;i--)
        {
            m->b[1][i]=((m->b[0][i])+(m->b[2][i])+(m->b[0][i+1])+(m->b[2][i+1]))/4.0;
        }
    }
    if(m->size==4)
    {
        double d1,d2;
        for(int i=(m->timesteps)-2;i>=0;i--)
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
        for(int i=(m->timesteps)-2;i>=0;i--)
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
        for(int i=(m->timesteps)-2;i>=0;i--)
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
    if(m->size>6)
    {
        printf("Just use brende scmidth instead, why bother this method");
        exit(0);
    }
}

void entry_mesh_para(int sizex,int sizey)
{
    printf("Enter the values for coordinates as shown below");
    for(int i=sizey-1;i>-1;i--)
    {
        printf("\n");
        for(int j=0;j<sizex;j++)
        {
            if(i==sizey-1  || j==0 ||j==sizex-1)
                printf("(%d,%d)\t\t",j,i);
            else
                printf("\t\t");
        }
        printf("\n");
    }
}

void print_mesh_para(M m)
{
    FILE *fp;
    fp=fopen("Output.txt","w+");
    fprintf(fp,"\n\n\n");
    double val;
    for(int i=m.timesteps-1;i>=0;i--)
    {
        for(int j=0;j<m.size;j++)
        {
            val=m.b[j][i];
            if(val==0)
            {
                fprintf(fp,"%.3lf\t\t",val);
            }
            else if(fabs(val)<0.01)
            {
                small_print(val,fp);
            }
            else if((val > -100.0 ) && ( val< 1000.0 ))
            {
                fprintf(fp,"%.3lf\t\t",val);
            }
            else
            {
                big_print(val,fp);
            }
        }
        fprintf(fp,"\n\n");
    }
    fclose(fp);
}

void Parabolic()
{
    system("cls");
    M m;
    printf("Enter no of steps in x:");
    scanf("%d",&(m.size));
    printf("Enter no of steps in t:");
    scanf("%d",&(m.timesteps));
    int ch;

    printf("Enter 0 for inputing each border value and 1 for input of border funtion\n");
    scanf("%d",&ch);
    if(ch==0)
        init_Parabolic(&m);
    else    
        step_input_para(&m);
    printf("Enter 0 to use Crank-Nickolson or 1 to use Brende-Scmidth Method\n");
    scanf("%d",&ch);
    if(ch==0)
        calc_Parabolic_Crank(&m);
    else
        calc_Parabolic_Brende(&m);

    print_mesh_para(m);
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
    m1->mode=0;
    int i;
    for(i=0;i<m1->size;i++)
    {
        printf("Enter value at (0,%d):",i);
        scanf("%lf",&(m1->b[0][i]));
        prank(m1->b[0][i]);
    }
    for(i=0;i<(m1->size);i++)
    {
        printf("Enter value at (%d,%d):",(m1->size)-1,i);
        scanf("%lf",&(m1->b[(m1->size)-1][i]));
        prank(m1->b[(m1->size)-1][i]);
    }
    for(i=1;i<(m1->size)-1;i++)
    {
        printf("Enter value at (%d,%d):",i,(m1->size)-1);
        scanf("%lf",&(m1->b[i][(m1->size)-1]));
        prank(m1->b[i][(m1->size)-1]);
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
    FILE *fp;
    fp=fopen("Output.txt","w+");
    fprintf(fp,"\n\n\n");
    double val;
    for(int i=m.size-1;i>=0;i--)
    {
        for(int j=0;j<m.size;j++)
        {
            val=m.b[j][i];
            if(val==0)
            {
                fprintf(fp,"%.3lf\t\t",val);
            }
            else if(fabs(val)<0.01)
            {
                small_print(val,fp);
            }
            else if((val > -100.0 ) && ( val< 1000.0 ))
            {
                fprintf(fp,"%.3lf\t\t",val);
            }
            else
            {
                big_print(val,fp);
            }
        }
        fprintf(fp,"\n\n");
    }
    fclose(fp);
}

void Hyperbolic()
{
    system("cls");
    M m;
    printf("Enter no of steps in the values:");
    scanf("%d",&(m.size));
    int ch;
    printf("Enter 0 for inputing each border value and 1 for input of border function\n");
    scanf("%d",&ch);
    if(ch==0)
        init_Hyberbolic(&m);
    else    
        step_input_hyper(&m);
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

void V_shape(M *m,int i,int j,int offset)
{
    m->b[i][j]=(double)((m->b[i-offset][j+offset])+(m->b[i+offset][j+offset]))/2.0;
}

void arrow_shape(M *m,int i,int j,int offset)
{
    m->b[i][j]=(double)((m->b[i-offset][j+offset])+(2*(m->b[i][j+offset]))+(m->b[i+offset][j+offset]))/4.0;
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
        prank((m->b[0][i]));
    }
    for(i=0;i<5;i++)
    {
        printf("Enter value at (4,%d):",i);
        scanf("%lf",&(m->b[4][i]));
        prank(m->b[4][i]);
    }
    for(i=1;i<4;i++)
    {
        printf("Enter value at (%d,0):",i);
        scanf("%lf",&(m->b[i][0]));
        prank(m->b[i][0]);
    }
    for(i=1;i<4;i++)
    {
        printf("Enter value at (%d,4):",i);
        scanf("%lf",&(m->b[i][4]));
        prank(m->b[i][4]);
    }
}


void manual_input_mesh_even()
{
    system("cls"); // to clear screen
    M m;
    m.size=5;
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
        prank(m->b[0][i]);
    }
    for(i=1;i<3;i++)
    {
        printf("Enter value at (3,%d):",i);
        scanf("%lf",&(m->b[3][i]));
        prank((m->b[3][i]));
    }
    for(i=1;i<3;i++)
    {
        printf("Enter value at (%d,0):",i);
        scanf("%lf",&(m->b[i][0]));
        prank((m->b[i][0]));
    }
    for(i=1;i<3;i++)
    {
        printf("Enter value at (%d,3):",i);
        scanf("%lf",&(m->b[i][3]));
        prank((m->b[i][3]));
    }
}

void print_mesh_odd(M m)
{
    FILE *fp;
    fp=fopen("Output.txt","w+");
    fprintf(fp,"\n\n\n");
    double val;
    for(int i=3;i>=0;i--)
    {
        for(int j=0;j<4;j++)
        {
            if((i%3==0)&&(j%3==0))
            {
                fprintf(fp,"\t\t");
                continue;
            }
            val=m.b[j][i];
            if(val==0)
            {
                fprintf(fp,"%.3lf\t\t",val);
            }
            else if(fabs(val)<0.01)
            {
                small_print(val,fp);
            }
            else if((val > -100.0 ) && ( val< 1000.0 ))
            {
                fprintf(fp,"%.3lf\t\t",val);
            }
            else
            {
                big_print(val,fp);
            }
        }
        fprintf(fp,"\n\n");
    }
    fclose(fp);
}

void manual_input_mesh_odd()
{
    system("cls"); // to clear screen
    M m;
    m.size=4;
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
    // P p1;
    // p1=getPoly();
    // p1->link=p1;
    // read_Poly(p1);
    // displayPoly(p1);
    // printf("%.3f",evaluate(p1,2,3));
    printf("\nProgram end");
    return 0;
}

void Eliptical()
{
    int ch;
    printf("Enter 0 for inputing each border value and 1 for input of border polynomial\n");
    scanf("%d",&ch);
    if(ch==0)
    {
        printf("Enter 0 for even mesh and 1 for odd mesh\n");
        scanf("%d",&ch);
        if(ch==1)
            manual_input_mesh_odd();
        else if(ch==0)
            manual_input_mesh_even();   
    }
    else
    {
        printf("Enter 0 for even mesh and 1 for odd mesh\n");
        scanf("%d",&ch);
        if(ch==0)
            step_input_mesh_even();
        else if(ch==1)
            step_input_mesh_odd();   
    }
}

void step_input_mesh_even()
{
    system("cls"); // to clear screen
    M m;
    m.size=5;
    step_input(&m);
    // printf("chcek-1");
    calculate_mesh_even(&m);
    // printf("-%lf-check-2",m.b[3][4]);
    print_mesh(m);   
}
void step_input_mesh_odd()
{
    system("cls"); // to clear screen
    M m;
    m.size=4;
    step_input(&m);
    calculate_mesh_odd(&m);
    print_mesh_odd(m);   
}

void step_input(M *m)
{
    double bord_x_min,bord_x_max,bord_t_min,bord_t_max,h,k;
    printf("enter border values of x:\n");
    scanf("%lf %lf",&bord_x_min,&bord_x_max);
    h=(bord_x_max-bord_x_min)/((float)m->size-1);
    printf("enter border values of t:\n");
    scanf("%lf %lf",&bord_t_min,&bord_t_max);
    k=(bord_t_max-bord_t_min)/((float)m->size-1);
    P up,down,left,right;
    up=getPoly();
    up->link=up;
    down=getPoly();
    down->link=down;
    left=getPoly();
    left->link=left;
    right=getPoly();
    right->link=right;
    printf("Enter Polynomial equation of top border\n");
    read_Poly(up);
    printf("Enter Polynomial equation of bottom border\n");
    read_Poly(down);
    printf("Enter Polynomial equation of left border\n");
    read_Poly(left);
    printf("Enter Polynomial equation of rigth border\n");
    read_Poly(right);
    for(int i=m->size-1;i>=0;i--)
    {
        for(int j=0;j<m->size;j++)
        {
            if(j==0)
            {
                m->b[j][i]=evaluate(left,bord_x_min,bord_t_min+i*k);
            }
            else if(j==m->size-1)
            {
                m->b[j][i]=evaluate(right,bord_x_max,bord_t_min+i*k);
            }
            else if(i==0)
            {
                m->b[j][i]=evaluate(down,bord_x_min+j*h,bord_t_min);
            }else if(i==m->size-1)
            {
                m->b[j][i]=evaluate(up,bord_x_min+j*h,bord_t_max);
            }
        }
        // printf("check%d\n",i);
    }

}



void step_input_hyper(M *m)
{
    m->mode=1;
    double bord_x_min,bord_x_max,bord_t_min,bord_t_max,h,k;
    printf("enter border values of x:\n");
    scanf("%lf %lf",&bord_x_min,&bord_x_max);
    h=(bord_x_max-bord_x_min)/((float)m->size-1);
    m->h=h;
    int ch;
    printf("Enter 0 for input of Step value and 1 for input of borders\n");
    scanf("%d",&ch);
    if(ch==1)
    {    
        printf("enter border values of t:\n");
        scanf("%lf %lf",&bord_t_min,&bord_t_max);
        k=(bord_t_max-bord_t_min)/((float)m->size-1);
    }
    else
    {
        printf("enter step value of t:\n");
        scanf("%lf",&k);
        bord_t_min=0;
        bord_t_max=((m->size)-1)*k;
    }
    m->k=k;    
    P up,down,left,right;
    up=getPoly();
    up->link=up;
    down=getPoly();
    down->link=down;
    left=getPoly();
    left->link=left;
    right=getPoly();
    right->link=right;
    printf("Enter Polynomial equation of top border/initial conditions\n");
    read_Poly(up);
    printf("Enter Polynomial equation of left border\n");
    read_Poly(left);
    printf("Enter Polynomial equation of rigth border\n");
    read_Poly(right);
    int i;
    for(i=0;i<m->size;i++)
    {
        m->b[0][i]=evaluate(left,bord_x_min,bord_t_min+i*k);
    }
    for(i=0;i<(m->size);i++)
    {
        m->b[(m->size)-1][i]=evaluate(right,bord_x_max,bord_t_min+i*k);
    }
    for(i=1;i<(m->size)-1;i++)
    {
        m->b[i][(m->size)-1]=evaluate(up,bord_x_min+i*h,bord_t_max);
    }
}
void calc_Parabolic_Brende(M *m)
{
    printf("Enter the value of c^2 from the heat equation given:");
    int i,j;
    scanf("%lf",&(m->c));
    if(m->mode==0)
    {
        printf("Enter the value of h and k from the heat equation given:");
        scanf("%lf%lf",&(m->h),&(m->k));
    }
    double lambda_reci;
    lambda_reci=(m->h)*(m->h)/((m->c)*(m->k));
    if(lambda_reci>1.95 && lambda_reci <2.05)
    {
        for(i=m->timesteps-2;i>=0;i--)
        {
            for(j=1;j<m->size-1;j++)
            {
                V_shape(m,j,i,1);
            }
        }
    }
    else if(lambda_reci>3.95 && lambda_reci <4.05)
    {
        for(i=m->timesteps-2;i>=0;i--)
        {
            for(j=1;j<m->size-1;j++)
            {
                arrow_shape(m,j,i,1);
            }
        }
    }
}

void step_input_para(M *m)
{
    m->mode=1;
    double bord_x_min,bord_x_max,bord_t_min,bord_t_max,h,k;
    printf("enter border values of x:\n");
    scanf("%lf %lf",&bord_x_min,&bord_x_max);
    h=(bord_x_max-bord_x_min)/((float)m->size-1);
    m->h=h;
    int ch;
    printf("Enter 0 for input of Step value and 1 for input of borders\n");
    scanf("%d",&ch);
    if(ch==1)
    {    
        printf("enter border values of t:\n");
        scanf("%lf %lf",&bord_t_min,&bord_t_max);
        k=(bord_t_max-bord_t_min)/((float)m->size-1);
    }
    else
    {
        printf("enter step value of t:\n");
        scanf("%lf",&k);
        bord_t_min=0;
        bord_t_max=((m->size)-1)*k;
    }
    m->k=k;    
    P up,down,left,right;
    up=getPoly();
    up->link=up;
    down=getPoly();
    down->link=down;
    left=getPoly();
    left->link=left;
    right=getPoly();
    right->link=right;
    printf("Enter Polynomial equation of top border/initial conditions\n");
    read_Poly(up);
    printf("Enter Polynomial equation of left border\n");
    read_Poly(left);
    printf("Enter Polynomial equation of rigth border\n");
    read_Poly(right);
    int i;
    for(i=0;i<m->timesteps;i++)
    {
        m->b[0][i]=evaluate(left,bord_x_min,bord_t_min+i*k);
    }
    for(i=0;i<(m->timesteps);i++)
    {
        m->b[(m->size)-1][i]=evaluate(right,bord_x_max,bord_t_min+i*k);
    }
    for(i=1;i<(m->size)-1;i++)
    {
        m->b[i][(m->timesteps)-1]=evaluate(up,bord_x_min+i*h,bord_t_max);
    }
}