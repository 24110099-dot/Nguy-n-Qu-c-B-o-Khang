/*
Name: NGUYEN QUOCS BAO KHANG
Class: 24110FIE4
ID: 24110099
DOB: 25/09/2006
*/
#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    string position;
    string gender;
    int age;
    int salary;

public:
    Employee(string name, string position,string gender, int age, int salary) {
        this->name = name;
        this->position = position;
        this->gender = gender;
        this->age = age;
        this->salary = salary;
    }

    void displayInfo() {
        cout << "----------------------\n";
        cout << "Name     : " << name << endl;
        cout << "Position : " << position << endl;
        cout << "Gender   : " << gender << endl;
        cout << "Age      : " << age << endl;
        cout << "Salary   : " << salary << " VND" << endl;
        cout << "Level    : " << getIncomeLevel() << endl;
    }

    string getIncomeLevel() {
        if (salary >= 30000000) return "High";
        else if (salary >= 10000000) return "Medium";
        else return "Low";
    }
};

int main() {
    Employee e1("Nguyen Van A", "Manager","female",21, 35000000);
    Employee e2("Tran Thi B", "Staff","male",22, 8000000);

    e1.displayInfo();
    e2.displayInfo();

    return 0;
}
