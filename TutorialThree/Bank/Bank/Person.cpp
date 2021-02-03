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
	return false;
}

bool Person::creditMoney(int* accNum, double* credit) {
	for (size_t i = 0; i < accounts.size(); i++) {
		if (accounts.at(i).getAccNo() == *accNum) {
			return accounts.at(i).credit(credit);
		}
	}
	return false;
}

bool Person::debitMoney(int* accNum, double* credit) {
	for (size_t i = 0; i < accounts.size(); i++) {
		if (accounts.at(i).getAccNo() == *accNum) {
			return accounts.at(i).withdraw(credit);
		}
	}
	return false;
}

//Getters
std::string Person::getName() {
	return this->name;
}

void Person::printAllAccounts() {
	if (accounts.size() > 0) {
		for (size_t i = 0; i < accounts.size(); i++) {
			std::cout << accounts.at(i).getDetails() << std::endl;
		}
	}
	else {
		std::cout << "Person: " << name << " has no accounts" << std::endl;
	}
}

//Deconstructor
Person::~Person() {
	accounts.clear();
}	