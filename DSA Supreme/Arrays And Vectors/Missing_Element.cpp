#include<iostream>
#include<vector>
using namespace std;
int Missing_Element(vector<int>& arr );
int main()
{
    vector<int> arr{1,2,3,4,5,7,8};
    int Index = Missing_Element(arr);
    cout << "\n\t Missing Element : " << Index;
    cout << endl << endl;
    return 0;
}
int Missing_Element(vector<int>& arr )
{
    int start = 0 , end = arr.size()-1 , mid;
    mid = start + (end - start)/2; 
    while(start <= end)
    {
        if(arr[mid] == (mid+1))
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return mid+1;
}
