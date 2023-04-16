#include <iostream>
using namespace std;
class Student
{
protected:
    string name;
    int roll;

public:
    void get_details()
    {
        cout << "\n\t Enter Name : ";
        cin >> name;
        cout << "\n\t Enter Roll No : ";
        cin >> roll;
    }
    void display_details()
    {
        cout << "\n\t\t\t Student Information ";
        cout << "\n\t\t  Name : " << name;
        cout << "\t\t  Roll No. : " << roll;
        cout << endl;
    }
};
class Examination : public Student
{
protected:
    float test1, test2;
public:
    void get_ExamDetails()
    {
        cout << "\n\t Enter marks for Test 1 : ";
        cin >> test1;
        cout << "\n\t Enter marks for Test 2 : ";
        cin >> test2;
    }
    float totalExam()
    {
        return (test1 + test2);
    }
    void cal_average()
    {
        cout << "\n\t Average of Both Tests : " << (test1 + test2) / 2;
    }
};
class Extracurricular : public Student
{
};
class result : public Examination, public Extracurricular
{
};