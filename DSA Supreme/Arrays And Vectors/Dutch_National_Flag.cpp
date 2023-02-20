#include<iostream>
#include<vector>
using namespace std;
void sort(vector<int> &arr);
void Print(vector<int> &arr1);
int main()
{ 
    vector<int> arr{1,0,1,0,0,0,1,1,1,1,0,0};
    sort(arr);
    cout<<endl;
    Print(arr);
    return 0;
}
void sort(vector<int> &arr)
{
    int start=0;
    int end=arr.size()-1;
    int i=0;
    while(i!=end)
    {
        if(arr[i]==0)
        {
            swap(arr[start],arr[i]);
            start++;
            i++;
        }
        else
        {
            swap(arr[i],arr[end]);
            end--;
        }
    }
}

void Print(vector<int> &arr1)
{
    cout<<"\t";
    for(auto i: arr1)    // Foreach loop
    {
        cout<<" "<<i;     // Elements is Printed Not Index
    }
}