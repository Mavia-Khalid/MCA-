#include<iostream>
using namespace std;
void Convert(int num,int base)
{
    int rem,i=0;
    char a[50];
    if(base==16)
    {
        while(num>0)
        {
            rem=num%base;
            if(rem<10)
            {
                a[i]=rem+48;
            }
            else
            {
                a[i]=rem+55;
            }
            num=num/base;
            i++;
        }
    }
    else
    {
        while(num>0)
        {
            rem=num%base;
            a[i]=rem+48;
            num=num/base;
            i++;
        }
    }
    cout<<"\n\t Converted Number into the Chosen Number System is : ";
    for(int j=i-1;j>=0;j--)
    {
        cout<<a[j];
    }
    cout<<endl;
}
int main()
{
    int num,choice;
    cout<<"\tEnter The Number To Convert \n\t";
    cin>>num;
    cout<<"\tEnter 1 TO Convert to Binary \n\tEnter 2 TO Convert to Octal \n\tEnter 3 TO Convert to Hexadecimal \n\t";
    cin>>choice;
    switch (choice)
    {
    case 1:
        Convert(num,2);
        break;
    case 2:
        Convert(num,8);
        break;
    case 3:
        Convert(num,16); 
        break;   
    default:
        cout<<"\tWrong Choice";
        break;
    }
    return 0;
}