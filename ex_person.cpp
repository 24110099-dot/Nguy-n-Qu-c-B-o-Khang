/*
Name: NGUYEN QUOCS BAO KHANG
Class: 24110FIE4
ID: 24110099
DOB: 25/09/2006
*/
#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int age;
    string address;
    string phoneNumber;
public:
    Person(string name, int age, string address, string phoneNumber)
    {
        this->name = name;
        this->age = age;
        this->address = address;
        this->phoneNumber = phoneNumber;
    }
    void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Address: " << address << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Is Adult: ";
        cout << isAdult() << endl;
    }
    string isAdult()
    {
        if (age >= 18) {
            return "This person is an adult.";
        }
        else {
            return "This person is not an adult.";
        }
    }
    void Move(string newAddress)
    {
        address = newAddress;
    }
};

int main() {
    Person person1("John Doe", 20, "123 Main St", "123-456-7890");
    person1.displayInfo();
    person1.Move("789 New Address");
    cout << "-------After moving-------:" << endl;
    person1.displayInfo();
    cout << "------------------------------\n";
    Person person2("Jane Smith", 16, "456 Elm St", "987-654-3210");
    person2.displayInfo();
    person2.Move("321 New Address");
    cout << "-------After moving-------:" << endl;
    person2.displayInfo();

    return 0;

}
