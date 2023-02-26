#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node * llink, *rlink;
    int info;
};

typedef struct node * NODE;

NODE getNode()
{
    NODE x;
    x=(NODE) malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("No Space");
        exit(0);
    }
    return x;
}

NODE insert_front(NODE first,int elem)
{
    NODE temp;
    temp=getNode();
    temp->info=elem;
    temp->llink=NULL;
    temp->rlink=first;
    if(first!=NULL)
        first->llink=temp;
    return temp;
}

NODE insert_rear(NODE first , int elem)
{
    
    NODE temp,cur=first;
    temp=getNode();
    temp->info=elem;
    temp->rlink=NULL;
    if(first==NULL)
    {
        temp->llink=NULL;
        return temp;
    }
    while(cur->rlink!=NULL)
        cur=cur->rlink;
    cur->rlink=temp;
    temp->llink=cur;
    return first;
}

void display(NODE first)
{
    if(first==NULL)
    {
        printf("NO elements\n");
        return;
    }
    printf("Elements of DLL are:\n");
    NODE cur=first;
    while(cur!=NULL)
    {
        printf("%d\n",cur->info);
        cur=cur->rlink;
    }
}

void traverse(NODE first)
{
    printf("Enter 1 to go right and 0 to go left\n");
    int ch;
    NODE cur=first;
    if(cur==NULL)
    {
        printf("NO elements");
        return;
    }
    while(1)
    {
        printf("%d\n",cur->info);
        scanf("%d",&ch);
        if(ch==1)
        {
            if(cur->rlink!=NULL)
                cur=cur->rlink;
            else    
                printf("Reached the End at right\n");
        }
        else if(ch==0)
        {
            if(cur->llink!=NULL)
                cur=cur->llink;
            else    
                printf("Reached the End at left\n");
        }
        else if(ch==-1)
        {
            printf("Exiting traverser\n");
            return;
        }
    }
}

NODE delete_front(NODE first)
{
    NODE next;
    if(first==NULL)
    {
        printf("NO elements\n");
        return NULL;
    }
    next=first->rlink;
    if(next!=NULL)
        next->llink=NULL;
    printf("%d deleted\n",first->info);
    free(first);
    return next;
}
NODE delete_rear(NODE first)
{
    NODE cur;
    if(first==NULL)
    {
        printf("NO elements\n");
        return NULL;
    }
    if(first->rlink==NULL)
    {
        printf("%d deleted\n",first->info);
        free(first);
        return NULL;
    }
    cur=first->rlink;
    while(cur->rlink!=NULL)
    {
        cur=cur->rlink;
    }
    (cur->llink)->rlink=NULL;
    printf("%d deleted\n",cur->info);
    free(cur);
    return first;
}

int length(NODE first)
{
    int count=0;
    NODE cur=first;
    while(cur!=NULL)
    {
        count++;
        cur=cur->rlink;
    }
    return count;
}

NODE merge(NODE first, NODE second)
{
    NODE third=NULL,cur;
    cur=first;
    while(cur!=NULL)
    {
        third=insert_front(third,cur->info);
        cur=cur->rlink;
    }
    cur=second;
    while(cur!=NULL)
    {
        third=insert_front(third,cur->info);
        cur=cur->rlink;
    }
    return third;
}

NODE merge2(NODE first, NODE second)
{
    NODE third=NULL,cur,temp;
    cur=first;
    while(cur!=NULL)
    {
        temp=getNode();
        temp->info=cur->info;
        temp->llink=NULL;
        temp->rlink=third;
        if(third!=NULL)
            third->llink=temp;
        third=temp;
        cur=cur->rlink;
    }
    cur=second;
    while(cur!=NULL)
    {
        temp=getNode();
        temp->info=cur->info;
        temp->llink=NULL;
        temp->rlink=third;
        if(third!=NULL)
            third->llink=temp;
        third=temp;
        cur=cur->rlink;
    }
    return third;
}



int main()
{
	int ch;
    NODE first=NULL,second=NULL,third=NULL;
    int elem;
	while(1)
	{//1ins,2del,3dis
        printf("Enter the operation no\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
                printf("Enter the element:");
                scanf("%d",&elem);
				first=insert_front(first,elem);
				break;
			case 2:
                printf("Enter the element:");
                scanf("%d",&elem);
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
                traverse(first);
                break;
            case 7:
                printf("lenght=%d\n",length(first));
                break;
            case 8:
                third=merge(first,second);
                display(third);
                break;
            case 9:
                third=merge2(first,second);
                display(third);
                break;
            case 11:
                printf("Enter the element:");
                scanf("%d",&elem);
				second=insert_front(second,elem);
				break;
			case 21:
                printf("Enter the element:");
                scanf("%d",&elem);
				second=insert_rear(second,elem);
				break;
			case 31:
				second=delete_front(second);
			    break;
			case 41:
				second=delete_rear(second);
			    break;
			case 51:
				display(second);
			    break;
            case 61:
                traverse(second);
                break;
            case 71:
                printf("lenght=%d\n",length(second));
                break;
			default:
				return 0;
		}
		printf("\n___\n");
	}
	return 0;
}