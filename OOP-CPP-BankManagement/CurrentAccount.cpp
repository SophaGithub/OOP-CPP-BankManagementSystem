#pragma once
#include <iostream> 
#include "BankAccount.cpp" 
#include "ConfirmService.cpp"
using namespace std;

class CurrentAccount : public BankAccount
{
private:
    double chargingFee;
public:
    CurrentAccount() :BankAccount(), chargingFee(0) {};
    CurrentAccount(string accountName, int accountNumber, double balance, double chargingFee) :
        BankAccount(accountName, accountNumber, balance), chargingFee(chargingFee) {};

    void setChargingFee(double chargingFee) {
        this->chargingFee = chargingFee;
    }
    double getChargingFee() {
        return chargingFee;
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
        cout << "\n\n\tthe balance is : " << balance << endl;
    }

    void inputAccount()
    {
        BankAccount::inputAccount();
        cout << "\n\n\tenter charging fee: ";
        cin >> chargingFee;
    }

    void outputAccount()
    {
        BankAccount::outputAccount();
        cout << "\n\n\tcharging fee: " << chargingFee << endl;
    }

};