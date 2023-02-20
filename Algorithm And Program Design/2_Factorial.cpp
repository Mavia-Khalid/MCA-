#include<iostream>
using namespace std;
int factorial_iterative(int num);
unsigned long long factorial_recursive(int num);
int main()
{
    int num,choice;
    cout<<"\t Enter The No. To Compute its Factorial ";
    cin>>num;
    cout<<"\t Enter 1 to Compute Factorial in Iterative Method "<<endl;
    cout<<"\t Enter 2 to Compute Factorial in Recursive Method ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        cout<<"\t Factorial of "<<num<<" = "<<factorial_iterative(num)<<endl;
        break;
    case 2:
        cout<<"\t Factorial of "<<num<<" = "<<factorial_recursive(num)<<endl;
        break;
    default:
        cout<<"\t Wrong Choice"<<endl;
    }
    return 0;
}
int factorial_iterative (int num)
{
    unsigned long long factorial=1;
    for (int i = 1; i<= num ; i++)
        {
            factorial*=i;
        }
    return factorial;
}    
unsigned long long factorial_recursive(int num)
{
    if(num>1)
    return num*factorial_recursive(num-1);
    else
    return 1;
}