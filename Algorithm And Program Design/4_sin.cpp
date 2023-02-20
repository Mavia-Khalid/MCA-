#include<iostream>
#include<math.h>
using namespace std;
int factorial(int num)
{
    int fact=1;
    for(int i=1;i<=num;i++)
    {
        fact*=i;
    }
    return fact;
}
int main()
{
    int no_of_terms;
    float angle,theta,sum=0;
    cout<<"\t Enter No. of Terms : ";
    cin>>no_of_terms;
    cout<<"\t Enter Value of x (angle in Degree) : ";
    cin>>angle;
    theta=(angle*(22/7))/180;
    for(int i=1,j=1;i<=no_of_terms;i++,j+=2)
    {
        if(i%2==0)
        {
            sum=sum-pow(theta,j)/factorial(j);
        }
        else
        {
            sum=sum+pow(theta,j)/factorial(j);
        }
    }
    cout<<"\t Sin("<<angle<<")="<<sum<<"\n";
    return 0;
}