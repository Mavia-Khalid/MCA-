#include<iostream>
using namespace std;
int Delete_Duplicates(int arr[],int n)
{
	if(n==0||n==1)
	{
		return n;
	}
	int j=0;
	for(int i=0;i<n-1;i++) // Loop to Traverse through The Array
	{
		if(arr[i]!=arr[i+1]) // Comparing Current Element with the Next Element 
		{
			arr[j++]=arr[i]; // Replacing the Array at Jth Index with Value ar ith Index 
		}
	}
	arr[j]=arr[n-1]; // Storing the Last Index Value at Current Jth Index Position
	return j; 
}
void PrintArray(int arr[], int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
}
int main()
{
	int arr[20]={1,1,2,2,2,3,3,3,3,4,4,5,5,6,6,6,7,8,9,10};
	cout<<"\t Original Array is : ";
	for(int i=0;i<20;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl<<endl;
	cout<<"\t Distinct Array After Removing Duplicates is : ";
	int n = Delete_Duplicates(arr , 20);
	PrintArray(arr, n+1);  // Printing Array Upto J+1 (J is Returned and Stored as n)
	cout<<endl<<endl;
	system("pause");
	return 0;
}
