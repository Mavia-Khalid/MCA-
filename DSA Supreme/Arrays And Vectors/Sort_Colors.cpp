#include <iostream>
#include <vector>
using namespace std;
void sort(vector<int> &arr);
int main()
{
    vector<int> arr{2, 0, 1};
    sort(arr);
    for (auto i : arr)
    {
        cout << " " << i;
    }
    cout << endl << endl;
}
void sort(vector<int> &arr)
{
    int l = 0, m = 0, h = arr.size() - 1;
    while (m <= h)
    {
        if (arr[m] == 0)
        {
            swap(arr[l++], arr[m++]);
        }
        else if (arr[m] == 1)
        {
            m++;
        }
        else
        {
            swap(arr[m], arr[h--]);
        }
    }
}