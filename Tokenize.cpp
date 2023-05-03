#include <iostream>
#include<string>
using namespace std;
bool digit(char ch)
{
    return ch >= '0' && ch <= '9';
}
int main()
{
    string str , n , token;
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
                n += str[i++];
            }
            i--;
            token += n;
        }
        else
        {
            token += str[i];
        }
    }
    for(int i = 0; i < token.size(); i++)
    {
        cout << "\"" << token[i] << "\",";
    }
    cout << "\b ";
    cout << endl;
    cout << endl;
    return 0;
}