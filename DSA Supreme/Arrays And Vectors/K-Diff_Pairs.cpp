#include <iostream>
#include <vector>
#include<set>
#include<algorithm>
using namespace std;
class Solution {
public:
    int bs(vector<int> &arr,int key,int s)
    {
        int start = s , end = arr.size()-1 , mid;
        mid = start + (end - start)/2; 
        while(start <= end)
        {
            if(arr[mid] == key)
            {
                return mid;
            }
            else if(key > arr[mid])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
            mid = start + (end - start)/2;
        }
        return -1;
    }
    int findPairs(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        set<pair<int,int>> ans;
        for(int i=0;i<arr.size();i++)
        {
            int key = arr[i]+k;
            int a = bs(arr,key,i+1);
            if(a!=-1)
            {
                ans.insert({arr[i],key});
            }

        }
        return ans.size();
    }
};