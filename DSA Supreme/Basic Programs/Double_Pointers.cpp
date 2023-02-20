#include<iostream>
using namespace std;
int main()
{
    int i=5;
    int *ptr=&i;
    int **ptr1=&ptr;
    cout<<i<<" "<<*ptr<<endl;
    cout<<&i<<" "<<ptr<<endl;
    cout<<ptr<<" "<<ptr1<<endl;
    cout<<*ptr1<<" "<<*ptr<<endl;
    cout<<**ptr1<<" "<<*ptr<<" "<<i;
    cout<<endl;
    return 0;
}
