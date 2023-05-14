#include <iostream>
using namespace std;
class Polygon
{
protected:
    float width, height, area;

public:
    void set_val()
    {
        cout << "\n\t Enter Width : ";
        cin >> width;
        cout << "\t Enter Height : ";
        cin >> height;
    }
    virtual float cal_area() = 0;     // virtual function declared in base class
};
class Rectangle : public Polygon
{
public:
    float cal_area()    
    {
        return (width * height);
    }
};
class Triangle : public Polygon
{
public:
    float cal_area()
    {
        return (width * height * 0.5);
    }
};
int main()
{
    Polygon *p1 , *p2;
    Rectangle a;
    Triangle b;
    p1 = &a;
    p2 = &b;
    p1 -> set_val();
    cout << "\n\t Area of Rectangle : " << p1 -> cal_area();
    cout << endl;
    p2 -> set_val();
    cout << "\n\t Area of Traingle : " << p2 -> cal_area();
    cout << endl << endl;
    return 0;
}