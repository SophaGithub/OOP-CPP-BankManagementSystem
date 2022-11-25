#pragma once
#include <iostream>
using namespace std;

class ConfirmService {
public:
	void invalidMessage() {
		cout << "\n\n\tinvalid";
	}
	void isInvalidNumber() {
		cout << "\n\n\tinvalid number";
	}
	void invalidAmount() {
		cout << "\n\n\tinvalid amount";
	}
	void thankMessage() {
		cout << "\n\n\tTHANKS FOR USING YOUR BANK MANAGEMENT SYSTEM";
	}
	void notFoundMessage() {
		cout << "\n\n\tnot found";
	}
	void deleteMessage() {
		cout << "account has been deleted" << endl;
	}
	void deleteCanncelMessage() {
		cout << "\n\n\tcanncel deleted" << endl;
	}
	void editMessage() {
		cout << "\n\n\taccount has been edited" << endl;
	}
	void editCanncelMessage() {
		cout << "\n\n\tcanncel edited" << endl;
	}
};