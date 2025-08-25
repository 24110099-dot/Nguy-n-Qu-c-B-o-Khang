/*
Name: NGUYEN QUOCS BAO KHANG
Class: 24110FIE4
ID: 24110099
DOB: 25/09/2006
*/
#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    string accountNumber;
    string ownerName;
    double balance;

public:
    Account(string accountNumber, string ownerName, double balance) {
        this->accountNumber = accountNumber;
        this->ownerName = ownerName;
        this->balance = balance;
    }
    void getDeposit(double amount)
    {
        balance += amount;
        cout << "Deposit: " << amount << endl;
    }
    void getWithdraw(double amount)
    {
        const double MIN_BALANCE = 100000;
        if (amount > balance - MIN_BALANCE)
        {
            cout << "Insufficient balance! You must keep at least " << MIN_BALANCE << " VND in your account." << endl;
        }
        else
        {
            balance -= amount;
            cout << "Withdrew: " << amount << endl;
        }
    }
    void displayBalance()
    {
        cout << "------------------------\n";
        cout << "Owner Name: " << ownerName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current balance: " << balance << endl;
    }
};

int main() {
    Account acc1("123456789", "Nguyen Van A", 100000);
    acc1.displayBalance();
    acc1.getDeposit(500000);

    acc1.displayBalance();
    acc1.getWithdraw(200000);

    acc1.displayBalance();
    acc1.getWithdraw(300000);
    acc1.displayBalance();
    return 0;
}