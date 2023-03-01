#include <iostream>
#include <vector>
using namespace std;
void Move(vector<int> &arr);
void Move_2(vector<int> &arr);
int main()
{
    vector<int> arr{1,2,3,-1,-4,-23,-54,23,56,-56};
    Move_2(arr);
    for(auto i:arr)
    {
        cout << " " << i;
    }
    cout << endl << endl;
}
void Move(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i+1; j < arr.size(); j++)
        {
            if(arr[j] < 0)
            {
                swap(arr[i] , arr[j]);
                break;
            }
        } 
    }
}
void Move_2(vector<int> &arr)                   // Two Pointer Approach
{
    int l = 0;
    int h = arr.size()-1;
    while (l <= h)
    {
        if(arr[l] < 0)
        {
            l++;
        }
        else if(arr[h] > 0)
        {
            h--;
        }
        else
        {
            swap(arr[l++] , arr[h--]);
        }
    }
}