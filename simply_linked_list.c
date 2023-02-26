#include<stdio.h>
#include<stdlib.h>
// #include<string.h>

typedef
struct information
{
    int I;
    char C;
    char S[100];
    double D;
}INFO;

struct node
{
    INFO info;
    struct node *link;
};

typedef struct node * NODE;

void print(INFO info)
{
    printf("%d",info.I);
}
void acc(INFO *info)
{
    printf("Enter Value:");
    scanf("%d",&(info->I));
}



NODE getNode()
{
    NODE x;
    x= (NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("NO Space");
        exit(0);
    }
    return x;
}


NODE insert_front(NODE first,INFO elem)
{
    NODE temp;
    temp=getNode();
    temp->info=elem;
    temp->link=first;
    return temp;
}
NODE insert_rear(NODE first,INFO elem)
{
    NODE temp,prev=first,cur=first;
    temp=getNode();
    temp->info=elem;
    temp->link=NULL;
    if(first==NULL)
    {
        return temp;
    }
    while(cur!=NULL)
    {
        prev=cur;
        cur=cur->link;
    }
    prev->link=temp;
    return first;
}
NODE delete_front(NODE first)
{
    NODE temp;
    if(first==NULL)
    {
        printf("No elements\n");
        return NULL;
    }
    temp=first->link;
    print(first->info);
    printf("deleted\n");
    free(first);
    return temp;
}
NODE delete_rear(NODE first)
{
    NODE temp,prev=first,cur=first;
    if(first==NULL)
    {
        printf("No elements\n");
        return NULL;
    }
    while(cur->link!=NULL)
    {
        prev=cur;
        cur=cur->link;
    }
    prev->link=NULL;
    print(cur->info);
    printf("deleted\n");
    free(cur);
    return first;
}
void display(NODE first)
{
    NODE temp,cur=first;
    if(first==NULL)
    {
        printf("No elements\n");
        return;
    }
    printf("Elements of list are:\n");
    while(cur!=NULL)
    {
        print(cur->info);
        printf("\n");
        cur=cur->link;
    }
}

int count(NODE first)
{
    int cnt=0;
        NODE temp,cur=first;
    if(first==NULL)
    {
        return 0;
    }
    printf("Elements of list are:\n");
    while(cur!=NULL)
    {
        cnt++;
        cur=cur->link;
    }
    return cnt;
}

void sort(NODE first)
{
    int size_sll,i,j;
    size_sll=count(first);
    NODE prev=first,cur=first,temp;
    for(i=0;i<size_sll;i++)
    {
        for(j=0;j<size_sll-i-1;j++)
        {

        }
    }

}
int main()
{
	int ch;
    NODE first=NULL;
    INFO elem;
	while(1)
	{//1ins,2del,3dis
        printf("Enter the operation no\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
                acc(&elem);
				first=insert_front(first,elem);
				break;
			case 2:
                acc(&elem);
				first=insert_rear(first,elem);
				break;
			case 3:
				first=delete_front(first);
			    break;
			case 4:
				first=delete_rear(first);
			    break;
			case 5:
				display(first);
			    break;
            case 6:
                printf("\n%d",count(first));
                break;
			default:
				return 0;
		}
		printf("\n___\n");
	}
	return 0;
}