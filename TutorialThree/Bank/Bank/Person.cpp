#include "Person.h"

#include "Account.h"
#include <string>
#include <vector>
#include <iostream>


//Constructor
Person::Person(std::string newName) :name(newName) {
	
}

//Setters
void Person::addAccount(Account &acc) {
	this->accounts.push_back(acc);
}

bool Person::closeAccount(int * accNum) {
	for (size_t i = 0; i < accounts.size(); i++) {
		if (accounts.at(i).getAccNo() == *accNum) {
			accounts.erase(accounts.begin() + i);
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
void Person::printAllAccounts() {
	if (accounts.size() > 0) {
		for (Account a : accounts) {
			std::cout << a.getDetails() << std::endl;
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