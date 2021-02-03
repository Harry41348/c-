// Bank.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Person.h"
#include "CurrentAccount.h"
#include "Bank.h"

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
	std::cout << "type 1 to Add Person to the Bank" << std::endl;
	std::cout << "type 2 to Open Current Account" << std::endl;
	std::cout << "type 3 to Close Account" << std::endl;
	std::cout << "type 4 to Credit money to an Account" << std::endl;
	std::cout << "type 5 to Debit money from an Account" << std::endl;
	std::cout << "type 6 to Print out the information of all the accounts" << std::endl;
	
	//initialise a Person object.
	Bank harryBank("Bank");

	while (command != -1)
	{
		std::cout << "Type your options now" << std::endl;
		std::cin >> command;

		switch (command)
		{
		case (1): // Add Person to Bank
		{
			std::string name;
			std::cout << "Input the name of the account holder (e.g Harry)" << std::endl;
			std::cin >> name;
			//Register the new person
			harryBank.registerPerson(name);
		}
		case (2): //Open a new account
		{
			std::string name;
			int accountNo;
			double startingBalance;
			std::cout << "Input the person, then an account number followed by the starting balance. (e.g harry 1234  50.00)" << std::endl;
			std::cin >> name >> accountNo >> startingBalance;
			//Now create a new Account object
			CurrentAccount acc(&accountNo, &startingBalance);
			//Add the account to the person's account vector
			if (harryBank.newAccount(acc, name)) {
				std::cout << "Account : " << accountNo << " has been successfully created with a balance of : " << startingBalance << std::endl;
			}
			else {
				std::cout << "Error opening account" << std::endl;
			}
			break;
		}
		case (3): //Close an account
		{
			int * accountNo;
			std::string accName;
			std::cout << "Input an accouunt name followed by account number (e.g harry 1234)" << std::endl;
			std::cin >> accName >> *accountNo;
			if (harryBank.closeAccount(accountNo, accName))
			{
				std::cout << "Successfully closed account : " << accountNo << std::endl;
			}
			else {
				std::cout << "Error closing account" << std::endl;
			}
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
