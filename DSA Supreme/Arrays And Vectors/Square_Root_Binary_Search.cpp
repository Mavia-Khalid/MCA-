#include<iostream>
using namespace std;
float Square_Root(int num);
int main()
{
    int num;
    cout << "\n\t Enter a Number : ";
    cin >> num;
    double Ans = Square_Root(num);
    cout << "\n\t Square Root : " << Ans;
    cout << endl << endl;
    return 0;
}
float Square_Root(int num)
{
    if(num == 0 || num == 1)
    {
        return num;
    }
    double start = 0 , end = num , mid;
    double ans;
    mid = start + (end - start)/2; 
    while(start <= end)
    {
        if(mid * mid == num)
        {
            return mid;
        }
        else if (mid * mid > num)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
            ans = mid;
        }
        mid = start + (end - start)/2;
    }
    for(double i = ans; i*i <= num; i += 0.01)
    {
        ans = i;
    }
    return ans;
}
