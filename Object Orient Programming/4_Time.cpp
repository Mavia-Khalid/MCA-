#include<iostream> 
using namespace std;
class Time  
{  
    public : 
    int hours; 
    int minutes; 
    void input() 
    {   
        int h,m; 
        cout<<"\n\t Enter Hours : "; 
        cin>>h; 
        cout<<"\n\t Enter Minutes : "; 
        cin>>m; 
        gettime(h,m); 
    } 
    void gettime(int h,int m) 
    { 
        hours=h; 
        minutes=m; 
    } 
    void sum(Time&,Time&);
}; 
void Display(Time&);  
void Time::sum(Time &a,Time &b) 
{    
    int m=a.minutes+b.minutes; 
    if(m>60) 
    { 
        a.minutes =m-60; 
        a.hours +=1;  
    } 
    a.hours=a.hours+b.hours; 
    Display(a); 
} 
void Display(Time &ob) 
{
    cout << "\n\t After Adition Hours : Minutes :: " << ob.hours << " : " << ob.minutes << endl;   
} 
int main() 
{ 
    Time a; 
    Time b; 
    cout << "\n\t Enter First Time format : "; 
    a.input(); 
    cout << "\n\t Enter Second Time format : "; 
    b.input(); 
    cout << "\n\t Result Time format is : "; 
    a.sum(a,b); 
    return 0; 
}