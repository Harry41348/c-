#include "Person.h"

#include "CurrentAccount.h"
#include "Account.h"

#include <string>
#include <vector>
#include <iostream>


//Constructor
Person::Person(std::string newName) :name(newName) {
	
}

//Setters
bool Person::addCurrentAccount(int accountNumber, double balance) {
	for (std::vector<Account*>::iterator it = this->accounts.begin(); it != this->accounts.end(); ++it) {
		if ((*it)->getAccountNumber == accountNumber) {
			std::cout << "Account number already exists." << std::endl;
			return false;
		}
	}
	this->accounts.push_back(new CurrentAccount(accountNumber, balance));
	std::cout << "Account created succesfully. Your account number is " << accountNumber << " with a balance of " << balance << ".\n";
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
	return unableToLocateAccount(accountNumber);
}

bool Person::depositMoney(int accountNumber, double amount) {
	for (std::vector<Account*>::iterator it = this->accounts.begin(); it != this->accounts.end(); ++it) {
		if ((*it)->getAccountNumber == accountNumber) {
			return (*it)->deposit(amount);
		}
	}
	return unableToLocateAccount(accountNumber);
}

bool Person::withdrawMoney(int accountNumber, double amount) {
	for (std::vector<Account*>::iterator it = this->accounts.begin(); it != this->accounts.end(); ++it) {
		if ((*it)->getAccountNumber == accountNumber) {
			return (*it)->withdraw(amount);
		}
	}
	return unableToLocateAccount(accountNumber);
}

//Getters
std::string Person::getName() const {
	return this->name;
}

void Person::printAllAccounts() {
	if (accounts.size > 0) {
		for (std::vector<Account*>::iterator it = this->accounts.begin(); it != this->accounts.end(); ++it) {
			std::cout << (*it)->getDetails << std::endl;
		}
	} else {
		std::cout << "Person: " << name << " has no accounts" << std::endl;
	}
}

//Functions
bool Person::unableToLocateAccount(int accountNumber) {
	std::cout << "Unable to locate the account " << accountNumber << ".\n";
	return false;
}

//Deconstructor
Person::~Person() {
	accounts.clear();
}	