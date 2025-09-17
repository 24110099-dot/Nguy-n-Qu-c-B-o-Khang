/*
Name: NGUYEN QUOCS BAO KHANG
Class: 24110FIE4
ID: 24110099
DOB: 25/09/2006
*/
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

string getCurrentDate() 
{
    time_t now = time(0);
    char buf[80];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&now));
    return string(buf);
}

class Transaction 
{
    double amount;
    string type;
    string date;
public:
    Transaction(double amt, string t) : amount(amt), type(t), date(getCurrentDate()) {}

    void display() const {
        cout << "[" << date << "] " << type << ": $" << amount << endl;
    }
};

class Account
{
protected:
    int accountNumber;
    double balance;
    string ownerName;
    vector<Transaction> history;

public:
    Account(int accNum, string owner, double bal = 0.0)
        : accountNumber(accNum), ownerName(owner), balance(bal) {}

    virtual ~Account() {}

    virtual void deposit(double amount) {
        balance += amount;
        *this += Transaction(amount, "Deposit");
    }

    virtual bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            *this += Transaction(amount, "Withdraw");
            return true;
        }
        return false;
    }

    double getBalance() const { return balance; }
    int getAccountNumber() const { return accountNumber; }
    string getOwnerName() const { return ownerName; }

    Account& operator+=(const Transaction& t) 
    {
        history.push_back(t);
        return *this;
    }

    bool operator==(const Account& other) const
    {
        return balance == other.balance; 
    }

    virtual void display() const 
    {
        cout << "Account #" << accountNumber << " | Owner: " << ownerName
            << " | Balance: $" << balance << endl;
    }

    void showHistory() const
    {
        cout << "Transaction History for Account #" << accountNumber << ":\n";
        for (const auto& t : history) {
            t.display();
        }
    }
};

class SavingsAccount : public Account 
{
    double interestRate; 
    int withdrawalCount;
    const int withdrawalLimit = 3; 
public:
    SavingsAccount(int accNum, string owner, double bal, double rate)
        : Account(accNum, owner, bal), interestRate(rate), withdrawalCount(0) {}

    bool withdraw(double amount) override 
    {
        if (withdrawalCount >= withdrawalLimit)
        {
            cout << "Withdrawal limit reached for Savings Account #" << accountNumber << endl;
            return false;
        }
        if (balance >= amount) 
        {
            balance -= amount;
            withdrawalCount++;
            *this += Transaction(amount, "Savings Withdraw");
            return true;
        }
        return false;
    }

    void applyInterest() 
    {
        double interest = balance * (interestRate / 100);
        balance += interest;
        *this += Transaction(interest, "Interest Applied");
    }

    void display() const override 
    {
        cout << "Savings Account #" << accountNumber << " | Owner: " << ownerName
            << " | Balance: $" << balance << " | Interest Rate: " << interestRate << "%\n";
    }
};

class Customer
{
    int id;
    string name;
    vector<Account*> accounts;

public:
    Customer(int i, string n) : id(i), name(n) {}

    ~Customer() 
    {
        for (auto acc : accounts) delete acc;
    }

    void openAccount(Account* acc) 
    {
        accounts.push_back(acc);
    }

    void displayAccounts() const
    {
        cout << "Customer: " << name << " (ID: " << id << ")\n";
        for (auto acc : accounts) 
        {
            acc->display();
        }
    }

    double totalBalance() const 
    {
        double sum = 0;
        for (auto acc : accounts) sum += acc->getBalance();
        return sum;
    }
};
int main() 
{
    Customer c1(1, "Alice");

    Account* acc1 = new Account(1001, "Alice", 500);
    SavingsAccount* acc2 = new SavingsAccount(2001, "Alice", 1000, 3.0);

    c1.openAccount(acc1);
    c1.openAccount(acc2);

    c1.displayAccounts();

    cout << "\n--- Performing Transactions ---\n";
    acc1->deposit(200);
    acc1->withdraw(100);

    acc2->withdraw(200);
    acc2->withdraw(200);
    acc2->withdraw(200); 
    acc2->withdraw(200);

    cout << "\nApplying interest to Savings...\n";
    acc2->applyInterest();

    c1.displayAccounts();

    cout << "\n--- Transaction Histories ---\n";
    acc1->showHistory();
    acc2->showHistory();

    cout << "\nComparing Accounts: ";
    if (*acc1 == *acc2) cout << "Balances are equal.\n";
    else cout << "Balances are different.\n";

    cout << "Total balance across Alice's accounts: $" << c1.totalBalance() << endl;

    return 0;
}
