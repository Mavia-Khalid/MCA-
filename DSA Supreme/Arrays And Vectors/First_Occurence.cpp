#include<iostream>
#include<vector>
using namespace std;
int First_Occurence(vector<int>& arr , int key);
int main()
{
    vector<int> arr{1,2,3,3,3,3,4,4,4,4,6,7,8,9};
    int Target;
    cout << "\n\t Enter To Find : ";
    cin >> Target;
    int Index = First_Occurence(arr , Target);
    cout << "\n\t Element At : " << Index;
    cout << endl << endl;
    return 0;
}
int First_Occurence(vector<int>& arr , int key)
{
    int start = 0 , end = arr.size()-1 , mid;
    mid = start + (end - start)/2;
    int Index = -1; 
    while(start <= end)
    {
        if(arr[mid] == key)
        {
            Index = mid;
            end = mid - 1;
        }
        else if(key > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return Index;
}
