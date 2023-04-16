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
        cout << "\t Enter Roll No : ";
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
class Examination : virtual public Student
{
protected:
    float test1, test2;

public:
    void Get_Exam_Details()
    {
        cout << "\n\t Enter Marks for Test 1 : ";
        cin >> test1;
        cout << "\t Enter Marks for Test 2 : ";
        cin >> test2;
    }
    float totalExam()
    {
        return (test1 + test2);
    }
    float cal_average()
    {
        return (test1 + test2) / float(2);
    }
    void display_average()
    {
        cout << "\n\t Average of Both Tests : " << cal_average();
    }
};
class Extracurricular : virtual public Student
{
protected:
    float painting, music;

public:
    void get_score()
    {
        cout << "\n\t Enter Marks for painting : ";
        cin >> painting;
        cout << "\t Enter Marks for music : ";
        cin >> music;
    }
    void display_total()
    {
        cout << "\n\t Total Marks in Music and Painting : " << (painting+music); 
    }
};
class result : public Examination, public Extracurricular
{
    float total = 0;
public:
    void cal_total()
    {
        total = (painting+music+test1+test2);
        cout << "\n\t Total Marks Obtained : " << total;
    }
    void comment()
    {
        if(total > 100)
        {
            cout << "\n\t Passed ";
        }
        else
        {
            cout << "\n\t Failed ";
        }
    }
};
int main()
{
    int n;
    cout<<"\n\t Enter the no of students : ";
    cin>>n;
    result *a = new result[n];
    for(int i = 0; i < n; i++)
    {
        cout << "\n\t Enter Student " << i+1 << " Details ";
        a[i].get_details();
        a[i].Get_Exam_Details();
        a[i].get_score();
    }
    for(int i = 0; i < n; i++)
    {
        cout << "\n\t\t         Student " << i+1 << " Details ";
        a[i].display_details();
        cout << "\n\t Marks in Tests : " << a[i].totalExam();
        a[i].display_average();
        a[i].display_total();
        a[i].cal_total();
        a[i].comment();
    }
    cout << endl << endl;
    return 0;

}