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
	void operator+ (Complex &b);
	
	
};
void Complex::operator+ (Complex &b)
{
	Complex c;
	c.real=real+b.real;
	c.imag=imag+b.imag;
	cout << "\n\t The Real part of result is : " << c.real << endl;
	cout << "\n\t The Imaginary part of result is : " << c.imag << endl;
}
int main()
{
	Complex a(10,20.55);
	Complex b(10); // Equal Real And Imaginary Values
	a+b;
	cout << endl;
	return 0;
}

