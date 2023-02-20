#include<iostream>
using namespace std;
int main()
{
	int coins[6]={1,5,10,20,50,100},count[6]={0,0,0,0,0,0},dollar_amt,cent_amt,amt,Dollar=1,min_coins=0;
	cout<<"\n\t Enter Amount in Dollars : ";
	cin>>dollar_amt;
	cout<<"\n\t Enter Amount in Cents : ";
	cin>>cent_amt;
	amt=dollar_amt*100+cent_amt;
	for(int i=5;i>=0;i--)
	{
		while(amt>=coins[i])
		{
			amt=amt-coins[i];
			count[i]++;
			min_coins++;
		}
	}
	cout<<"\n\t Minimum No. of Coins Required are : "<<min_coins;
	cout<<endl<<endl;
	cout<<"\t ";
	for(int j=0;j<6;j++)
	{
		if(count[j]!=0)
		{
			if(coins[j]==100)
			{
				cout<<"\n\t Minimum No. of "<<Dollar<<" Dollar Coins Required : "<<count[j];
				break;
			}
			cout<<"\n\t Minimum No. of "<<coins[j]<<" Cents Coins Required : "<<count[j];
		}
	}
	cout<<endl<<endl;
	system("pause");
	return 0;
}
