#include <iostream>
#include<string>
#include<queue>
using namespace std;
bool digit(char ch)
{
    return ch >= '0' && ch <= '9';
}
int main()
{
    string str ;
    queue<char> s;
    cout << "\n\t Enter String ";
    getline(cin, str);
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == ' ')
        {
            continue;
        }
        else if (digit(str[i]))
        {
            while(i < str.length() && digit(str[i]))
            {
                s.push(str[i++]);
            }
            i--;
        }
        else
        {
            s.push(str[i]);
        }
    }
    while(!s.empty())
    {
        cout << "\"" << s.front() << "\",";
        s.pop();
    }
    cout << "\b ";
    cout << endl;
    cout << endl;
    return 0;
}