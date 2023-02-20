#include<iostream>
#include<math.h>
using namespace std;
void prime(int start,int end);
int main()
{
    int start,end;
    char ch;
    do
    {
        cout<<"\t Enter Start Range to Print Prime Numbers : ";
        cin>>start;
        cout<<"\t Enter End Range to Print Prime Numbers : ";
        cin>>end;
        prime(start,end);
        cout<<"\t Enter y/Y to Continue : ";
        cin>>ch;
    } 
    while(ch=='y'||ch=='Y');
    return 0;
}
void prime(int start,int end)
{
    int prime;
    cout<<"\t";
    for(int i=start;i<=end;i++) // Loop to Iterate in the Given Range
    {
        prime=1;
        if(i==0||i==1)
        {
            continue;
        }
        for(int j=2;j<=sqrt(i);j++) // Loop to Find if the Number is Prime or Not 
        {
            if(i%j==0) 
            {
                prime=0;    // Prime Set to Zero If Factor Found 
                break;      // Breaking Loop as a Factor is Found
            }
        }
        if(prime==1)
        {
            cout<<" "<<i<<" ";
        }
    }
}