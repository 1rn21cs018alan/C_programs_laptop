#include<iostream>
using namespace std;
int main()
{
    int a,b,x;
    cout<<"Enter the values for a and b\n";
    cin>>a>>b;
    x=a-b;
    try
    {
        if(x!=0)
        {
            cout<<"Result="<<(a/x)<<endl;
        }
        else
        {
            throw (x);
        }
    }
    catch(int i)
    {
        cout<<"Exception caught:Divide by zero"<<endl;
    }
    cout<<"END";
    return 0;
}