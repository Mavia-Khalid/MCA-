#include <iostream>
using namespace std;
float strtofloat(string str)
{
    bool isNegative = false;
    int index = 0;
    float sum = 0.0;
    if (str[index] == '-')
    {
        isNegative = true;
        index++;
    }
    while (str[index] != '\0' && str[index] != '.')
    {
        if (str[index] >= 48 && str[index] <= 57)
        {
            sum = sum * 10 + (str[index] - 48);
        }
        else
        {
            cout << "\n\t Invalid Input ";
        }
        index++;
    }
    if (str[index] == '.')
    {
        index++;
        float d = 10.0;
        while (str[index] != '\0')
        {
            if (str[index] >= 48 && str[index] <= 57)
            {
                sum = (sum * d + (str[index] - 48)) / d;
                d = d * 10.0;
            }
            else
            {
                cout << "\n\t Invalid Input ";
                exit(0);
            }
            index++;
        }
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
    val = strtofloat(a);
    cout << "\n\t" << val << endl << endl;
    return 0;
}