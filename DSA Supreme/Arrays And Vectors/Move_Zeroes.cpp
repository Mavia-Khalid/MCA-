#include <iostream>
#include <vector>
using namespace std;
void MoveZeroes(vector<int>& nums);
int main()
{
    vector<int> arr{0,0,0,1};
    MoveZeroes(arr);
    for(auto i:arr)
    {
        cout << " "<< i;
    }
    cout << endl << endl;
}
void MoveZeroes(vector<int>& nums) {
    int j = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] != 0)
        {
            nums[j++] = nums[i];
        }
    }
    while(j < nums.size())
    {
        nums[j++] = 0;
    }
    }