#include<stdio.h>
#include<stdlib.h>
// #include<string.h>

void flag()
{
    printf("??????????............");
}

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
    printf("%d ",info.I);
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


void insert_front(NODE head,INFO elem)
{
    NODE temp;
    temp=getNode();
    temp->info=elem;
    temp->link=head->link;
    head->link=temp;
}
void insert_rear(NODE head,INFO elem)
{
    NODE cur=head->link;
    NODE temp;
    temp=getNode();
    temp->info=elem;
    temp->link=head;
    while(cur->link!=head)
    {
        cur=cur->link;
    }
    cur->link=temp;
}
void delete_front(NODE head)
{
    NODE cur=head->link;
    if(head==head->link)
    {
        printf("No elements\n");
        return;
    }
    head->link=cur->link;
    printf("%d deleted\n",cur->info.I);
    free(cur);
}
void delete_rear(NODE head)
{
    NODE cur=head->link, prev;
    if(cur==head)
    {
        printf("No elements\n");
        return;
    }
    prev=cur;
    while(cur->link!=head)
    {
        prev=cur;
        cur=cur->link;
    }
    prev->link=head;
    printf("%d deleted\n",cur->info.I);
    
    free(cur);
}
void display(NODE head)
{
    NODE cur=head->link;
    if(cur==head)
    {
        printf("No elements\n");
        return;
    }
    printf("Elements of list are:\n");
    while(cur!=head)
    {
        print(cur->info);
        printf("\n");
        cur=cur->link;
    }
}

int count(NODE head)
{
    
    NODE cur=head->link;
    if(cur==head)
        return 0;
    // if(last->link=last)
    //     return 1;
    int cnt=1;
    while(cur->link!=head)
    {
        cnt++;
        cur=cur->link;
    }   
    return cnt;
}


void sort(NODE head)
{
    int size_sll,i,j,temp;
    size_sll=count(head);
    NODE first , next;
    if(size_sll<2)
        return;
    for(i=0;i<size_sll;i++)
    {
        next=head->link;
        for(j=0;j<size_sll-i-1;j++)
        {
            first=next;
            next=first->link;
            if((first->info.I) > (next->info.I))
            {
                temp = next->info.I;
                next->info.I = first->info.I;
                first->info.I = temp;
            }
        }
    }
}

NODE merge(NODE head1,NODE head2)
{
    NODE merge_head,temp,cur,mer_cur;
    merge_head=getNode();
    merge_head->link=merge_head;
    int count1,count2;
    count1=count(head1);
    count2=count(head2);
    cur=head1->link;
    mer_cur=merge_head;
    while(count1--)
    {
        temp=getNode();
        temp->info=cur->info;
        cur=cur->link;
        mer_cur->link=temp;
        mer_cur=temp;
    }
    cur=head2->link;
    while(count2--)
    {
        temp=getNode();
        temp->info=cur->info;
        cur=cur->link;
        mer_cur->link=temp;
        mer_cur=temp;
    }
    mer_cur->link=merge_head;
    return merge_head;
}

NODE copy(NODE head)
{
    NODE copy_head,temp,cur,mer_cur;
    copy_head=getNode();
    copy_head->link=copy_head;
    int count1,count2;
    count1=count(head);
    cur=head->link;
    mer_cur=copy_head;
    while(count1--)
    {
        temp=getNode();
        temp->info=cur->info;
        cur=cur->link;
        mer_cur->link=temp;
        mer_cur=temp;
    }
    mer_cur->link=copy_head;
    return copy_head;
}

int main()
{
	int ch;
    NODE head,head1;
    head1=getNode();
    head=getNode();
    head->link=head;
    head1->link=head1;
    INFO elem;
	while(1)
	{//1ins,2del,3dis
        printf("Enter the operation no\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
                acc(&elem);
				insert_front(head,elem);
				break;
			case 2:
                acc(&elem);
				insert_rear(head,elem);
				break;
			case 3:
				delete_front(head);
			    break;
			case 4:
				delete_rear(head);
			    break;
			case 5:
				display(head);
			    break;
            case 6:
                printf("\n%d\n",count(head));
                break;
            case 7:
                sort(head);
                break;
            case 8:
                printf("\n %d\n",head->info.I);
                break;
            case 9:
                acc(&elem);
				insert_front(head1,elem);
                break;
            case 10:
                head1=merge(head1,head);
                display(head1);
                break;
            case 11:
                head1=copy(head);
                display(head1);
                break;
			default:
				return 0;
		}
		printf("\n___\n");
	}
	return 0;
}