#include<iostream>
using namespace std;
void test(int x)
{
    if(x==1) throw x;
    else if (x==0) throw 'x';
    else if (x==-1) throw 1.0;
    else if (x==3) throw "aasdsa";
}
int main()
{
    try
    {
        cout<<"End of try catch block";
        cout<<"testing for multiple cases\n";
        cout<<"\nx==1\n";
        test(1);
        cout<<"\nx==0\n";
        test(0);
        cout<<"\nx==-1\n";
        test(-1);
        cout<<"\nx==2\n";
        test(2);
        cout<<"\nx==3\n";
        test(3);
    }
    catch(char c)
    {
        cout<<"Caugth a character"<<endl;
    }
    catch(int i)
    {
        cout<<"Caugth an integer"<<endl;
    }
    catch(double a)
    {
        cout<<"Caugth a double"<<endl;
    }
    catch(...)
    {
        cout<<"Caugth a something else"<<endl;
    }
    
    return 0;
}