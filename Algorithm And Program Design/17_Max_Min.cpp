#include<iostream>
#include<climits>              //for INT_MIN and INT_MAX
using namespace std;
int max_element(int arr[],int size);
int min_element(int arr[],int size);
int main()
{
    int max,min;
    int n,arr[100];
    cout << "\t Enter Size Of Array : ";
    cin>>n;
    cout << "\t Enter Elements of Array : ";
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
    	cout << "\t                           ";
	}
    max=max_element(arr , n);
    min=min_element(arr , n);
    cout << endl << "\t Maximum Element is  : " << max;
    cout << endl << "\t Minimum Element is  : " << min;
    cout << endl << endl;
    system("pause");
    return 0;
}
int max_element(int arr[] , int size)
{
    int max = INT_MIN;     // Stores the Minimum Value INT can Store
    for(int i=0;i<size;i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
int min_element(int arr[] , int size) 
{
    int min = INT_MAX;   // Stores the Maximum Value INT can Store
    for(int i=0;i<size;i++)
    {
        if(arr[i] < min)  
        {
            min = arr[i];
        }
    }
    return min;
}

