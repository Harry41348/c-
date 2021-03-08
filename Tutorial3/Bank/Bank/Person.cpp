#include "Person.h"

#include "CurrentAccount.h"
#include "SavingsAccount.h"
#include "Account.h"

#include <string>
#include <vector>
#include <iostream>


//Constructor
Person::Person(std::string newName) :name(newName) {
	
}

//Setters
bool Person::addCurrentAccount(int accountNumber, double balance) {
	for (size_t i = 0; i < accounts.size(); i++) {
		if (accounts.at(i)->getAccountNumber == accountNumber) {
			std::cout << "Account number already exists." << std::endl;
			return false;
		}
	}
	//for (std::vector<Account*>::iterator it = this->accounts.begin(); it != this->accounts.end(); ++it) {
	//	if ((*it)->getAccountNumber == accountNumber) {
	//		std::cout << "Account number already exists." << std::endl;
	//		return false;
	//	}
	//}
	this->accounts.push_back(new CurrentAccount(accountNumber, balance));
	std::cout << "Account created succesfully, with the account number of " << accountNumber << " and a balance of £" << balance << ".\n";
	return true;
}

bool Person::addSavingsAccount(int accountNumber, double balance, double *interest) {
	for (size_t i = 0; i < accounts.size(); i++) {
		if (accounts.at(i)->getAccountNumber == accountNumber) {
			std::cout << "Account number already exists." << std::endl;
			return false;
		}
	}
	this->accounts.push_back(new SavingsAccount(accountNumber, balance, interest));
	std::cout << "Account created succesfully, with the account number of " << accountNumber << " and a balance of £" << balance << ".\n";
	return true;
}

bool Person::closeAccount(int accountNumber) {
	for (size_t i = 0; i < accounts.size(); i++) {
		int checkNumber = accounts.at(i)->getAccountNumber;
		if (checkNumber == accountNumber) {
			accounts.erase(accounts.begin() + i);
			std::cout << "Account " << accountNumber << " removed succesfully." << std::endl;
			return true;
		}
	}
	unableToLocateAccount(accountNumber);
	return false;
}

bool Person::depositMoney(int accountNumber, double amount) {
	for (size_t i = 0; i < accounts.size(); i++) {
		if (accounts.at(i)->getAccountNumber == accountNumber) {
			return accounts.at(i)->deposit(amount);
		}
	}
	unableToLocateAccount(accountNumber);
	return false;
}

bool Person::withdrawMoney(int accountNumber, double amount) {
	for (size_t i = 0; i < accounts.size(); i++) {
		if (accounts.at(i)->getAccountNumber == accountNumber) {
			return accounts.at(i)->withdraw(amount);
		}
	}
	unableToLocateAccount(accountNumber);
	return false;
}

//Getters
std::string Person::getName() const {
	return this->name;
}

double Person::checkBalance(int accountNumber) {
	for (std::vector<Account*>::iterator it = this->accounts.begin(); it != this->accounts.end(); ++it) {
		if ((*it)->getAccountNumber == accountNumber) {
			return (*it)->getBalance();
		}
	}
	unableToLocateAccount(accountNumber);
	return 0;
}

void Person::printAllAccounts() {
	if (accounts.size > 0) {
		for (std::vector<Account*>::iterator it = this->accounts.begin(); it != this->accounts.end(); ++it) {
			std::cout << (*it)->printDetails << std::endl;
		}
	} else {
		std::cout << "Person: " << name << " has no accounts" << std::endl;
	}
}

//Functions
void Person::unableToLocateAccount(int accountNumber) {
	std::cout << "Unable to locate the account " << accountNumber << ".\n";
}

//Deconstructor
Person::~Person() {
	accounts.clear();
}	