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
        for(int j=0;j<arr2.size();j++)
        {
            if(arr1[i]==arr2[j])
            {
                result.push_back(arr1[i]);
                break;
            }
        }
    }
    cout<<"\n\t Intersection of Both Arrays : ";
    for(int i=0;i<result.size();i++)
    {
        cout<<" "<<result[i];
    }
    cout<<endl<<endl;
    return 0;

}