/*
Name: NGUYEN QUOCS BAO KHANG
Class: 24110FIE4
ID: 24110099
DOB: 25/09/2006
*/
#include <iostream>
#include <string>
using namespace std;

class Circle {
private:
    double radius;
    string color;
public:
    Circle(double radius,string color) {
        if (radius > 0)
        {
            this->radius = radius;
        }
        else
        {
            this->radius = 1;
            cout << "Invalid radius! Set to 1 by default.\n";
        }
        this->radius = radius;
        this->color = color;
    }
    double getArea() {
        return 3.14 * radius * radius;
    }
    double getCircumference() {
        return 3.14 * 2 * radius;
    }
    void display()
    {
        cout << "Color: " << color << endl;
        cout << "Area: " << getArea() << endl;
        cout << "Circumference: " << getCircumference() << endl;
    }

};

int main() {
    Circle b1(3.14,"red");
    b1.display();
    return 0;
}
