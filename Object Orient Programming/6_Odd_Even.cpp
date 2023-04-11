#include<iostream>
using namespace std;
class Odd_Even
{
	int num;
	public:
	Odd_Even(int a)
	{
		num = a;
	}
	bool operator! ()
	{
		if(num%2 == 0)
		{
			return true;	
		}	
		return false;
	}
		
};
int main()
{
	int num;
	cout << "\n\t Enter A Number ";
	cin >> num;
	Odd_Even a = Odd_Even (num);
	if(!a)
	{
		cout << "\n\t Even" << endl;
	}
	else
	{
		cout << "\n\t Odd " << endl;
	}
	system("pause");
	return 0;
	
}
