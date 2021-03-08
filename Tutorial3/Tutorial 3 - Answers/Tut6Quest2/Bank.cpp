

#include <iostream>
#include "Account.h"
#include "Person.h"
#include "Date.h"
#include "CurrentAccount.h"
#include "SavingAccount.h"
using namespace std;

int main() {


	int command = 0;

	cout << "Use the following options to control this program" << endl;
	cout << "type -1 to exit" << endl;
	cout << "type 1 to Open Account" << endl;
	cout << "type 2 to Close Account" << endl;
	cout << "type 3 to Credit money to an Account" << endl;
	cout << "type 4 to Debit money from an Account" << endl;
	cout << "type 5 to Print out the information of all the accounts" << endl;
	cout << "type 6 to Print total number of accounts created" << endl;
	//initialise a Person object.
	Person person1("John", (20, 10, 2000));

	while (command != -1)
	{
		cout << "Type your options now" << endl;
		cin >> command;

		switch (command)
		{
		case (1): //Open a new account
		{
			int accountNo, day, month, year, acctType;
			double startingBalance, IRate;

			cout << "Input an account number followed by the starting balance and date of Creation. (e.g 1234  50.00 dd mm yyyy)" << endl;
			cin >> accountNo >> startingBalance >> day >> month >> year;
			Date date(day, month, year);

			cout << "type 1 for Current Account" << endl;
			cout << "type 2 for Saving Account" << endl;
			cin >> acctType;
			if (acctType == 1){
				CurrentAccount currAcct(&accountNo, &startingBalance, date);
				person1.addAccount(currAcct);
			}
			else
			{ 
				cout << "Enter Interest Rate" << endl;
				cin >> IRate;
				SavingAccount savAcct(&accountNo, &startingBalance, date, IRate);
				person1.addAccount(savAcct);	//Add the account to the person's account vector
			}			
			
			cout << "Account : " << accountNo << " has been successfully created with a balance of : " << startingBalance << endl;
			break;
		}
		case (2): //Close an account
		{
			int accountNo;
			cout << "Input an account number" << endl;
			cin >> accountNo;
			if (person1.closeAccount(&accountNo))
			{
				cout << "Successfully closed account : " << accountNo << endl;
			}
			else {
				cout << "Cannot find account : " << accountNo << endl;
			}
			break;
		}
		case (3): //Credit money to an account
		{
			int accNo;
			double bal;
			cout << "Input account number followed by balance to add (e.g 123 20.00)" << endl;
			cin >> accNo >> bal;
			if (person1.creditMoney(&accNo, &bal)) {
				cout << "Successfully deposited : " << bal << " to account : " << accNo << endl;
			}
			else {
				cout << "Account not found or negative quantity supplied" << endl;
			}

			break;
		}
		case (4): //Debit money from an account
		{
			int accNo;
			double bal;
			cout << "Input and account number followed by the balance to remove (e.g 123 20.00)" << endl;
			cin >> accNo >> bal;
			if (person1.debitMoney(&accNo, &bal)) {
				cout << "Successfully withdrawn : " << bal << " to account : " << accNo << endl;
			}
			else {
				cout << "Account not found or negative quantity supplied" << endl;
			}
			break;
		}
		case (5): //Print out account information for all accounts
		{
			person1.printAllAccounts();
			break;
		}
		case (6):
		{
			cout << "Total numbers of existing accounts: " << Account::getCount() << endl;
			break;
		}
		case (-1):
		{
			command = -1;
			break;
		}
		default:
		{
			cout << "Command not recognised. Try again" << endl;
			break;
		}
		}


	}
	cout << "Exiting" << endl;
	return 0;
}
