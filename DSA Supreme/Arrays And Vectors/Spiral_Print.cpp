#include <iostream>
#include <vector>
using namespace std;
void Spiral_Print(vector<vector<int>> &arr);
void Print(vector<vector<int>> &arr);
int main()
{
    vector<vector<int>> arr{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12},{13,14,15,16}};
    Print(arr);
    Spiral_Print(arr);
    cout << endl << endl;
}
void Spiral_Print(vector<vector<int>> &arr)
{
    int StartRow = 0;
    int EndRow = arr.size()-1;
    int StartCol = 0;
    int EndCol = arr[0].size()-1;
    int count = 0;
    int Total_Elements = (arr.size()*arr[0].size());
    while(count < Total_Elements)
    {
        for(int i = StartRow; i <= EndCol && count < Total_Elements; i++)
        {
            cout << arr[StartRow][i] << " ";
            count++;
        }
        StartRow++;
        for(int i = StartRow; i <= EndRow && count < Total_Elements; i++)
        {
            cout << arr[i][EndCol] << " ";
            count++;
        }
        EndCol--;
        for(int i = EndCol; i >= StartCol && count < Total_Elements; i--)
        {
            cout << arr[EndRow][i] << " ";
            count++;
        }
        EndRow--;
        for(int i = EndRow; i >= StartRow && count < Total_Elements; i--)
        {
            cout << arr[i][StartCol] << " ";
            count++;
        }
        StartCol++;
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