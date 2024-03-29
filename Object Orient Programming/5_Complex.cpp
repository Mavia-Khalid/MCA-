#include<iostream> 
using namespace std;  
class Complex 
{   
   float real; 
   float imag; 
   public :  
   Complex() 
   { 
      real=0.0; 
      imag=0.0; 
   } 
   Complex(float val) 
   { 
      real=val; 
      imag=val; 
   } 
   Complex(float r,float i) 
   { 
      real=r; 
      imag=i; 
   } 
   friend Complex sum(Complex &a,Complex &b); 
   friend void Show(Complex &ob); 
  
};  
Complex sum(Complex &a,Complex &b) 
{    
   Complex c; 
   c.real=a.real+b.real; 
   c.imag=a.imag+b.imag; 
   return c;                   // returning object reference of a object 
}  
void Show(Complex &ob) 
{ 
   cout << "\n\t The Real part of result is : " << ob.real << endl; 
   cout << "\n\t The Imaginary part of result is : " << ob.imag << endl; 
} 
int main() 
{   
   Complex a(10,20.55); 
   Complex b(10);                   // Equal Real And Imaginary Values
   Complex c; 
   c=sum(a,b); 
   Show(c); 
   cout << endl;
   return 0;  
}