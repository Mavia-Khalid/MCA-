#include <iostream>
#include <fstream>
using namespace std;
/*
    Contents of STORY.txt:
    The rose is red.
    A girl is playing there.
    Numbers are not allowed in the password.
    There is a playground.
    An aeroplane is in the sky.
*/
int main()
{
    ifstream fin;
    string line;
    int count = 0;
    fin.open("STORY.txt");
    while (getline(fin, line))
    {
        if (line[0] != 'A')
            count++;
    }
    fin.close();
    cout << "\n\t Lines Not Starting With 'A' in STORY.txt = " << count << endl << endl;
    return 0;
}