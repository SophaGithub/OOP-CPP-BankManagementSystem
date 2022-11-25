#include <iostream>
#include "Application.cpp"
#include "UserManager.cpp"
#include "ApplicationService.cpp"
using namespace std;

int main() {
	Application app;
	UserManager userManager;
	string username;
	string password;

	do {
		cout << "\n\n\n\tWELCOME TO BANK MANAGEMENT";
		cout << "\n\n\tenter username: ";
		cin >> username;
		cout << "\n\n\tenter password: ";
		cin >> password;

		User* user = userManager.authenticateUser(username, password);
		if (user != nullptr) {
			if (user->getType() == 1) {
				app.userApplication();
				//cout << "hello world";
			}
			else if (user->getType() == 2) {
				app.bankApplication();
			}
		}
		else {
			cout << "invalid user" << endl;
		}
	} while (true);
			
	return 0;
}