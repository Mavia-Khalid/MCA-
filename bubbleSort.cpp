#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int *arr, int size)
{

    for (int i = 1; i < size; i++)
    {
        bool isSorted = true;
        for (int j = 0; j < size - i; j++)
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSorted = false;
            }
        if (isSorted)
            break;
    }
}

void seggregatedBubbleSort(int *arr, int size)
{

    for (int i = 1; i < size; i++)
    {
        bool isSorted = true;
        for (int j = 0; j < size - i; j++)
            // if ((arr[j] % 2 == 0 && arr[j + 1] % 2 == 0 && arr[j] < arr[j + 1]) || (arr[j] % 2 == 1 && arr[j + 1] % 2 == 1 && arr[j] > arr[j + 1]) || (arr[j] % 2 == 0 && arr[j + 1] % 2 == 1))
            if (
                (arr[j] % 2 == 0 && arr[j] < arr[j + 1]) ||
                (arr[j + 1] % 2 != 0 && arr[j + 1] < arr[j]))
            {
                swap(arr[j], arr[j + 1]);
                isSorted = false;
            }
        if (isSorted)
            break;
    }
}

void seggregatedBubble(int *a, int n)
{
    int odd_index = 0;
    for (int index = 0; index < n; index++)
    {
        if (a[index] % 2 == 1)
        {
            swap(a[odd_index], a[index]);
            odd_index++;
        }
    }

    for (int i = 1; i < odd_index; i++)
    {
        bool isSorted = true;
        for (int j = 0; j < odd_index - i; j++)
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                isSorted = false;
            }
        if (isSorted)
            break;
    }

    for (int i = odd_index + 1; i < n; i++)
    {
        bool isSorted = true;
        for (int j = odd_index; j < n - i; j++)
            if (a[j] < a[j + 1])
            {
                swap(a[j], a[j + 1]);
                isSorted = false;
            }
        if (isSorted)
            break;
    }
}

void printArr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int a[] = {3, 2, 45, 21, 32, 1, 98, 1099, 13, 49, 12, 45};
    int n = (sizeof(a) / sizeof(a[0]));
    printArr(a, n);
    seggregatedBubbleSort(a, n);
    printArr(a, n);
    return 0;
}