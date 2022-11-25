
Name: PHENG SOPHA
Project:  BANK MANAGEMENT

App Features
User Login (User Managers)

UI DESIGN

-------------------------------------
WELCOME TO BANK MANAGEMENT
-------------------------------------
Enter username: 
Enter password:
If user and password is correct will checking type of (USER Manager or Branch Manager) and then go to different menu
Else go to input username and password again
NOTE: username : dara password : 123 Type ADMIN | username : lina password : 123 Type NORMAL
-------------------------------------
1 USER MENU
-------------------------------------
1.	ADD NEW USER
2.	EDIT USER
3.	DELETE USER
4.	VIEW USER
5.	SEARCH USER
0.	EXIT
Enter Command: 1
If choose not option (0-5) show message invalid option
If user choose 1 go ADD NEW USER
-------------------------------------
1 ADD NEW USER
-------------------------------------
Enter User Name:
Enter User Password: 
Enter User Role: Press 1. ADMIN 2. NORMAL
Do you want to continue (y/n)?: y
If yes go to add new user
If no back to USER menu
-------------------------------------
2 EDIT USER
-------------------------------------
By Name
Search before edit 
Enter NAME: Lina
If wrong id, name will show message the branch’s id or name was not found
Else right will go to:
NAME : Lina 
1.	EDIT NAME
2.	EDIT PASSWORD
3.	EDIT ROLE
Enter command: 
After edited will show message: Do you want to continue(y/n)?: y
If yes will go to choose option again
Else back to USER menu
-------------------------------------
3 DELETE USER
-------------------------------------
By Name
Enter Name: Lina
If id or name not in the list, will show name is not in the list
Else right will show full information of USER:
NAME : Lina
Role: ADMIN
Are you sure?(y/n):
If yes deleted successfully and ask: Do you want to continue? 
Else no deleted was cancelled and ask Do you want to continue?
If yes will go to choose option again
Else back to USER Menu
-------------------------------------
4 VIEW
-------------------------------------
NAME			TYPE
Lina			NORMAL
Dara			ADMIN
Bora			NORMAL
-------------------------------------
5 SEARCH USER
-------------------------------------
Enter NAME: Lina
Show Information: 
Name: Lina Role : ADMIN
Do you want to continue?: 
If yes will go to Enter name again
Else go to USER MENU
-------------------------------------
0 EXIT
-------------------------------------
THANK YOU
-------------------------------------
2 BANK MENU
-------------------------------------
1 ADD BANK ACCOUNT
2 DEPOSITS, WITHDRAW, BALANCE
3 VIEW ALL BANK ACCOUNT
4 EDIT BANK ACCOUNT
5 DELETE BANK ACCOUNT 
6 SEARCH BANK ACCOUNT
7 SORT ALL BANK ACCOUNT
0 EXIT
Enter Command: 1
-------------------------------------
1 ADD BANK ACCOUNT
-------------------------------------
1 Saving Account 
2 Checking Account
0 EXIT
Enter command: 1
-------------------------------------
Saving Account
-------------------------------------
Enter Account No: 
Enter Name:
Enter Balance:
Enter Interest Rate: 
-------------------------------------
Checking Account
-------------------------------------
Enter Account Number: 
Enter Name:
Enter Balance:
Enter Charge Fee: 
Do you want to continue?(y/n):
If yes go to add new bank account
Else back to choose option again
Enter command: 0 back to MAIN MENU

-------------------------------------
2 DEPOSITS, WITHDRAW, BALANCE
-------------------------------------
1 Deposit
2 Withdraw
3 Check Balance
Enter command: 1
Enter Account Number: 101
Enter amount: 100
Deposit success to your account: 100
Do you want to continue(y/n):
-------------------------------------
3 EDIT BANK ACCOUNT
-------------------------------------
1 By Acc No.
2 By Name
Enter command: 1
Enter Account Number: 101 
Enter New Name: dada
Are you Sure?(y/n)
After edited will show message: Do you want to continue(y/n)?: y
If yes will go to choose option again
Else back to main menu
-------------------------------------
4 DELETE ACCOUNT
-------------------------------------
1 By Acc No.
2 By Name
Enter command: 1
Enter ID: 101
If id or name not in the list, will show id and name are not in the list
Else right will show full information of account:
Account No: 101
Name: Lina
Interest Rate: 5
Are you sure?(y/n):
If yes deleted successfully and ask: Do you want to continue? 
Else no deleted was cancelled and ask Do you want to continue?
If yes will go to choose option again
Else back to MAIN Menu
-------------------------------------
5 VIEW ALL ACCOUNT
-------------------------------------
No.	Acc  No.	NAME		Balance		
1	10001		Lina		5000		
2	10002		Bora		1000		
3	10003		Dara		7000	

-------------------------------------
6 SEARCH ACCOUNT
-------------------------------------
1 By Acc No.
2 By Name
Enter command: 1
Enter Account Number: 10001
Show Information: 
Acc No. 10001
Name: Lina
Balance: 5000
Interest Rate: 5
Do you want to continue?: 
If yes will go to choose option again
Else go to MAIN MENU
-------------------------------------
7 SORT ACCOUNT
-------------------------------------
1 By ID
2 By Name
Enter command: 1 or 2
-------------------------------------		
1 VIEW (Sort by NAME)
-------------------------------------
No.	Acc  No.	NAME		Balance	
1	102		Bora		1000
2	103		Dara		7000		
3	101		Lina		5000		
-------------------------------------
0 EXIT
-------------------------------------
THANK FOR USING OUR BANK MANAGEMENT SYSTEM

