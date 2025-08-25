/*
Name: NGUYEN QUOCS BAO KHANG
Class: 24110FIE4
ID: 24110099
DOB: 25/09/2006
*/
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int mssv;
    int age;
    double grade;
public:

    Student(string name, int mssv, int age, double grade)
    {
        this->name = name;
        this->mssv = mssv;
        this->age = age;
        this->grade = grade;
    }
    void getDisplay()
    {
        cout << "----------------------\n";
        cout << "Full Name: " << name << endl;
        cout << "Mssv: " << mssv << endl;
        cout << "Age: " << age << endl;
        cout << "Grade: " << grade << endl;
        cout << "Rank: " << getAverage() << endl;
   }
    string getAverage()
    {
        if (grade >= 9.0) return "Excellent";
        else if (grade >= 8.0) return "Good";
        else if (grade >= 6.5) return "Fair";
        else if (grade >= 5.0) return "Average";
        else return "Poor";
    }


};

int main() {
    Student s1("kukkaka",22110098,21,8.0);
    Student s2("Chubby", 22110088, 21, 8.0);
    Student s3("Com khong voi cha bong", 22110098, 21, 8.0);
    Student s4("Lau ga binh thuan", 22110098, 21, 8.0);
    Student s5("Mot thang 5 trieu", 22110097, 21, 5.0);
    s1.getDisplay();
    s2.getDisplay();
    s3.getDisplay();
    s4.getDisplay();
    s5.getDisplay();
    return 0;
}