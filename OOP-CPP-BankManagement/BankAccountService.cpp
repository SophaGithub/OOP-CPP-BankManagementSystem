#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "BankAccount.cpp"
using namespace std;

class BankAccountService {
private:
	vector<BankAccount*> accounts;
public:
	/*~BankAccountService() {
		vector<BankAccount*>::iterator it;
		for (it = accounts.begin(); it != accounts.end(); it++) {
			delete* it;
		}
	}*/
	void addBankAccount(BankAccount* account) {
		accounts.push_back(account);
	}
	void viewAllBankAccount() {
		vector<BankAccount*>::iterator it;
		for (it = accounts.begin(); it != accounts.end(); it++) {
			(*it)->outputAccount();
			cout << endl;
		}
	}
	void editBankAccount(string name) {
		vector<BankAccount*>::iterator it;
		for (it = accounts.begin(); it != accounts.end(); it++) {
			if ((*it)->getAccountName().compare(name)) {
				(*it)->inputAccount();
				break;
			}
		}
	}
	void deleteBankAccount(string name) {
		vector<BankAccount*>::iterator it;
		for (it = accounts.begin(); it != accounts.end(); it++) {
			if ((*it)->getAccountName().compare(name) == 0) {
				accounts.erase(it);
				break;
			}
		}
	}
	void sortBankAccount() {
		vector<BankAccount*>::iterator it;
		sort(accounts.begin(), accounts.end(), greater<BankAccount*>());
		for (it = accounts.begin(); it != accounts.end(); it++) {
			(*it)->outputAccount();
		}
	}
	BankAccount* getBankAccountByName(string name) {
		vector<BankAccount*>::iterator it;
		for (it = accounts.begin(); it != accounts.end(); it++) {
			if ((*it)->getAccountName().compare(name) == 0) {
				return *it;
			}
		}
	}


};