#include<iostream>
#include<vector>
using namespace std;
int Odd(vector<int> &arr)
{
    if(arr.size()==0)
    {
        return -1;
    }
    int s=0,e=arr.size()-1;
    int mid = s+(e-s)/2;
    while(s<e)
    {
        if(s==e)
        {
            return s;
        }
        if(mid%2==0)
        {
            if(arr[mid]==arr[mid+1])
            {
                s = mid + 2;
            }
            else
            {
                e = mid;
            }
        }
        else
        {
            if(arr[mid]==arr[mid-1])
            {
                s= mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        mid = s+(e-s)/2;
    }
    return mid;
}
int main()
{
    vector<int> arr = {11,11,22,22,3,44,44};
    int ans = Odd(arr);
    if(ans>=0)
    {
        cout << "\t Ans is " << arr[ans] << endl;
    }
    return 0; 
}