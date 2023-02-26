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


NODE insert_front(NODE last,INFO elem)
{
    NODE temp;
    temp=getNode();
    temp->info=elem;
    if(last==NULL)
        last = temp;
    else
        temp->link=last->link;
    last->link=temp;
    return last;
}
NODE insert_rear(NODE last,INFO elem)
{
    NODE temp;
    temp=getNode();
    temp->info=elem;
    if(last==NULL)
    {
        last=temp;
        last->link=temp;
        return last;
    }
    temp->link=last->link;
    last->link=temp;
    return temp;
}
NODE delete_front(NODE last)
{
    NODE temp;
    if(last==NULL)
    {
        printf("No elements\n");
        return NULL;
    }
    if(last->link==last)
    {
        print(last->info);
        printf(" deleted\n");
        free(last);
        return NULL;
    }
    temp=last->link;
    last->link=temp->link;
    print(temp->info);
    printf("deleted\n");
    free(temp);
    return last;
}
NODE delete_rear(NODE last)
{
    NODE temp;
    if(last==NULL)
    {
        printf("No elements\n");
        return NULL;
    }
    if(last->link==last)
    {
        print(last->info);
        printf(" deleted\n");
        free(last);
        return NULL;
    }
    temp=last->link;
    while(temp->link!=last)
    {
        temp=temp->link;
    }
    temp->link=last->link;
    free(last);
    return temp;
}
void display(NODE last)
{
    NODE cur=last;
    if(last==NULL)
    {
        printf("No elements\n");
        return;
    }
    printf("Elements of list are:\n");
    do
    {
        cur=cur->link;
        // flag();
        print(cur->info);
        printf("\n");
    }while(cur!=last);
}

int count(NODE last)
{
    if(last==NULL)
        return 0;
    // if(last->link=last)
    //     return 1;
    int cnt=1;
    NODE temp=last->link;
    while(temp!=last)
    {
        cnt++;
        temp=temp->link;
    }   
    return cnt;
}

NODE sort2(NODE last){
   
    NODE prev=last;
    if(last==NULL||last->link==last){
        return last;
    }
  //  int q= count(last);
    for( NODE curl=last->link;curl!=last;curl=curl->link){
        for(;prev!=last;prev=prev->link){
            if(prev->info.I>curl->info.I){
                int t=prev->info.I;
                prev->info.I=curl->info.I;
                curl->info.I=t;
            }
        }
        prev=last;
        
    }
    return last;
}

void sort(NODE last)
{
    int size_sll,i,j,temp;
    size_sll=count(last);
    NODE first=last , next=last;
    if(size_sll<2)
        return;
    for(i=0;i<size_sll;i++)
    {
        // next=last;
        next=last->link;
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

int main()
{
	int ch;
    NODE last=NULL;
    INFO elem;
	while(1)
	{//1ins,2del,3dis
        printf("Enter the operation no\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
                acc(&elem);
				last=insert_front(last,elem);
				break;
			case 2:
                acc(&elem);
				last=insert_rear(last,elem);
				break;
			case 3:
				last=delete_front(last);
			    break;
			case 4:
				last=delete_rear(last);
			    break;
			case 5:
				display(last);
			    break;
            case 6:
                printf("\n%d\n",count(last));
                break;
            case 7:
                sort(last);
                // last=sort2(last);
                break;
            case 8:
                printf("\n %d\n",last->info.I);
			default:
				return 0;
		}
		printf("\n___\n");
	}
	return 0;
}