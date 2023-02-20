#include<iostream>
#include<ctime>
using namespace std;
void insert_array(int arr[], int size);
void Quick_Sort(int arr[], int s, int e);
int Partition(int arr[], int s, int e);
void PrintArray(int arr[], int size);
int main()
{
	int arr[100], n;
	cout<<"\t Enter Array Size : ";
	cin>>n;
	cout<<"\t Enter Array Elements : ";
	insert_array(arr , n);
	clock_t time=clock();
	Quick_Sort(arr, 0, n-1);
	cout<<endl;
	cout<<"\t Sorted Array is : ";
	PrintArray(arr,n);
	time=clock()-time;
    cout<< endl <<"\t Time Taken to Sort = "<<(double)time/CLOCKS_PER_SEC<<" Seconds "<< endl;
	cout<<endl<<endl;
	system("pause");
	return 0;
}
void insert_array(int arr[], int size)
{
    cout<<"\n\t Enter Array Elements : ";
    for(int i=0; i<size; i++)
    {
        cin>>arr[i];
    }
    cout<<endl;
}
void Quick_Sort(int arr[], int s, int e)
{
	
	if(s>=e)
	{
		return;
	}
	
	int p;
	p=Partition(arr, s, e);
	
	Quick_Sort(arr, s, p-1);
	
	Quick_Sort(arr, p+1, e);
	
}
int Partition(int arr[], int s, int e )
{
	int pivot=arr[e];
	int count=0;
	for(int i=s;i<e;i++)
	{
		if(arr[i]>pivot)
		{
			count++;
		}
	}
	//Giving Pivot its Correct Postion
	int PivotIndex=e-count;
	swap(arr[PivotIndex],arr[e]);
	//Sorting Left And Right Parts of Pivot
	int i = s , j = e;
	
	while(i<PivotIndex && j>PivotIndex)
	{
		while(arr[i]<pivot)
		{
			i++;
		}
		while(arr[j]>pivot)
		{
			j--;
		}
		if(i<PivotIndex && j>PivotIndex)
		{
			swap(arr[i++],arr[j--]);
		}
	}
	return PivotIndex;
}
void PrintArray(int arr[], int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
}
