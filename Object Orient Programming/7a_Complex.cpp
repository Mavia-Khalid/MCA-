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
	friend Complex operator+ (Complex &a,Complex &b);
	friend void show(Complex &c);
	
	
};
Complex operator+ (Complex &a,Complex &b)
{
	Complex c;
	c.real=a.real+b.real;
	c.imag=a.imag+b.imag;
	return c;
}
void show(Complex &c)
{
	cout << "\n\t The Real part of result is : " << c.real << endl;
	cout << "\n\t The Imaginary part of result is : " << c.imag << endl;
}
int main()
{
	Complex a(10,20.55);
	Complex b(10); // Equal Real And Imaginary Values
	Complex c;
	c = a+b;
	show(c);
	cout << endl;
	return 0;
}

