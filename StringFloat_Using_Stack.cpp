#include <iostream>
using namespace std;
#include<stack>
float str_to_float(string str)
{
    stack<char> s;
    bool isNegative = false;
    float sum = 0.0;
    if (str[0] == '-')
    {
        isNegative = true;
    }
    for(int i = str.length()-1; i >= 0; i--)
    {
        s.push(str[i]);
    }
    while(s.top() != '.')
    {
        if(s.top() == '-')
        {
            s.pop();
            continue;
        }
        sum = sum * 10 + (s.top()-48);
        s.pop();
    }
    s.pop();
    float d = 10;
    while(!s.empty())
    {
        sum = (sum * d + (s.top()-48))/d;
        d = d * 10;
        s.pop();
    }
    if (isNegative)
    {
        sum = 0 - sum;
    }
    return sum;
}
int main()
{
    string a;
    cout << "\n\t Enter String in Integer Format ";
    getline(cin, a);
    float val;
    val = str_to_float(a);
    cout << "\n\t" << val << endl << endl;
    return 0;
}