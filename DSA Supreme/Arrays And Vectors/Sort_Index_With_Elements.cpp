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
        int index = arr[i];
        if(arr[i] != arr[index])
        {
            swap(arr[i] , arr[index]);
        }
        else
        {
            i++;
        }
    }
    for(auto i:arr)
    {
        cout << i << " ";
    }
    cout << endl << endl;
}