#include<iostream>
#include<vector>
using namespace std;
void PairSum(vector<int> arr , int target);
int main()
{
    vector<int> arr(7);
    int target;
    cout<<"\n\t Enter Array : ";
    for(int i=0;i<arr.size();i++)
    {
        cin>>arr[i];
    }
    cout<<"\n\t Enter Target : ";
    cin>>target;
    PairSum(arr , target);
    cout<<endl<<endl;
    return 0;
}
void PairSum(vector<int> arr , int target)
{
    for(int i=0;i<arr.size();i++)
    {
        for(int j=i+1;j<arr.size();j++)
        {
            if(arr[i]+arr[j]==target)
            {
                cout<<"\n\t Index are "<<i<<" "<<j;
            }
        }
    }
}