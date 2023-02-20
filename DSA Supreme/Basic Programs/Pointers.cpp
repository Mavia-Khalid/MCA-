#include<iostream>
using namespace std;
int main()
{
    int arr[4]={1,2,3,4};
    int *ptr=&arr[0];
    
    cout<<"\n\t"<<arr;
    cout<<"\n\t"<<&arr;
    cout<<"\n\t"<<*(arr+2);  // arr[i]=*(arr+i) or i[arr]=*(arr+i)
    cout<<"\n\t"<<1[arr];    // arr[1]=1[arr]
    cout<<endl;
    cout<<"\n\t"<<ptr;
    cout<<"\n\t"<<*ptr;
    cout<<"\n\t"<<&ptr;
    cout<<endl;
    cout<<"\n\t"<<sizeof(arr);
    cout<<"\n\t"<<sizeof(&arr);
    cout<<"\n\t"<<sizeof(&arr[0]);
    cout<<endl;
    cout<<"\n\t"<<sizeof(ptr);
    cout<<"\n\t"<<sizeof(*ptr);
    cout<<"\n\t"<<sizeof(&ptr);
    cout<<endl;
    
    char ch[6]="abcde";
    char *c=ch;                     // char *c=&ch[0];  is same
    cout<<"\n\t"<<ch;           // Elements of array will be displayed in case of char
    cout<<"\n\t"<<c;
    cout<<endl;
    char temp='z';
    char *p=&temp;
    cout<<"\n\t"<<p;       // pointer will not stop unless null is encountered 

    // in function , int arr[]==int *arr
    cout<<endl;
    return 0;
}