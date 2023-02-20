#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> arr1(5);
    vector<int> arr2(4);
    vector<int> result;
    cout<<"\n\t Enter 1st Array : ";
    for(int i=0;i<arr1.size();i++)
    {
        cin>>arr1[i];
    }
    cout<<"\n\t Enter 2nd Array : ";
    for(int i=0;i<arr2.size();i++)
    {
        cin>>arr2[i];
    }
    cout<<endl;
    for(int i=0;i<arr1.size();i++)
    {
        result.push_back(arr1[i]);
    }
    for(int i=0;i<arr2.size();i++)
    {
        result.push_back(arr2[i]);
    }
    cout<<endl;
    cout<<"\n\t Union of Both Arrays : ";
    for(int i=0;i<result.size();i++)
    {
        cout<<" "<<result[i];
    }
    cout<<endl<<endl;
    return 0;
}