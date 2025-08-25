/*
Name: NGUYEN QUOCS BAO KHANG
Class: 24110FIE4
ID: 24110099
DOB: 25/09/2006
*/
#include <iostream>

using namespace std;
// Class definition for Car
class Car {
public:
    // Attributes
        // Using string for brand and model to allow for more flexible input
    string brand;
    string model;
    int year;
    // Methods
    void getInformation() {
        cout << "Enter car brand: ";
        cin >> brand;
        cout << "Enter car model: ";
        cin >> model;
        cout << "Enter car year: ";
        cin >> year;
        cout << "---------------------------------\n";
    }
    // Display method to show car information
    void display() {
        cout << "Car Brand: " << brand << endl;
        cout << "Car Model: " << model << endl;
        cout << "Car Year: " << year << endl;
    }
};
int main() {
    Car s1;
    s1.getInformation();
    s1.display();
    return 0;
}