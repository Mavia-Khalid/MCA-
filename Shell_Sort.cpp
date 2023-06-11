#include <iostream>
#include <math.h>
using namespace std;
void Print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << " " << arr[i];
    }
}
void Shell_Sort(int *arr, int n)
{
    int gap, temp, j, i;
    gap = floor(n / 2);
    while (gap >= 1)
    {
        for (i = gap; i < n; i++)
        {
            temp = arr[i];
            j = i;
            while (j >= gap && arr[j - gap] > temp)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
        cout << "\n\t  After Iteration : ";
        Print(arr, n);
        gap = floor(gap / 2);
    }
}
void Shell_Sort_2(int *arr, int n)
{
    int gap,i,j,temp;
    gap = 1;
    while(gap<n/3)
    {
        gap = 3*gap+1;
    }
    while (gap >= 1)
    {
        for (i = gap; i < n; i++)
        {
            temp = arr[i];
            j = i;
            while (j >= gap && arr[j - gap] > temp)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
        cout << "\n\t  After Iteration : ";
        Print(arr, n);
        gap = (gap-1)/3;
    }
}
void Input(int *arr, int n)
{
    cout << "\n\t Enter Elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}
int main()
{
    int n;
    cout << "\n\t Enter Array : ";
    cin >> n;
    int *arr = new int[n];
    Input(arr, n);
    cout << "\n\t Entered Array is : ";
    Print(arr, n);
    Shell_Sort_2(arr, n);
    cout << "\n\t After Sorting : ";
    Print(arr, n);
    cout << endl;
    return 0;
}