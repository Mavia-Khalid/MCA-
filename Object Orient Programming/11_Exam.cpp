#include <iostream>
#include <string.h>
#include<cstdlib>
#include<windows.h>
using namespace std;
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
class Student
{
    int stud_roll;
    string stud_name, course_name, dob;

public:
    void Getrec();
    void Modifyrec();
    void Printrec();
    friend class Exam;
};
void Student::Getrec()
{
    cout << "\n\t Enter your Roll No. : ";
    cin >> stud_roll;
    cin.ignore();
    cout << "\n\t Enter your Name : ";
    getline(cin , stud_name);
    cout << "\n\t Enter your Course Name : ";
    cin >> course_name;
    cout << "\n\t Enter your DOB : ";
    cin >> dob;
    cout << endl;
}
void Student::Modifyrec()
{
    int choice;
    do
    {
        cout << "\n\t Enter 1 to Change RollNo ";
        cout << "\n\t Enter 2 to Change Name ";
        cout << "\n\t Enter 3 to Change Course Name ";
        cout << "\n\t Enter 4 to Change Dob ";
        cout << "\n\t Enter 5 to Exit ";
        cout << endl;
        cout << "\n\t Which field you want to Modify : ";
        cin >> choice;
        switch(choice)
        {
        case 1:
            cout << "\n\t Enter New Roll No. : ";
            cin >> stud_roll;
            break;
        case 2:
            cout << "\n\t Enter Name : ";
            cin >> stud_name;
            break;
        case 3:
            cout << "\n\t Enter New Course Name : ";
            cin >> course_name;
            break;
        case 4:
            cout << "\n\t Enter correct DOB : ";
            cin >> dob;
            break;
        case 5:
            break;
        }
    } while(choice != 5);
    cout << endl;
}
void Student::Printrec()
{
    gotoxy(15,2);
    cout << " Student Information ";
    gotoxy(3,5);
    cout << " Name : " << stud_name;
    gotoxy(30,5);
    cout << " Roll No. : " << stud_roll;
    gotoxy(3,6);
    cout << " Course : " << course_name;
    gotoxy(30,6);
    cout << " DOB : " << dob;
    cout << endl;
}
class Exam
{
    string exam_name, paper_name[4], paper_code[4];
    int marks_obtained[4], total_marks;
    char grade[4];

public:
    Exam()
    {
        total_marks = 100;
    }
    void getmarks();
    void modifymarks();
    void printresult();
    void getgrade(int i);
    int totalmarks();
};
void Exam::getmarks()
{
    cout << "\n\t Enter Exam Name : ";
    cin >> exam_name;
    for(int i = 0; i < 4; i++)
    {
        cout << "\n\t Enter Paper " << i << " Code ";
        cin >> paper_code[i];
        cout << "\n\t Enter Paper " << i << " Name ";    
        cin >> paper_name[i];
        cout << "\n\t Enter Marks : ";
        cin >> marks_obtaine[i];
        getgrade(i);
    }
}
void Exam::getgrade(int i)
{
    if(marks_obtained[i] >= 90)
    {
        grade[i] = 'A';
    }
    else if(marks_obtained[i] >= 80 && marks_obtained[i] < 90)
    {
        grade[i] = 'B';
    }
    else if(marks_obtained[i] >= 70 && marks_obtained[i] < 80)
    {
        grade[i] = 'C';
    }
    else if(marks_obtained[i] >= 60 && marks_obtained[i] < 70)
    {
        grade[i] = 'D';
    }
    else if(marks_obtained[i] >= 50 && marks_obtained[i] < 60)
    {
        grade[i] = 'E';
    }
    else
    {
        grade[i] = 'F';
    }
}
int Exam::totalmarks()
{
    int total;
    for(int i = 0; i < 4; i++)
    {
        total = total + marks_obtained[i];
    }
    return total;
}
int main()
{
    cout << endl;
    float sum = 0;
    Student s1;
    s1.Getrec();
    s1.Printrec();
    return 0;
}