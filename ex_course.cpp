/*
Name: NGUYEN QUOCS BAO KHANG
Class: 24110FIE4
ID: 24110099
DOB: 25/09/2006
*/
#include <iostream>
#include <string>
using namespace std;

class Course {
private:
    string courseName;
    int courseCode;
    int credits;
    string instructorName;

public:
    Course(string courseName, int courseCode, int credits, string instructorName)
    {
        this->courseName = courseName;
        this->courseCode = courseCode;
        this->credits = credits;
        this->instructorName = instructorName;
    }
    void displayCourseInfo() const
    {
        cout << "Course Name: " << courseName << endl;
        cout << "Instructor Name: " << instructorName << endl;
        cout << "Course Code: " << courseCode << endl;
        cout << "Credits: " << credits << endl;
        cout << "IshightCredits: " << isHighCredits() << endl;
        cout << "Lab: " << isLabRequired() << endl;

    }
    string isHighCredits() const
    {
        if (credits > 3) {
            return "This course has high credits.";
        }
        else {
            return "This course does not have high credits.";
        }
    }
    string isLabRequired() const
    {
        if (credits >= 4) {
            return "Lab is required for this course.";
        }
        else {
            return "Lab is not required for this course.";
        }
    }
};

int main() {
    Course course1("Data Structures", 101, 4, "Dr. Smith");
    cout << "Course Information:" << endl;
    cout << "---------------------" << endl;
    course1.displayCourseInfo();

}
