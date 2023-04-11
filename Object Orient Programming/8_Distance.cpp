#include<iostream>
using namespace std;
class Distance
{
	float feet;
	float inch;
	public:
		Distance()
		{
			feet = 0;
			inch = 0;		
		
		}
		Distance(int a, int b)
		{
			feet = a;
			inch = b;
		}
		friend void getdata(Distance &ob);
		void show();
		bool operator< (Distance &ob)
		{
			if(feet < ob.feet)
			{
				return true;
			}
			if(feet == ob.feet && inch < ob.inch)
			{
				return true;
			}
			return false;
		}	
};
void getdata(Distance &ob)
{
	cout << "\n\t Enter Feet ";
	cin >> ob.feet;
	cout << "\n\t Enter Inch : ";
	cin >> ob.inch;		
}
void Distance::show()
{
	cout << "\n\t Feet : " << feet;
	cout << "\n\t Inch : " << inch;
}
int main()
{
	Distance a,b;
	getdata(a);
	a.show();
	getdata(b);
	b.show();
	int c = a<b;
	if(c)
	{
		cout << "\n\t A is Larger ";
	}
	else
	{
		cout << "\n\t B is Larger ";
	}
	return 0; 
}
