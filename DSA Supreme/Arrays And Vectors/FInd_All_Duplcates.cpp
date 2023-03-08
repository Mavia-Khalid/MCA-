#include <iostream>
#include <vector>
using namespace std;                                    // Constraint is a[i] belongs to [1,N]
void Find_Duplicate(vector<int>& arr)                   // Visiting Method
{
    vector<int> ans;
    int i = 0;
    while (i < arr.size())
    {
        int index = abs(arr[i])-1;
        if(arr[index] < 0)
        {
            ans.push_back(index+1);
        }
        else
        {
            arr[index] *= -1;
        }
        i++;
    }
    for(auto i:ans)
    {
        cout << i << " ";
    }
}
void Find_Duplicate_2(vector<int>& arr)             // Positioning Method
{
    int i = 0;
    while (i < arr.size())
    {
        int index = arr[i]-1;
        if(arr[i] != arr[index])
        {
            swap(arr[i], arr[index]);
        }
        else
        {
            i++;
        }
    }
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] != i+1)
            cout << arr[i] << " ";
    }
}
int main()
{
    vector<int> arr{4,3,2,7,8,2,3,1};
    Find_Duplicate_2(arr);
    cout << endl << endl;
}