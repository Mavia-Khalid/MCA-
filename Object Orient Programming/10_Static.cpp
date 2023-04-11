#include <iostream>
#include <string.h>
using namespace std;
class Static_1
{
public:
	// declare a static data member
	static int static_member;
	Static_1()
	{
		static_member++;
	}
	static void disp()
	{
		cout << "\n\t No of objects : " << static_member;
	}
};
// initialized the static data member to 0
int Static_1::static_member = 0;
int main()
{
	Static_1 a;
	Static_1 b;
	Static_1 c;
	Static_1::disp();
	cout << endl << endl;
	return 0;
}