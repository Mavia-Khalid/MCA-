#include<iostream>
#include<vector>
using namespace std;
int Binary_Search(vector<int> arr , int target)
{
    int s= 0;
    int e = arr.size()-1;
    int mid = s + (e-s)/2;
    while(s<=e)
    {
        if(arr[mid] == target)
        {
            return mid;
        }
        if(mid-1 >=0 && arr[mid-1] == target)
        {
            return mid-1;
        }
        if(mid+1 < arr.size() && arr[mid+1] == target)
        {
            return mid+1;
        }
        if(arr[mid] < target)
        {
            s = mid + 2;
        }
        else
        {
            e = mid - 2;
        }
        mid = s+(e-s)/2;
    }
    return -1;
}
int main()
{
    vector<int> arr = {10,3,20,40,20,50,80,70};
    int target = 70;
    int i = Binary_Search(arr , target);
    cout << "\n\t Element at " << i << endl;
    return 0;
}