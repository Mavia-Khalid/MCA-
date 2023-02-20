#include<iostream>
using namespace std;
int main() 
{
    int num1,num2;
    cout<<"\n\t Enter 1st Number  ";
    cin>>num1;
    cout<<"\t Enter 2nd Number  ";
    cin>>num2;
    cout<<"\t Before Swapping :- 1st Number : "<<num1<<" , 2nd Number : "<<num2<<endl;
    num1=num1+num2;
    num2=num1-num2;
    num1=num1-num2;
    cout<<"\t After Swapping :- 1st Number : "<<num1<<" , 2nd Number : "<<num2<<endl;
    return 0;
}