#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char str[]="geeksforfgeeks";
    memset(str , 'A' , sizeof(str));
    for(int i=0;i<sizeof(str);i++)
    {
        cout<<" "<<str[i];
    }
    int strr[6];
    memset(strr , -1 , sizeof(strr));   // Initializes Array with -1. In Integral Values only 1 and 0 
                                        // Can be Initialized with
    
    for(int i=0;i<sizeof(strr);i++)
    {
        cout<<" "<<strr[i];
    }
   
    return 0;
}