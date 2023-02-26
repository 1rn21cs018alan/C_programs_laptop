#include<stdio.h>
#include<stdlib.h>
// #include<string.h>

void flag()
{
    printf("??????????............");
}

struct poly
{
    int px,py,pz,cf;
    struct poly * link;
};

typedef struct poly * P;


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


void insert_front(P head,int cf,int px,int py,int pz)
{
    P temp;
    temp=getPoly();
    temp->cf=cf;
    temp->px=px;
    temp->py=py;
    temp->pz=pz;
    temp->link=head->link;
    head->link=temp;
}
void insert_rear(P head,int cf,int px,int py,int pz)
{
    P cur=head->link;
    P temp;
    temp=getPoly();
    temp->cf=cf;
    temp->px=px;
    temp->py=py;
    temp->pz=pz;
    temp->link=head;
    while(cur->link!=head)
    {
        cur=cur->link;
    }
    cur->link=temp;
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
        printf("%d( X^%d Y^%d Z^%d) ",cur->cf,cur->px,cur->py,cur->pz);
        
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
            printf("+%d( ",cur->cf);
            if(cur->px==0){}
            else if(cur->px==1)
            {
                printf("X ");
            }
            else
            {
                printf("X^%d ",cur->px);
            }
            if(cur->py==0){}
            else if(cur->py==1)
            {
                printf("Y ");
            }
            else
            {
                printf("Y^%d ",cur->py);
            }
            if(cur->pz==0){}
            else if(cur->pz==1)
            {
                printf("Z ");
            }
            else
            {
                printf("Z^%d ",cur->pz);
            }
            printf(")");
        }   
        else if(cur->cf<0)
        {
            printf("%d( ",cur->cf);
            if(cur->px==0){}
            else if(cur->px==1)
            {
                printf("X ");
            }
            else
            {
                printf("X^%d ",cur->px);
            }
            if(cur->py==0){}
            else if(cur->py==1)
            {
                printf("Y ");
            }
            else
            {
                printf("Y^%d ",cur->py);
            }
            if(cur->pz==0){}
            else if(cur->pz==1)
            {
                printf("Z ");
            }
            else
            {
                printf("Z^%d ",cur->pz);
            }
            
            printf(")");
        }
        
        cur=cur->link;
        
    }
    printf("\n");
}


void read_Poly(P p1,int n)
{
    P temp,next;
    int i;
    for(i=0;i<n;i++)
    {
        temp=getPoly();
        printf("\nEnter coefficient and powers of x,y,z\n");
        scanf("%d%d%d%d",&(temp->cf),&(temp->px),&(temp->py),&(temp->pz));
        next=p1->link;
        p1->link=temp;
        temp->link=next;
    }
}

P compare(P term , P p2)
{
    P cur;
    cur=p2->link;
    while(cur!=p2)
    {
        if((cur->px == term->px)  && (cur->py == term->py ) && (cur->pz == term->pz ))
        {   
            if(term->cf==0)
            {
                return NULL;
            }
            return cur;
        }
        cur=cur->link;
    }
    return NULL;
}

void add_poly(P p1,P p2, P p3)
{
    P temp,cur;
    cur=p2->link;
    printf("\n_________________________\n");
    while(cur!=p2)
    {
        temp=compare(cur,p1);
        // printf("\n--%d( X^%d Y^%d Z^%d) ",cur->cf,cur->px,cur->py,cur->pz);
        if(temp==NULL)
        {
            insert_front(p3,cur->cf,cur->px,cur->py,cur->pz);
        }
        else 
        {
            // if((temp->cf)+(cur->cf)!=0)
                insert_front(p3,((temp->cf)+(cur->cf)),temp->px,temp->py,temp->pz);
            temp->cf=0;
        }
        cur=cur->link;
    }
    cur=p1->link;
    while(cur!=p1)
    {
        if(cur->cf!=0)
        {
            insert_front(p3,cur->cf,cur->px,cur->py,cur->pz);
        }
        cur=cur->link;
    }
}

int main()
{
    P p1;
    p1=getPoly();
    p1->link=p1;
    read_Poly(p1,3);
    display(p1);
    P p2;
    p2=getPoly();
    p2->link=p2;
    read_Poly(p2,3);
    display(p2);
    displayPoly(p1);
    displayPoly(p2);
    P p3,temp,cur=p2->link;
    p3=getPoly();
    p3->link=p3;
    cur=p2->link;
    printf("\n_________________________\n");
    // while(cur!=p2)
    // {
    //     temp=compare(cur,p1);
    //     printf("\n--%d( X^%d Y^%d Z^%d) ",cur->cf,cur->px,cur->py,cur->pz);
    //     if(temp==NULL)
    //     {
    //         printf("No Match");
            
    //         insert_front(p3,cur->cf,cur->px,cur->py,cur->pz);
    //     }
    //     else
    //     {
    //         insert_front(p3,((temp->cf)+(cur->cf)),temp->px,temp->py,temp->pz);
    //         temp->cf=0;
    //     }
    //     cur=cur->link;
    // }
    add_poly(p1,p2,p3);
    display(p3);
}