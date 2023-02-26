#include <iostream>
#include <cmath>
using namespace std;


void calc(int a,int b,int c)
{
    int i,count=0,v[3];
    v[0]=1;
    for(i=2;i<=a/v[0];i++)
    {
        if(a%i==0)
        {
            cout<<"1 "<<i<<" "<<a/i<<endl;
            return;
        }
    }
    cout<<"-1"<<endl;
    return;
}

int main() {
	// your code goes here
	int i,n=1,x=0,y=0,z=0;
	cin>>n;// comment this if only one test case always
	for(i=0;i<n;i++)
	{
	    cin>>x;  //remove y or z based on number of input
	    calc(x,y,z);
	    
	}
	return 0;
}