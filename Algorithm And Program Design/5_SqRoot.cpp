#include<iostream>
using namespace std;
void Square_Root(int num)
{
    float i;
    for(i=0.01;i*i<num;i=i+0.01)
    cout<<"\t Square Root of "<<num<<" is : "<<i-0.01<<endl;
}
int main()
{
    int num;
    cout<<"\t Enter a Number to Find its Square Root : ";
    cin>>num;
    Square_Root(num);
    return 0;
}