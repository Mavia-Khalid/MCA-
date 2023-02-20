#include<iostream>
using namespace std;
int main()
{
	tryy:
	int e,hit=0,sink=0,f[4]={0},g[4]={0};
	char a[4]={'4','5','4','5'},t;
	string guess;
	my:	
	cout<<"\n\t Enter 4 Digit Guess : ";
	cin>>guess;
	e=guess.length();
	if(e!=4)
	{
		cout<<"\n\t Entered Value is Not 4 Digits ";
		goto my;
	}
	for(int i=0;i<4;i++)
	{
		if(a[i]==guess[i])
		{
			sink++;
			f[i]=1;
			g[i]=1;
		}
	}
	for(int i=0;i<4;i++)
	{
		if(f[i]==1)
			{
				continue;
			}
		for(int j=0;j<4;j++)
		{
			if(g[j]==1)
			{
				continue;
			}
			if(a[i]==guess[j])
			{
				hit++;
				g[j]=1;
				break;
			}
		}
	}
	if(hit!=0||sink!=0)
	{
		if(sink==4)
		{
			cout<<"\n\t Matched ";
			cout<<endl<<endl;
			system("pause");
			return 0;
		}
		else
		{
			cout<<"\n\t No. of Hits : "<<hit;
			cout<<"\n\t No. of sinks : "<<sink;
		}
	}
	if(hit==0&&sink==0)
	{
		cout<<"\n\t No Match ";
	}
	cout<<"\n\n\t Want to Try Again ? Enter Y/y for Yes or N/n for No ";
	cin>>t;
	if(t=='Y'||t=='y')
	{
		goto tryy;
	}
	cout<<endl<<endl;
	system("pause");
	return 0;
}
