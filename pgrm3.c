#include <stdio.h>
double cal(double, double );
int main()
{
	int i,j,v=10;
    double dmg=100;
	for(j=50;j<=300;j+=v)
	{
		printf("\t%d", j);
	}
	for(i=5;i<=100;i+=5)
	{
        dmg=cal(i,50);
		printf("\n%d",i);
		for(j=50;j<=300;j+=v)
		{
			printf("\t%.1f",cal (i,j)-dmg);
            dmg=cal(i,j);
		}
	}
	
	
	return 0;
}
double cal(double crt, double cdmg)
{
	int a,i;
	float dmg=0,ave;
	i=100;
	while(i>0)
	{
		a=i%100;
		dmg=dmg+100.0;
		if(a<=crt)
			dmg+=cdmg;
		i--;
	//	printf("s%lf",dmg);
	}
	ave=dmg/100.0;
	return ave;
}