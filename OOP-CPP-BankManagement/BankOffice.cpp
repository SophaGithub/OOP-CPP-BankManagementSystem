#pragma once
#include<iostream>
#include<iomanip>
#include <vector>
#include "BankAccount.cpp"
#include "ConfirmService.cpp"
#include "InputService.cpp"
#include "DynamicArray.cpp"
#include <fstream>
using namespace std;
class BankOffice : public BankAccount {
private:
	//BankAccount* accounts[100];
	DynamicArray<BankAccount*> accounts;
	//vector<BankAccount*> accounts;
	int count = 0;
public:
	//~BankOffice() {
	//	/*vector<BankAccount*>::iterator it;
	//	for (it = accounts.begin(); it != accounts.end(); it++) {
	//		delete* it;
	//	}*/
	//}
	//Find account by number
	int findBankAccountById(int accountNumber) {
		for (int i = 0; i < count; i++) {
			if (accounts[i]->getAccountNumber() == accountNumber) {
				return i;
			}
		}
		return -1;
	}
	int findBankAccountByName(string accountName) {
		for (int i = 0; i < count; i++) {
			if (accounts[i]->getAccountName() == accountName) {
				return i;
			}
		}
		return -1;
	}
	//Get account by number
	BankAccount* getAccountById(int accountNumber) {
		BankAccount* account = nullptr;
		for (int i = 0; i < count; i++) {
			if (accounts[i]->getAccountNumber() == accountNumber) {
				return accounts[i];
			}
		}
		return account;
	}
	BankAccount* getAccountByName(string accountName) {
		BankAccount* account = nullptr;
		for (int i = 0; i < count; i++) {
			if (accounts[i]->getAccountName() == accountName) {
				return accounts[i];
			}
		}
		return account;
	}

	//addBankAccount
	void addBankAccount(BankAccount* account) {
		accounts[count] = new BankAccount();
		accounts[count] = account;
		count++;
	}
	//editBankAccount
	void editBankAccount(int accountNumber) {
		string name;
		char option;
		int found = findBankAccountById(accountNumber);

			if (found != -1) {
				name = InputService::getNewName();
				option = InputService::confirmMessage();
				if (option != 'n') {
					accounts[found]->setAccountName(name);
					ConfirmService::editMessage(); //message
				}
				else {
					ConfirmService::editCanncelMessage(); //message
				}
			}
			else {
				ConfirmService::notFoundMessage();
			}
		
	}
	void editBankAccount(string accountName) {
		string name;
		char option;
		int found = findBankAccountByName(accountName);

		if (found != -1) {
			name = InputService::getNewName();
			option = InputService::confirmMessage();
			if (option != 'n') {
				accounts[found]->setAccountName(name);
				ConfirmService::editMessage(); //message
			}
			else {
				ConfirmService::editCanncelMessage(); //message
			}
		}
		else {
			ConfirmService::notFoundMessage();
		}

	}
	//deleteBankAccount
	void deleteBankAccount(int accountNumber) {
		int found = findBankAccountById(accountNumber);
		if (found != -1) {
			for (int i = found; i < count; i++) {
				accounts[i] = accounts[i + 1];
			}
			count--;
		}
		else {
			ConfirmService::notFoundMessage(); //message
		}
	}
	void deleteBankAccount(string accountName) {
		int found = findBankAccountByName(accountName);
		if (found != -1) {
			for (int i = found; i < count; i++) {
				accounts[i] = accounts[i + 1];
			}
			count--;
		}
		else {
			ConfirmService::notFoundMessage(); //message
		}
	}
	void deletedBankAccountbyName(string accountName) {
		char option;
		int index = findBankAccountByName(accountName);
		if (index != -1) {
			accounts[index]->outputAccount();
			option = InputService::confirmMessage();
			if (option != 'n') {
				deleteBankAccount(accountName);
				ConfirmService::deleteMessage(); //message
			}
			else {
				ConfirmService::deleteCanncelMessage(); //message
			}
		}
		else {
			ConfirmService::notFoundMessage(); //message
		}
	}
	void deletedBankAccountbyAccNo(int accountNumber) {
		char option;
		int index = findBankAccountById(accountNumber);
		if (index != -1) {
			accounts[index]->outputAccount();
			option = InputService::confirmMessage();
			if (option != 'n') {
				deleteBankAccount(accountNumber);
				ConfirmService::deleteMessage(); //message
			}
			else {
				ConfirmService::deleteCanncelMessage(); //message
			}
		}
		else {
			ConfirmService::notFoundMessage(); //message
		}
	}
	//sort bank account by number
	void sortBankAccountById() {
		BankAccount* temp;
		for (int i = 0; i < count - 1; i++) {
			for (int j = 0; j < count - i - 1; j++) {
				if (accounts[j]->getAccountNumber() > accounts[j + 1]->getAccountNumber()) {
					temp = accounts[j];
					accounts[j] = accounts[j + 1];
					accounts[j + 1] = temp;
				}
			}
		}
	}
	//viewAllBankAccount
	void viewAllBankAccount() {
		cout <<"No" <<"\t" << "Account No" << setw(10) << " " << "Account Name" << setw(10) << " " << "Balance" << endl;

		for (int i = 0; i < count; i++) {
			cout << i + 1 << "\t" << accounts[i]->getAccountNumber() << setw(17) << " " << accounts[i]->getAccountName() << setw(18) << " " << accounts[i]->getBalance() << endl;
		}
	}

	//void writeBankAccount()
	//{
	//	BankAccount* account;
	//	ofstream outFile;
	//	outFile.open("account2.dat", ios::binary);
	//	for (int i = 0; i < count; i++) {
	//		account = accounts[i];
	//		outFile.write(reinterpret_cast<char*> (account), sizeof(BankAccount));
	//	}
	//	outFile.close();
	//}

	//bool readBankAccount()
	//{
	//	BankAccount account;
	//	//bool flag = false;
	//	//int count = 0;
	//	ifstream inFile;
	//	inFile.open("account2.dat", ios::binary);
	//	if (!inFile)
	//	{
	//		cout << "File could not be open !! Press any Key...";
	//		return false;
	//	}
	//	cout << "\nBALANCE DETAILS\n";

	//	while (inFile.read(reinterpret_cast<char*> (&account), sizeof(BankAccount)))
	//	{
	//		//account.outputAccount();

	//	}
	//	inFile.close();
	//	return true;
	//}
	void depositBankAccount(int accountNumber) {
		double amount;
		//int found = findBankAccountById(accountNumber);
		//if (found != -1) {
		//	cout << "Enter amount:";
		//	cin >> amount;
		//	accounts[found]->deposit(amount);
		//}
		//else {
		//	cout << "Not found" << endl;
		//}
		//another option
		BankAccount* account = getAccountById(accountNumber);
		if (account != nullptr) {
			amount = InputService::getAmount();
			account->deposit(amount);
			cout << "\\n\n\tdeposit success to your account " << amount << endl;
		}
		else {
			ConfirmService::invalidAmount();
		}

	}
	void withdrawBankAccount(int accountNumber) {
		double amount;
		//int found = findBankAccountById(accountNumber);
		//if (found != -1) {
		//	accounts[found]->checkBalance();
		//	cout << "Enter amount: ";
		//	cin >> amount;
		//	accounts[found]->withdraw(amount);
		//}
		//else {
		//	cout << "Not found" << endl;
		//}
		//another option
		BankAccount* account = getAccountById(accountNumber);
		if (account != nullptr) {
			amount = InputService::getAmount();
			account->withdraw(amount);
			cout << "\n\n\twithdraw success from your account " << amount << endl;
		}
		else {
			ConfirmService::invalidAmount();
		}

	}

	void checkBalance(int accountNumber) {
		BankAccount* account = getAccountById(accountNumber);
		if (account != nullptr) {
			cout << "\n\n\tThe account balance is:" << account->getBalance();
		}
		else {
			ConfirmService::notFoundMessage();
		}
	}

	/*char confirmMessage() {
		char option;
		cout << "\n\tare you sure?: ";
		cin >> option;
		return option;
	}*/


};