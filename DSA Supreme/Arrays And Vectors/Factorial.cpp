#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;  
void Factorial(int Number)
{
    int result , carry = 0;
    vector<int> ans;
    ans.push_back(1);
    for(int i = 2; i <= Number; i++)
    {
        for(int j = 0; j < ans.size(); j++)
        {
            result = ans[j] * i + carry;
            ans[j] = result % 10;
            carry = result / 10;
        }
        while(carry)
        {
            ans.push_back((carry%10));
            carry = carry / 10;
        }
    }
    ans.shrink_to_fit();
    reverse(ans.begin() , ans.end());
    cout << "\t";
    for(int i:ans)
    {
       cout << i; 
    }
}
int main()
{
    int num;
    cout << "\n\t Enter A Number : ";
    cin >> num;
    Factorial(num);
    cout << endl << endl;
    return 0;
}