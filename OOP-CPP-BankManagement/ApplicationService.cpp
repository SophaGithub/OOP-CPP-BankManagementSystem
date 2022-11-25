#include <iostream>
#include "BankAccount.cpp"
#include "CurrentAccount.cpp"
#include "SavingAccount.cpp"
#include "BankOffice.cpp"
#include "Menu.cpp"
#include "ConfirmService.cpp"
#include "User.cpp"
#include "UserManager.cpp"
#include "InputService.cpp"
#include "BankAccountService.cpp"
//#include "User.cpp"
//#include "UserManager.cpp"
using namespace std;

class ApplicationService{
public:
	void run() {
		
		BankAccountService accounts;
		SavingAccount* savingAccount = nullptr;
		CurrentAccount* currentAccount = nullptr;
		string name;
		int count = 0;
		int op;
		do {
			cout << "1 add" << endl;
			cout << "2 add" << endl;
			cout << "3 view" << endl;
			cout << "4 delete" << endl;
			cout << "5 sort" << endl;
			cin >> op;
			switch (op) {
			case 1:
				savingAccount->inputAccount();
				accounts.addBankAccount(savingAccount);
				break;
			case 2:
				currentAccount->inputAccount();
				accounts.addBankAccount(currentAccount);
				break;
			case 3:
				accounts.viewAllBankAccount();
				break;
			case 4:
				cin >> name;
				accounts.deleteBankAccount(name);
				break;
			case 5:
				accounts.sortBankAccount();
				break;
			}
		} while (op != 0);
	}


};