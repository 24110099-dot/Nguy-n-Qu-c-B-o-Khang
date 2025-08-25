/*
Name: NGUYEN QUOCS BAO KHANG
Class: 24110FIE4
ID: 24110099
DOB: 25/09/2006
*/
#include <iostream>

using namespace std;

class Rectangle {
private: 
    double width;
    double length;

public:

    Rectangle(double width, double length)
    {
        this->width = width;
        this->length = length;
    }
    double getArea() {
        return width * length;
    }

    double getPerimeter() {
        return (width + length) * 2;
    }

    void display() {
        cout << "Area: " << getArea() << endl;
        cout << "Perimeter: " << getPerimeter() << endl;
    }
};

int main() {
    Rectangle r1(5,10);
    r1.display();
    return 0;
}