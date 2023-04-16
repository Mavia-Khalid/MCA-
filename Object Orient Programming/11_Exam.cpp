#include <iostream>
#include <string.h>
using namespace std;
int count = 0;
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
    cout << "\t Enter your Name : ";
    getline(cin , stud_name);
    cout << "\t Enter your Course Name : ";
    cin >> course_name;
    cout << "\t Enter your DOB : ";
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
    cout << "\n\t\t\t Student Information ";  
    cout << "\n\t\t  Name : " << stud_name;
    cout << "\t\t  Roll No. : " << stud_roll;
    cout << "\n\t\t  Course : " << course_name;
    cout << "\t\t  DOB : " << dob;
    cout << endl;
}
class Exam
{
    string exam_name, paper_name[2], paper_code[2];
    float marks_obtained[2], total_marks , n = 2;
    string grade[2];
    Student a;
public:
    Exam()            // Constructor
    {
        total_marks = 100;
    }
    void getmarks();
    void modifymarks();
    void printresult();
    void getgrade(int i);
    int totalmarks();
    void students();
    int roll(int r, int i)  // Checks if the given roll no exists or not 
    {
        if (a.stud_roll == r)
        {
            return i;    // returns index of the object where the record is stored
        }
        else
            return -1;   // if record not found , returns -1
    }
};
void Exam::getmarks()
{
    cout << "\n\t Enter Exam Name : ";
    cin >> exam_name;
    for(int i = 0; i < n; i++)
    {
        cout << "\n\t Enter Paper " << i+1 << " Code ";
        cin >> paper_code[i];
        cout << "\t Enter Paper " << i+1 << " Name ";    
        cin >> paper_name[i];
        cout << "\t Enter Marks : ";
        cin >> marks_obtained[i];
        getgrade(i);
    }
}
void Exam::students()  
{
    a.Getrec();   // gets student info
    getmarks();   // gets student exam info
}
void Exam::getgrade(int i)
{
    if(marks_obtained[i] >= 90)
    {
        grade[i] = "A+";
    }
    else if(marks_obtained[i] >= 80 && marks_obtained[i] < 90)
    {
        grade[i] = "A-";
    }
    else if(marks_obtained[i] >= 70 && marks_obtained[i] < 80)
    {
        grade[i] = "B+";
    }
    else if(marks_obtained[i] >= 60 && marks_obtained[i] < 70)
    {
        grade[i] = "B-";
    }
    else if(marks_obtained[i] >= 50 && marks_obtained[i] < 60)
    {
        grade[i] = "C+";
    }
    else if(marks_obtained[i] >= 40 && marks_obtained[i] < 50)
    {
        grade[i] = "C-";
    }
    else if(marks_obtained[i] >= 33 && marks_obtained[i] < 40)
    {
        grade[i] = "E";
    }
    else
    {
        grade[i] = "F";
    }
}
int Exam::totalmarks()
{
    float total = 0;
    for(int i = 0; i < n; i++)
    {
        total = total + marks_obtained[i];
    }
    return total;
}
void Exam::printresult()
{      
    a.Printrec();
    cout << "\n\t\t\t Examination Name : " << exam_name;
    cout << "\n\t    Paper Name " << "\t Paper Code "<< "\t Marks " << "\t   Grade ";
    for(int i = 0; i < n; i++)
    {
        cout << "\n\t\t" << paper_name[i] << "\t   " << paper_code[i] << "\t   " << marks_obtained[i] << "        " << grade[i];
    }
    cout << endl;
    float p = (totalmarks()*100)/float(200);
    cout << "\n\t    Total marks : " << totalmarks();
    cout << "\t Percentage : " << p;
    if(p >= 33)
    {
        cout << "\n\n\t\t\t   Result : Pass "; 
    }
    else
    {
        cout << "\n\n\t\t\t   Result : Fail ";
    }
    cout << endl << endl;
}
void Exam::modifymarks()
    {
        char choice;
        cout << "\n\t Press 1 to Modify Student Info  ";
        cout << "\n\t Press 2 to Modify Student Marks ";
        cin >> choice;
        switch(choice)
        {
        case '1':
        {
            a.Modifyrec();
            break;
        }
        case '2':
        {
            int j = 0;
            cout << "\n\t Enter serial no. to modify marks ";
            for (int i = 0; i < n; i++)   // loop to iterate through subjects
            {
                cout << endl << i + 1 << ". " << paper_name[i] << "  ";
                cout << marks_obtained[i] << endl;
            }
            cin >> j;
            cin.ignore();
            if (j >= 1 && j <= n)  // condition to check entered value is correct
            {
                cout << "Enter the correct marks of the student\n";
                cin >> marks_obtained[j - 1];
                cin.ignore();
            }
            else
            {
                cout << "\n\t Invalid Choice ";
            }
            break;
        }
        default:
            cout << "\n\t Invalid Choice ";
            break;
        }
}
int main()
{
    Exam a[10];
    char choice;
    do
    {
        cout << "\n\t Press 1 to Create new Student record ";
        cout << "\n\t Press 2 to Modify or View existing student record ";
        cout << "\n\t Press 3 to Exit ";
        cin >> choice;
        switch(choice)
        {
            case '1':
            {
                a[count++].students();
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
                    j = a[i].roll(roll, i);     // stores index of record if found
                    i++;
                }
                if (j != -1)
                {
                    char choice1;
                    do
                    {
                        cout << "\n\t Press 1 to show marksheet of the student ";
                        cout << "\n\t Press 2 to modify student record ";
                        cout << "\n\t Press 3 to exit ";
                        cin >> choice1;
                        switch (choice1)
                        {
                            case '1':
                            {
                                a[j].printresult();   // j is the index where record is stored
                                break;
                            }
                            case '2':
                            {
                                a[j].modifymarks();
                                break;
                            }
                            case '3':
                            {
                                break;
                            }
                            default:
                            {
                                cout << "\n\t Invalid Input";
                            }
                        }
                    } while (choice1 != '3');
                }
                else if (j == -1)
                {
                    cout << "\n\t No record found ";
                }
                break;
            }
            case '3':
            {
                break;
            }
            default:
            {
                cout << "\n\t Enter valid input ";
                break;
            }
        }
    } while(choice != '3');
    cout << endl;
    return 0;
}
