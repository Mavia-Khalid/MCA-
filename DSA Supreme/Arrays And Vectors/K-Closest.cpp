class Solution {
public:
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int s=0,e=arr.size()-1;
        
        while(e-s+1>k)
        {
            if(x-arr[s]>arr[e]-x)
            {
                s++;
            }
            else
            {
                e--;
            }
        }
        
        return vector<int>(arr.begin()+s,arr.begin()+e+1);
        
    }
};