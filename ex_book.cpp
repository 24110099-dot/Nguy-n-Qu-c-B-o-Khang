/*
Name: NGUYEN QUOCS BAO KHANG
Class: 24110FIE4
ID: 24110099
DOB: 25/09/2006
*/
#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string id;
    double price;
    int year;

public:
    Book(string title, string author, string isbn, double price, int year) {
        this->title = title;
        this->author = author;
        this->id = isbn;
        this->price = price;
        this->year = year;
    }

    void displayInfo() {
        cout << "----------------------\n";
        cout << "Title : " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN  : " << id << endl;
        cout << "Price : " << price << " VND" << endl;
        cout << "Year  : " << year << endl;
        cout << "Status: " << isExpensive() << endl;
    }
    // Kiểm tra sách có đắt không
    string isExpensive() {
        if (price > 100000) return "Expensive";
        else return "Affordable";
    }
};

int main() {
    Book b1("You'd like to diet", "Chubby Chabong", "ISBN12345", 120000, 2022);
    Book b2("AWS", "Kamado tanjiro", "ISBN67890", 85000, 2021);

    b1.displayInfo();
    b2.displayInfo();

    return 0;
}
