#include <iostream> 
using namespace std; 
class Distance
{
    int inch;
    int feet;
public:
    Distance()
    {
    }
    Distance(float feet, float inch)
    {
        this->feet = feet;
        this->inch = inch;
    }
    operator double()
    {
        double meter;
        meter = feet * 12 + inch;
        meter = (meter * 0.0254);
        return (meter);
    }

    void display()
    {
        if(inch > 11)
        {
            feet += inch/12;
            inch = int(inch)%12;
        }
        cout << "\n\t Feet : " << feet;
        cout << "\n\t Inch : " << inch;
        return;
    }
};
int main()
{
    double meter;
    int feet, inch;
    cout << "\n\t Enter Feet : ";
    cin >> feet;
    cout << "\n\t Enter inch : ";
    cin >> inch;
    Distance *d = new Distance(feet, inch);
    d->display();
    meter = *d; // invoke conversion function   	
    cout << "\n\t Distance in meters is : " << meter;
    cout << endl << endl;
    return 0;
}
