#include<iostream>
using namespace std;
void Encrypt(int num[]);
int main()
{
    int message,a[4];
    cout<<"\t Enter a 4 Digit Message : ";  
    cin>>message;
    for(int i=3;i>=0;i--)                
	{
		a[i]=message%10;
		message=message/10;
	}
    cout<<endl;
    Encrypt(a);
}
void Encrypt(int num[])
{
    int temp;
    for(int i=0;i<4;i++)
    {
        num[i]=(num[i]+7)%10; //Adding all the digit by 7 and getting modulus by 10
    }
    for(int j=0;j<2;j++) //Swapping The Numbers
    {
        temp=num[j+2];
        num[j+2]=num[j];
        num[j]=temp;
    }
    cout<<"\t Encrypted Message is : ";
    for(int i=0;i<4;i++)
    {
        cout<<num[i];
    }
    cout<<endl<<endl;
}