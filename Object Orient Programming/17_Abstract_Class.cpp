#include <iostream>
using namespace std;
class Student
{
    int rollno;
    string name;

public:
    Student()
    {
        rollno = 0;
        name = " ";
    }
    Student(int rollno, int name)
    {
        this->rollno = rollno;
        this->name = name;
    }
    void input_student()
    {
        cout << "\n\t Enter the Roll no : ";
        cin >> rollno;
        cout << "\t Enter the name : ";
        cin >> name;
    }
    void display_Student()
    {
        cout << "\n\t Roll No. : " << rollno;
        cout << "\t\t Name : " << name;
    }
    virtual void display() = 0;
};
class Engineering : public Student
{
    string course;
    int duration;
    int fees;

public:
    Engineering()
    {
        course = " MCA ";
        duration = 2;
        fees = 8700;
    }
    void display()
    {
        cout << "\n\t Course : " << course;
        cout << "\t Duration : " << duration;
        cout << "\t Fees : " << fees;
    }
};
class Medicine : public Student
{
    string course;
    float duration;
    int fees;

public:
    Medicine()
    {
        course = " BPTH ";
        duration = 5.5;
        fees = 150000;
    }
    void display()
    {
        cout << "\n\t Course : " << course;
        cout << "\t Duration : " << duration;
        cout << "\t Fees : " << fees;
    }
};
class Science : public Student
{
    string course;
    int duration;
    int fees;

public:
    Science()
    {
        course = " Physics ";
        duration = 1;
        fees = 34000;
    }
    void display()
    {
        cout << "\n\t Course : " << course;
        cout << "\t Duration : " << duration;
        cout << "\t Fees : " << fees;
    }
};
int main()
{
    int i = 0;
    Student *s[3];
    Engineering a;
    Medicine b;
    Science c;
    s[0] = &a;
    s[1] = &b;
    s[2] = &c;
    while (i < 3)
    {
        s[i]->input_student();
        i++;
    }
    int j = 0;
    while (j < 3)
    {
        s[j]->display_Student();
        s[j]->display();
        cout << endl;
        j++;
    }
    cout << endl << endl;
    return 0;
}
