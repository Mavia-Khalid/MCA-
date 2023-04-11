#include<iostream>
using namespace std;
bool Binary_Search(int arr[][3] , int rows , int cols , int target)
{
    int s = 0;
    int e = rows*cols-1;
    int mid = s + (e-s)/2;
    while(s <= e)
    {
        int RowIndex = mid / cols;
        int ColIndex = mid % cols;
        if(arr[RowIndex][ColIndex] == target)
        {
            return true;
        }
        else if(arr[RowIndex][ColIndex] > target)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return false;
}
int main()
{
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    bool ans = Binary_Search(arr , 3 , 3 , 10);
    if(ans)
    {
        cout << "\n\t Found ";
    }
    else
    {
        cout << "\n\t Not Found ";
    }
    cout << endl;
    return 0;
}