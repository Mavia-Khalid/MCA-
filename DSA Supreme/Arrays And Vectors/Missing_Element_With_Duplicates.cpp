#include <iostream>
#include <vector>
#include<cstdlib>
using namespace std;
void FInd_Missing(vector<int> &arr)             // Method 1
{
    for (int i = 0; i < arr.size(); i++)
    {
        int index = abs(arr[i]);
        if(arr[index-1] > 0)
        {
            arr[index-1] *= -1;
        }
    }
    cout << "\n\t Missing Elements : ";
    for(int i=0 ; i < arr.size(); i++)
    {
        if(arr[i] > 0)
        {
            cout << i+1 << " ";
        }
    }
}
void FInd_Missing_2(vector<int> &arr)    
{
    int i = 0;
    while( i < arr.size())
    {
        if(arr[i] != arr[arr[i]-1])
        {
            swap(arr[i] , arr[arr[i]-1]);
        }
        else
        {
            i++;
        }
    }
    for(int i=0 ; i < arr.size(); i++)
    {
        if(arr[i] != i+1)
        {
            cout << i+1 << " ";
        }
    }
}
int main()                         // Constraint is a[i] belongs to [1,N]
{
    vector<int> arr{3,3,3,3,4,5};
    FInd_Missing_2(arr);
    cout << endl << endl;
    return 0;
}