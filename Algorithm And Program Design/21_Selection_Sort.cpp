#include<iostream>
#include<ctime>
using namespace std;
void insert_array(int arr[], int size)
{
    cout<<"\n\t Enter Array Elements : ";
    for(int i=0; i<size; i++)
    {
        cin>>arr[i];
    }
    cout<<endl;
}
void print_array(int arr[], int size)
{
    for(int i=0; i<size; i++)
    {
        cout<<" "<<arr[i];
    }
    cout<<endl;
}
void selection_sort(int arr[], int size)
{
    int max_index;
    for(int i=size-1;i>0;i--)
    {
        max_index=i;
        for(int j=i-1;j>=0;j--)
        {
            if(arr[j]>arr[max_index])
            {
                max_index=j;
            }
        }
        if(max_index!=i)
        {
            swap(arr[i],arr[max_index]);
        }
    }
}
int main()
{
    int arr[20] , n;
    cout << "\n\t Enter Array Size : ";
    cin >> n;
    insert_array(arr , n);
    cout<<"\n\t Array Before Sorting : ";
    print_array(arr , n);
    selection_sort(arr , n);
    cout<<"\n\t Array After Sorting : ";
    print_array(arr , n);
    cout<<endl<<endl;
    system("pause");
    return 0;
}