#include<iostream>
#include<vector>
using namespace std;
int removeDuplicates(vector<int> &nums) 
{
        int j = nums.size();
        for(int i=nums.size()-1; i > 0; i--)
        {
            if(nums[i] == nums[i-1])
            {
                nums.erase(nums.begin()+i);
                j--;
            }
        }
    return j;
}
int main()
{
    vector<int> arr{1,2,3,4,5,6,6,8,8,9};
    int j = removeDuplicates(arr);
    cout << j << endl;
    for( int i = 0 ; i<j; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl << endl;
}