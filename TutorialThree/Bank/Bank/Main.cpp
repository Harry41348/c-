// Bank.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Person.h"
#include "Account.h"

int main()
{

	//Command List
	 //1 = Open Account
	 //2 = Close Account
	 //3 = Credit money to an Account
	 //4 = Debit money from an Account
	int command = 0;

	std::cout << "Use the following options to control this program" << std::endl;
	std::cout << "type -1 to exit" << std::endl;
	std::cout << "type 1 to Open Account" << std::endl;
	std::cout << "type 2 to Close Account" << std::endl;
	std::cout << "type 3 to Credit money to an Account" << std::endl;
	std::cout << "type 4 to Debit money from an Account" << std::endl;
	std::cout << "type 5 to Print out the information of all the accounts" << std::endl;
	//initialise a Person object.
	Person person1("Harry");

	while (command != -1)
	{
		std::cout << "Type your options now" << std::endl;
		std::cin >> command;

		switch (command)
		{
		case (1): //Open a new account
		{
			int accountNo;
			double startingBalance;
			std::cout << "Input an account number followed by the starting balance. (e.g 1234  50.00)" << std::endl;
			std::cin >> accountNo >> startingBalance;
			//Now create a new Account object
			Account acc1(&accountNo, &startingBalance);
			//Add the account to the person's account vector
			person1.addAccount(acc1);
			std::cout << "Account : " << accountNo << " has been successfully created with a balance of : " << startingBalance << std::endl;
			break;
		}
		case (2): //Close an account
		{
			int accountNo;
			std::cout << "Input an account number" << std::endl;
			std::cin >> accountNo;
			if (person1.closeAccount(&accountNo))
			{
				std::cout << "Successfully closed account : " << accountNo << std::endl;
			}
			else {
				std::cout << "Cannot find account : " << accountNo << std::endl;
			}
			break;
		}
		case (3): //Credit money to an account
		{
			int accNo;
			double bal;
			std::cout << "Input and account number followed by the balance to add (e.g 123 20.00)" << std::endl;
			std::cin >> accNo >> bal;
			if (person1.creditMoney(&accNo, &bal)) {
				std::cout << "Successfully deposited : " << bal << " to account : " << accNo << std::endl;
			}
			else {
				std::cout << "Account not found or negative quantity supplied" << std::endl;
			}

			break;
		}
		case (4): //Debit money from an account
		{
			int accNo;
			double bal;
			std::cout << "Input and account number followed by the balance to remove (e.g 123 20.00)" << std::endl;
			std::cin >> accNo >> bal;
			if (person1.debitMoney(&accNo, &bal)) {
				std::cout << "Successfully withdrawn : " << bal << " to account : " << accNo << std::endl;
			}
			else {
				std::cout << "Account not found or negative quantity supplied" << std::endl;
			}
			break;
		}
		case (5): //Print out account information for all accounts
		{
			person1.printAllAccounts();
			break;
		}
		case (-1):
		{
			command = -1;
			break;
		}
		default:
		{
			std::cout << "Command not recognised. Try again" << std::endl;
			break;
		}
		}


	}
	std::cout << "Exiting" << std::endl;
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
