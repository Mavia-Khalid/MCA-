#include<iostream>
#include<ctime>
using namespace std;
void Insert_Array(int arr[], int size);
void Insertion_Sort(int arr[], int size);
void PrintArray(int arr[], int size);
int main()
{
	int arr[100], n;
	cout<<"\t Enter Array Size : ";
	cin>>n;
	Insert_Array(arr , n);
	Insertion_Sort(arr,n);
	cout<<endl;
	cout<<"\t Sorted Array is : ";
	PrintArray(arr,n);
	cout<<endl<<endl;
	system("pause");
	return 0;
}
void Insert_Array(int arr[], int size)
{
    cout<<"\n\t Enter Array Elements : ";
    for(int i=0; i<size; i++)
    {
        cin>>arr[i];
    }
    cout<<endl;
}
void Insertion_Sort(int arr[], int size)
{
	int i,j;
	for(i=1;i<size;i++) // Loop to Traverse through The Array
	{
		int temp=arr[i]; // Storing a[i] in Temporary Variable 
		for(j=i-1;j>=0;j--) // Loop to Traverse Array in Reverse From i-1 to 0
		{
			if(temp<arr[j])   // Checking If temp is Smaller than Previous Elements or Not
			{
				arr[j+1]=arr[j]; // Shifting the Current Element at J to Next Index
				
			}
			else
			{
				break;
			}
		}
		if(i!=j+1)
		{
			arr[j+1]=temp;
		}
	}
}
void PrintArray(int arr[], int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}





