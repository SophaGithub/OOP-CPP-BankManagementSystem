#pragma once
#include <iostream>
using namespace std;

class Menu {
public:
	void mainMenu() {
		cout << "\n\n\n\tMAIN MENU";
		cout << "\n\n\t01. NEW ACCOUNT";
		cout << "\n\n\t02. DEPOSIT, WITHDRAW, BALANCE";
		cout << "\n\n\t03. VIEW ALL ACCOUNT";
		cout << "\n\n\t04. DELETE AN ACCOUNT";
		cout << "\n\n\t05. EDIT AN ACCOUNT";
		cout << "\n\n\t06. SEARCH AN ACCOUNT";
		cout << "\n\n\t07. SORT ACCOUNT";
		/*cout << "\n\n\t08. SAVE";
		cout << "\n\n\t09. LOAD";*/
		cout << "\n\n\t00. EXIT";
		cout << "\n\n\tselect you option (0-7) ";
	}
	void createNewAccountMenu() {
		cout << "\n\n\n\tMenu";
		cout << "\n\n\n\t01. SAVING ACCOUNT";
		cout << "\n\n\n\t02. CURRENT ACCOUNT";
		cout << "\n\n\n\tselect your option: ";
	}
	void userMenu() {
		cout << "\n\n\tADMIN MENU";
		cout << "\n\n\t01. ADD NEW USER";
		cout << "\n\n\t02. VIEW ALL USERS";
		cout << "\n\n\t03. EDIT AN USER";
		cout << "\n\n\t04. DELETE AN USER";
		cout << "\n\n\t05. SEARCH AN USER";
		cout << "\n\n\t00. EXIT";
		cout << "\n\n\tSelect your option: ";
	}
	void customerMenu() {
		cout << "\n\n\t01. DEPOSIT AMOUNT";
		cout << "\n\n\t02. WITHDRAW AMOUNT";
		cout << "\n\n\t03. CHECK BALANCE";
		cout << "\n\n\t00. EXIT";
		cout << "\n\n\n\tselect your option: ";
	}
	void optionMenu() {
		cout << "\n\n\t01. BY ACC NO.";
		cout << "\n\n\t02. BY NAME";
		cout << "\n\n\t00. EXIT";
		cout << "\n\n\tselect your option: ";
	}
	void editUserMenu() {
		cout << "\n\n\t01. EDIT ROLE";
		cout << "\n\n\t02. EDIT NAME";
		cout << "\n\n\t03. EDIT PASSWORD";
		cout << "\n\n\t04. EXIT" << endl;
		cout << "\n\n\t enter command: ";

	}
	
	
	
};