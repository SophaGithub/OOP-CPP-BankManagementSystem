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
using namespace std;

enum menuType { NEW_ACCOUNT = '1', CUSTOMER_SERVICE = '2',VIEW_ALL_ACCOUNT = '3', 
	DELETE_ACCOUNT = '4', EDIT_ACCOUNT = '5', SEARCH_ACCOUNT = '6', SORT_ACCOUNT = '7', /*SAVE_ACCOUNT = '8', LOAD_ACCOUNT = '9',*/ EXIT_APPLICATION = '0' };
enum accountType { SAVING_ACCOUNT = 1, CHECKING_ACCOUNT = 2, EXIT_ACCOUNT = 0};
enum customerType {DEPOSIT = 1, WITHDRAW = 2, CHECKING_BALANCE = 3, EXIT_CUSTOMER = 0};
enum userMenuType {NEW_USER = '1', VIEW_USER = '2', EDIT_USER = '3', DELETE_USER = '4', SEARCH_USER = '5', EXIT_USER = '0' };
class Application : public BankOffice {
public:
	void bankApplication() {
		char ch;
		int num = 0;
		string name;
		int op = 0;
		BankOffice bankOffice;
		SavingAccount* savingAccount = nullptr;
		CurrentAccount* currentAccount = nullptr;
		char choice;
		do
		{
			system("cls");
			Menu::mainMenu();
			ch = InputService::getCommand(); //method from input service class
			system("cls");
			switch (ch)
			{
			case menuType::NEW_ACCOUNT:
				//input accounts
				do {
					Menu::createNewAccountMenu();
					op = InputService::getCommand2();
					switch (op) {
					case accountType::SAVING_ACCOUNT:
						savingAccount = new SavingAccount();
						savingAccount->inputAccount();
						bankOffice.addBankAccount(savingAccount);
						break;
					case accountType::CHECKING_ACCOUNT:
						currentAccount = new CurrentAccount();
						currentAccount->inputAccount();
						bankOffice.addBankAccount(currentAccount);
						break;
					case accountType::EXIT_ACCOUNT: break;
					default: cout << "\a"; break;
					}
					choice = getContinue(); //method from input service class
				} while (choice != 'n');
				break;
			case CUSTOMER_SERVICE:
				do {
					Menu::customerMenu();
					op = InputService::getCommand3();
					switch (op) {
					case customerType::DEPOSIT:
						num = getNumber(); //method from input service class
						bankOffice.depositBankAccount(num);
						break;
					case customerType::WITHDRAW:
						num = getNumber(); //method from input service class
						bankOffice.withdrawBankAccount(num);
						break;
					case customerType::CHECKING_BALANCE:
						num = getNumber(); //method from input service class
						bankOffice.checkBalance(num);
						break;
					case customerType::EXIT_CUSTOMER: break;
					default: cout << "\a";
					}
					choice = getContinue();
				} while (choice != 'n');
				break;
			case menuType::VIEW_ALL_ACCOUNT:
				bankOffice.viewAllBankAccount();
				break;
			case menuType::DELETE_ACCOUNT:
				do {
					Menu::optionMenu();
					op = InputService::getOption();
					switch (op) {
					case 1:
						num = getNumber(); //method from input service class
						bankOffice.deletedBankAccountbyAccNo(num);
						break;
					case 2:
						name = AccountName();
						bankOffice.deletedBankAccountbyName(name);
						break;
					case 0: break;
					default: cout << "\a";
					}

					choice = getContinue();
				} while (choice != 'n');
				break;
			case menuType::EDIT_ACCOUNT:
				do {
					Menu::optionMenu();
					op = InputService::getOption();
					switch (op) {
					case 1:
						num = getNumber(); //method from input service class
						bankOffice.editBankAccount(num);
						break;
					case 2:
						name = AccountName();
						bankOffice.editBankAccount(name);
						  break;

					case 0: break;
					default: cout << "\a";
					}
					choice = getContinue();
				} while (choice != 'n');
				break;
			case menuType::SEARCH_ACCOUNT:
				Menu::optionMenu();
				op = InputService::getOption();
				switch (op) {
				case 1: {
					num = getNumber(); //method from input service class
					BankAccount* account = bankOffice.getAccountById(num);
					account->outputAccount();
					
				}
					  break;

				case 2: {
					name = AccountName(); //method from input service class
					BankAccount* account = bankOffice.getAccountByName(name);
					account->outputAccount();
				}
					  break;

				case 0:
					break;
				default: cout << "\a";
				}
				break;

			case menuType::SORT_ACCOUNT:
				bankOffice.sortBankAccountById();
				break;
				//case menuType::SAVE_ACCOUNT:
				//	//bankOffice.writeBankAccount();
				//	break;
				//case menuType::LOAD_ACCOUNT:
				//	//bankOffice.readBankAccount();
				//	break;
			case EXIT_APPLICATION:
				exit(1);
				ConfirmService::thankMessage();

				break;
			default:cout << "\a";
			}
			cin.ignore();
			cin.get();
		} while (ch != '0');
	}
	void userApplication() {
		char cha;
		string username;
		UserManager userManager;
		do
		{
			system("cls");
			Menu::userMenu();
			cin >> cha;
			system("cls");
			switch (cha)
			{
			case userMenuType::NEW_USER: {
				User user;
				user.inputUser();
				userManager.addUser(user);
				break;
			}
			case userMenuType::VIEW_USER:
				userManager.viewUser();
				break;
			case userMenuType::EDIT_USER: {
				do{
					Menu::editUserMenu();
					cin >> cha;
					switch (cha) {
					case '1':
						username = getName();
						userManager.editUserRole(username);
						break;
					case '2':
						username = getName();
						userManager.editUserName(username);
						break;
					case '3':
						username = getName();
						userManager.editUserPassword(username);
					break;
					case '0':
						break;
					default: cout << "\a";
					}
					cha = getContinue();
				} while (cha != 'n');
				break;
			}
			case userMenuType::DELETE_USER: {
				string username = getName();
				userManager.deleteUser(username);
				break;
			}
			case userMenuType::SEARCH_USER: {
				string username = getName();
				User* user = userManager.getUserByName(username);
				break;
			}
			case userMenuType::EXIT_USER: exit(1); break;
			default:
				cout << "\a";
			}
			cin.ignore();
			cin.get();
		} while (cha != '0');
	}


};