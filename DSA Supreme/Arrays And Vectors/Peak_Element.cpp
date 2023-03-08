#include<iostream>
#include<vector>
using namespace std;
int Peak_Element(vector<int>& arr );
int main()
{
    vector<int> arr{0,10,5,7};
    int Index = Peak_Element(arr);
    cout << "\n\t Peak Element : " << arr[Index];
    cout << endl << endl;
    return 0;
}
int Peak_Element(vector<int>& arr )
{
    int start = 0 , end = arr.size()-1 , mid;
    mid = start + (end - start)/2; 
    while(start < end)
    {
        if(arr[mid] < arr[mid+1])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
        mid = start + (end - start)/2;
    }
    return start;
}
