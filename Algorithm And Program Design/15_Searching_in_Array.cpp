#include<iostream>
#include<ctime>
using namespace std;
int Linear_Search(int arr[],int size,int key);
int Binary_Search(int arr[],int size,int key);
void sort(int arr[],int size);
int main()
{
    int choice,arr[100],n;
    int key,index;
    cout<< endl <<"\t Enter Array Size : ";
    cin>>n;
    cout<<"\t Enter Array Elements : \n";
    for(int i=0; i<n; i++)             // Loop to Insert Array
    {
        cout<<"\t Enter Element Array["<<i<<"] : ";
        cin>>arr[i];
    }
    cout << endl << "\t Enter An Element To Search : ";
    cin >> key;
    cout<<"\t Enter 1 to search Using Linear Search or Enter 2 to Search using Binary Search : ";
    cin>>choice;
    clock_t time=clock();
    switch(choice)
    {
        case 1:
            index = Linear_Search(arr , n , key);
            break;
        case 2:
            sort(arr , n);
            index = Binary_Search(arr , n , key);
            break;
        default:
            cout<<"\t Wrong Choice";
            break;
    }
    if(index)
    {
        cout << endl << "\t Element is Present"; 
    }
    else
    {
        cout << endl << "\t Element is Absent ";
    }
    time=clock()-time;
    cout<< endl <<"\t Time Taken to Search in Selected Type of Search = "<<(double)time/CLOCKS_PER_SEC<<" Seconds ";
    cout << endl << endl;
    return 0;
}
int Linear_Search(int arr[] , int size , int key)
{
    for(int i=0;i<size;i++) //Loop to Traverse through Whole of the Array
    {
        if(arr[i] == key) // Comparing Each Index Value with the Key
        {
            return 1;
        }
    }
    return 0;
}
int Binary_Search(int arr[],int size,int key)
{
    int start = 0 , end = size-1 , mid;
    mid = start + (end - start)/2; 
    while(start <= end)
    {
        if(arr[mid] == key)
        {
            return mid+1;
        }
        if(key > arr[mid])
        {
            start = mid + 1;
        }
        if(key < arr[mid])
        {
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return 0;
}
void sort(int arr[],int size) // Sorting for Binary Search
{
    int temp;
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}