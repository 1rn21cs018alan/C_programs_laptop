#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int character[26]={0},i,val;
    char arr[20];
    cout<<"Enter\n";
    cin>>arr;
    for(i=0;arr[i]!='\0';i++)
    {
        if(arr[i]>='a')
            val=arr[i]-'a';
        else
            val=arr[i]-'A';
        character[val]++;
    }
    for(i=0,val=0;i<26;i++)
    {
        if(character[i]>1)
        {
            //cout<<" "<<i<<" ";
            val+=character[i];
        }
    }
    cout<<val;
    return 0;
}