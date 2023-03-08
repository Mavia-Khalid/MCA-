#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;
int First_Repeating_Element(vector<int> &arr);               // Time Complexity : O(n)
int main()
{
    vector<int> arr{1,2,3,3,5,6,6,8,8,9};
    int val = First_Repeating_Element(arr);
    if(val != -1)
    {
        cout << "\n\t First Repeating Element : " << val;
    }
    else
    {
        cout << "\n\t No Repeating Element ";
    }
    cout << endl << endl;
}
int First_Repeating_Element(vector<int> &arr)
{
    unordered_map<int,int> Hash;
    for (int i = 0; i < arr.size(); i++)
    {
        Hash[arr[i]]++;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if(Hash[arr[i]] > 1)
        {
            return arr[i];
        }
    }
    return -1;
}