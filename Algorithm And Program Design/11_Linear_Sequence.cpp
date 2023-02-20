#include<iostream>
using namespace std;
void Linear_Congruential_Method(int range,int a,int b,int mod,int initial);
int main()
{
    int x[100],a,b,mod,range,initial;
    cout<<endl;
    cout<<"\t Enter The Range : ";
    cin>>range;
    cout<<"\t Enter The Multiplier : ";
    cin>>a;
    cout<<"\t Enter The Incrementing Value : ";
    cin>>b;
    cout<<"\t Enter THe Initial Value : ";
    cin>>initial;
    cout<<"\t Enter The Modulus (Should Be Greater than Multiplier,Incrementing value and Initial Value) : ";
    cin>>mod;
    Linear_Congruential_Method(range,a,b,mod,initial);
    cout<<endl<<endl;
    return 0;
}
void Linear_Congruential_Method(int range,int a,int b,int mod,int initial)
{
    int x[100];
    x[0]=initial;
    for(int i=1;i<range;i++)
    {
        x[i]=(a*x[i-1]+b)%mod;      // Formula to Calculate Pseudo Random Enters
    }
    cout<<"\n\t Set Of Psuedo Random Numbers according to Selected Range is :";
    for(int i=0;i<range;i++)
    {
        cout << " " <<x[i];
    }
}