#include<iostream>
using namespace std;
long long int exponent(int base,int power);
int main()
{
    int base,power;
    char ch;
    do
    {
        cout<<"\t Enter the Base : ";
        cin>>base;
        cout<<"\t Enter Exponent : ";
        cin>>power;
        cout<<"\t "<<base<<"^"<<power<<" = "<<exponent(base,power);
        cout<<endl;
        cout<<"\t Enter y/Y to Continue : ";
        cin>>ch;
    }
	while(ch=='y'||ch=='Y');
    system("pause");
    return 0;
}
long long int exponent(int base,int power)
{
    long long int val=1;
    for(int i=1;i<=power;i++) // Loop to Iterate Upto Input of Power
    {
        val*=base;  // Calculates The Value by Repeated Multiplication 
    }
    return val;
}
