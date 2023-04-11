#include <iostream>
#include <vector>
using namespace std;
void Wave_Print(vector<vector<int>> &arr);
void Print(vector<vector<int>> &arr);
int main()
{
    vector<vector<int>> arr{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    Print(arr);
    Wave_Print(arr);
    cout << endl << endl;
}
void Wave_Print(vector<vector<int>> &arr)
{
    int j,i;
    for (int j = 0; j < arr[0].size(); j++)
    {
        cout << "\t";
        if ((j&1)== 0)
        {
            for (i = 0; i < arr.size(); i++)
            {
                cout << arr[i][j] << " ";
            }   
        }
        else
        {
            for (i = arr.size() - 1; i >= 0; i--)
            {
                cout << arr[i][j] << " ";
            }   
        }
    }
}
void Print(vector<vector<int>> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << "\t";
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}