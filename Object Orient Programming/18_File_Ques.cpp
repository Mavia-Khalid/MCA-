#include <iostream>
#include <fstream>
using namespace std;
/*
    Contents of File1.txt:
    Name : Mavia Khalid
    Course : MCA

    Contents of File2.txt:
    Roll No. : 22MCA026
    University : Jamia Millia Islamia
*/
int main()
{
    ifstream fin;
    fin.open("File1.txt");
    string line, merged = "";
    while (getline(fin, line))
    {
        merged = merged + line + '\n';
    }
    fin.close();

    fin.open("File2.txt");
    while (getline(fin, line))
    {
        merged = merged + line + '\n';
    }
    fin.close();
    ofstream fout;
    fout.open("merged.txt");
    fout << merged;
    fout.close();
/*
    Output :
    Contents of nmergedtxt:
    Name : Mavia Khalid
    Course : MCA
    Contents of File2.txt:
    Roll No. : 22MCA026
    University : Jamia Millia Islamia
*/
}