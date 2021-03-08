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
	std::cout << "type 2 to Remove Person from the Bank" << std::endl;
	std::cout << "type 3 to Open Current Account" << std::endl;
	std::cout << "type 4 to Open Savings Account" << std::endl;
	std::cout << "type 5 to Close an Account" << std::endl;
	std::cout << "type 6 to Deposit money to an Account" << std::endl;
	std::cout << "type 7 to Withdraw money from an Account" << std::endl;
	std::cout << "type 8 to check the balance of an Account" << std::endl;
	std::cout << "type 9 to Print out the information of all the accounts" << std::endl;
	
	//initialise a Person object.
	Bank harryBank("Bank");

	while (command != -1)
	{
		std::cout << "Type your options now" << std::endl;
		std::cin >> command;

		switch (command)
		{
		case (1): //Add Person to Bank
		{
			std::string name;
			std::cout << "Input the name of the account holder (e.g Harry)" << std::endl;
			std::cin >> name;
			//Register the new person
			harryBank.registerPerson(name);
		}
		case (2): //Remove a Person from the Bank
		{
			std::string name;
			std::cout << "Input the name of the account holder (e.g Harry)" << std::endl;
			std::cin >> name;
			//Register the new person
			harryBank.removePerson(name);
		}
		case (3): //Open a current account
		{
			std::string name;
			int accountNo;
			double startingBalance;
			std::cout << "Input the person, then an account number followed by the starting balance. (e.g harry 1234  50.00)" << std::endl;
			std::cin >> name >> accountNo >> startingBalance;
			//Try to add the current account to the person's accounts
			harryBank.newCurrentAccount(name, accountNo, startingBalance);
			break;
		}
		case (4): //Open a current account
		{
			std::string name;
			int accountNo;
			double startingBalance;
			double *interest;
			std::cout << "Input the persons name, account number, starting balance and finally the interest (e.g harry 1234  50.00 1.1(for 10%))" << std::endl;
			std::cin >> name >> accountNo >> startingBalance >> *interest;
			//Try to add the current account to the person's accounts
			harryBank.newSavingsAccount(name, accountNo, startingBalance, interest);
			break;
		}
		case (5): //Close an account
		{
			std::string name;
			int accountNumber;
			std::cout << "Input an account name followed by account number (e.g harry 1234)" << std::endl;
			std::cin >> name >> accountNumber;
			harryBank.closeAccount(name, accountNumber);
			break;
		}
		case (6): //Deposit money into an account
		{
			std::string name;
			int accountNumber;
			double amount;
			std::cout << "Input the account holders name, account number and the amount you wish to deposit (e.g harry 1234 50.0)" << std::endl;
			std::cin >> name >> accountNumber >> amount;
			harryBank.depositMoney(name, accountNumber, amount);
			break;
		}
		case (7): //Withdraw money from an account
		{
			std::string name;
			int accountNumber;
			double amount;
			std::cout << "Input the account holders name, account number and the amount you wish to withdraw (e.g harry 1234 50.0)" << std::endl;
			std::cin >> name >> accountNumber >> amount;
			harryBank.withdrawMoney(name, accountNumber, amount);
			break;
		}
		case (8): //Check an accounts balance
		{
			std::string name;
			int accountNumber;
			std::cout << "Input the account holders name followed by the account number you wish to check for(e.g harry 1234)" << std::endl;
			std::cin >> name >> accountNumber;
			harryBank.checkBalance(name, accountNumber);
			break;
		}
		case (9): //Print all account information of an account holder
		{
			std::string name;
			std::cout << "Input the account holders name for who you wish to check the account of(e.g harry)" << std::endl;
			std::cin >> name;
			harryBank.checkAccounts(name);
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
