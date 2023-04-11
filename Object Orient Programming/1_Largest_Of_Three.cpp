#include<iostream> 
using namespace std;  
class Largest 
{

  
    int first; 
    int second; 
    int third; 
    
    public :    
    Largest(int a,int b,int c) 
    { 
        first=a; 
        second=b; 
        third=c;  
    } 
    void Find_Largest();
};  
void Largest::Find_Largest()

{ 
    if(first>second && first>third) 
    { 
        cout << "\n\t Largest is " << first << endl;
    } 
    else if(second>first && second>third) 
    { 
        cout << "\n\t Largest is " << second << endl;
    } 
    else 
    { 
        cout << "\n\t Largest is " << third << endl;
    }  
} 
int main() 
{ 
    int a,b,c; 
    cout << "\n\tEnter First Value : "; 
    cin >> a; 
    cout << "\n\t Enter Second Value : "; 
    cin >> b; 
    cout << "\n\t Enter Third Value : "; 
    cin >> c; 
    Largest v(a,b,c); 
    v.Find_Largest(); 
    cout << endl;
    return 0; 
}