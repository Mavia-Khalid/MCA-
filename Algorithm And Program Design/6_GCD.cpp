#include<iostream>
using namespace std;
int Greatest_Common_Divisor(int num1, int num2)
{
    int small,Greatest_Common_Divisor=1;
    if(num1>num2)
    {
        small=num2;
    }
    else
    {
        small=num1;
    }
    for(int i=2;i<=small;i++)
    {
        if(num1%i==0&&num2%i==0)
        Greatest_Common_Divisor=i;
    }
    return Greatest_Common_Divisor;
}
int main()
{
    int num1,num2;
    cout<<"\t Enter 1st Number : ";
    cin>>num1;
    cout<<"\t Enter 2nd Number : ";
    cin>>num2;
    if(num1<=0||num2<=0)
    {
        cout<<"\t Wrong Input \n";
    }
    cout<<"Greatest Common Divisor of "<<num1<<" and "<<num2<<" = "<<Greatest_Common_Divisor(num1,num2)<<endl;
    return 0;
}