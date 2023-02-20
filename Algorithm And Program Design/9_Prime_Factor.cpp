#include<iostream>
using namespace std;
void prime_factors(int num)
{
    int prime=0,i;
    cout<<"\t Prime Factors of "<<num<<" : ";
    for(i=2;i<=num/2;i++)
    {
        if(num%i==0)
        {
            prime=1;
            for(int j=2;j<=i/2;j++)
            {
                if(i%j==0)
                {
                    prime=0;
                    break;
                }
            }
        }
        if(prime==1)
        {
            cout<<i<<" ";
        }
        prime=0;
    }
    cout<<endl;
}
int main()
{
    int num;
    cout<<"\t Enter A Number to Compute its Prime Factors  ";
    cin>>num;
    prime_factors(num);
    return 0;
}