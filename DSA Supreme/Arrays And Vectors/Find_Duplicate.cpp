#include <iostream>
#include <vector>
#include<algorithm>
#include <math.h>
using namespace std;
void Find_Duplicate(vector<int> arr)
{
    sort(arr.begin() , arr.end());                         // Approach 1 O(nlogn)
    for (int i = 0; i < arr.size()-1; i++)
    {
        if(arr[i] == arr[i+1])
        {
            cout << "\n\t Duplicate Element : " << arr[i];
            break;
        }
    }
}
int Find_Duplicate_2(vector<int> arr)                
{
    int ans = -1;
    for (int i = 0; i < arr.size(); i++)                    // Approach 2 O(n)
    {
        int index = abs(arr[i]);
        if(arr[index] < 0)
        {
            ans = index;
        }
        arr[index] *= -1;
    }
    return ans;
}
int Find_Duplicate_3(vector<int> arr)                
{
    while(arr[0] != arr[arr[0]])
    {
        swap(arr[0] , arr[arr[0]]);
    }
    return (arr[0]);
}
int main()
{
    vector<int> arr{1,2,3,4,5,6,7,8,8,9};
    Find_Duplicate(arr);
    cout << "\n\t Duplicate Element : " << Find_Duplicate_3(arr);
    cout << endl << endl;
}