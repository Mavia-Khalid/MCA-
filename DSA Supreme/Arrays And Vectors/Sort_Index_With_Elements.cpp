#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> arr{1,3,2,4,0};
    int i = 0;
    while( i < arr.size())
    {
        while(arr[i] != i)
        {
            swap(arr[i] , arr[arr[i]]);
        }
        i++;
    }
    for(auto i:arr)
    {
        cout << i << " ";
    }
    cout << endl << endl;
}