#include <iostream> 
using namespace std;
class Shape
{
public:
    double Area(float base, float height)
    {
        return (base * height) / 2;
    }

    double Area(int breadth, int length)
    {
        return breadth * length;
    }

    double Area(float radius)
    {
        return (22 * radius * radius) / 7;
    }
};

int main()
{
    int breadth, length;
    float base, height;
    float radius;
    char choice;
    Shape *s = new Shape();
    do
    {
        cout << "\n\t Enter your choice : ";
        cout << "\n\t Enter 1 for Triangle ";
        cout << "\n\t Enter 2 for Rectangle ";
        cout << "\n\t Enter 3 for Circle ";
        cout << "\n\t Enter 4 to Exit .";
        cin >> choice;
        switch(choice)
        {
        case '1':
            cout << "\n\t Enter base : ";
            cin >> base; 
            cout << "\n\t Enter height : ";
            cin >> height;
            cout << "\n\t Area of Triangle is : " << s->Area(base, height);
            cout << endl;
            break;

        case '2':
            cout << "\n\t Enter length : ";
            cin >> length;
            cout << "\n\t Enter breadth : ";
            cin >> breadth;
            cout << "\n\t Area of Rectangle is : " << s->Area(breadth, length);
            cout << endl;
            break;

        case '3':
            cout << "\n\t Enter radius : ";
            cin >> radius;
            cout << "\n\t Area of Circle is : " << s->Area(radius);
            cout << endl;
            break;
        case '4':
            break;
        }

    } while (choice != '4');
}
