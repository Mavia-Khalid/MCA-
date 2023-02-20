#include<iostream>
#include<iomanip>
using namespace std;
void fibonacci_iterative(int num);
int fibonacci_recursive(int num);
int main() 
{
    int num,choice;
    clock_t time=clock();
    cout<<"\t Enter No. Of Terms ";
    cin>>num;
    cout<<"\t Enter 1 to Compute Factorial in Iterative Method "<<endl;
    cout<<"\t Enter 2 to Compute Factorial in Recursive Method ";
    cin>>choice;
    switch(choice)
    {
        case 1:
            fibonacci_iterative(num);
            break;
        case 2:
            cout<<"\t ";
            for(int i=0;i<num;i++)
            {
            cout<<" "<<fibonacci_recursive(i);
            }
            cout<<endl;
            break;
        default:
            cout<<"\t Wrong"<<endl;
            break;
    }
    time=clock()-time;
    cout<<"\t "<<(double)time/CLOCKS_PER_SEC<<" Seconds ";
    return 0;
}
void fibonacci_iterative(int num)
{
    int first_term=0,second_term=1,third_term;
    if(num==0)
    {
    }
    else if (num==1)
    {
        cout<<first_term<<endl;
    }
    else
    {
        cout<<"\t "<<first_term<<" "<<second_term;
        for(int i=3;i<=num;i++)
        {
            third_term=first_term+second_term;
            first_term=second_term;
            second_term=third_term;
            cout<<" "<<third_term;
        }
        cout<<endl;
    }
}
int fibonacci_recursive(int num)
{
    if(num==1||num==0)
    {
        return num;
    }
    else
    {
        return (fibonacci_recursive(num-1)+fibonacci_recursive(num-2));
    }
}