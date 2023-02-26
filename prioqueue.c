#include <stdio.h>
#define MAX 10

void display (int Q[MAX][2],int front,int rear);

void sort(int Q[MAX][2], int rear)
{
	int i,j,t,t2;
	//printf("?");
	for(i=0;i<=rear;i++)
	{
		for(j=1;j<rear;j++)
		{
			if(Q[j][1]>Q[j+1][1])
			{
				t=Q[j][0];
				Q[j][0]=Q[j+1][0];
				Q[j+1][0]=t;
				t2=Q[j][1];
				Q[j][1]=Q[j+1][1];
				Q[j+1][1]=t2;
			//	printf(";;;%d,%d;;;;\n",Q[j][1],t2);
			//	display(Q,0,rear);
			}
		}
	}
	//display(Q,0,rear);
}


void insert(int Q[MAX][2],int * rear)
{
	if(*rear==MAX-1)
	{
		printf("\n full queue");
		return;
	}
	(*rear)++;
    printf("Enter number & priority\n");
	scanf("%d%d",&Q[*rear][0],&Q[*rear][1]);
	sort(Q,*rear);
}

void del(int Q[MAX][2],int front,int *rear)
{
	if(front>*rear)
	{
		printf ("\n No element");
	}
	else
	{
		printf("%d-P%d deleted \n",Q[front][0],Q[front][1]);
	  for(int i=front;i<*rear;i++)
 	 {
 	 	Q[i][1]=Q[i+1][1];
 	 	Q[i][0]=Q[i+1][0];
 	 }
    (*rear)--;
	}
}

void display(int Q[MAX][2],int front, int rear)
{
	if(front>rear)
	{
		printf ("\n No element");
	}
	for(int i=front;i<=rear;i++)
		printf("%d-P%d\n",Q[i][0],Q[i][1]);
}





int main()
{
	int Q[MAX][2],rear=-1,front=0,ch;
	while(1)
	{//1ins,2del,3dis
        printf("Enter the operation no\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert(Q,&rear);
				break;
			case 2:
				del(Q,front,&rear);
				break;
			case 3:
			  display(Q,front,rear);
			  break;
			default:
				return 0;
		}
		printf("\n___\n");
	}
	return 0;
}