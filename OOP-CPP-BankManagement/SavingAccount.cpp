#pragma once 
#include <iostream> 
#include "BankAccount.cpp" 
#include "ConfirmService.cpp"
using namespace std;

class SavingAccount : public BankAccount
{
private:
    double interestRate;
public:
    SavingAccount() :BankAccount(), interestRate(0) {};
    SavingAccount(string accountName, int accountNumber, double balance, double interestRate) :
        BankAccount(accountName, accountNumber, balance), interestRate(interestRate) {};

    void setinterestRate(double interestRate) {
        this->interestRate = interestRate;
    }
    double getinterestRate() {
        return interestRate;
    }
    void deposit(double amount) {
        if (amount < 0) {
            ConfirmService::invalidAmount();
        }
        else {
            balance += amount;
        }
    }
    void withdraw(double amount) {
        if (amount > balance) {
            ConfirmService::invalidAmount();
        }
        else {
            balance -= amount;
        }
    }
    void checkBalance() {
        cout << "\n\n\the balance is : " << balance << endl;
    }

    void inputAccount()
    {
        BankAccount::inputAccount();
        cout << "\n\n\tenter interest rate: ";
        cin >> interestRate;
    }

    void outputAccount()
    {
        BankAccount::outputAccount();
        cout << "\n\n\tinterest rate: " << interestRate << endl;
    }

};