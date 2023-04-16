/*1. Class student contains roll number, name and course as data members and
Input_student() and display_student() as member functions. A derived class exam is
created from the class student with publicly inherited. The derived class contains mark1,
mark2, mark3 as marks of three subjects and input_marks() and display_result() as
member functions. Create an array of objects of the exam class and display the result of 5
students.*/
#include <iostream>
using namespace std;
class Student
{
        string name, course;
    protected:
        int roll;
    public:
        void input_student();
        void display_student();
};
void Student::input_student()
{
    cout << "\n\t Enter your RollNo : ";
    cin >> roll;
    cin.ignore();
    cout << "\n\t Enter your Name : ";
    getline(cin, name);
    cout << "\n\t Enter your Course Name : ";
    getline(cin, course);
    cout << endl;
}
void Student::display_student()
{
    cout << "\n\t\t\t Student Information ";  
    cout << "\n\t\t  Name : " << name;
    cout << "\t\t  Roll No. : " << roll;
    cout << "\n\t\t  Course : " << course;
    cout << endl;
}
class Exam:public Student
{
    string marks[3];
    public:
    void input_marks();
    void display_result();
    int rollno(int r, int i);
};
void Exam::input_marks()
{
    cout << "\n\t Enter Marks for DL : ";
    cin >> marks[0];
    cout << "\n\t Enter Marks for DM : ";
    cin >> marks[1];
    cout << "\n\t Enter Marks for APD : ";
    cin >> marks[2];
}
void Exam::display_result()
{
    cout << "\n\t\t\t Examination Details : ";
    cout << "\n\t\t\t   Paper Name " << "\t Marks ";
    cout << "\n\t\t\t      DL " << "\t  " << marks[0];
    cout << "\n\t\t\t      DM " << "\t  " << marks[1];
    cout << "\n\t\t\t      APD" << "\t  " << marks[2];
}
int Exam::rollno(int r, int i)
 {
    if (roll == r)
    {
        return i;    // returns index of the object where the record is stored
    }
    else
        return -1;   // if record not found , returns -1
}
int count = 0;
int main()
{
    Exam a[5];
    char choice;
    do
    {
        cout << "\n\t Press 1 to Create new Student record ";
        cout << "\n\t Press 2 to View student record ";
        cout << "\n\t Press 3 to Exit ";
        cin >> choice;
        switch(choice)
        {
            case '1':
            {
                a[count].input_student();
                a[count++].input_marks();
                break;
            }
            case '2':
            {
                int roll;
                int j = -1;  // variable to store index of record and if not available value stays -1 or in wrong input
                cout << "\n\t Enter the Roll to acess student record: ";
                cin >> roll;
                int i = 0;    // variable to iterate through array of objects
                while (j == -1 && i < count)    // as soon as j value is changed that means record found
                {
                    j = a[i].rollno(roll, i);     // stores index of record if found
                    i++;
                }
                if(j != -1)
                {
                    a[j].display_student();
                    a[j].display_result();
                }
                else
                {
                    cout << "\n\t Invalid Choice ";
                }
                break;
            }
            case '3':
                break;
            default:
                break;
        }
    } while(choice != '3');
}
